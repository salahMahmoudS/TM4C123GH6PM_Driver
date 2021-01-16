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
#include "Port_Types.h"
#include "Port.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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
portPinsConfig pinsConfigArray[] =
{
	//define your configuration files in the below order 
	//{portPinNumber,portPinMode,portPinDirection,portInitialValueIfOutput,portOutputCurrent,portPinResistorAttchIfInput}
	{PORT_PINF0,PORT_PF0_DIO,PORT_INPUT,PORT_NA,PORT_NA,PORT_ATTACH_PULL_UP_RESISTOR},
	{PORT_PINF1,PORT_PF1_DIO,PORT_OUTPUT,PORT_HIGH,PORT_OCURRENT_2mA, PORT_NA},
	{PORT_PINF4,PORT_PF4_DIO,PORT_INPUT,PORT_NA,PORT_NA,PORT_ATTACH_PULL_UP_RESISTOR},
	{PORT_PINF2,PORT_PF2_DIO,PORT_OUTPUT,PORT_LOW,PORT_OCURRENT_2mA,PORT_NA}
	
};

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
