/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *
 * 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Bit_Math.h"
#include "TM4C123GH6PM_Hw.h"
#include "Port_Cfg.h"
#include "Port_Types.h"
#include "Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint32 portAHBbaseAddressArray[] = {GPIO_Port_A_AHB_BASE_ADDRESS,GPIO_Port_B_AHB_BASE_ADDRESS,GPIO_Port_C_AHB_BASE_ADDRESS,
																					 GPIO_Port_D_AHB_BASE_ADDRESS,GPIO_Port_E_AHB_BASE_ADDRESS,GPIO_Port_F_AHB_BASE_ADDRESS};
			
	
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern portPinsConfig pinsConfigArray[];

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static	uint8 Port_UnlockIfSpecialPin(uint16 pinNum,uint32 baseRegisterAddress,uint8 offset);
static uint8 Port_ConfigOutputCurrent(uint8 portOutputCurrent,uint32 pinAddress,uint8 offset);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
static uint8 Port_ConfigureAttachresistor(uint8 resistorType, uint32 regaddress, uint8 offset);
static uint8 Port_ConfigureAlternatingFunction(uint8 alternatingFun,uint32 regAddress,uint8 offset);


/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

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
uint8 Port_Init(void)
{
	
/*********** Clock enable for ports********************/
	
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




/*********************Step 2 set direction of registers*********************************************/

for (int i=0;i<NUNBER_OF_CONFIGURED_PINS;i++)
{
	uint32 pinBaseAddress = portAHBbaseAddressArray[pinsConfigArray[i].portPinNumber/8];
	uint8 pinOffset = pinsConfigArray[i].portPinNumber%8;
	
	Port_UnlockIfSpecialPin(pinsConfigArray[i].portPinNumber,pinBaseAddress,pinOffset);
	Port_ConfigureAlternatingFunction(pinsConfigArray[i].portPinMode,pinBaseAddress,pinOffset);
	Port_ConfigureAttachresistor(pinsConfigArray[i].portPinResistorAttchIfInput, pinBaseAddress, pinOffset);

	if (pinsConfigArray[i].portPinDirection == PORT_OUTPUT)
	{
		
		SET_BIT(GPIODIR(pinBaseAddress),pinOffset);				//set direction to output
		Port_ConfigOutputCurrent(pinsConfigArray[i].portOutputCurrent,pinBaseAddress,pinOffset);
		//GPIODATA(pinBaseAddress + (0x0008))= 0xff;
		GPIODATA(pinBaseAddress + 0x3FC)|=(uint32) 0x1<<pinOffset;	
		
	}
	
	else if (pinsConfigArray[i].portPinDirection == PORT_INPUT)
	{
		CLEAR_BIT(GPIODIR(pinBaseAddress),pinOffset);					//set direction to input
		Port_ConfigOutputCurrent(PORT_NA,pinBaseAddress,pinOffset);
	}
	else 
	{
		return PORT_ERROR; //Do nthing and return error
	}
	
	/*********************Step 3 configure alternating functions for each pin*********************************************/
	//Port_ConfigureAlternatingFunction(pinsConfigArray[i].portPinMode,pinBaseAddress,pinOffset);
	
}

return PORT_SUCCESS;
}


static uint8 Port_ConfigOutputCurrent(uint8 portOutputCurrent,uint32 regAddress,uint8 offset)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
		{
		switch(portOutputCurrent)
		{
			case PORT_OCURRENT_2mA: SET_BIT(GPIODR2R(regAddress),offset);break;
			case PORT_OCURRENT_4mA: SET_BIT(GPIODR4R(regAddress),offset);break;
			case PORT_OCURRENT_8mA: SET_BIT(GPIODR8R(regAddress),offset);break;
			case PORT_NA: break;//Do nothing
			default: return PORT_ERROR;
	
		}
		return PORT_SUCCESS;
	}

	static uint8 Port_ConfigureAttachresistor(uint8 resistorType, uint32 regaddress, uint8 offset)
	{
	switch (resistorType)
			{
				case PORT_ATTACH_PULL_DOWN_RESISTOR: SET_BIT(GPIOPDR(regaddress),offset);break;
				case PORT_ATTACH_PULL_UP_RESISTOR: SET_BIT(GPIOPUR(regaddress),offset);break;
				case PORT_ATTACH_OPEN_DRAIN: SET_BIT(GPIOODR(regaddress),offset);break;
				case PORT_NA:break;
				default : return PORT_ERROR;
			}			
			return PORT_SUCCESS;
	}
	
	static uint8 Port_ConfigureAlternatingFunction(uint8 alternatingFun,uint32 regAddress,uint8 offset)
	{
		if (alternatingFun == PORT_PINx_ANALOG_FUNC)
	{
		//ENABLE ANALOG
		CLEAR_BIT(GPIODEN(regAddress),offset);		//Disable digital mode
		SET_BIT(GPIOAMSEL(regAddress),offset);		//Enable alternative mode
	}
	else if(alternatingFun == PORT_PINx_DIO)
	{
		
		CLEAR_BIT(GPIOAFSEL(regAddress),offset);
		SET_BIT(GPIODEN(regAddress),offset);			//Enable digital mode
		CLEAR_BIT(GPIOAMSEL(regAddress),offset);		//Disable alternative mode
	}
	else if (alternatingFun > PORT_PINx_DIO && alternatingFun <= 15)
	{
		SET_BIT(GPIOAFSEL(regAddress),offset);					
		GPIOPCTL(regAddress) &=(uint32) 0x0<<(offset*4);						//Clear any previous recording
		GPIOPCTL(regAddress) |=(uint32) alternatingFun<<(offset*4);		//configure the pin to the correct mode
		SET_BIT(GPIODEN(regAddress),offset);				//Enable digital mode
		CLEAR_BIT(GPIOAMSEL(regAddress),offset);		//Disable alternative mode
	}
	else
	{
		return PORT_ERROR;			//Do nothing and return error
	}
	return PORT_SUCCESS;
	}
	
	
	static	uint8 Port_UnlockIfSpecialPin(uint16 pinNum,uint32 baseRegisterAddress,uint8 offset)
{
	switch(pinNum)
	{
		case PORT_PINA0: case PORT_PINA1: case PORT_PINA2: case PORT_PINA3:case PORT_PINA4:
		case PORT_PINA5: case PORT_PINB2:case PORT_PINB3:case PORT_PINC0:case PORT_PINC1:
		case PORT_PINC2:case PORT_PINC3:case PORT_PIND7:case PORT_PINF0:
		GPIOLOCK(baseRegisterAddress) = 0x4C4F434B;break;
		SET_BIT(GPIOCR(baseRegisterAddress),offset);
		default:;//Do nothing
			
		
	}
	return PORT_SUCCESS;
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
