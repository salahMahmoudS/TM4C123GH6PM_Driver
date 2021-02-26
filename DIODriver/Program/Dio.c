/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief  
 *
 *      \details  
 *		\Author: Salah Mahmoud
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Bit_Math.h"
#include "TM4C123GH6PM_Hw.h"
#include "Det.h"
#include "Dem.h"
#include "MemMap.h"
#include "DIO.h"

/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS 
*********************************************************************************************************************/
/* Defining the company ID in the AUTOSAR */
/* I am using a dummy ID for now */



/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
   
   /* This array contains all base addresses for PORT driver (advanced peripheral bus) */
   uint32 portAddressMapper[] =  {GPIO_Port_A_APB_BASE_ADDRESS,
                                  GPIO_Port_B_APB_BASE_ADDRESS,
                                  GPIO_Port_C_APB_BASE_ADDRESS,
                                  GPIO_Port_D_APB_BASE_ADDRESS,
                                  GPIO_Port_E_APB_BASE_ADDRESS,
                                  GPIO_Port_F_APB_BASE_ADDRESS
                                  };                    /*This array contains the physical addresses of each port in the MCU */


  
   
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
static const Dio_ChannelConfigType * Dio_ConfigurationChannelsPointer;
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
	void Dio_Init(const Dio_ConfigType* ConfigPtr)
{
  Dio_ConfigurationChannelsPointer = ConfigPtr->ConfiguredChannelsArray;
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType pinLevelType)
{
	/* Step 1 validate that the channel is output channel */
		/*
  
  
  */
  
		/* Step 2 write the desired value on the desired channel */
		/* a) get the port from the configuratoin ptr */
		/* b) get the channel ID itself, it already exists and mapped*/            
                uint32 pinBaseAddress = portAddressMapper[Dio_ConfigurationChannelsPointer[ChannelId].postBuildPortID];
                uint8 pinOffset = Dio_ConfigurationChannelsPointer[ChannelId].postBuildChannelID;	
                 
                /* Create a pointer to the desired PIN using bitbanding */
		volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<pinOffset)));
                
                
		if (pinLevelType == STD_HIGH)             /* if desired value is high */
		{  
		*pinAddress = STD_HIGH<<pinOffset;      /* Set the desired channel to high */
		}
		else if (pinLevelType == STD_LOW)       /* else if desired value is low */
		{
		*pinAddress = STD_LOW<<pinOffset;               /* Set the desired channel to low */
		}
		else
		{
		  /* Do nothing*/
		}
	   
}


	Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
	{
          uint8 pinState;
          /* Step 1 validate that the channel is output channel */
		/*
  
  
  */
  
		/* Step 2 write the desired value on the desired channel */
		/* a) get the port from the configuratoin ptr */
		/* b) get the channel ID itself, it already exists and mapped*/                  
                uint32 pinBaseAddress = portAddressMapper[Dio_ConfigurationChannelsPointer[ChannelId].postBuildPortID];
                uint8 pinOffset = Dio_ConfigurationChannelsPointer[ChannelId].postBuildChannelID;	
                volatile uint32* pinAddress = &(GPIODATA(pinBaseAddress+(0x04<<pinOffset)));
                
        /* if the address in bitbanding is HIGH, return HIGH */        
	if (*pinAddress >= STD_HIGH)
	{
		pinState= STD_HIGH;
	}
                /* if the address in bitbanding is LOW, return LOW */        
		else if (*pinAddress <= STD_LOW)
		{
		pinState= STD_LOW;
		
		}
		else 
		{
			
			
		}
        return pinState;
	}
	
        
        
        Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
	{
        uint8 pinState;
	if (Dio_ReadChannel(ChannelId) == STD_HIGH)
	{
	Dio_WriteChannel(ChannelId,STD_LOW);
	pinState= STD_LOW;
	}
	else if (Dio_ReadChannel(ChannelId) == STD_LOW)
	{
	Dio_WriteChannel(ChannelId,STD_HIGH);
	pinState= STD_HIGH;
	}
	else
	{
          /* Do nothing */
	}
	return pinState;
	}
	void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
	{
	uint32 portAddress = portAddressMapper[PortId];
	
	GPIODATA((portAddress + 0x3FC))= Level; 
	
	}
	
	
	Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
	{
	uint32 portAddress = portAddressMapper[PortId];        /* Get the physical address of the desired port */
	
	return GPIODATA((portAddress+0x3FC));                /* Read the desired port and return result */
	}
	
		

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
