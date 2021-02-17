/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO_Types.h"
#include "DIO_Cfg.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define DIO_AR_RELEASE_MAJOR_VERSION    2
#define DIO_AR_RELEASE_MINOR_VERSION    5

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/*Use THE BELOW PORTS NAMING CONVENTION
  
     DIO_PORTA
     DIO_PORTB 
     DIO_PORTC 
     DIO_PORTD 
     DIO_PORTE 
     DIO_PORTF 
*/


/* USE THE BELOW PINS
	DIO_PINA0,	   //PIN0
	DIO_PINA1,         //PIN1
	DIO_PINA2,         //PIN2
	DIO_PINA3,         //PIN3
	DIO_PINA4,         //PIN4
	DIO_PINA5,         //PIN5
	DIO_PINA6,         //PIN6
	DIO_PINA7,         //PIN7
	DIO_PINB0,         //PIN8
	DIO_PINB1,         //PIN9
	DIO_PINB2,         //PIN10
	DIO_PINB3,         //PIN11
	DIO_PINB4,         //PIN12
	DIO_PINB5,         //PIN13
	DIO_PINB6,         //PIN14
	DIO_PINB7,         //PIN15
	DIO_PINC0,         //PIN16
	DIO_PINC1,         //PIN17
	DIO_PINC2,         //PIN18
	DIO_PINC3,         //PIN19
	DIO_PINC4,         //PIN20
	DIO_PINC5,         //PIN21
	DIO_PINC6,         //PIN22
	DIO_PINC7,         //PIN23
	DIO_PIND0,         //PIN24
	DIO_PIND1,         //PIN25
	DIO_PIND2,         //PIN26
	DIO_PIND3,         //PIN27
	DIO_PIND4,         //PIN28
	DIO_PIND5,         //PIN29
	DIO_PIND6,         //PIN30
	DIO_PIND7,         //PIN31
	DIO_PINE0,         //PIN32
	DIO_PINE1,         //PIN33
	DIO_PINE2,         //PIN34
	DIO_PINE3,         //PIN35
	DIO_PINE4,         //PIN36
	DIO_PINE5,         //PIN37
	DIO_PINF0,         //PIN38			
	DIO_PINF1,         //PIN39
	DIO_PINF2,         //PIN40
	DIO_PINF3,         //PIN41
	DIO_PINF4,         //PIN42
*/	




/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define DIO_SUCCESS 		0
#define DIO_FAIL 			1
#define DIO_ERROR			99


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
uint8 DIO_Init(void);
uint8 DIO_WriteChannel(Dio_ChannelType pinNumber, Dio_LevelType pinLevel);
Dio_LevelType DIO_ReadChannel(Dio_ChannelType pinNumber);
uint8 DIO_ToggleChannel(Dio_ChannelType pinNumber);
uint8 DIO_WritePort(Dio_PortType portNumber, uint8 portValue);
uint8 DIO_ReadPort(Dio_PortType portNumber); 
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
