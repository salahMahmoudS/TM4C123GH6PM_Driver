/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_TYPES_H
#define DIO_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
/* Defining the company ID in the AUTOSAR */
/* I am using a dummy ID for now */

#define COMPILER_VENDOR_ID					(2007U)


/* Defining the Module software verison by Major.Minor.Patch format */

#define DIO_TYPES_SW_MAJOR_VERSION			(1U)
#define DIO_TYPES_SW_MINOR_VERSION			(0U)
#define DIO_TYPES_SW_PATCH_VERSION			(0U)

/* Defining the autosar version ued for the module */

#define DIO_TYPES_AR_RELEASE_MAJOR_VERSION		(4U)
#define DIO_TYPES_AR_RELEASE_MINOR_VERSION		(0U)
#define DIO_TYPES_AR_RELEASE_PATCH_VERSION		(3U)


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/* Type definition for portLevel Type */
typedef uint8   Dio_PortLevelType; 

/* Type definition for channel Level type */
typedef uint8	Dio_LevelType;

/* Type definition for channelType and the allowed channels */
typedef uint8	Dio_ChannelType;

#define	DIO_PINA0 			((Dio_ChannelType) 0x00)		//PIN0
#define	DIO_PINA1 			((Dio_ChannelType) 0x01)     	//PIN1
#define	DIO_PINA2 			((Dio_ChannelType) 0x02)     	//PIN2
#define	DIO_PINA3 			((Dio_ChannelType) 0x03)     	//PIN3
#define	DIO_PINA4 			((Dio_ChannelType) 0x04)     	//PIN4
#define	DIO_PINA5 			((Dio_ChannelType) 0x05)     	//PIN5
#define	DIO_PINA6 			((Dio_ChannelType) 0x06)     	//PIN6
#define	DIO_PINA7 			((Dio_ChannelType) 0x07)     	//PIN7
#define	DIO_PINB0 			((Dio_ChannelType) 0x00)     	//PIN8
#define	DIO_PINB1 			((Dio_ChannelType) 0x01)     	//PIN9
#define	DIO_PINB2 			((Dio_ChannelType) 0x02)     	//PIN10
#define	DIO_PINB3 			((Dio_ChannelType) 0x03)     	//PIN11
#define	DIO_PINB4 			((Dio_ChannelType) 0x04)     	//PIN12
#define	DIO_PINB5 			((Dio_ChannelType) 0x05)     	//PIN13
#define	DIO_PINB6 			((Dio_ChannelType) 0x06)     	//PIN14
#define	DIO_PINB7 			((Dio_ChannelType) 0x07)     	//PIN15
#define	DIO_PINC0 			((Dio_ChannelType) 0x00)     	//PIN16
#define	DIO_PINC1 			((Dio_ChannelType) 0x01)     	//PIN17
#define	DIO_PINC2 			((Dio_ChannelType) 0x02)     	//PIN18
#define	DIO_PINC3 			((Dio_ChannelType) 0x03)     	//PIN19
#define	DIO_PINC4 			((Dio_ChannelType) 0x04)     	//PIN20
#define	DIO_PINC5 			((Dio_ChannelType) 0x05)     	//PIN21
#define	DIO_PINC6 			((Dio_ChannelType) 0x06)     	//PIN22
#define	DIO_PINC7 			((Dio_ChannelType) 0x07)     	//PIN23
#define	DIO_PIND0 			((Dio_ChannelType) 0x00)     	//PIN24
#define	DIO_PIND1 			((Dio_ChannelType) 0x01)     	//PIN25
#define	DIO_PIND2 			((Dio_ChannelType) 0x02)     	//PIN26
#define	DIO_PIND3 			((Dio_ChannelType) 0x03)     	//PIN27
#define	DIO_PIND4 			((Dio_ChannelType) 0x04)     	//PIN28
#define	DIO_PIND5 			((Dio_ChannelType) 0x05)     	//PIN29
#define	DIO_PIND6 			((Dio_ChannelType) 0x06)     	//PIN30
#define	DIO_PIND7 			((Dio_ChannelType) 0x07)     	//PIN31
#define	DIO_PINE0 			((Dio_ChannelType) 0x00)     	//PIN32
#define	DIO_PINE1 			((Dio_ChannelType) 0x01)     	//PIN33
#define	DIO_PINE2 			((Dio_ChannelType) 0x02)     	//PIN34
#define	DIO_PINE3 			((Dio_ChannelType) 0x03)     	//PIN35
#define	DIO_PINE4 			((Dio_ChannelType) 0x04)     	//PIN36
#define	DIO_PINE5 			((Dio_ChannelType) 0x05)     	//PIN37
#define	DIO_PINF0 			((Dio_ChannelType) 0x00)     	//PIN38 
#define	DIO_PINF1 			((Dio_ChannelType) 0x01)     	//PIN39
#define	DIO_PINF2 			((Dio_ChannelType) 0x02)     	//PIN40
#define	DIO_PINF3 			((Dio_ChannelType) 0x03)     	//PIN41
#define	DIO_PINF4 			((Dio_ChannelType) 0x04)     	//PIN42
	                                           

/*Type definition for port types and their allowed values */
typedef uint8 	Dio_PortType;
   
#define DIO_PORTA	    	((Dio_PortType) 0x00U)	     	 //PORTA
#define DIO_PORTB           ((Dio_PortType) 0x01U)           //PORTB
#define DIO_PORTC           ((Dio_PortType) 0x02U)           //PORTC
#define DIO_PORTD           ((Dio_PortType) 0x03U)           //PORTD
#define DIO_PORTE           ((Dio_PortType) 0x04U)           //PORTE
#define DIO_PORTF           ((Dio_PortType) 0x05U)           //PORTF
                                               



/* Type definition for the channel group type and their parameters */
typedef struct
{
  uint8 mask;
  uint8 offset;
  Dio_PortType port;
  
}Dio_ChannelGroupType;


/*Type definition for the channel configuration type */ 
typedef struct
{
   Dio_PortType         	postBuildPortID;
   Dio_ChannelType       postBuildChannelID;
}Dio_ChannelConfigType;

typedef struct
{
	Dio_ChannelConfigType ConfiguredChannelsArray[DIO_NUMBER_OF_CONFIGURED_CHANNELS];
}Dio_ConfigType;

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
