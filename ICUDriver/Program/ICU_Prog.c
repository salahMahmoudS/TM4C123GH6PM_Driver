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
#include "ICU_Types.h"
#include "ICU_Config.h"
#include "ICU.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static uint32 ICUAPBbaseAddressArray[] = {GPIO_Port_A_APB_BASE_ADDRESS,GPIO_Port_B_APB_BASE_ADDRESS,GPIO_Port_C_APB_BASE_ADDRESS,
                                              GPIO_Port_D_APB_BASE_ADDRESS,GPIO_Port_E_APB_BASE_ADDRESS,GPIO_Port_F_APB_BASE_ADDRESS};

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
extern ICU_channelsConfiguration ICUChannelsConfigurationArray[];
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
ICU_ReturnCodes ICU_ICUReturnCodesInit(void)
{
  
  /*
        icuChannel;	
interruptMaskConfig;
interruptSenseConfig;
interruptEdgeconfig;*/

for (int i=0;i<ICU_NUMBER_OF_CONFIGURED_CHANNELS;i++)
{
	uint32 pinBaseAddress = ICUAPBbaseAddressArray[ICUChannelsConfigurationArray[i].icuChannel/8];
	uint8 pinOffset = ICUChannelsConfigurationArray[i].icuChannel%8;
        /* Step 1 disable the interrupt to start configuration */
        CLEAR_BIT(ICU_GPIOIM_REGISTER(pinBaseAddress),pinOffset); 
        
        /* Step 2 configure the interrupt sense of the channel to be level or edge triggered */
         if (ICUChannelsConfigurationArray[i].interruptSenseConfig == ICU_INTERRUPT_DETECT_EDGES_CONFIG)
        {
         CLEAR_BIT(ICU_GPIOIS_REGISTER(pinBaseAddress),pinOffset);
                
             if (ICUChannelsConfigurationArray[i].interruptEdgeconfig == ICU_INTERRUPT_BOTH_EDGES_CONFIG)
                {
                SET_BIT(ICU_GPIOIBE_REGISTER(pinBaseAddress),pinOffset);
                }
                else if (ICUChannelsConfigurationArray[i].interruptEdgeconfig ==ICU_INTERRUPT_RISING_EDGE_CONFIG)
                {
                SET_BIT(ICU_GPIOIEV_REGISTER(pinBaseAddress),pinOffset);
                }
                else if (ICUChannelsConfigurationArray[i].interruptEdgeconfig ==ICU_INTERRUPT_FALLING_EDGE_CONFIG)
                {
                CLEAR_BIT(ICU_GPIOIEV_REGISTER(pinBaseAddress),pinOffset);
                }
                else
                {
                  return ICU_ERROR;
                }
         
        }
        else if (ICUChannelsConfigurationArray[i].interruptSenseConfig ==ICU_INTERUPT_DETECT_LEVELS_CONFIG)
        {
         SET_BIT(ICU_GPIOIS_REGISTER(pinBaseAddress),pinOffset);
        }
        else
        {
          return ICU_ERROR;
        }

        /* Step 3 configure the interrupt mode of the channel to be rising edge, or falling edge or both edges  */

        
        if (ICUChannelsConfigurationArray[i].interruptMaskConfig == ICU_INTERRUPT_DISABLE)
        {
         CLEAR_BIT(ICU_GPIOIM_REGISTER(pinBaseAddress),pinOffset);
        }
        else if (ICUChannelsConfigurationArray[i].interruptMaskConfig == ICU_INTERRUPT_ENABLE)
        {
         SET_BIT(ICU_GPIOIM_REGISTER(pinBaseAddress),pinOffset);
        }
        else
        {
          return ICU_ERROR;
        }

        SET_BIT(ICU_GPIOICR_REGISTER(pinBaseAddress),pinOffset);               /* clear the interrupt if it was preset */

}


return ICU_SUCCESS;	
}

ICU_ActiveType ICU_ICUActiveTypeIsActiveInterrupt(ICU_ChannelType icuChannel)
{
  uint32 pinBaseAddress = ICUAPBbaseAddressArray[icuChannel/8];
	uint8 pinOffset = icuChannel%8;
        
  if (CHECK_BIT(ICU_GPIORIS_REGISTER(pinBaseAddress),pinOffset) == ICU_HIGH)
  {
    return ICU_IS_ACTIVE_INTEERUPT;
  }
  else if (CHECK_BIT(ICU_GPIORIS_REGISTER(pinBaseAddress),pinOffset) == ICU_LOW)
  {
    return ICU_NOT_ACTIVE_INTERRUPT;
  }
  else 
  {
   
  }
   return ICU_ERROR;
}

ICU_ReturnCodes ICU_ICUReturnCodesClearInterruptFlag(ICU_ChannelType ICU_Channel)
{
  uint32 pinBaseAddress = ICUAPBbaseAddressArray[ICU_Channel/8];
  uint8 pinOffset = ICU_Channel%8;
  
  SET_BIT(ICU_GPIOICR_REGISTER(pinBaseAddress),pinOffset);
  return ICU_SUCCESS;
}

ICU_ActiveType ICU_ICUReturnCodesIsInterruptActive(ICU_ChannelType ICU_Channel)
{
  uint32 pinBaseAddress = ICUAPBbaseAddressArray[ICU_Channel/8];
  uint8 pinOffset = ICU_Channel%8;
  if (CHECK_BIT(ICU_GPIORIS_REGISTER(pinBaseAddress),pinOffset) == ICU_HIGH)
  {
    return ICU_IS_ACTIVE_INTEERUPT;
  }
      else if (CHECK_BIT(ICU_GPIORIS_REGISTER(pinBaseAddress),pinOffset) == ICU_LOW)
      {
        return ICU_NOT_ACTIVE_INTERRUPT;
      }
                else
                {
                  return ICU_ERROR;
                }
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
