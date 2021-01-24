/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef SYSTICK_H
#define SYSTICK_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "SysTick_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 
*********************************************************************************************************************/
SysTick_returnCodes Systick_Init(void);								//set timer value
SysTick_returnCodes Systick_SetTimerMS(uint32 timerValue);			//set timer in milli seconds value
SysTick_returnCodes Systick_SetTimerHexa(uint32 timerValue);			//set timer in hexavalue timer
uint32 Systick_GetTimerValue(void);									//get_timer value
SysTick_returnCodes Systick_IsTimerFinished(void);					//checks if timer finished 
SysTick_returnCodes Systick_delayMS(uint32 milliSeconds);			//makes a delay by desired milliseconds
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
