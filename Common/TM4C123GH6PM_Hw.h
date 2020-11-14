/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <TM4C123GH6PM_HW.h>
 *       Module:  Common
 *
 *  Description:  <This file contains the TM4C123GH6PM registers and pins which are mapped to the real board>     
 *  
 *********************************************************************************************************************/
#ifndef TM4C123GH6PM_HW_H_
#define TM4C123GH6PM_HW_H_


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/******************* BASE ADDRESSES ***************************************************************************************/

#define CORE_PERIPHERAL_BASE_ADDRESS 		0xE000E000

/******************************************************************************************************************************/

/*******************************************System control block (SCB) registers **********************************************/

#define APINT 			*((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0xD0C ))  		//Application Interrupt and Reset Control
											//Application manager and reset control vectorkey to use register


/****************** Nested Vectored Interrupt Controller (NVIC) Registers *****************************************************/
#define DDRA *((u8 volatile *) 0x3A)
#define	 EN0           *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x100 ))		// Interrupt 0-31 Set Enable
#define	 EN1           *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x104 ))        // Interrupt 32-63 Set Enable 
#define	 EN2           *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x108 ))        // Interrupt 64-95 Set Enable 
#define	 EN3           *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x10C ))        // Interrupt 96-127 Set Enable
#define	 EN4           *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x110 ))        // Interrupt 128-138 Set Enable
#define	 DIS0          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x180 ))        // Interrupt 0-31 Clear Enable 
#define	 DIS1          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x184 ))        // Interrupt 32-63 Clear Enable
#define	 DIS2          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x188 ))        // Interrupt 64-95 Clear Enable
#define	 DIS3          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x18C ))        // Interrupt 96-127 Clear Enable 
#define	 DIS4          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x190 ))        // Interrupt 128-138 Clear Enable
#define	 PEND0         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x200 ))        // Interrupt 0-31 	Set Pending 
#define	 PEND1         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x204 ))        // Interrupt 32-63 Set Pending 
#define	 PEND2         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x208 ))        // Interrupt 64-95 Set Pending 
#define	 PEND3         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x20C ))        // Interrupt 96-127 Set Pending
#define	 PEND4         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x210 ))        // Interrupt 128-138 Set Pending
#define	 UNPEND0       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x280 ))        // Interrupt 0-31 Clear Pending 
#define	 UNPEND1       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x284 ))        // Interrupt 32-63 Clear Pending
#define	 UNPEND2       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x288 ))        // Interrupt 64-95 Clear Pending
#define	 UNPEND3       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x28C ))        // Interrupt 96-127 Clear Pending 
#define	 UNPEND4       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x290 ))        // Interrupt 128-138 Clear Pending
#define	 ACTIVE0       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x300 ))        // Interrupt 0-31 Active Bit 
#define	 ACTIVE1       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x304 ))        // Interrupt 32-63 Active Bit
#define	 ACTIVE2       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x308 ))        // Interrupt 64-95 Active Bit
#define	 ACTIVE3       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x30C ))        // Interrupt 96-127 Active Bit 
#define	 ACTIVE4       *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x310 ))        // Interrupt 128-138 Active Bit
#define	 PRI0          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x400 ))        // Interrupt 0-3 Priority 
#define	 PRI1          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x404 ))        // Interrupt 4-7 Priority 
#define	 PRI2          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x408 ))        // Interrupt 8-11 Priority
#define	 PRI3          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x40C ))        // Interrupt 12-15 Priority 
#define	 PRI4          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x410 ))        // Interrupt 16-19 Priority 
#define	 PRI5          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x414 ))        // Interrupt 20-23 Priority 
#define	 PRI6          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x418 ))        // Interrupt 24-27 Priority 
#define	 PRI7          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x41C ))        // Interrupt 28-31 Priority 
#define	 PRI8          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x420 ))        // Interrupt 32-35 Priority 
#define	 PRI9          *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x424 ))        // Interrupt 36-39 Priority 
#define	 PRI10         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x428 ))        // Interrupt 40-43 Priority 
#define	 PRI11         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x42C ))        // Interrupt 44-47 Priority 
#define	 PRI12         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x430 ))        // Interrupt 48-51 Priority 
#define	 PRI13         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x434 ))        // Interrupt 52-55 Priority 
#define	 PRI14         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x438 ))        // Interrupt 56-59 Priority 
#define	 PRI15         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x43C ))        // Interrupt 60-63 Priority 
#define	 PRI16         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x440 ))        // Interrupt 64-67 Priority 
#define	 PRI17         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x444 ))        // Interrupt 68-71 Priority 
#define	 PRI18         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x448 ))        // Interrupt 72-75 Priority 
#define	 PRI19         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x44C ))        // Interrupt 76-79 Priority 
#define	 PRI20         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x450 ))        // Interrupt 80-83 Priority 
#define	 PRI21         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x454 ))        // Interrupt 84-87 Priority 
#define	 PRI22         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x458 ))        // Interrupt 88-91 Priority 
#define	 PRI23         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x45C ))        // Interrupt 92-95 Priority 
#define	 PRI24         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x460 ))        // Interrupt 96-99 Priority 
#define	 PRI25         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x464 ))        // Interrupt 100-103 Priority 
#define	 PRI26         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x468 ))        // Interrupt 104-107 Priority 
#define	 PRI27         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x46C ))        // Interrupt 108-111 Priority 
#define	 PRI28         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x470 ))        // Interrupt 112-115 Priority 
#define	 PRI29         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x474 ))        // Interrupt 116-119 Priority 
#define	 PRI30         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x478 ))        // Interrupt 120-123 Priority 
#define	 PRI31         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x47C ))        // Interrupt 124-127 Priority 
#define	 PRI32         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x480 ))        // Interrupt 128-131 Priority 
#define	 PRI33         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x484 ))        // Interrupt 132-135 Priority 
#define	 PRI34         *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0x488 ))        // Interrupt 136-138 Priority 
#define	 SWTRIG        *((volatile uint32*)(CORE_PERIPHERAL_BASE_ADDRESS + 0xF00 ))        // Software Trigger Interrupt

/***********************************************************************************/






































































 

 
#endif  /* TM4C123GH6PM_HW_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
