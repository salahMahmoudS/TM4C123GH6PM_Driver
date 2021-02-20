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
   uint32 portAddressMapper[] =  {GPIO_Port_A_APB_BASE_ADDRESS,
                                  GPIO_Port_B_APB_BASE_ADDRESS,
                                  GPIO_Port_C_APB_BASE_ADDRESS,
                                  GPIO_Port_D_APB_BASE_ADDRESS,
                                  GPIO_Port_E_APB_BASE_ADDRESS,
                                  GPIO_Port_F_APB_BASE_ADDRESS
                                  };                    /*This array contains the physical addresses of each port in the MCU */


  
   
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
	void Dio_Init(void)
{
  
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType pinLevelType)
{
	/* Step 1 validate that the channel is output channel */
		/*
  
  
  */
  
		/* Step 2 write the desired value on the desired channel */
                uint32 pinBaseAddress = portAddressMapper[ChannelId/8];
                uint8 pinOffset = ChannelId%8;	
		//(*volatile uint32) pinAddressPointer = 
		volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<pinOffset)));    /* Create a pointer to the desired PIN using bitbanding */
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


Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
  uint32 pinBaseAddress = portAddressMapper[ChannelId/8];
  uint8 pinOffset = ChannelId%8;
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
          /* TODO implement return Deterror  */
          return DIO_ERROR;
	}
}
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
 if (Dio_ReadChannel(ChannelId) == DIO_HIGH)
 {
   Dio_WriteChannel(ChannelId,DIO_LOW);
   return DIO_LOW;
 }
 else if (Dio_ReadChannel(ChannelId) == DIO_LOW)
 {
   Dio_WriteChannel(ChannelId,DIO_HIGH);
   return DIO_HIGH;
 }
 else
 {
   return DIO_ERROR;
 }
 
}
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{
 uint32 portAddress = PortId;
 
 GPIODATA((portAddress + 0x3FC))= Level; 
 
}


Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{
 uint32 portAddress = portAddressMapper[PortId];        /* Get the physical address of the desired port */

  return GPIODATA((portAddress+0x3FC));                /* Read the desired port and return result */
}
 


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
