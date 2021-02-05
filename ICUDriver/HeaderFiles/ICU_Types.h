/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef ICU_TYPES_H
#define ICU_TYPES_H

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
typedef enum
{
	ICU_SUCCESS = 0x00,
	ICU_FAIL = 0x10,
	ICU_ERROR = 0x80
}ICU_ReturnCodes;


typedef enum
{
	ICU_LOW = 0x00,
	ICU_HIGH
}ICU_LevelType;


typedef enum
{
	ICU_INTERRUPT_DISABLE = 0xA0,
	ICU_INTERRUPT_ENABLE
	
}	ICU_InterruptMaskconfiguration;



typedef enum
{
	ICU_INTERUPT_DETECT_LEVELS_CONFIG = 0x10,
	ICU_INTERRUPT_DETECT_EDGES_CONFIG
}ICU_InterruptSenseConfiguration;

typedef enum
{
	ICU_INTERRUPT_BOTH_EDGES_CONFIG = 0x20,
	ICU_INTERRUPT_RISING_EDGE_CONFIG,
	ICU_INTERRUPT_FALLING_EDGE_CONFIG,
	ICU_NA
}ICU_EdgeTriggeringConfiguration;

typedef enum
{
  ICU_IS_ACTIVE_INTEERUPT  = 0x30,
  ICU_NOT_ACTIVE_INTERRUPT
}ICU_ActiveType;


typedef enum
{
	
	ICU_PINA0=0,	   //PIN0
	ICU_PINA1,         //PIN1
	ICU_PINA2,         //PIN2
	ICU_PINA3,         //PIN3
	ICU_PINA4,         //PIN4
	ICU_PINA5,         //PIN5
	ICU_PINA6,         //PIN6
	ICU_PINA7,         //PIN7
	ICU_PINB0,         //PIN8
	ICU_PINB1,         //PIN9
	ICU_PINB2,         //PIN10
	ICU_PINB3,         //PIN11
	ICU_PINB4,         //PIN12
	ICU_PINB5,         //PIN13
	ICU_PINB6,         //PIN14
	ICU_PINB7,         //PIN15
	ICU_PINC0,         //PIN16
	ICU_PINC1,         //PIN17
	ICU_PINC2,         //PIN18
	ICU_PINC3,         //PIN19
	ICU_PINC4,         //PIN20
	ICU_PINC5,         //PIN21
	ICU_PINC6,         //PIN22
	ICU_PINC7,         //PIN23
	ICU_PIND0,         //PIN24
	ICU_PIND1,         //PIN25
	ICU_PIND2,         //PIN26
	ICU_PIND3,         //PIN27
	ICU_PIND4,         //PIN28
	ICU_PIND5,         //PIN29
	ICU_PIND6,         //PIN30
	ICU_PIND7,         //PIN31
	ICU_PINE0,         //PIN32
	ICU_PINE1,         //PIN33
	ICU_PINE2,         //PIN34
	ICU_PINE3,         //PIN35
	ICU_PINE4,         //PIN36
	ICU_PINE5,         //PIN37
	ICU_PINF0=40,      //PIN38				----To make pins divisble by 8 
	ICU_PINF1,         //PIN39
	ICU_PINF2,         //PIN40
	ICU_PINF3,         //PIN41
	ICU_PINF4,         //PIN42
	
	
}ICU_ChannelType;

typedef struct
{
	ICU_ChannelType			        icuChannel;
	ICU_InterruptMaskconfiguration	interruptMaskConfig;
	ICU_InterruptSenseConfiguration	interruptSenseConfig;
	ICU_EdgeTriggeringConfiguration	interruptEdgeconfig;
	
}ICU_channelsConfiguration;









/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
