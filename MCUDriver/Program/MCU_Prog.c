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
#include "MCU_Types.h"
#include "MCU_Config.h"
#include "MCU.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
static MCU_ReturnCodes MCU_PLLInit(void);
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/


f32 MCU_clkFrequenciesAllowedValues[] = {                                         
                                              2,
                                              4,
                                              8,
                                              16,
                                              21.05  ,                                             
                                              22.222 , 
                                              23.529 ,
                                              25     ,
                                              26.667 ,
                                              28.571 ,
                                              30.769 ,
                                              32     ,
                                              33.333 ,
                                              36.363 ,
                                              40     ,
                                              44.444 ,
                                              50     ,
                                              57.142 ,
                                              64     ,
                                              66.667 ,
                                              80     ,
                                              100    ,
                                              128    ,
                                              133.333,
                                              200    ,
                                              264    ,
                                              400    
                                                    };
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static MCU_ReturnCodes MCU_setOscillatorSource(MCU_OscillatorInternalScource oscillatorSource);
static MCU_ReturnCodes MCU_PLLInit(void);
static MCU_ReturnCodes MCU_SetPLLClockFrequency(void);
static MCU_ReturnCodes MCU_SetCrystalFrequency(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static MCU_ReturnCodes MCU_setOscillatorSource(MCU_OscillatorInternalScource oscillatorSource)
{
  switch(oscillatorSource)
  {
  case MCU_CLK_SRC_MOSC: MCU_RCC2_REGISTER |= MCU_CLK_SRC_MOSC<<4;break;
  case MCU_CLK_SRC_PIOSC:MCU_RCC2_REGISTER |= MCU_CLK_SRC_PIOSC<<4;break;               
  case MCU_CLK_SRC_PIOSC_DIV_4:MCU_RCC2_REGISTER |= MCU_CLK_SRC_PIOSC_DIV_4<<4;break;            
  case MCU_CLK_SRC_LOW_FREQ_INTERNAL_OSCILLATOR:MCU_RCC2_REGISTER |= MCU_CLK_SRC_LOW_FREQ_INTERNAL_OSCILLATOR<<4;break;
  case MCU_CLK_SRC_32_768KHz_EXTERNAL_OSCILLATOR:MCU_RCC2_REGISTER |= MCU_CLK_SRC_32_768KHz_EXTERNAL_OSCILLATOR<<4;break;
  default: return MCU_ERROR;
                                
  }
  return MCU_SUCCESS;
}

MCU_ReturnCodes MCU_SetCrystalFrequency()
{
  
  #if (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_4_MHz)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_4_MHz<<6;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_4_096_MHz)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_4_096_MHz<<6;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION ==MCU_XTAL_FREQUENCY_CONFIG_4_9152_MHz)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_4_9152_MHz<<6; 

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_5_MHz      )
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_5_MHz<<6;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_5_12_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_5_12_MHz<<6 	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_6_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_6_MHz<<6 	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_6_144_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_6_144_MHz<<6 ;	

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_7_327_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_7_327_MHz<<6 ;	

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_8_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_8_MHz<<6	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_8_192_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_8_192_MHz<<6 ;	

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_10_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_10_MHz<<6	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_12_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_12_MHz<<6 	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_12_288_MHz )
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_12_288_MHz<<6  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_13_56_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_13_56_MHz<<6 ;	

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_14_318_MHz )
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_14_318_MHz<<6  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_16_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_16_MHz<<6 	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_16_384_MHz	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_16_384_MHz<<6;	

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_18_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_18_MHz<<6 	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_20_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_20_MHz<<6 	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_24_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_24_MHz<<6 	  ;

#elif (MCU_XTAL_FREQUENCY_CONFIGURATION == MCU_XTAL_FREQUENCY_CONFIG_25_MHz 	)
MCU_RCC_REGISTER |= MCU_XTAL_FREQUENCY_CONFIG_25_MHz<<6 	  ;      

#else

#error "Wrong Oscillator, please select oscillator from the allowed values in the MCU.h file"

#endif

return MCU_SUCCESS;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
}




MCU_ReturnCodes MCU_SetPLLClockFrequency(void)
{
/*  
 #if   (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_2MHZ         )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_4MHZ         )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_8MHZ         )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_16MHZ        )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_21_052MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_22_222MH     )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_23_529MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_25MHZ        )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_26_667MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_28_571MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_30_769MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_32MHZ        )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_33_333MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_36_363MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_40MHZ        )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_44_444MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_50MHZ        )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_57_142MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_64MHZ        )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_66_667MHZ    )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_80MHZ        )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_100MHZ       )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_128MHZ       )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_133_333MHZ   )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_200MHZ       )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_264MHZ       )
 #elif (MCU_PLL_CLCK_FREQUENCY_CONFIG == MCU_PLL_CLCK_FREQUENCY_CONFIG_400MHZ       )
#else
#endif
*/  
  if (MCU_PLLClockFrequencyConfigurationValue <=400 && 
            (MCU_PLLClockFrequencyConfigurationValue >= 3.125 &&  CHECK_BIT(MCU_RCC2_REGISTER,MCU_DIV400_BIT) == 1)||
                (MCU_PLLClockFrequencyConfigurationValue >= 6.25 &&  CHECK_BIT(MCU_RCC2_REGISTER,MCU_DIV400_BIT) == 0))
  {
  uint8 divisorValue = (uint8) (400/MCU_PLLClockFrequencyConfigurationValue);
  MCU_RCC2_REGISTER |= --divisorValue<<22;
  }
  else
  {
    return MCU_ERROR;
  }
  return MCU_SUCCESS;
}
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
   
   static MCU_ReturnCodes MCU_PLLInit(void)
{

/* 1) Set USERCC2 bit in RCC2 resgister to use the additional cofigurations	*/

uint8 tempBit = MCU_USERRCC2_BIT;
SET_BIT(MCU_RCC2_REGISTER,tempBit);

/* 2) Set bypass bit in RCC2 to disconnect the PLL */

SET_BIT(MCU_RCC2_REGISTER,MCU_BYPASS2_BIT);

/* 3) set the crystal frequency in the XTAL bits in RCC */

  MCU_SetCrystalFrequency();

/* 4) select the main oscillator as the clock source */
  MCU_setOscillatorSource(MCU_CLK_SRC_MOSC);
/* 5) set the PWRDN2 bit to activate PLL */
  CLEAR_BIT(MCU_RCC2_REGISTER,MCU_PWRDWN2_BIT);
/* 6) configure PLL output frequency through DIV400 in RCC2 register  */
  SET_BIT(MCU_RCC2_REGISTER,MCU_DIV400_BIT);
/* 7) enable the clock divider using the bits in SYSDIV2 in RCC2 register */
// IMPORTANT NOTICE: the divider formula is [[[[CONFIGURED_FREQ/(n+1) ]]]] where n is the value inside SYSDIV bit field
  MCU_SetPLLClockFrequency();
  
/* 8) wait for PLL to be ready when PLLRIS is high in RIS register*/
  while (CHECK_BIT(MCU_RIS_REGISTER,MCU_PLLRIS_BIT) != MCU_HIGH);

/* 9) Connect the PLL by clearing BYPASS*/
  CLEAR_BIT(MCU_RCC2_REGISTER,MCU_BYPASS2_BIT);

	return MCU_SUCCESS;
}




MCU_ReturnCodes MCU_Init()
{
#if (MCU_PLL_ENABLE_CONFIG == MCU_PLL_ENABLE_CONFIG_ENABLE)			
  MCU_PLLInit();
  
#endif
  
  return MCU_SUCCESS;
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
