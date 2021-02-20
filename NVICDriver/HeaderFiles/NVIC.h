
/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <NVIC_INT_H>
 *       Module:  NVICDriver
 *
 *  Description:  <This file contains the prototype functions used in this driver>     
 *  
 *********************************************************************************************************************/
#ifndef NVIC_H
#define NVIC_H

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
typedef struct
{
	uint8 interruptVTValue;
	uint8 interruptPriorityLevelGroup;
	uint8 interruptPriorityLevelSubGroup;
	
}NVIC_interruptConfigStructure;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
#define NVIC_SUCCESS 		0
#define NVIC_FAIL 			1
#define NVIC_ERROR			95
#define NVIC_IS_ACTIVE		2
#define NVIC_IS_NOT_ACTIVE	3
#define NVIC_IS_ENABLED		4
#define NVIC_Is_DISABLED	5
#define NVIC_IS_PENDING		6
#define NVIC_IS_NOT_PENDING	7



/************************************Defining interrupt vector table Interrupt number ***********************************************/
#define	INTERRUPT_VT_GPIO_PORT_A						0 		 
#define	INTERRUPT_VT_GPIO_PORT_B						1 		 
#define	INTERRUPT_VT_GPIO_PORT_C						2 		 
#define	INTERRUPT_VT_GPIO_PORT_D						3 		 
#define	INTERRUPT_VT_GPIO_PORT_E						4 		 
#define	INTERRUPT_VT_UART0							5 		 
#define	INTERRUPT_VT_UART1							6 		 
#define	INTERRUPT_VT_SSI0							7 		 
#define	INTERRUPT_VT_I2C0							8 		 
#define	INTERRUPT_VT_PWM0_FAULT							9 		 
#define	INTERRUPT_VT_PWM0_GENERATOR_0						10		
#define	INTERRUPT_VT_PWM0_GENERATOR_1						11		
#define	INTERRUPT_VT_PWM0_GENERATOR_2						12		
#define	INTERRUPT_VT_QEI0							13		
#define	INTERRUPT_VT_ADC0_SEQUENCE_0						14		
#define	INTERRUPT_VT_ADC0_SEQUENCE_1						15		
#define	INTERRUPT_VT_ADC0_SEQUENCE_2						16		
#define	INTERRUPT_VT_ADC0_SEQUENCE_3						17		
#define	INTERRUPT_VT_WATCHDOG_TIMERS_0_AND_1				        18		
#define	INTERRUPT_VT_16_32_BIT_TIMER_0A						19		
#define	INTERRUPT_VT_16_32_BIT_TIMER_0B						20		
#define	INTERRUPT_VT_16_32_BIT_TIMER_1A						21		
#define	INTERRUPT_VT_16_32_BIT_TIMER_1B						22		
#define	INTERRUPT_VT_16_32_BIT_TIMER_2A						23		
#define	INTERRUPT_VT_16_32_BIT_TIMER_2B						24		
#define	INTERRUPT_VT_ANALOG_COMPARATOR_0					25		
#define	INTERRUPT_VT_ANALOG_COMPARATOR_1					26		
#define	INTERRUPT_VT_SYSTEM_CONTROL						28	
#define	INTERRUPT_VT_FLASH_MEMORY_AND_EEPROM_CONTROL	                        29 
#define	INTERRUPT_VT_GPIO_PORT_F                                                30 
#define	INTERRUPT_VT_UART2                                                      33 
#define	INTERRUPT_VT_SSI1                                                       34 
#define	INTERRUPT_VT_16_32_BIT_TIMER_3A                                         35 
#define	INTERRUPT_VT_16_32_BIT_TIMER_3B                                         36 
#define	INTERRUPT_VT_I2C1                                                       37 
#define	INTERRUPT_VT_QEI1                                                       38 
#define	INTERRUPT_VT_CAN0                                                       39 
#define	INTERRUPT_VT_CAN1                                                       40 
#define	INTERRUPT_VT_HIBERNATION_MODULE                                         43 
#define	INTERRUPT_VT_USB                                                        44
#define	INTERRUPT_VT_PWM_GENERATOR_3                                            45
#define INTERRUPT_VT_MDMA                                                       46
#define INTERRUPT_VT_MDMA_ERRPR                                                 47
#define	INTERRUPT_VT_ADC1_SEQUENCE_0                                            48
#define	INTERRUPT_VT_ADC1_SEQUENCE_1                                            49
#define	INTERRUPT_VT_ADC1_SEQUENCE_2                                            50
#define	INTERRUPT_VT_ADC1_SEQUENCE_3                                            51
#define	INTERRUPT_VT_SSI2                                                       57
#define	INTERRUPT_VT_SSI3                                                       58 
#define	INTERRUPT_VT_UART3                                                      59 
#define	INTERRUPT_VT_UART4                                                      60 
#define	INTERRUPT_VT_UART5                                                      61 
#define	INTERRUPT_VT_UART6                                                      62 
#define	INTERRUPT_VT_UART7                                                      63 
#define	INTERRUPT_VT_I2C2                                                       68 
#define	INTERRUPT_VT_I2C3                                                       69 
#define	INTERRUPT_VT_16_32_BIT_TIMER_4A                                         70 
#define	INTERRUPT_VT_16_32_BIT_TIMER_4B                                         71 
#define	INTERRUPT_VT_16_32_BIT_TIMER_5A                                         92 
#define	INTERRUPT_VT_16_32_BIT_TIMER_5B                                         93 
#define	INTERRUPT_VT_32_64_BIT_TIMER_0A                                         94 
#define	INTERRUPT_VT_32_64_BIT_TIMER_0B                                         95 
#define	INTERRUPT_VT_32_64_BIT_TIMER_1A                                         96 
#define	INTERRUPT_VT_32_64_BIT_TIMER_1B                                         97 
#define	INTERRUPT_VT_32_64_BIT_TIMER_2A                                         98 
#define	INTERRUPT_VT_32_64_BIT_TIMER_2B                                         99 
#define	INTERRUPT_VT_32_64_BIT_TIMER_3A                                         100
#define	INTERRUPT_VT_32_64_BIT_TIMER_3B                                         101
#define	INTERRUPT_VT_32_64_BIT_TIMER_4A                                         102
#define	INTERRUPT_VT_32_64_BIT_TIMER_4B                                         103
#define	INTERRUPT_VT_32_64_BIT_TIMER_5A                                         104
#define	INTERRUPT_VT_32_64_BIT_TIMER_5B                                         105
#define	INTERRUPT_VT_SYSTEM_EXCEPTION_IMPRECISE			                106
#define	INTERRUPT_VT_PWM1_GENERATOR_0                                           134
#define	INTERRUPT_VT_PWM1_GENERATOR_1                                           135
#define	INTERRUPT_VT_PWM1_GENERATOR_2                                           136
#define	INTERRUPT_VT_PWM1_GENERATOR_3                                           137
#define	INTERRUPT_VT_PWM1_FAULT                                                 138
 
//27		-	Reserved	 
//41-42	-	Reserved
//31-32 	-	Reserved
//52-56 	-	Reserved
//64-67 	-	Reserved
//72-91  	-	Reserved
//107-133	-	Reserved


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
uint8 NVIC_Init(void);																	//This function initializes the interrupt
uint8 NVIC_SetEnableInterrupt(uint8 interruptVTValue); 									//This function enables the configured interrupts
uint8 NVIC_GetIsPendingInterupt(uint8 interruptVTValue);								//This function disables the interrupt
uint8 NVIC_SetInterruptToPending(uint8 interruptVTValue);								//This function sets enabled interrupt to pending
uint8 NVIC_ClearPendingInterrupt(uint8 interruptVTValue);								//this fiunction clears any pending interrupt
uint8 NVIC_GetIsPendingInterupt(uint8 interruptVTValue);								//This function returns if interrupt is pending
uint8 NVIC_SWActivateInterrupt(uint8 interruptVTValue);									//This function activates interrupt by softwarre
uint8 NVIC_SetInterruptPriority(NVIC_interruptConfigStructure desiredInterrupt);		//This function configures the interrupt priority		
uint8 NVIC_DisableInterrupt(uint8 interruptVTValue);									//This function disable interrupt

 
#endif  /* NVIC_INT_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
