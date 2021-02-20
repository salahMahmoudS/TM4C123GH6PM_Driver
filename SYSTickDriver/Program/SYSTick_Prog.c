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
#define SYTICK_RELOAD_REGISTER_DEFAULT_VALUE        16000000                //This is the default value put in the timer register and calculations are based on it

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
 
/*Step 1 disable the systick register while doing the configurations */
  CLEAR_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_ENABLE);                      //Turn off the systick control during initialization

#if (SYSTICK_SET_ENABLE == SYSTICK_DISABLE)                             // if it is disabld do nothing and halt program

#elif (SYSTICK_SET_ENABLE == SYSTICK_ENABLE)                            //if enabled 
       
 /*Step 2 set the reload register with the initial value RELOAD_REGISTER_DEFAULT_VALUE */
        
  Systick_SetTimerReg(SYSTICK_TIMER_INITIAL_VALUE);        
            
/*Step 3 choose system clock */
        
        #if (SYSTICK_OSCILLATOR_SRC  == SYSTEM_CLOCK)           //if clock source is the 16Mhz system clock
        SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_CLK_SRC);         //set the clock source to system clock 
        #elif (SYSTICK_CLK_SRC  == PIOSC_DIVIDED_4)             //if clock source is the precision internal oscillator/4   (PIOSC)
        CLEAR_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_CLK_SRC);        //set the clock source to PIOSC
        #else
        #error "Wrong defined mode for Systick clock, please choose between SYSTEM_CLOCK and PIOSC_DIVIDED_4";
        #endif
 
  /*Step 4 Enable or Disable systick interrupts */
        
        #if (SYSTICK_INTERRUPT_ENABLE == SYSTICK_ENABLE)        //if Systick interrupt configuration is enabled
          SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_INTEN); //enable the interrupts in systick control register

         Systick_SystickReturnCodesEnableSystickInterrupt();          //enable the interrupts in systick control register
        
        #elif (SYSTICK_INTERRUPT_ENABLE == SYSTICK_DISABLE)     //if Systick interrupt configuration is disabled
         SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_INTEN); //enable the interrupts in systick control register

         Systick_SystickReturnCodesDisableSystickInterrupt();     //disable the interrupt in systick control resgister
        
        #else
        #error "Wrong defined mode for interrupt enable , please choose between SYSTICK_ENABLE and SYSTICK_DINABLE";    //throw compilation error
        #endif

  /*Step 5 Enable the systick timer to stop counting */
        
        SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_ENABLE);          //Enable the systick timer to work again
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
  SYSTICK_STRELOAD = --Systick_timerRegisterValue;
  SYSTICK_STCURRENT = 0x00;
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
  float32 numberOfSeconds= milliSeconds/1000.0;                              //Transforming the milli seconds to seconds to know number of iteraitons
  uint32 numberOfClockCycles = (uint32)(numberOfSeconds*clockInitialFrequency);
  uint32 numberOfIterations = (uint32) (numberOfClockCycles/16000000);
  uint32 remainingIterationValue = numberOfClockCycles%16000000;
  if (remainingIterationValue>0)
  {
  Systick_SetTimerReg(remainingIterationValue);
  SYSTICK_STRELOAD = SYTICK_RELOAD_REGISTER_DEFAULT_VALUE;
  numberOfIterations++;
  }
  else
  {
    /* Do nothing */
  }
  for (int i=0;i<numberOfIterations;i++)
  {
  while (CHECK_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_COUNT) != SYSTICK_HIGH)
  {
    
  }
  
  }
  return SYSTICK_SUCCESS;
}

SysTick_returnCodes Systick_SystickReturnCodesEnableSystickInterrupt(void)
{
  SET_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_INTEN); //enable the interrupts in systick control register
  return SYSTICK_SUCCESS;
}

SysTick_returnCodes Systick_SystickReturnCodesDisableSystickInterrupt(void)
{
  CLEAR_BIT(SYSTICK_STCTRL,SYSTICK_STCTRL_INTEN); //enable the interrupts in systick control register
  return SYSTICK_SUCCESS;
}





/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
