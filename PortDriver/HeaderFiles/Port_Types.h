/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Port_Types.h>
 *       Module:  Port
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H_
#define PORT_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**Defining the direction types**/ 
#define PORT_INPUT 		0
#define PORT_OUTPUT		1
#define PORT_NA			9


/**defining the level if output, if not configured as output use NA**/
#define PORT_LOW 		0
#define PORT_HIGH 		1
//HINT: you can choose NA configuration here as well

/**defining the outputcurrent configuration**/
#define PORT_OCURRENT_2mA	0
#define PORT_OCURRENT_4mA	1
#define PORT_OCURRENT_8mA	2
//HINT: you can choose NA configuration here as well


/**defining the attached resistor mode configuration**/ 
#define PORT_ATTACH_PULL_UP_RESISTOR	0
#define PORT_ATTACH_PULL_DOWN_RESISTOR	1
#define PORT_ATTACH_OPEN_DRAIN			2
//HINT: you can choose NA configuration here as well

#define PORT_ENABLE		0
#define PORT_DISABLE	1


/******************************************************************************************************
defining each pin mode configuration, below section contains all possible configurations for each pin
/*****************************************************************************************************/
/**********General Mode*********/
#define PORT_PINx_DIO				0
#define PORT_PINx_ANALOG_FUNC		16

/***********PA0 modes**********/
#define PORT_PA0_DIO				0
#define PORT_PA0_U0Rx				1
#define PORT_PA0_CAN1Rx				8							//PA0 


/***********PA1 modes**********/
#define PORT_PA1_DIO				0
#define PORT_PA1_U0Tx				1
#define PORT_PA1_CAN1Tx    			8                         	//PA1 


/***********PA2 modes**********/
#define PORT_PA2_DIO				0
#define PORT_PA2_SSI0Clk  			2                          	//PA2 


/***********PA3 modes**********/
#define PORT_PA3_DIO				0
#define PORT_PA3_SSI0Fss  			2                          	//PA3 


/***********PA4 modes**********/
#define PORT_PA4_DIO				0
#define PORT_PA4_SSI0Rx   			2                         	//PA4 


/***********PA5 modes**********/
#define PORT_PA5_DIO				0
#define PORT_PA5_SSI0Tx  			2                         	//PA5 


/***********PA6 modes**********/
#define PORT_PA6_DIO				0
#define PORT_PA6_I2C1SCL			3
#define PORT_PA6_M1PWM2  			5                     		//PA6 


/***********PA7 modes**********/
#define PORT_PA7_DIO				0
#define PORT_PA7_I2C1SDA			3
#define PORT_PA7_M1PWM3  			5                     		//PA7 


/***********PB0 modes**********/
#define PORT_PB0_DIO				0
#define PORT_PB0_USB0ID				16
#define PORT_PB0_U1Rx				1
#define PORT_PB0_T2CCP0    			7              		       //PB0 
 

/***********PB1 modes**********/
#define PORT_PB1_DIO				0
#define PORT_PB1_USB0VBUS			16
#define PORT_PB1_U1Tx				1
#define PORT_PB1_T2CCP1     		7                     //PB1 


/***********PB2 modes**********/
#define PORT_PB2_DIO				0
#define PORT_PB2_I2C0SCL			3
#define PORT_PB2_T3CCP0    			7                        //PB2 


/***********PB3 modes**********/
#define PORT_PB3_DIO				0
#define PORT_PB3I2C0SDA				3
#define PORT_PB3T3CCP1			    7                          //PB3 


/***********PB4 modes**********/
#define PORT_PB4_DIO				0
#define PORT_PB4_AIN10				16
#define PORT_PB4_SSI2Clk			2
#define PORT_PB4_M0PWM2				4
#define PORT_PB4_T1CCP0				7
#define PORT_PB4_CAN0Rx				8               //PB4 


/***********PB5 modes**********/
#define PORT_PB5_DIO				0
#define PORT_PB5_AIN11				16
#define PORT_PB5_SSI2Fss			2
#define PORT_PB5_M0PWM3				4
#define PORT_PB5_T1CCP1				7
#define PORT_PB5_CAN0Tx				8               //PB5 


/***********PB6 modes**********/
#define PORT_PB6_DIO				0
#define PORT_PB6_SSI2Rx				2
#define PORT_PB6_M0PWM0				4
#define PORT_PB6_T0CCP0         	7                 //PB6 


/***********PB7 modes**********/
#define PORT_PB7_DIO				0
#define PORT_PB7_SSI2Tx				2
#define PORT_PB7_M0PWM1				4
#define PORT_PB7_T0CCP1        		7                //PB7 



/***********PC0 modes**********/
#define PORT_PC0_DIO				0
#define PORT_PC0_TCKSWCLK			1
#define PORT_PC0_T4CCP0     		7                    //PC0 
			
/***********PC1 modes**********/
#define PORT_PC1_DIO				0
#define PORT_PC1_TMSSWDIO			1
#define PORT_PC1_T4CCP1     	    7                            //PC1 
			

/***********PC2 modes**********/
#define PORT_PC2_DIO				0
#define PORT_PC2_TDI				1
#define PORT_PC2_T5CCP0     	    7                                 //PC2 
			

/***********PC3 modes**********/
#define PORT_PC3_DIO				0
#define PORT_PC3_TDOSWO				1
#define PORT_PC3_T5CCP1     	    7                                //PC3 
			

/***********PC4 modes**********/
#define PORT_PC4_DIO				0
#define PORT_PC4_C1_NEG				16
#define PORT_PC4_U4Rx 				1
#define PORT_PC4_U1Rx				2
#define PORT_PC4_M0PWM6				4
#define PORT_PC4_IDX1				6
#define PORT_PC4_WT0CCP0			7
#define PORT_PC4_U1RTS         		8    //PC4 
			

/***********PC5 modes**********/
#define PORT_PC5_DIO				0
#define PORT_PC5_C1_POS				16
#define PORT_PC5_U4Tx				1
#define PORT_PC5_U1Tx				2
#define PORT_PC5_M0PWM7				4
#define PORT_PC5_PhA1				6
#define PORT_PC5_WT0CCP1			7
#define PORT_PC5_U1CTS         		8     //PC5 
			

/***********PC6 modes**********/
#define PORT_PC6_DIO				0
#define PORT_PC6_C0_POS				16
#define PORT_PC6_U3Rx				1
#define PORT_PC6_PhB1				6
#define PORT_PC6_WT1CCP0			7
#define PORT_PC6_USB0EPEN       	8             //PC6 
			

/***********PC7 modes**********/
#define PORT_PC7_DIO				0
#define PORT_PC7_C0_NEG 			16
#define PORT_PC7_U3Tx				1
#define PORT_PC7_WT1CCP1			7
#define PORT_PC7_USB0PFLT      		8                //PC7 


/***********PD0 modes**********/
#define PORT_PD0_DIO				0
#define PORT_PD0_AIN7				16
#define PORT_PD0_SSI3Clk			1
#define PORT_PD0_SSI1Clk			2
#define PORT_PD0_I2C3SCL			3
#define PORT_PD0_M0PWM6				4
#define PORT_PD0_M1PWM0				5
#define PORT_PD0_WT2CCP0  			7  //PD0 
	
	
/***********PD1 modes**********/
#define PORT_PD1_DIO			0
#define PORT_PD1_AIN6			16
#define PORT_PD1_SSI3Fss		1
#define PORT_PD1_SSI1Fss		2
#define PORT_PD1_I2C3SDA		3
#define PORT_PD1_M0PWM7			4
#define PORT_PD1_M1PWM1			5
#define PORT_PD1_WT2CCP1 		7    //PD1 
			 

/***********PD2 modes**********/
#define PORT_PD2_DIO			0
#define PORT_PD2_AIN5			16
#define PORT_PD2_SSI3Rx 		1
#define PORT_PD2_SSI1Rx			2
#define PORT_PD2_M0FAULT0		4
#define PORT_PD2_WT3CCP0		7
#define PORT_PD2_USB0EPEN		8       //PD2 
			 

/***********PD3 modes**********/
#define PORT_PD3_DIO			0
#define PORT_PD3_AIN4			16
#define PORT_PD3_SSI3Tx			1
#define PORT_PD3_SSI1Tx			2
#define PORT_PD3_IDX0			4
#define PORT_PD3_WT3CCP1		7
#define PORT_PD3_USB0PFLT       8      //PD3 
			 

/***********PD4 modes**********/
#define PORT_PD4_DIO			0
#define PORT_PD4_USB0DM			16
#define PORT_PD4_U6Rx			1
#define PORT_PD4_WT4CCP0        7                   //PD4 
			 

/***********PD5 modes**********/
#define PORT_PD5_DIO			0
#define PORT_PD5_USB0DP 		16
#define PORT_PD5_U6Tx 			1
#define PORT_PD5_WT4CCP1        7                    //PD5 
			 

/***********PD6 modes**********/
#define PORT_PD6_DIO			0
#define PORT_PD6_U2Rx			2
#define PORT_PD6_M0FAULT0		5
#define PORT_PD6_PhA0			6
#define PORT_PD6_WT5CCP0        7               //PD6 
			 

/***********PD7 modes**********/
#define PORT_PD7_DIO			0
#define PORT_PD7_U2Tx			2
#define PORT_PD7_PhB0			6
#define PORT_PD7_WT5CCP1		7
#define PORT_PD7_NMI            8               //PD7 


/***********PE0 modes**********/
#define PORT_PE0_DIO			0
#define PORT_PE0_AIN3			16
#define PORT_PE0_U7Rx           1                         //PE0 
			 

/***********PE1 modes**********/
#define PORT_PE1_DIO			0
#define PORT_PE1_AIN2			16
#define PORT_PE1_U7Tx           1                        //PE1 
			 
			 
/***********PE2 modes**********/
#define PORT_PE2_DIO			0
#define PORT_PE2_AIN1			16                            //PE2 
			 

/***********PE3 modes**********/
#define PORT_PE3_DIO			0
#define PORT_PE3_AIN0           16                             //PE3 
			 

/***********PE4 modes**********/
#define PORT_PE4_DIO			0
#define PORT_PE4_AIN9			16
#define PORT_PE4_U5Rx			1
#define PORT_PE4_I2C2SCL		3
#define PORT_PE4_M0PWM4			4
#define PORT_PE4_M1PWM2			5
#define PORT_PE4_CAN0Rx         8     //PE4 
			 

/***********PE5 modes**********/
#define PORT_PE5_DIO			0
#define PORT_PE5_AIN8			16
#define PORT_PE5_U5Tx			1
#define PORT_PE5_I2C2SDA		3
#define PORT_PE5_M0PWM5			4
#define PORT_PE5_M1PWM3			5
#define PORT_PE5_CAN0Tx         8      //PE5 


/***********PF0 modes**********/
#define PORT_PF0_DIO			0
#define PORT_PF0_U1RTS			1
#define PORT_PF0_SSI1Rx			2
#define PORT_PF0_CAN0Rx			3
#define PORT_PF0_M1PWM4			5
#define PORT_PF0_PhA0			6
#define PORT_PF0_T0CCP0			7
#define PORT_PF0_NMI			8
#define PORT_PF0_C0o          	9		//PF0 


/***********PF1 modes**********/
#define PORT_PF1_DIO			0
#define PORT_PF1_U1CTS			1
#define PORT_PF1_SSI1Tx			2
#define PORT_PF1_M1PWM5			5
#define PORT_PF1_PhB0			6
#define PORT_PF1_T0CCP1 		7
#define PORT_PF1_C1o			9
#define PORT_PF1_TRD1			14              //PF1 


/***********PF2 modes**********/
#define PORT_PF2_DIO			0
#define PORT_PF2_SSI1Clk		2	
#define PORT_PF2_M0FAULT0		4
#define PORT_PF2_M1PWM6			5
#define PORT_PF2_T1CCP0			7
#define PORT_PF2_TRD0           14   //PF2


/***********PF3 modes**********/
#define PORT_PF3_DIO			0
#define PORT_PF3_SSI1Fss		2
#define PORT_PF3_CAN0Tx			3
#define PORT_PF3_M1PWM7			5
#define PORT_PF3_T1CCP1 		7
#define PORT_PF3_TRCLK          14       //PF3 


/***********PF4 modes**********/
#define PORT_PF4_DIO			0
#define PORT_PF4_M1FAULT0		5		
#define PORT_PF4_IDX0			6
#define PORT_PF4_T2CCP0			7
#define PORT_PF4_USB0EPEN       8              //PF4 


















/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


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

 
#endif  /* PORT_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: PORT_TYPES_H
 *********************************************************************************************************************/
