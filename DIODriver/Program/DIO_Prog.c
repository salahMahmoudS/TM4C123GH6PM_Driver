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
#include "Bit_Math.h"
#include "TM4C123GH6PM_Hw.h"
#include "Det.h"
#include "Dem.h"
#include "MemMap.h"
#include "DIO.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
   uint32 portIndex[] = {DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD,DIO_PORTE,DIO_PORTF};







  
   
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

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
	uint8 DIO_Init(void)
{
  return DIO_SUCCESS;
}

uint8 DIO_WriteChannel(Dio_ChannelType pinNumber, Dio_LevelType pinLevelType)
{
	/* Step 1 validate that the channel is output channel */
		/*
  
  
  */
  
		/* Step 2 write the desired value on the desired channel */
  
		uint32 pinBaseAddress = portIndex[pinNumber/8];
	uint8 pinOffset = pinNumber%8;
	//will be set by bit banding later
		//(*volatile uint32) pinAddressPointer = 
		volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<pinOffset)));    /* Create a pointer to the desired PIN */
		if (pinLevelType == DIO_HIGH)             /* if desired value is high */
		{  
		*pinAddress = STD_HIGH<<pinOffset;      /* Set the desired channel to high */
		}
		else if (pinLevelType == DIO_LOW)       /* else if desired value is low */
		{
		*pinAddress = STD_LOW<<pinOffset;               /* Set the desired channel to low */
		}
		else
		{
		  /* Do nothing*/
		}
		return DIO_SUCCESS;
	   //GPIODATA(pinBaseAddress + 0x3FC)= pinLevelType<<pinOffset;               //Write 1 or 0 on the desired pin in address register
	   /* 
		if (pinLevelType == DIO_LOW)
		{
		  CLEAR_BIT((*pinAddress),pinOffset);
		}
		else if (pinLevelType == DIO_HIGH)
		{
		  SET_BIT((*pinAddress),pinOffset);
		}
		else
		{
		  return DIO_ERROR;
		}

		return DIO_SUCCESS;
		*/
}


Dio_LevelType DIO_ReadChannel(Dio_ChannelType pinNumber)
{
  uint32 pinBaseAddress = portIndex[pinNumber/8];
  uint8 pinOffset = pinNumber%8;
  volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<pinOffset)));
  if (*pinAddress >= DIO_HIGH)
  {
	return DIO_HIGH;
  }
	else if (*pinAddress <= DIO_LOW)
	{
	  return DIO_LOW;
	  
	}
	else 
	{
	  return DIO_ERROR;
	}
}
uint8 DIO_ToggleChannel(Dio_ChannelType pinNumber)
{
 if (DIO_ReadChannel(pinNumber) == DIO_HIGH)
 {
   DIO_WriteChannel(pinNumber,DIO_LOW);
 }
 else if (DIO_ReadChannel(pinNumber) == DIO_LOW)
 {
   DIO_WriteChannel(pinNumber,DIO_HIGH);
 }
 else
 {
   return DIO_ERROR;
 }
 return DIO_SUCCESS;
}
uint8 DIO_WritePort(Dio_PortType portNumber, uint8 portValue)
{
 uint32 portAddress = portNumber;
 
 GPIODATA((portAddress + 0x3FC))= portValue; 
 
 return DIO_SUCCESS;
}
uint8 DIO_ReadPort(Dio_PortType portNumber)
{
 uint32 portAddress = portNumber;

  return GPIODATA((portAddress+0x3FC));
}
 


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
