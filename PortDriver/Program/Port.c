/**********************************************************************************************************************
*  FILE DESCRIPTION
*  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
*        \brief  This file contains implementation of all functions in port driver
*
*        
*
*        Author: Salah Mahmoud
*********************************************************************************************************************/
/* TODO disable interrupts when initializing */
/**********************************************************************************************************************
*  INCLUDES
*********************************************************************************************************************/
#include "TM4C123GH6PM_Hw.h"
#include "Port.h"


#if (PORT_DEV_ERROR_DETECT == STD_ON)

#include "Det.h"

/* will check for autosar release compatability after refactoring Det to autosar module */
/*
#if ((PORT_AR_RELEASE_MAJOR_VERSION != DET_AR_MAJOR_VERSION)\
  || (PORT_AR_RELEASE_MINOR_VERSION != DET_AR_MINOR_VERSION)\
  || (PORT_AR_RELEASE_PATCH_VERSION != DET_AR_PATCH_VERSION))
#error "The autosar version of Det.h is not matching this module version"
#endif
*/

#endif

/**********************************************************************************************************************
*  LOCAL DATA 
*********************************************************************************************************************/

/*local variable containing status of port driver*/
uint8 Port_InitializeStatus = PORT_NOT_INITIALIZED;

/* Local Pointer that will point to the configuration pointer */
STATIC const Port_PinConfigType *Port_ConfigurationPinsPointer = NULL_PTR;


/* Mapper that maps port number to the port address through index */
STATIC uint32 portAPBbaseAddressArray[] = {GPIO_Port_A_APB_BASE_ADDRESS,
                                           GPIO_Port_B_APB_BASE_ADDRESS,
                                           GPIO_Port_C_APB_BASE_ADDRESS,
                                           GPIO_Port_D_APB_BASE_ADDRESS,
                                           GPIO_Port_E_APB_BASE_ADDRESS,
                                           GPIO_Port_F_APB_BASE_ADDRESS};

/* structure containing version info for port driver*/
STATIC Std_VersionInfoType Port_VersionInfo = 
                                      {PORT_VENDOR_ID,
                                      PORT_MODULE_ID,
                                      PORT_SW_MAJOR_VERSION,
                                      PORT_SW_MINOR_VERSION,
                                      PORT_SW_PATCH_VERSION,
                                      };


/**********************************************************************************************************************
*  GLOBAL DATA
*********************************************************************************************************************/

/*configuration pointer*/
extern Port_ConfigType Port_Configuration;

/**********************************************************************************************************************
*  LOCAL FUNCTION PROTOTYPES
*********************************************************************************************************************/
/* local function to configure output current ampere*/
STATIC void Port_ConfigOutputCurrent(uint8 portOutputCurrent,uint32 pinAddress,Port_PinType offset); 
/* local function to configure attached resistor to input pin */
STATIC void Port_ConfigureAttachresistor(uint8 resistorType, uint32 regaddress, Port_PinType offset);
/* local function to configure pin mode */
STATIC void Port_ConfigurePinMode(Port_PinModeType alternatingFun,uint32 regAddress,Port_PinType offset);



/**********************************************************************************************************************
*  GLOBAL FUNCTIONS
*********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void Port_Init(const Port_ConfigType * ConfigPtr)        
* \Description     : This function initializes ALL port pins in port driver module using configuration files                            
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : const Port_ConfigType * ConfigPtr                     
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr)
{
  
  /*if DET errors are enabled*/ 
#if (PORT_DEV_ERROR_DETECT == STD_ON)
  
  /*if configuration pointer is null during initialize*/ 
  if (ConfigPtr == NULL_PTR)
    
  {
    
    /* Report det error */ 
    Det_ReportError (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_INIT_SID,
                     PORT_E_PARAM_CONFIG);
    
    
  }
  else				/*else initialize the Port driver with the provided pointer */
#endif	
  {
    
    /* Set port driver status is initialized */      
    Port_InitializeStatus = PORT_INITIALIZED;	
    /* set configuration pointer to the configuration array */
    Port_ConfigurationPinsPointer = ConfigPtr->ConfiguredPinsArray;
    
    /*********** First Clock enable for ports to apply initial configuration********************/
    
    /*************************enabling port A ************************/
#if(PORTA_ENABLE==PORT_ENABLE)
    
    SET_BIT(RCGCGPIO,R0);
#elif(PORTA_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    /*************************enabling port B ************************/
#if(PORTB_ENABLE==PORT_ENABLE)
    
    SET_BIT(RCGCGPIO,R1);
#elif(PORTB_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    /*************************enabling port C ************************/
    
#if(PORTC_ENABLE==PORT_ENABLE)
    SET_BIT(RCGCGPIO,R2);
#elif(PORTC_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    
    /*************************enabling port D ************************/
    
#if(PORTD_ENABLE==PORT_ENABLE)
    SET_BIT(RCGCGPIO,R3);
#elif(PORTD_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    
    /*************************enabling port E ************************/
    
#if(PORTE_ENABLE==PORT_ENABLE)
    SET_BIT(RCGCGPIO,R4);
#elif(PORTE_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    
    /*************************enabling port F ************************/
    
#if(PORTF_ENABLE==PORT_ENABLE)
    SET_BIT(RCGCGPIO,R5);
#elif(PORTF_ENABLE==PORT_DISABLE)
    
#else
#error "Wrong configuration, please choose either PORT_ENABLE or PORT_DISABLE"
#endif
    
    
    /*********************Second set configurations of each pin*********************************************/
    
    /* loop for all the configuration pins */
    for (int i=0;i<PORT_NUMBER_OF_CONFIGURED_PINS;i++)
    {
      /* Get port number from configuration pointer*/
      Port_PortType ConfiguredPort = Port_ConfigurationPinsPointer[i].PortConfigPortNumber;
      /* Get the port address using the mapping array */
      uint32 pinBaseAddress = portAPBbaseAddressArray[Port_ConfigurationPinsPointer[i].PortConfigPortNumber];
      /* Get pin number from configuration pointer */
      Port_PinType ConfiguredPin = Port_ConfigurationPinsPointer[i].PortConfigPinNumber;
      
      
      /***************** Step1) Unlock the register if required ******************************/        
      /*if the configured pin is PD7 or PF0*/
      if (((ConfiguredPort == PORT_PORT_D)&&(ConfiguredPin == PORT_PIN_D_7))
          ||((ConfiguredPort == PORT_PORT_F)&&((ConfiguredPin == PORT_PIN_F_0))))
      {
        /*Unlock the lock register*/
        GPIOLOCK(pinBaseAddress) = 0x4C4F434B;
        /*Commit the change*/
        SET_BIT(GPIOCR(pinBaseAddress),ConfiguredPin);        }
      /* else if the configured pins are the JTAG pins*/
      else if (((ConfiguredPort == PORT_PORT_C)&&(ConfiguredPin == PORT_PIN_C_3
                                                  ||ConfiguredPin == PORT_PIN_C_2
                                                    ||ConfiguredPin == PORT_PIN_C_1
                                                      ||ConfiguredPin == PORT_PIN_C_0)))
      {
        /* Do nothing these are JTAG pins */
      }
      else
      {
        /* Do nothing */
      }
      
      /***********************Step2) Configure the pinMode of the pin*****************************************/
      Port_ConfigurePinMode(Port_ConfigurationPinsPointer[i].PortPinMode,pinBaseAddress,ConfiguredPin);
      
      /************************Step3) Configure the attached resistor to be pull-up or pull-down**************/
      Port_ConfigureAttachresistor(Port_ConfigurationPinsPointer[i].PortPinResistorAttchIfInput, pinBaseAddress, ConfiguredPin);
      
      /*************************Step4) Configure the pin Direction and level***********************************/
      
      /* if the pin direction is output*/
      if (Port_ConfigurationPinsPointer[i].PortPinDirection == PORT_PIN_OUT)
      {
        /*Set direction to output*/
        SET_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);				
        /*configure output current value*/
        Port_ConfigOutputCurrent(Port_ConfigurationPinsPointer[i].PortOutputCurrent,pinBaseAddress,ConfiguredPin);
        /*Get bid address for bit banding */
        volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<ConfiguredPin)));
        /*Set the output value */
        *pinAddress = Port_ConfigurationPinsPointer[i].PortPinLevelValue<<ConfiguredPin;             
	
      }
      
      else if (Port_ConfigurationPinsPointer[i].PortPinDirection == PORT_PIN_IN)
      {
        /*Clear direction register to set pin as input*/
        CLEAR_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);
        
      }
      else 
      {
        /*Do nothing and return error*/
      }
      
      
    }
    
    
  }
}

/******************************************************************************
* \Syntax          : void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)       
* \Description     : This function sets the port pin direction during runtime                           
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Pin (Port pin ID number)
*                    Direction (Port Pin directon)
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Port_SetPinDirection (Port_PinType Pin, Port_PinDirectionType Direction)
{
  /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
  /* Get the port address using the mapping array */
  uint32 pinBaseAddress = portAPBbaseAddressArray[Port_ConfigurationPinsPointer[Pin].PortConfigPortNumber];
  /* Get pin number from configuration pointer */
  Port_PinType ConfiguredPin = Port_ConfigurationPinsPointer[Pin].PortConfigPinNumber;
  /* if Det errors are enabled */        
#if (PORT_DEV_ERROR_DETECT == STD_ON)       
  /* If port is not initialized*/      
  if (Port_InitializeStatus == PORT_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_UNINIT);
  }
  else
  {
    /*Do nothing*/
  }
  
  /*if Pin ID is greater than the number of configured pins*/
  if (Pin>= PORT_NUMBER_OF_CONFIGURED_PINS)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_PARAM_PIN);
  }
  else
  {
    /*Do nothing*/
  }
  
  
  /* If pin is not allowed to be configured during runtime*/
  if (Port_ConfigurationPinsPointer[Pin].PortPinDirectionChangeable == FALSE)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_DIRECTION_SID, PORT_E_DIRECTION_UNCHANGEABLE);
    
  }
  else
  {
    /*Do nothing*/
  }
  
#endif
  
  
  if (isDetErrorDetected == FALSE) 
  {
    /* if direction is set to output */
    if (Direction == PORT_PIN_OUT)
    {
      /*Set direction to output*/
      SET_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);				
      /*configure output current value*/
      Port_ConfigOutputCurrent(Port_ConfigurationPinsPointer[Pin].PortOutputCurrent,pinBaseAddress,ConfiguredPin);
      /*Get bid address for bit banding */
      volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<ConfiguredPin)));
      /*Set the output value */
      *pinAddress = Port_ConfigurationPinsPointer[Pin].PortPinLevelValue<<ConfiguredPin;             
      
    }
    /* if direction is set to input */
    else if (Direction == PORT_PIN_IN)
    {
      /*Clear direction register to set pin as input*/
      CLEAR_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);
      
    }
    else 
    {
      /*Do nothing */
    }
    
    
  }
}

/* This function refresh the mode of all pins whose mode is not changeable during runtime*/
/******************************************************************************
* \Syntax          : void Port_RefreshPortDirection( void )
* \Description     : This function refreshes port direction for pins whose
*                    direction is unchangeable during runtime
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
void Port_RefreshPortDirection(void)
{
  /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)       
  /* If port is not initialized*/      
  if (Port_InitializeStatus == PORT_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_REFRESH_PORT_DIRECTION_SID, PORT_E_UNINIT);
  }
  else
  {
    /*Do nothing*/
  }
  
  
#endif
  
  
  if (isDetErrorDetected == FALSE) 
  {
    
    for (int i=0;i<PORT_NUMBER_OF_CONFIGURED_PINS;i++)
    {
      /* Get the port address using the mapping array */
      uint32 pinBaseAddress = portAPBbaseAddressArray[Port_ConfigurationPinsPointer[i].PortConfigPortNumber];
      /* Get pin number from configuration pointer */
      Port_PinType ConfiguredPin = Port_ConfigurationPinsPointer[i].PortConfigPinNumber;
      
      
      if (Port_ConfigurationPinsPointer[i].PortPinDirectionChangeable == FALSE)
      {
        if (Port_ConfigurationPinsPointer[i].PortPinDirection == PORT_PIN_OUT)
        {
          /*Set direction to output*/
          SET_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);				
          /*configure output current value*/
          Port_ConfigOutputCurrent(Port_ConfigurationPinsPointer[i].PortOutputCurrent,pinBaseAddress,ConfiguredPin);
          /*Get bid address for bit banding */
          volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<ConfiguredPin)));
          /*Set the output value */
          *pinAddress = Port_ConfigurationPinsPointer[i].PortPinLevelValue<<ConfiguredPin;             
          
        }
        
        else if (Port_ConfigurationPinsPointer[i].PortPinDirection == PORT_PIN_IN)
        {
          /*Clear direction register to set pin as input*/
          CLEAR_BIT(GPIODIR(pinBaseAddress),ConfiguredPin);
          
        }
        else 
        {
          /*Do nothing and return error*/
        }
      }
      else
      {
        /* Do nothing */
      }
    }
  }
  
}

/******************************************************************************
* \Syntax          : void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
* \Description     : This function returns version information of this module
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): versioninfo (pointer to where version info are stored of this module)                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
#if (PORT_VERSION_INFO_API == STD_ON)

void Port_GetVersionInfo( Std_VersionInfoType* versioninfo )
{
  /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
#if (PORT_DEV_ERROR_DETECT == STD_ON)       
  /* If port is not initialized*/      
  if (Port_InitializeStatus == PORT_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_UNINIT);
  }
  else
  {
    /*Do nothing*/
  }
  
  /*if the versioninfo ointer in null pointer*/
  if (versioninfo == NULL_PTR)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  (PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_GET_VERSION_INFO_SID, PORT_E_PARAM_POINTER);
  }
  else
  {
    /* Do nothing */
  }
  
#endif
  
  
  if (isDetErrorDetected == FALSE) 
  {
    /* point the versioninfo to the structure containing driver data*/
    *versioninfo = Port_VersionInfo;
    
  }
}
#elif (PORT_GET_VERSION_INFO_API == STD_OFF)

#else
#error "Wrong mode chosen for PORT_GET_VERSION_INFO_API, please choose either STD_ON or STD_OFF"
#endif 


/******************************************************************************
* \Syntax          : void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
* \Description     : This function sets pin mode of the port pins during runtime
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Reentrant                                             
* \Parameters (in) : Pin (Port Pin ID number)
*                    Mode (New port pin Mode)
* \Parameters (out): None                                                      
* \Return value:   : None
*                                                                      
*******************************************************************************/
/* This functions sets the pinMode of the pin*/
void Port_SetPinMode( Port_PinType Pin, Port_PinModeType Mode )
{
  /* variable to detect det error */
  boolean isDetErrorDetected = FALSE;
  /* Get the port address using the mapping array */
  uint32 pinBaseAddress = portAPBbaseAddressArray[Port_ConfigurationPinsPointer[Pin].PortConfigPortNumber];
  /* Get pin number from configuration pointer */
  Port_PinType ConfiguredPin = Port_ConfigurationPinsPointer[Pin].PortConfigPinNumber;
  
  /* if Det errors are enabled */        
#if (PORT_DEV_ERROR_DETECT == STD_ON)       
  /* If port is not initialized*/      
  if (Port_InitializeStatus == PORT_NOT_INITIALIZED)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_UNINIT);
  }
  else
  {
    /*Do nothing*/
  }
  
  /*if Pin ID is greater than the number of configured pins*/
  if (Pin>= PORT_NUMBER_OF_CONFIGURED_PINS)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_PARAM_PIN);
  }
  else
  {
    /*Do nothing*/
  }
  
  
  /* If pin is not allowed to be configured during runtime*/
  if (Port_ConfigurationPinsPointer[Pin].PortPinModeChangeable == FALSE)
  {
    /*Set det error status to detected*/
    isDetErrorDetected = TRUE;
    /*Report det error*/
    Det_ReportError  ( PORT_MODULE_ID, PORT_INSTANCE_ID, PORT_SET_PIN_MODE_SID, PORT_E_MODE_UNCHANGEABLE);
    
  }
  else
  {
    /*Do nothing*/
  }
  
#endif
  
  
  if (isDetErrorDetected == FALSE) 
  {
    /* call local function to configure the configure the pinMode */
    Port_ConfigurePinMode(Mode,pinBaseAddress,ConfiguredPin);
    
  }
  else
  {
    /* do nothing */
  }
}


/**********************************************************************************************************************
*  LOCAL FUNCTIONS
*********************************************************************************************************************/
/* function to set the output current of output pins */
STATIC void Port_ConfigOutputCurrent(uint8 portOutputCurrent,uint32 regAddress,uint8 offset)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
{
  switch(portOutputCurrent)
  {
    /* In case the pin output current configured to 2mA, configure the corresponding register*/
  case PORT_OCURRENT_2_MA: SET_BIT(GPIODR2R(regAddress),offset);break;
  /* In case the pin output current configured to 4mA, configure the corresponding register*/
  case PORT_OCURRENT_4_MA: SET_BIT(GPIODR4R(regAddress),offset);break;
  /* In case the pin output current configured to 8mA, configure the corresponding register*/
  case PORT_OCURRENT_8_MA: SET_BIT(GPIODR8R(regAddress),offset);break;
  /* In case the pin output current configured to NA Do nothing*/
  case PORT_NA: break;
  default: /*Do nothing*/;
  
  }
}

/* function to configure attached resistors for input pins */
STATIC void Port_ConfigureAttachresistor(uint8 resistorType, uint32 regaddress, uint8 offset)
{
  switch (resistorType)
  {
    /* In case the pin resistor configured to pull down resistor, configure the corresponding register*/
  case PORT_ATTACH_PULL_DOWN_RESISTOR: SET_BIT(GPIOPDR(regaddress),offset);break;
  /* In case the pin resistor configured to pull Up resistor, configure the corresponding register*/
  case PORT_ATTACH_PULL_UP_RESISTOR: SET_BIT(GPIOPUR(regaddress),offset);break;
  /* In case the pin resistor configured to open drain, configure the corresponding register*/
  case PORT_ATTACH_OPEN_DRAIN: SET_BIT(GPIOODR(regaddress),offset);break;
  /* In case the pin resistor  no configuration, Do nothing*/
  case PORT_NA:break;
  default : /*Do nothing*/;
  }			
}

/* function to configure pinMode of the port pin */
STATIC void Port_ConfigurePinMode(uint8 alternatingFun,uint32 regAddress,uint8 offset)
{
  if (alternatingFun == PORT_PINx_ANALOG_FUNC)
  {
    /*Disable Digital Mode*/
    CLEAR_BIT(GPIODEN(regAddress),offset);
    /*Enable alternative mode*/
    SET_BIT(GPIOAMSEL(regAddress),offset);		
  }
  else if(alternatingFun == PORT_PINx_DIO)
  {
    /*Disable Alternative function*/
    CLEAR_BIT(GPIOAFSEL(regAddress),offset);
    /*Enable digital mode*/
    SET_BIT(GPIODEN(regAddress),offset);	
    /*Disable alternative mode*/
    CLEAR_BIT(GPIOAMSEL(regAddress),offset);		
  }
  else if (alternatingFun > PORT_PINx_DIO && alternatingFun <= 15)
  {
    /* Set the Mode to Alternative function*/
    SET_BIT(GPIOAFSEL(regAddress),offset);	
    /*Clear any pin previous mode configuration*/
    GPIOPCTL(regAddress) &=(uint32) 0x0<<(offset*4);
    /*Set the pin Mode to the new configuration*/
    GPIOPCTL(regAddress) |=(uint32) alternatingFun<<(offset*4);		
    /*Enable digital mode*/
    SET_BIT(GPIODEN(regAddress),offset);	
    /*Disable Analog mode*/
    CLEAR_BIT(GPIOAMSEL(regAddress),offset);		
  }
  else
  {
    /*Do nothing and return error*/
  }
}




/**********************************************************************************************************************
*  END OF FILE: Port.c
*********************************************************************************************************************/

