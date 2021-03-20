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
#ifndef <FILE_NAME_H>
#define <FILE_NAME_H>

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

#define <MODULE>_SW_MAJOR_VERSION			(1U)
#define <MODULE>_SW_MINOR_VERSION			(0U)
#define <MODULE>_SW_PATCH_VERSION			(0U)

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
/*********************UNCOMMENT TO USE ***********************/

/**

#include "Std_Types.h"

#if ((<MODULE>_AR_MAJOR_VERSION != STD_TYPES_AR_MAJOR_VERSION)\
||	 (<MODULE>_AR_MINOR_VERSION != STD_TYPES_AR_MINOR_VERSION)\
||	 (<MODULE>_AR_PATCH_VERSION != STD_TYPES_AR_PATCH_VERSION))
#error "The autosar version of <included module> is not matching this module version"
#endif

**/

/*
 * Macros for module Status
 */
#define <MODULE>_INITIALIZED                (1U)
#define <MODULE>_NOT_INITIALIZED            (0U)


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

 
#endif  /* FILE_NAME_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
