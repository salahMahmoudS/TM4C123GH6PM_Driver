/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Write File Name>
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DET_H
#define DET_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/*Defining the Module software version by Major.Minor.Patch format */

#define DET_SW_MAJOR_VERSION		(1U)
#define DET_SW_MINOR_VERSION		(0U)
#define DET_SW_PATCH_VERSION		(0U)

/* Defining the autosar version ued for the module */
/**************** UNCOMMENT TO USE ***************************/
/**
#define <MODULE>_AR_RELEASE_MAJOR_VERSION		(4U)
#define <MODULE>_AR_RELEASE_MINOR_VERSION		(0U)
#define <MODULE>_AR_RELEASE_PATCH_VERSION		(3U)
**/

/*

For files you include from different modules check AUTOSAR compatability
For files you include from same module check SW versoin compatability
for example you will include STD types then you have to check autosar version
If you will include file in Dio.h and Dio_Types then you need to check software and autosar

*/
#include "Std_Types.h"


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
extern uint16 Det_ModuleId;             /* The DET driver ID*/
extern uint8 Det_InstanceId;           /* The DET driver instance ID*/
extern uint8 Det_ApiId;              /* The DET Api (function) ID*/
extern uint8 Det_ErrorId;             /* The DET error code*/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
Std_ReturnType Det_ReportError  ( uint16 ModuleId,
                                   uint8 InstanceId,
                                   uint8 ApiId,
                                   uint8 ErrorId
                                 );
 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Det.h
 *********************************************************************************************************************/
