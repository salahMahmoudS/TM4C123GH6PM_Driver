/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_CONFIG_H
#define MCU_CONFIG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


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
f32 MCU_PLLClockFrequencyConfigurationValue = 8;
//define the crystal frequency DONOT CHANGE UNLESS THE uC crystal is different than 16 MHz, below are allowed values for uCs

   /*
     MCU_XTAL_FREQUENCY_CONFIG_4_MHz
     MCU_XTAL_FREQUENCY_CONFIG_4_096_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_4_9152_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_5_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_5_12_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_6_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_6_144_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_7_327_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_8_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_8_192_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_10_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_12_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_12_288_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_13_56_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_14_318_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_16_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_16_384_MHz	
     MCU_XTAL_FREQUENCY_CONFIG_18_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_20_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_24_MHz 	
     MCU_XTAL_FREQUENCY_CONFIG_25_MHz 	
*/

#define MCU_XTAL_FREQUENCY_CONFIGURATION	MCU_XTAL_FREQUENCY_CONFIG_16_MHz	

#define MCU_CLOCK_SOURCE_CONFIG			MCU_CLOCK_SOURCE_CONFIG_PLL
#define MCU_PLL_ENABLE_CONFIG			MCU_PLL_ENABLE_CONFIG_ENABLE
#define MCU_PLL_CLCK_FREQUENCY_CONFIG           MCU_PLL_CLCK_FREQUENCY_CONFIG_10_MHZ
#define MCU_CLK_SRC_CONFIG                      MCU_CLK_SRC_CONFIG_MAIN_OSCILLATOR

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
