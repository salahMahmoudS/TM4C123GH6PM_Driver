
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Std_Types>
 *       Module:  Common
 *
 *  Description:  <This file defines the std type that are used accross the project in common folder >     
 *  
 *********************************************************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef char int8;					//define signed char as int8 
typedef unsigned char uint8;		//define unsigned char as uint8 
typedef short int16;				//define signed short as int16 
typedef unsigned short uint16;		//define unsigned short as uint16 
typedef long int32;					//define signed long as int32 
typedef unsigned long uint32;		//define unsigned long as uint32 
typedef long long int64;			//define signed loong long as int64 
typedef unsigned long long uint64;	//define unsigned long long as uint64 
typedef float f32;					//define float as f32 
typedef double f64;		

typedef uint8 Std_returnType;


typedef struct
{
    uint16 vendorID;
    uint16 moduleID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
} Std_VersionInfoType;

#define STD_HIGH        0x01    /*physical state 5V or 3.3V */
#define STD_LOW         0x00    /*physical state 0V */

#define STD_ACTIVE      0x01    /* Logical state active */
#define STD_IDLE        0x00    /* Logical state idle */ 

#define STD_ON          0x01    /* Logical state ON */
#define STD_OFF         0x00    /* Logical state OFF */


#endif  /* STD_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
