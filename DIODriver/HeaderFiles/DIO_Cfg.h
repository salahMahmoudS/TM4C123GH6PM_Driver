/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>
 *	Author: Salah Mahmoud
 *  
 *********************************************************************************************************************/
#ifndef DIO_CFG_H
#define DIO_CFG_H




 



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

#define DIO_CFG_SW_MAJOR_VERSION			(1U)
#define DIO_CFG_SW_MINOR_VERSION			(0U)
#define DIO_CFG_SW_PATCH_VERSION			(0U)

/* Defining the autosar version ued for the module */

#define DIO_CFG_AR_RELEASE_MAJOR_VERSION		(4U)
#define DIO_CFG_AR_RELEASE_MINOR_VERSION		(0U)
#define DIO_CFG_AR_RELEASE_PATCH_VERSION		(3U)


/*
For files you include from different modules check AUTOSAR compatability
For files you include from same module check SW versoin compatability
for example you will include STD types then you have to check autosar version
If you will include file in Dio.h and Dio_Types then you need to check software and autosar

*/
/*********************UNCOMMENT TO USE ***********************/

/**

#include "Std_Types.h"

#if ((<MODULE>_AR_MAJOR_VERSION != STD_TYPES_AR_MAJOR_VERSION)\
||	 (<MODULE>_AR_MINOR_VERSION != STD_TYPES_AR_MINOR_VERSION)\
||	 (<MODULE>_AR_PATCH_VERSION != STD_TYPES_AR_PATCH_VERSION))
#error "The autosar version of <included module> is not matching this module version"
#endif

**/
/* Non AUTOSAR files */





/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/* Pre-compile option for Version Info API */
#define DIO_VERSION_INFO_API                (STD_OFF)

/* Pre-compile option for presence of OptionalFunction API */
/* to be inserted here */

/* Pre-compile option for Flip Channel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)





#define DIO_NUMBER_OF_CONFIGURED_CHANNELS		(5U)

/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_LED1_CHANNEL_ID_INDEX        (uint8)0x00
#define DioConf_LED2_CHANNEL_ID_INDEX        (uint8)0x01
#define DioConf_SW1_CHANNEL_ID_INDEX         (uint8)0x02
#define DioConf_SW2_CHANNEL_ID_INDEX         (uint8)0x03
#define DioConf_TEST_CHANNEL_ID_INDEX        (uint8)0x04
/* DIO Configured Port ID's  */
#define DioConf_LED1_PORT_NUM                (Dio_PortType)DIO_PORTF /* PORTF */
#define DioConf_LED2_PORT_NUM                (Dio_PortType)DIO_PORTF /* PORTF */
#define DioConf_SW1_PORT_NUM                 (Dio_PortType)DIO_PORTF /* PORTF */
#define DioConf_SW2_PORT_NUM                 (Dio_PortType)DIO_PORTF /* PORTF */
#define DioConf_TEST_PORT_NUM                (Dio_PortType)DIO_PORTA /* PORTF */

/* DIO Configured Channel ID's */
#define DioConf_LED1_CHANNEL_NUM             (Dio_ChannelType)DIO_PINF1  /* Pin 1 in PORTF */
#define DioConf_LED2_CHANNEL_NUM             (Dio_ChannelType)DIO_PINF2  /* Pin 2 in PORTF */
#define DioConf_SW1_CHANNEL_NUM              (Dio_ChannelType)DIO_PINF4  /* Pin 4 in PORTF */
#define DioConf_SW2_CHANNEL_NUM              (Dio_ChannelType)DIO_PINF0  /* Pin 0 in PORTF */
#define DioConf_TEST_CHANNEL_NUM             (Dio_ChannelType)DIO_PINA0 /* PORTF */


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/





#endif /* DIO_H */
