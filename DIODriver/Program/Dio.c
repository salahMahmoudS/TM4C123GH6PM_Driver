/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
   
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *		\Author: Salah Mahmoud
 *
 *********************************************************************************************************************/ 
  
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/ 
#include "Bit_Math.h"
#include "TM4C123GH6PM_Hw.h"
#include "Det.h"
#include "Dem.h"
#include "MemMap.h"
#include "DIO.h"
  
/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS 
*********************************************************************************************************************/ 
  
 
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/ 
  
  /* This array contains all base addresses for PORT driver (advanced peripheral bus) */ 
  uint32 portAddressMapper[] =
{
GPIO_Port_A_APB_BASE_ADDRESS, 
GPIO_Port_B_APB_BASE_ADDRESS,
    
GPIO_Port_C_APB_BASE_ADDRESS, 
GPIO_Port_D_APB_BASE_ADDRESS,
    
GPIO_Port_E_APB_BASE_ADDRESS, 
GPIO_Port_F_APB_BASE_ADDRESS 
};

 
 
 
 
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/ 
  
/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/ 
  
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/ 
static const Dio_ChannelConfigType *Dio_ConfigurationChannelsPointer = NULL_PTR;

uint8 Dio_InitializeStatus = DIO_NOT_INITIALIZED;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/ 
  
 
/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)        
* \Description     : Describe this service                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : parameterName   Parameter Describtion                     
* \Parameters (out): None                                                      
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK                                  
*******************************************************************************/ 
  void
Dio_Init (const Dio_ConfigType * ConfigPtr) 
{
  
/*if DET errors are enabled*/ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
    
/*if configuration pointer is null during initialize*/ 
    if (ConfigPtr == NULL_PTR)
    
    {
      
	/* Report det error */ 
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_INIT_SID,
			 DIO_E_PARAM_CONFIG);
    
 
}
  
 
  else				/*else initialize the DIO driver with the provided pointer */
    
#endif	
    {
      
Dio_InitializeStatus = DIO_INITIALIZED;	/*Dio status is initialized */
      
Dio_ConfigurationChannelsPointer = ConfigPtr->ConfiguredChannelsArray;
    
}

}


 
void Dio_WriteChannel (Dio_ChannelType ChannelId, Dio_LevelType pinLevelType) 
{
       uint8 isDetErrorDetected = FALSE;

    /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)

    /*if DIO module is not initialized */ 
    if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
    {
      
	/*report det error */ 
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID, DIO_E_UNINIT);
    
 
}
  
 
    else
    {
      /*Do nothing */
    }
    
    if (ChannelId >= DIO_NUMBER_OF_CONFIGURED_CHANNELS)
    {
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    
    }
      
    
 #endif
 
    if (isDetErrorDetected == FALSE)

    {
	
	
	/* Write the desired value on the desired channel */ 
	/* a) get the port from the configuratoin ptr */ 
	uint32 pinBaseAddress =
	portAddressMapper[Dio_ConfigurationChannelsPointer[ChannelId].
			  postBuildPortID];
      
 
	/* b) get the channel offset in port */ 
	uint8 pinOffset =
	Dio_ConfigurationChannelsPointer[ChannelId].postBuildChannelID;
      
 
	/* c) get the channel address using bitbanding */ 
      volatile uint32 *pinAddress =
	&(GPIODATA (pinBaseAddress + (0x04 << pinOffset)));
      
 
 
if (pinLevelType == STD_HIGH)	/* if desired value is high */
	
	{
	  
*pinAddress = STD_HIGH << pinOffset;	/* Set the desired channel to high */
	
}
      
      else if (pinLevelType == STD_LOW)	/* else if desired value is low */
	
	{
	  
*pinAddress = STD_LOW << pinOffset;	/* Set the desired channel to low */
	
}
      
      else
	
	{
	  
	    /* Do nothing */ 
	}
    
    }
    else
    {
      /* Do nothing */ 
    }

}


 
 
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId) 
{
   uint8 isDetErrorDetected = FALSE;
   uint8 pinState;		/*This variable will contain the channel state */


    /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
     /*if DET errors are enabled*/ 
  
    /*if DIO module is not initialized */ 
    if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
    {
      
	/*report det error */ 
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID, DIO_E_UNINIT);
    
 
}
  
 
    else
    {
      /*Do nothing */
    }
    
    if (ChannelId >= DIO_NUMBER_OF_CONFIGURED_CHANNELS)
    {
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    
    }
      
          #endif

    if (isDetErrorDetected == FALSE)

    {
  
  
    /* Step 1 validate that the channel is output channel */ 
    /*
       
       
     */ 
    
    /* Step 2 Read the desired value from the desired channel */ 
    /* a) get the port from the configuratoin ptr */ 
    uint32 pinBaseAddress =
    portAddressMapper[Dio_ConfigurationChannelsPointer[ChannelId].
		      postBuildPortID];
  
 
    /* b) get the channel offset in the port */ 
    uint8 pinOffset =
    Dio_ConfigurationChannelsPointer[ChannelId].postBuildChannelID;
  
 
    /*Get the pin address using bitbanding */ 
  volatile uint32 *pinAddress =
    &(GPIODATA (pinBaseAddress + (0x04 << pinOffset)));
  
 
    /* if the channel state is HIGH, return HIGH */ 
    if (*pinAddress >= STD_HIGH)
    
    {
      
pinState = STD_HIGH;
    
}
  
    /* if the channel state is LOW, return LOW */ 
    else if (*pinAddress <= STD_LOW)
    
    {
      
pinState = STD_LOW;
    
 
}
  
  else
    
    {
      
 
	/* Do nothing */ 
    }
    
    }
    return pinState;

}


 
#if (DIO_FLIP_CHANNEL_API == STD_ON)
 
Dio_LevelType Dio_FlipChannel (Dio_ChannelType ChannelId) 
{
  
 uint8 isDetErrorDetected = FALSE;
   uint8 pinState;		/*This variable will contain the channel state */


    /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
     /*if DET errors are enabled*/ 
  
    /*if DIO module is not initialized */ 
    if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
    {
      
	/*report det error */ 
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID, DIO_E_UNINIT);
    
 
}
  
 
    else
    {
      /*Do nothing */
    }
    
    if (ChannelId >= DIO_NUMBER_OF_CONFIGURED_CHANNELS)
    {
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_FLIP_CHANNEL_SID, DIO_E_PARAM_INVALID_CHANNEL_ID);
    
    }
      
          #endif

    if (isDetErrorDetected == FALSE)

    {
    
 
    /*if channel state is HIGH, Flip channel by writing LOW */ 
    if (Dio_ReadChannel (ChannelId) == STD_HIGH)
    
    {
      
Dio_WriteChannel (ChannelId, STD_LOW);
      
pinState = STD_LOW;	/*set the channel state to LOW */
    
}
  
    /*else if channel state is LOW, Flip channel by writing HIGH */ 
    else if (Dio_ReadChannel (ChannelId) == STD_LOW)
    
    {
      
Dio_WriteChannel (ChannelId, STD_HIGH);
      
pinState = STD_HIGH;	/*set the channel state to HIGH */
    
}
  
  else
    
    {
      
	/* Do nothing */ 
    }
    }
return pinState;

}

#else
/* Do nothing */
#endif
 
 
void
Dio_WritePort (Dio_PortType PortId, Dio_PortLevelType Level) 
{
   uint8 isDetErrorDetected = FALSE;

    /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
     /*if DET errors are enabled*/ 
  
    /*if DIO module is not initialized */ 
    if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
    {
      
	/*report det error */ 
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_PORT_SID, DIO_E_UNINIT);
    
 
}
  
 
    else
    {
      /*Do nothing */
    }
    
    if (PortId >= NUMBER_OF_PORTS)
    {
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_WRITE_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    
    }
      
          #endif

    if (isDetErrorDetected == FALSE)

    {
  
  
    /*get the desired port address */ 
    uint32 portAddress = portAddressMapper[PortId];
  
 
    /*write the desired level value on the port using bitbanding */ 
    GPIODATA ((portAddress + 0x3FC)) = Level;

    }
} 
 
 
Dio_PortLevelType Dio_ReadPort (Dio_PortType PortId) 
{
  uint8 isDetErrorDetected = FALSE;
  uint8 portValue;
    /*if DET errors are enabled */ 
#if (DIO_DEV_ERROR_DETECT == STD_ON)
     /*if DET errors are enabled*/ 
  
    /*if DIO module is not initialized */ 
    if (Dio_InitializeStatus == DIO_NOT_INITIALIZED)
    
    {
      
	/*report det error */ 
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_PORT_SID, DIO_E_UNINIT);
    
 
}
  
 
    else
    {
      /*Do nothing */
    }
    
    if (PortId >= NUMBER_OF_PORTS)
    {
      isDetErrorDetected = TRUE;
	Det_ReportError (DIO_MODULE_ID, DIO_INSTANCE_ID,DIO_READ_PORT_SID, DIO_E_PARAM_INVALID_PORT_ID);
    
    }
      
          #endif

    if (isDetErrorDetected == FALSE)

    {
uint32 portAddress = portAddressMapper[PortId];	/* Get the physical address of the desired port */
  
 
portValue = GPIODATA ((portAddress + 0x3FC));	/* Read the desired port and return result using bitbanding */
    }
    return portValue;
}


 
 
 
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/ 
