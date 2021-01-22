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
#include "DIO_Types.h"
#include "DIO_Cfg.h"
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
uint8 DIO_uint8WriteChannel(Dio_ChannelType pinNumber, Dio_LevelType pinLevelType)
{
	uint32 pinBaseAddress = portIndex[pinNumber/8];
	uint8 pinOffset = pinNumber%8;
	//will be set by bit banding later
        //(*volatile uint32) pinAddressPointer = 
        volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x3FC)));
       //GPIODATA(pinBaseAddress + 0x3FC)= pinLevelType<<pinOffset;               //Write 1 or 0 on the desired pin in address register
        
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
}


Dio_LevelType DIO_uint8ReadChannel(Dio_ChannelType pinNumber)
{
  uint32 pinBaseAddress = portIndex[pinNumber/8];
  uint8 pinOffset = pinNumber%8;
  if ((CHECK_BIT(GPIODATA(pinBaseAddress+0x3FC),pinOffset)) == DIO_HIGH)
  {
    return DIO_HIGH;
  }
    else if ((CHECK_BIT(GPIODATA(pinBaseAddress+0x3FC),pinOffset)) == DIO_LOW)
    {
      return DIO_LOW;
      
    }
    else 
    {
      return DIO_ERROR;
    }
}
uint8 DIO_uint8ToggleChannel(Dio_ChannelType pinNumber)
{
 if (DIO_uint8ReadChannel(pinNumber) == DIO_HIGH)
 {
   DIO_uint8WriteChannel(pinNumber,DIO_LOW);
 }
 else if (DIO_uint8ReadChannel(pinNumber) == DIO_LOW)
 {
   DIO_uint8WriteChannel(pinNumber,DIO_HIGH);
 }
 else
 {
   return DIO_ERROR;
 }
 return DIO_SUCCESS;
}
uint8 DIO_uint8WritePort(Dio_PortType portNumber, uint8 portValue)
{
 uint32 portAddress = portNumber;
 
 GPIODATA((portAddress + 0x3FC))= portValue; 
 
 return DIO_SUCCESS;
}
uint8 DIO_uint8ReadPort(Dio_PortType portNumber)
{
 uint32 portAddress = portNumber;

  return GPIODATA((portAddress+0x3FC));
}
 


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
