/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_TYPES_H
#define MCU_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define MCU_XTAL_FREQUENCY_CONFIG_4_MHz			0x06
#define MCU_XTAL_FREQUENCY_CONFIG_4_096_MHz 	        0x07
#define MCU_XTAL_FREQUENCY_CONFIG_4_9152_MHz 	        0x08
#define MCU_XTAL_FREQUENCY_CONFIG_5_MHz 		0x09
#define MCU_XTAL_FREQUENCY_CONFIG_5_12_MHz 		0x0A
#define MCU_XTAL_FREQUENCY_CONFIG_6_MHz 		0x0B
#define MCU_XTAL_FREQUENCY_CONFIG_6_144_MHz 	        0x0C
#define MCU_XTAL_FREQUENCY_CONFIG_7_327_MHz 	        0x0D
#define MCU_XTAL_FREQUENCY_CONFIG_8_MHz 		0x0E
#define MCU_XTAL_FREQUENCY_CONFIG_8_192_MHz 	        0x0F
#define MCU_XTAL_FREQUENCY_CONFIG_10_MHz 		0x10
#define MCU_XTAL_FREQUENCY_CONFIG_12_MHz 		0x11
#define MCU_XTAL_FREQUENCY_CONFIG_12_288_MHz 	        0x12
#define MCU_XTAL_FREQUENCY_CONFIG_13_56_MHz 	        0x13
#define MCU_XTAL_FREQUENCY_CONFIG_14_318_MHz 	        0x14
#define MCU_XTAL_FREQUENCY_CONFIG_16_MHz 		0x15
#define MCU_XTAL_FREQUENCY_CONFIG_16_384_MHz	        0x16
#define MCU_XTAL_FREQUENCY_CONFIG_18_MHz 		0x17
#define MCU_XTAL_FREQUENCY_CONFIG_20_MHz 		0x18
#define MCU_XTAL_FREQUENCY_CONFIG_24_MHz 		0x19
#define MCU_XTAL_FREQUENCY_CONFIG_25_MHz 		0x1A



#define MCU_PLL_CLCK_FREQUENCY_CONFIG_2MHZ             0
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_4MHZ             1
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_8MHZ             2
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_16MHZ            3
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_21_052MHZ        4
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_22_222MH         5
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_23_529MHZ        6
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_25MHZ            7
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_26_667MHZ        8
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_28_571MHZ        9
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_30_769MHZ        10
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_32MHZ            11
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_33_333MHZ        12
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_36_363MHZ        13
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_40MHZ            14
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_44_444MHZ        15
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_50MHZ            16
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_57_142MHZ        17
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_64MHZ            18
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_66_667MHZ        19
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_80MHZ            20 
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_100MHZ           21
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_128MHZ           22
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_133_333MHZ       23 
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_200MHZ           24 
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_264MHZ           25 
#define MCU_PLL_CLCK_FREQUENCY_CONFIG_400MHZ           26 













/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define MCU_LOW		0
#define MCU_HIGH	1

typedef enum
{
	MCU_SUCCESS	= 0x00,
	MCU_FAIL 	= 0x10,
	MCU_ERROR	= 0x99
}MCU_ReturnCodes;

typedef enum
{
	MCU_CLOCK_SOURCE_CONFIG_PLL = 0x10,
	MCU_CLOCK_SOURCE_CONFIG_OSC = 0x20
}MCU_ClockSourceConfiguration;

typedef enum
{
	MCU_PLL_ENABLE_CONFIG_ENABLE = 0x20,
	MCU_PLL_ENABLE_CONFIG_DISABLE = 0x20,
	
}MCU_PllEnableConfiguration;

typedef enum
{
  MCU_PLL_STATUS_LOCKED =       0x30,
  MCU_PLL_STATUS_UNLOCKED =     0x31,
  MCU_PLL_STATUS_UNSUPPORTED=   0x32
}MCU_PllLockStatusReturnType;


typedef enum
{
  MCU_CLK_SRC_MOSC                              = 0x0,
  MCU_CLK_SRC_PIOSC                             = 0x1,
  MCU_CLK_SRC_PIOSC_DIV_4                       = 0x2,
  MCU_CLK_SRC_LOW_FREQ_INTERNAL_OSCILLATOR      = 0x3,
  MCU_CLK_SRC_32_768KHz_EXTERNAL_OSCILLATOR     = 0x7,
   
}MCU_OscillatorInternalScource;


                                                

                                                
                                                
                                                
                                                
                                                
                                                
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                 
                                                        
                                                        
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
