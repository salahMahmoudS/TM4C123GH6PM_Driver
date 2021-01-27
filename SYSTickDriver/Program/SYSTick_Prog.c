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
uint32 clockInitialFrequency = 16000000;

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

#elif (SYSTICK_SET_ENABLE == SYSTICK_ENABLE)
        Systick_SetTimerReg(SYSTICK_TIMER_INITIAL_VALUE);
        SYSTICK_STCURRENT = 0x00;                               //clearing the STCURRENT register with writing dummy data on it
        #if (SYSTICK_OSCILLATOR_SRC  == SYSTEM_CLOCK)
        SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_CLK_SRC);
        #elif (SYSTICK_CLK_SRC  == PIOSC_DIVIDED_4)
        CLEAR_BIT(SYSTICK_STCTRL,SYSTICK_CLK_SRC);        
        #else
        #error "Wrong defined mode for Systick clock, please choose between SYSTEM_CLOCK and PIOSC_DIVIDED_4";
        #endif
      
        #if (SYSTICK_INTERRUPT_ENABLE == SYSTICK_ENABLE)
        SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_INTEN);
        
        #elif (SYSTICK_INTERRUPT_ENABLE == SYSTICK_DISABLE)
        CLEAR_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_INTEN);
        
        #else
        #error "Wrong defined mode for interrupt enable , please choose between SYSTICK_ENABLE and SYSTICK_DINABLE";
        #endif

        SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_ENABLE);
#else
#error "Wrong defined mode for Systick set enable, please choose between SYSTICK_ENABLE and SYSTICK_DINABLE";   
#endif
return SYSTICK_SUCCESS;
  


}
SysTick_returnCodes Systick_SetTimerMS(uint32 timerValue)			//set timer in milli seconds value
{
  clockInitialFrequency = clockInitialFrequency/1000;
  uint32 STRELOADValue = timerValue*clockInitialFrequency;
  SYSTICK_STRELOAD = STRELOADValue-1;
  return SYSTICK_SUCCESS;
}
SysTick_returnCodes Systick_SetTimerReg(uint32 Systick_timerRegisterValue)			//set timer in hexavalue timer
{
  SYSTICK_STRELOAD = Systick_timerRegisterValue-1;
  return SYSTICK_SUCCESS;
}
uint32 Systick_GetTimerValue(void)									//get_timer value
{
return SYSTICK_STCURRENT;
}
SysTick_returnCodes Systick_IsTimerFinished(void)					//checks if timer finished 
{
if (CHECK_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_COUNT) == SYSTICK_HIGH)
return SYSTICK_TIMER_FINISH;

else
{
  return SYSTICK_TIMER_NOT_FINISH;
}
}
SysTick_returnCodes Systick_delayMS(uint32 milliSeconds)			//makes a delay by desired milliseconds
{
 // uint16 numberOfClockCycles = 32;         //Hard coded value corresponds to total execution clock cycles in the below loop
  clockInitialFrequency= clockInitialFrequency/1000;
  uint32 numberOfClockCycles = milliSeconds*clockInitialFrequency;
  uint32 numberOfIterations = (uint32)numberOfClockCycles/0x00FFFFFF;
  uint32 remainingIterations = numberOfClockCycles%16777215;
  if (remainingIterations>0)
  {
  Systick_SetTimerReg(remainingIterations);
  numberOfIterations++;
  }
  for (int i=0;i<numberOfIterations;i++)
  {
  while (CHECK_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_COUNT) != SYSTICK_HIGH)
  {
    
  }
  
  }
  return SYSTICK_SUCCESS;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
