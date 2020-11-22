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

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static	uint8 Port_UnlockIfSpecialPin(uint16 pinNum,uint32 baseRegisterAddress,uint8 offset)
{
	switch(pinNum)
	{
		case PORT_PIN0: case PORT_PIN1: case PORT_PIN2: case PORT_PIN3:case PORT_PIN4:
		case PORT_PIN5: case PORT_PIN10:case PORT_PIN11:case PORT_PIN16:case PORT_PIN17:
		case PORT_PIN18:case PORT_PIN19:case PORT_PIN31:case PORT_PIN38:
		GPIOLOCK(baseRegisterAddress) = 0x4C4F434B;break;
		SET_BIT(GPIOCR(baseRegisterAddress),offset);
		default:;//Do nothing
			
		
	}
	return PORT_SUCCESS;
}
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
	
	if (pinsConfigArray[i].portPinDirection == PORT_OUTPUT)
	{
		SET_BIT(GPIODIR(pinBaseAddress),pinOffset);				//set direction to output
		
		switch(pinsConfigArray[i].portOutputCurrent)
		{
			case PORT_OCURRENT_2mA: SET_BIT(GPIODR2R(pinBaseAddress),pinOffset);break;
			case PORT_OCURRENT_4mA: SET_BIT(GPIODR4R(pinBaseAddress),pinOffset);break;
			case PORT_OCURRENT_8mA: SET_BIT(GPIODR8R(pinBaseAddress),pinOffset);break;
			case PORT_NA: break;//Do nothing
			default: return PORT_ERROR;
	
		}
		
		if (pinsConfigArray[i].portPinResistorAttchIfInput == PORT_ATTACH_OPEN_DRAIN)
		{
			SET_BIT(GPIOODR(pinBaseAddress),pinOffset); 		//This is available configuration in case of output
		}
		else if (pinsConfigArray[i].portPinResistorAttchIfInput == PORT_NA)
		{
			//do nothing
		}
		else
		{
			return PORT_ERROR;
		}
	}
	else if (pinsConfigArray[i].portPinDirection == PORT_INPUT)
	{
		CLEAR_BIT(GPIODIR(pinBaseAddress),pinOffset);					//set direction to input
			switch (pinsConfigArray[i].portPinResistorAttchIfInput)
			{
				case PORT_ATTACH_PULL_DOWN_RESISTOR: SET_BIT(GPIOPDR(pinBaseAddress),pinOffset);break;
				case PORT_ATTACH_PULL_UP_RESISTOR: SET_BIT(GPIOPUR(pinBaseAddress),pinOffset);break;
				case PORT_ATTACH_OPEN_DRAIN: SET_BIT(GPIOODR(pinBaseAddress),pinOffset);break;
				default : return PORT_ERROR;
			}			
	}
	else 
	{
		return PORT_ERROR; //Do nthing and return error
	}
	
	/*********************Step 3 configure alternating functions for each pin*********************************************/
	if (pinsConfigArray[i].portPinMode == PORT_PINx_ANALOG_FUNC)
	{
		//ENABLE ANALOG
		CLEAR_BIT(GPIODEN(pinBaseAddress),pinOffset);		//Disable digital mode
		SET_BIT(GPIOAMSEL(pinBaseAddress),pinOffset);		//Enable digital mode
	}
	else if(pinsConfigArray[i].portPinMode == PORT_PINx_DIO)
	{
		
		CLEAR_BIT(GPIOAFSEL(pinBaseAddress),pinOffset);
		SET_BIT(GPIODEN(pinBaseAddress),pinOffset);			//Enable digital mode
		CLEAR_BIT(GPIOAMSEL(pinBaseAddress),pinOffset);		//Disable digital mode
	}
	else if (pinsConfigArray[i].portPinMode > PORT_PINx_DIO && pinsConfigArray[i].portPinMode <= 15)
	{
		SET_BIT(GPIOAFSEL(pinBaseAddress),pinOffset);					
		GPIOPCTL(pinBaseAddress) &=(uint32) 0x0<<(pinOffset*4);						//Clear any previous recording
		GPIOPCTL(pinBaseAddress) |=(uint32) pinsConfigArray[i].portPinMode<<(pinOffset*4);		//configure the pin to the correct mode
		SET_BIT(GPIODEN(pinBaseAddress),pinOffset);				//Enable digital mode
		CLEAR_BIT(GPIOAMSEL(pinBaseAddress),pinOffset);		//Disable digital mode
	}
	else
	{
		return PORT_ERROR;			//Do nothing and return error
	}
	
	
	
	
}



return PORT_SUCCESS;
}





/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
