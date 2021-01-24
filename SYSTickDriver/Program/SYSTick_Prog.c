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
#include "SysTick_Types.h"
#include "SysTick_cfg.h"
#include "SysTick.h"
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
SysTick_returnCodes Systick_Init(void)								//set timer value
{
 

  CLEAR_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_ENABLE);

#if (SYSTICK_SET_ENABLE == SYSTICK_DISABLE)

#elif(SYSTICK_SET_ENABLE == SYSTICK_ENABLE)
        Systick_SetTimerHexa(SYSTICK_TIMER_INITIAL_VALUE);
        SYSTICK_STCURRENT = 0x11;                               //clearing the STCURRENT register with writing dummy data on it
        #if(SYSTICK_CLK_SRC  == SYSTEM_CLOCK)
        SET_BIT(SYSTICK_STCTRL,SYSTICK_CLK_SRC);
        #elif(SYSTICK_CLK_SRC  == PIOSC_DIVIDED_4)
        CLEAR_BIT(SYSTICK_STCTRL,SYSTICK_CLK_SRC);        
        #else
        #error "Wrong defined mode for Systick clock, please choose between SYSTEM_CLOCK and PIOSC_DIVIDED_4";
        #endif
      
        #if (SYSTICK_INTERRUPT_ENABLE == SYSTICK_ENABLE)
        SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_INTEN);
        
        #elif(SYSTICK_INTERRUPT_ENABLE == SYSTICK_DISABLE)
        CLEAR_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_INTEN);
        
        #else
        #error "Wrong defined mode for interrupt enable , please choose between SYSTICK_ENABLE and SYSTICK_DINABLE";
        #endif

#else
#error "Wrong defined mode for Systick set enable, please choose between SYSTICK_ENABLE and SYSTICK_DINABLE";   
#endif
return SYSTICK_SUCCESS;
  


}
SysTick_returnCodes Systick_SetTimerMS(uint32 timerValue);			//set timer in milli seconds value
SysTick_returnCodes Systick_SetTimerHexa(uint32 timerValue);			//set timer in hexavalue timer
uint32 Systick_GetTimerValue(void);									//get_timer value
SysTick_returnCodes Systick_IsTimerFinished(void);					//checks if timer finished 
SysTick_returnCodes Systick_delayMS(uint32 milliSeconds);			//makes a delay by desired milliseconds

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
