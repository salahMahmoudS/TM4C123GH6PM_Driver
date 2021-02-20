/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Port.h>
 *       Module:  -
 *
 *  Description:  <In this file you will find all allowed values for configuring port driver>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_H_
#define PORT_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define PORT_AR_RELEASE_MAJOR_VERSION    2
#define PORT_AR_RELEASE_MINOR_VERSION    5

typedef struct 

{
	uint8 portPinNumber;
	uint8 portPinMode;
	uint8 portPinDirection;
	uint8 portInitialValueIfOutput;
	uint8 portOutputCurrent;
	uint8 portPinResistorAttchIfInput;
	
}portPinsConfig;



/**************Use below in "portPinNumber" configuration in Port_Lcfg********/
//portPinNumber 

 typedef enum
{
	PORT_PINA0=0,		//PIN0
	PORT_PINA1,         //PIN1
	PORT_PINA2,         //PIN2
	PORT_PINA3,         //PIN3
	PORT_PINA4,         //PIN4
	PORT_PINA5,         //PIN5
	PORT_PINA6,         //PIN6
	PORT_PINA7,         //PIN7
	PORT_PINB0,         //PIN8
	PORT_PINB1,         //PIN9
	PORT_PINB2,         //PIN10
	PORT_PINB3,         //PIN11
	PORT_PINB4,         //PIN12
	PORT_PINB5,         //PIN13
	PORT_PINB6,         //PIN14
	PORT_PINB7,         //PIN15
	PORT_PINC0,         //PIN16
	PORT_PINC1,         //PIN17
	PORT_PINC2,         //PIN18
	PORT_PINC3,         //PIN19
	PORT_PINC4,         //PIN20
	PORT_PINC5,         //PIN21
	PORT_PINC6,         //PIN22
	PORT_PINC7,         //PIN23
	PORT_PIND0,         //PIN24
	PORT_PIND1,         //PIN25
	PORT_PIND2,         //PIN26
	PORT_PIND3,         //PIN27
	PORT_PIND4,         //PIN28
	PORT_PIND5,         //PIN29
	PORT_PIND6,         //PIN30
	PORT_PIND7,         //PIN31
	PORT_PINE0,         //PIN32
	PORT_PINE1,         //PIN33
	PORT_PINE2,         //PIN34
	PORT_PINE3,         //PIN35
	PORT_PINE4,         //PIN36
	PORT_PINE5,         //PIN37
	PORT_PINF0=40,      //PIN38				----To make pins divisble by 8 
	PORT_PINF1,         //PIN39
	PORT_PINF2,         //PIN40
	PORT_PINF3,         //PIN41
	PORT_PINF4,         //PIN42
	
	
}portArmPins;


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define PORT_SUCCESS 		0
#define PORT_FAIL 			1
#define PORT_ERROR			99
#define PORT_IS_ENABLED		4
#define PORT_Is_DISABLED	5

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
typedef enum 
{
	GPIO_Port_A_APB,
	GPIO_Port_A_AHB,
	GPIO_Port_B_APB,
	GPIO_Port_B_AHB,
	GPIO_Port_C_APB,
	GPIO_Port_C_AHB,
	GPIO_Port_D_APB,
	GPIO_Port_D_AHB,
	GPIO_Port_E_APB,
	GPIO_Port_E_AHB,
	GPIO_Port_F_APB,
	GPIO_Port_F_AHB,
}Ports;
 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
uint8 Port_Init(void);					//This functions initializes the GPIO port
 
 /**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 ***********************************************************************************************************************/
 
/************ USE THIS IN portPinMode configurationin Port_Lcfg*******************************************************************************************
 *defining each pin mode configuration, below section contains all possible configurations for each pin
 ******************************************************************************************
  
 ***********General Mode************
 //REPLACE x with the required pin
 //e.g if you wish to make A0 DIO -->>PORT_PINA0_DIO
 
 // PORT_PINx_DIO			
 // PORT_PINx_ANALOG_FUNC	
 
 
 
 
 ***********PA0 modes***************
 // PORT_PA0_DIO			
 // PORT_PA0_U0Rx			
 // PORT_PA0_CAN1Rx									//PA0 
 
 
 ***********PA1 modes***************
 // PORT_PA1_DIO			
 // PORT_PA1_U0Tx			
 // PORT_PA1_CAN1Tx    	                         	//PA1 
 
 ***********PA2 modes***************
 // PORT_PA2_DIO			
 // PORT_PA2_SSI0Clk  		                      	//PA2 
 
 
 ***********PA3 modes***************
 // PORT_PA3_DIO			
 // PORT_PA3_SSI0Fss  		                      	//PA3 
 
 ***********PA4 modes***************
 // PORT_PA4_DIO			
 // PORT_PA4_SSI0Rx   		                     	//PA4 
 
 ***********PA5 modes***************
 // PORT_PA5_DIO			
 // PORT_PA5_SSI0Tx  		                     	//PA5 
 
 
 ***********PA6 modes***************
 // PORT_PA6_DIO			
 // PORT_PA6_I2C1SCL		
 // PORT_PA6_M1PWM2  		                 		//PA6 
 
 
 ***********PA7 modes***************
 // PORT_PA7_DIO			
 // PORT_PA7_I2C1SDA		
 // PORT_PA7_M1PWM3  		                 		//PA7 
 
 
 ***********PB0 modes***************
 // PORT_PB0_DIO			
 // PORT_PB0_USB0ID		
 // PORT_PB0_U1Rx			
 // PORT_PB0_T2CCP0    	              		       //PB0 
  
 
 ***********PB1 modes***************
 // PORT_PB1_DIO			
 // PORT_PB1_USB0VBUS		
 // PORT_PB1_U1Tx			
 // PORT_PB1_T2CCP1     	                 //PB1 
 
 
 ***********PB2 modes***************
 // PORT_PB2_DIO			
 // PORT_PB2_I2C0SCL		
 // PORT_PB2_T3CCP0    	                        //PB2 
 
 
 ***********PB3 modes***************
 // PORT_PB3_DIO			
 // PORT_PB3I2C0SDA		
 // PORT_PB3T3CCP1			                        //PB3 
 
 
 ***********PB4 modes***************
 // PORT_PB4_DIO			
 // PORT_PB4_AIN10			
 // PORT_PB4_SSI2Clk		
 // PORT_PB4_M0PWM2		
 // PORT_PB4_T1CCP0		
 // PORT_PB4_CAN0Rx		               //PB4 
 
 
 ***********PB5 modes***************
 // PORT_PB5_DIO			
 // PORT_PB5_AIN11			
 // PORT_PB5_SSI2Fss		
 // PORT_PB5_M0PWM3		
 // PORT_PB5_T1CCP1		
 // PORT_PB5_CAN0Tx		               //PB5 
 
 
 ***********PB6 modes***************
 // PORT_PB6_DIO			
 // PORT_PB6_SSI2Rx		
 // PORT_PB6_M0PWM0		
 // PORT_PB6_T0CCP0       	             //PB6 
 
 
 ***********PB7 modes***************
 // PORT_PB7_DIO			
 // PORT_PB7_SSI2Tx		
 // PORT_PB7_M0PWM1		
 // PORT_PB7_T0CCP1                       //PB7 
 
 
 ***********PC0 modes***************
 // PORT_PC0_DIO			
 // PORT_PC0_TCKSWCLK		
 // PORT_PC0_T4CCP0     	                //PC0 
 

************PC1 modes****************
 // PORT_PC1_DIO			
 // PORT_PC1_TMSSWDIO		
 // PORT_PC1_T4CCP1     	                          //PC1 
  
	
 ***********PC2 modes***************
 // PORT_PC2_DIO			
 // PORT_PC2_TDI			
 // PORT_PC2_T5CCP0     	                               //PC2 
  

 ***********PC3 modes***************
 // PORT_PC3_DIO			
 // PORT_PC3_TDOSWO		
 // PORT_PC3_T5CCP1     	                              //PC3 
  

 ***********PC4 modes***************
 // PORT_PC4_DIO			
 // PORT_PC4_C1_NEG		
 // PORT_PC4_U4Rx 			
 // PORT_PC4_U1Rx			
 // PORT_PC4_M0PWM6		
 // PORT_PC4_IDX1			
 // PORT_PC4_WT0CCP0		
 // PORT_PC4_U1RTS            //PC4 
  

 ***********PC5 modes***************
 // PORT_PC5_DIO			
 // PORT_PC5_C1_POS		
 // PORT_PC5_U4Tx			
 // PORT_PC5_U1Tx			
 // PORT_PC5_M0PWM7		
 // PORT_PC5_PhA1			
 // PORT_PC5_WT0CCP1		
 // PORT_PC5_U1CTS       	     //PC5 
  

 ***********PC6 modes***************
 // PORT_PC6_DIO			
 // PORT_PC6_C0_POS		
 // PORT_PC6_U3Rx			
 // PORT_PC6_PhB1			
 // PORT_PC6_WT1CCP0		
 // PORT_PC6_USB0EPEN     	         //PC6 
  

 ***********PC7 modes***************
 // PORT_PC7_DIO		
 // PORT_PC7_C0_NEG 	
 // PORT_PC7_U3Tx		
 // PORT_PC7_WT1CCP1	
 // PORT_PC7_USB0PFLT               //PC7 
  

 ***********PD0 modes***************
 // PORT_PD0_DIO		
 // PORT_PD0_AIN7			
 // PORT_PD0_SSI3Clk		
 // PORT_PD0_SSI1Clk		
 // PORT_PD0_I2C3SCL		
 // PORT_PD0_M0PWM6		
 // PORT_PD0_M1PWM0		
 // PORT_PD0_WT2CCP0  		 //PD0 
  

 ***********PD1 modes***************
 // PORT_PD1_DIO		
 // PORT_PD1_AIN6		
 // PORT_PD1_SSI3Fss	
 // PORT_PD1_SSI1Fss	
 // PORT_PD1_I2C3SDA	
 // PORT_PD1_M0PWM7	
 // PORT_PD1_M1PWM1	
 // PORT_PD1_WT2CCP1 	 //PD1 
  

 ***********PD2 modes***************
 // PORT_PD2_DIO		
 // PORT_PD2_AIN5		
 // PORT_PD2_SSI3Rx 	
 // PORT_PD2_SSI1Rx	
 // PORT_PD2_M0FAULT0	
 // PORT_PD2_WT3CCP0	
 // PORT_PD2_USB0EPEN	    //PD2 
  

 ***********PD3 modes***************
 // PORT_PD3_DIO		
 // PORT_PD3_AIN4		
 // PORT_PD3_SSI3Tx	
 // PORT_PD3_SSI1Tx	
 // PORT_PD3_IDX0		
 // PORT_PD3_WT3CCP1	
 // PORT_PD3_USB0PFLT        //PD3 
  

 ***********PD4 modes***************
 // PORT_PD4_DIO			
 // PORT_PD4_USB0DM		
 // PORT_PD4_U6Rx			
 // PORT_PD4_WT4CCP0                        //PD4 
  

 ***********PD5 modes***************
 // PORT_PD5_DIO			
 // PORT_PD5_USB0DP 		
 // PORT_PD5_U6Tx 			
 // PORT_PD5_WT4CCP1                         //PD5 
  

 ***********PD6 modes***************
 // PORT_PD6_DIO			
 // PORT_PD6_U2Rx			
 // PORT_PD6_M0FAULT0		
 // PORT_PD6_PhA0			
 // PORT_PD6_WT5CCP0                    //PD6 
  

 ***********PD7 modes***************
 // PORT_PD7_DIO			
 // PORT_PD7_U2Tx			
 // PORT_PD7_PhB0			
 // PORT_PD7_WT5CCP1		
 // PORT_PD7_NMI                        //PD7 
 
 
 ***********PE0 modes***************
 // PORT_PE0_DIO			
 // PORT_PE0_AIN3			
 // PORT_PE0_U7Rx                                 //PE0 
 
 *****PE1 modes**********
 // PORT_PE1_DIO			
 // PORT_PE1_AIN2			
 // PORT_PE1_U7Tx                                  //PE1 
 
 
 ***********PE2 modes***************
 // PORT_PE2_DIO			
 // PORT_PE2_AIN1			                         //PE2 
 
 
 ***********PE3 modes***************
 // PORT_PE3_DIO			
 // PORT_PE3_AIN0                                //PE3 
 
 
 ***********PE4 modes***************
 // PORT_PE4_DIO			
 // PORT_PE4_AIN9			
 // PORT_PE4_U5Rx			
 // PORT_PE4_I2C2SCL		
 // PORT_PE4_M0PWM4		
 // PORT_PE4_M1PWM2		
 // PORT_PE4_CAN0Rx          //PE4 
  
			 
 ***********PE5 modes***************
 // PORT_PE5_DIO			
 // PORT_PE5_AIN8			
 // PORT_PE5_U5Tx			
 // PORT_PE5_I2C2SDA		
 // PORT_PE5_M0PWM5		
 // PORT_PE5_M1PWM3		
 // PORT_PE5_CAN0Tx           //PE5 
  

 ***********PF0 modes***************
 // PORT_PF0_DIO			
 // PORT_PF0_U1RTS			
 // PORT_PF0_SSI1Rx		
 // PORT_PF0_CAN0Rx		
 // PORT_PF0_M1PWM4		
 // PORT_PF0_PhA0			
 // PORT_PF0_T0CCP0		
 // PORT_PF0_NMI			
 // PORT_PF0_C0o          		//PF0 
  

 ***********PF1 modes***************
 // PORT_PF1_DIO			
 // PORT_PF1_U1CTS			
 // PORT_PF1_SSI1Tx		
 // PORT_PF1_M1PWM5		
 // PORT_PF1_PhB0			
 // PORT_PF1_T0CCP1 		
 // PORT_PF1_C1o			
 // PORT_PF1_TRD1			           //PF1 
  

 ***********PF2 modes***************
 // PORT_PF2_DIO			
 // PORT_PF2_SSI1Clk		
 // PORT_PF2_M0FAULT0		
 // PORT_PF2_M1PWM6		
 // PORT_PF2_T1CCP0		
 // PORT_PF2_TRD0           //PF2
  

 ***********PF3 modes***************
 // PORT_PF3_DIO			
 // PORT_PF3_SSI1Fss		
 // PORT_PF3_CAN0Tx		
 // PORT_PF3_M1PWM7		
 // PORT_PF3_T1CCP1 		
 // PORT_PF3_TRCLK              //PF3 
 
  
 ***********PF4 modes***************
 // PORT_PF4_DIO			
 // PORT_PF4_M1FAULT0			
 // PORT_PF4_IDX0			
 // PORT_PF4_T2CCP0		
 // PORT_PF4_USB0EPEN                 //PF4 
 
 
 
**************************************************************************/
 
/************ USE THIS IN portPinDirection configuration in Port_Lcfg*******

 //Defining the direction types 
 //portPinDirection
 
 // PORT_INPUT 	
 // PORT_OUTPUT	
 // PORT_NA		
 ******************************************************************************************************/

/************ USE THIS IN portInitialValueIfOutput configuration in Port_Lcfg***********
//defining the level if output, if not configured as output use NA
//portInitialValueIfOutput

 // PORT_LOW 	
 // PORT_HIGH 
 // PORT_NA
 ******************************************************************************************************/

/************ USE THIS IN portOutputCurrent configuration in Port_Lcfg***********

 //defining the outputcurrent configuration
 /portOutputCurrent
 
 // PORT_OCURRENT_2mA	
 // PORT_OCURRENT_4mA	
 // PORT_OCURRENT_8mA	
 //	PORT_NA
 ******************************************************************************************************/

/************ USE THIS IN portPinResistorAttchIfInput configuration in Port_Lcfg***********

 //defining the attached resistor mode configuration
//portPinResistorAttchIfInput


 // PORT_ATTACH_PULL_UP_RESISTOR	
 // PORT_ATTACH_PULL_DOWN_RESISTOR	
 // PORT_ATTACH_OPEN_DRAIN			
 //	PORT_NA
*****************************************************************************/


 
 
 
 
 
 
#endif  /* PORT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/
