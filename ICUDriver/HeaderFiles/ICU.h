/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef ICU_H
#define ICU_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "ICU_Types.h"

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
ICU_ReturnCodes ICU_ICUReturnCodesInit(void);
ICU_ReturnCodes ICU_ICUReturnCodesClearInterruptFlag(ICU_ChannelType ICU_Channel);
ICU_ReturnCodes ICU_ICUReturnCodesEnableInterrupt(ICU_ChannelType ICU_Channel);
ICU_ReturnCodes ICU_ICUReturnCodesDisableInterrupt(ICU_ChannelType ICU_Channel);
ICU_ActiveType  ICU_ICUReturnCodesIsInterruptActive(ICU_ChannelType ICU_Channel);
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
