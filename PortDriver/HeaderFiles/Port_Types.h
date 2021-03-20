/**********************************************************************************************************************

*  FILE DESCRIPTION
*  -------------------------------------------------------------------------------------------------------------------
*         File:  <Port_Types.h>
*       Module:  Port
*
*  Description:  <Write File DESCRIPTION here>     
*  
*********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H


/**********************************************************************************************************************
*  GLOBAL CONSTANT MACROS
*********************************************************************************************************************/

/* Defining the Module software verison by Major.Minor.Patch format */
#define PORT_TYPES_SW_MAJOR_VERSION				(1U)
#define PORT_TYPES_SW_MINOR_VERSION				(0U)
#define PORT_TYPES_SW_PATCH_VERSION				(0U)

/* Defining the autosar version ued for the module */
#define PORT_TYPES_AR_RELEASE_MAJOR_VERSION		(4U)
#define PORT_TYPES_AR_RELEASE_MINOR_VERSION		(0U)
#define PORT_TYPES_AR_RELEASE_PATCH_VERSION		(3U)



/***************** TYPEDEFINITIONS FOR PORT DRIVER ******************/


/*Definitions to enable and disable port clocks*/
#define PORT_ENABLE	(0U)
#define PORT_DISABLE	(1U)




/*Type definition for the pin configuration type */ 
typedef uint8 Port_PinType;
typedef uint8 Port_PinModeType;


/*Definition for pin direction configuration*/
typedef enum
{
  PORT_PIN_IN,
  PORT_PIN_OUT
}Port_PinDirectionType;


/*Type definition for port types and their allowed values */
typedef uint8 	Port_PortType;

#define PORT_PORT_A	                 	((Port_PortType) 0x00)	         //PORTA
#define PORT_PORT_B                     ((Port_PortType) 0x01)          //PORTB
#define PORT_PORT_C                     ((Port_PortType) 0x02)          //PORTC
#define PORT_PORT_D                     ((Port_PortType) 0x03)          //PORTD
#define PORT_PORT_E                     ((Port_PortType) 0x04)          //PORTE
#define PORT_PORT_F                     ((Port_PortType) 0x05)          //PORTF



/*Definition for Port pin configurations structure*/
typedef struct 

{
  Port_PinType                    PortConfigPinNumber;
  Port_PortType	                  PortConfigPortNumber;
  Port_PinModeType                PortPinMode;
  Port_PinDirectionType           PortPinDirection;
  uint8                           PortPinLevelValue;
  uint8                           PortOutputCurrent;
  uint8                           PortPinResistorAttchIfInput;
  boolean  		      	  PortPinDirectionChangeable;
  boolean			  PortPinModeChangeable;			
  
}Port_PinConfigType;



/*Definition for port configurations structure*/
typedef struct
{
  Port_PinConfigType ConfiguredPinsArray[PORT_NUMBER_OF_CONFIGURED_PINS];
}Port_ConfigType;



/*state before Port_Init() is not called*/
#define PORT_NOT_INITIALIZED             (0U)
/*state after Port_Init() is called*/
#define PORT_INITIALIZED                 (1U)

/*Port pins allowed values for current MCU*/
#define	PORT_PIN_A_0 			((Port_PinType) 0x00)		//PIN0
#define	PORT_PIN_A_1 			((Port_PinType) 0x01)     	//PIN1
#define	PORT_PIN_A_2 			((Port_PinType) 0x02)     	//PIN2
#define	PORT_PIN_A_3 			((Port_PinType) 0x03)     	//PIN3
#define	PORT_PIN_A_4 			((Port_PinType) 0x04)     	//PIN4
#define	PORT_PIN_A_5 			((Port_PinType) 0x05)     	//PIN5
#define	PORT_PIN_A_6 			((Port_PinType) 0x06)     	//PIN6
#define	PORT_PIN_A_7 			((Port_PinType) 0x07)     	//PIN7
#define	PORT_PIN_B_0 			((Port_PinType) 0x00)     	//PIN8
#define	PORT_PIN_B_1 			((Port_PinType) 0x01)     	//PIN9
#define	PORT_PIN_B_2 			((Port_PinType) 0x02)     	//PIN10
#define	PORT_PIN_B_3 			((Port_PinType) 0x03)     	//PIN11
#define	PORT_PIN_B_4 			((Port_PinType) 0x04)     	//PIN12
#define	PORT_PIN_B_5 			((Port_PinType) 0x05)     	//PIN13
#define	PORT_PIN_B_6 			((Port_PinType) 0x06)     	//PIN14
#define	PORT_PIN_B_7 			((Port_PinType) 0x07)     	//PIN15
#define	PORT_PIN_C_0 			((Port_PinType) 0x00)     	//PIN16
#define	PORT_PIN_C_1 			((Port_PinType) 0x01)     	//PIN17
#define	PORT_PIN_C_2 			((Port_PinType) 0x02)     	//PIN18
#define	PORT_PIN_C_3 			((Port_PinType) 0x03)     	//PIN19
#define	PORT_PIN_C_4 			((Port_PinType) 0x04)     	//PIN20
#define	PORT_PIN_C_5 			((Port_PinType) 0x05)     	//PIN21
#define	PORT_PIN_C_6 			((Port_PinType) 0x06)     	//PIN22
#define	PORT_PIN_C_7 			((Port_PinType) 0x07)     	//PIN23
#define	PORT_PIN_D_0 			((Port_PinType) 0x00)     	//PIN24
#define	PORT_PIN_D_1 			((Port_PinType) 0x01)     	//PIN25
#define	PORT_PIN_D_2 			((Port_PinType) 0x02)     	//PIN26
#define	PORT_PIN_D_3 			((Port_PinType) 0x03)     	//PIN27
#define	PORT_PIN_D_4 			((Port_PinType) 0x04)     	//PIN28
#define	PORT_PIN_D_5 			((Port_PinType) 0x05)     	//PIN29
#define	PORT_PIN_D_6 			((Port_PinType) 0x06)     	//PIN30
#define	PORT_PIN_D_7 			((Port_PinType) 0x07)     	//PIN31
#define	PORT_PIN_E_0 			((Port_PinType) 0x00)     	//PIN32
#define	PORT_PIN_E_1 			((Port_PinType) 0x01)     	//PIN33
#define	PORT_PIN_E_2 			((Port_PinType) 0x02)     	//PIN34
#define	PORT_PIN_E_3 			((Port_PinType) 0x03)     	//PIN35
#define	PORT_PIN_E_4 			((Port_PinType) 0x04)     	//PIN36
#define	PORT_PIN_E_5 			((Port_PinType) 0x05)     	//PIN37
#define	PORT_PIN_F_0 			((Port_PinType) 0x00)     	//PIN38 
#define	PORT_PIN_F_1 			((Port_PinType) 0x01)     	//PIN39
#define	PORT_PIN_F_2 			((Port_PinType) 0x02)     	//PIN40
#define	PORT_PIN_F_3 			((Port_PinType) 0x03)     	//PIN41
#define	PORT_PIN_F_4 			((Port_PinType) 0x04)     	//PIN42





/*Value for not applicable configurations*/ 
#define PORT_NA			9



/**defining the outputcurrent configuration**/
/* Output current 2mA */
#define PORT_OCURRENT_2_MA	(00U)   
/* Output current 4mA */
#define PORT_OCURRENT_4_MA	(01U)
/* Output current 8mA */
#define PORT_OCURRENT_8_MA	(02U)
//HINT: you can choose NA configuration here as well


/**defining the attached resistor mode configuration**/ 
/* Pull up resistor is attached configuration */
#define PORT_ATTACH_PULL_UP_RESISTOR	        (00U)
/* Pull down resistor is attached configuration */
#define PORT_ATTACH_PULL_DOWN_RESISTOR	        (01U)
/* pin is open drain configuration */
#define PORT_ATTACH_OPEN_DRAIN			(02U)
//HINT: you can choose NA configuration here as well



/******************************************************************************************************
defining each pin mode configuration, below section contains all possible configurations for each pin
*****************************************************************************************************/
/**********General Mode*********/
#define PORT_PINx_DIO				(00U)
#define PORT_PINx_ANALOG_FUNC		        (16U)
/***********PA0 modes**********/
#define PORT_PA0_DIO				(00U)
#define PORT_PA0_U0Rx				(01U)
#define PORT_PA0_CAN1Rx				(08U)
/***********PA1 modes**********/                     
#define PORT_PA1_DIO				(00U)
#define PORT_PA1_U0Tx				(01U)
#define PORT_PA1_CAN1Tx    			(08U)         	//PA1 
/***********PA2 modes**********/                     
#define PORT_PA2_DIO				(00U)
#define PORT_PA2_SSI0Clk  			(02U)         	//PA2 
/***********PA3 modes**********/                     
#define PORT_PA3_DIO				(00U)
#define PORT_PA3_SSI0Fss  			(02U)          	//PA3 
/***********PA4 modes**********/                     
#define PORT_PA4_DIO				(00U)
#define PORT_PA4_SSI0Rx   			(02U)         	//PA4 
/***********PA5 modes**********/                     
#define PORT_PA5_DIO				(00U)
#define PORT_PA5_SSI0Tx  			(02U)         	//PA5 
/***********PA6 modes**********/                     
#define PORT_PA6_DIO				(00U)
#define PORT_PA6_I2C1SCL			(03U)
#define PORT_PA6_M1PWM2  			(05U)     	//PA6 
/***********PA7 modes**********/                     
#define PORT_PA7_DIO				(00U)
#define PORT_PA7_I2C1SDA			(03U)
#define PORT_PA7_M1PWM3  			(05U)     	//PA7 
/***********PB0 modes**********/                     
#define PORT_PB0_DIO				(00U)
#define PORT_PB0_USB0ID				(16U)
#define PORT_PB0_U1Rx				(01U)
#define PORT_PB0_T2CCP0    			(07U)           //PB0 
/***********PB1 modes**********/                     
#define PORT_PB1_DIO				(00U)
#define PORT_PB1_USB0VBUS			(16U)
#define PORT_PB1_U1Tx				(01U)
#define PORT_PB1_T2CCP1     		        (07U)           //PB1 
/***********PB2 modes**********/                     
#define PORT_PB2_DIO				(00U)
#define PORT_PB2_I2C0SCL			(03U)
#define PORT_PB2_T3CCP0    			(07U)           //PB2 
/***********PB3 modes**********/                     
#define PORT_PB3_DIO				(00U)
#define PORT_PB3I2C0SDA				(03U)
#define PORT_PB3T3CCP1			        (07U)          //PB3 
/***********PB4 modes**********/                     
#define PORT_PB4_DIO				(00U)
#define PORT_PB4_AIN10				(16U)
#define PORT_PB4_SSI2Clk			(02U)
#define PORT_PB4_M0PWM2				(04U)
#define PORT_PB4_T1CCP0				(07U)
#define PORT_PB4_CAN0Rx				(08U)           //PB4 
/***********PB5 modes**********/                     
#define PORT_PB5_DIO				(00U)
#define PORT_PB5_AIN11				(16U)
#define PORT_PB5_SSI2Fss			(02U)
#define PORT_PB5_M0PWM3				(04U)
#define PORT_PB5_T1CCP1				(07U)
#define PORT_PB5_CAN0Tx				(08U)           //PB5 
/***********PB6 modes**********/                     
#define PORT_PB6_DIO				(0U) 
#define PORT_PB6_SSI2Rx				(2U) 
#define PORT_PB6_M0PWM0				(4U) 
#define PORT_PB6_T0CCP0         	        (7U)            //PB6 
/***********PB7 modes**********/                     
#define PORT_PB7_DIO				(0U) 
#define PORT_PB7_SSI2Tx				(2U) 
#define PORT_PB7_M0PWM1				(4U) 
#define PORT_PB7_T0CCP1        		        (7U)            //PB7 
/***********PC0 modes**********/                     
#define PORT_PC0_DIO				(00U)
#define PORT_PC0_TCKSWCLK			(01U)
#define PORT_PC0_T4CCP0     		        (07U)           //PC0 	
/***********PC1 modes**********/                     
#define PORT_PC1_DIO				(0U) 
#define PORT_PC1_TMSSWDIO			(1U) 
#define PORT_PC1_T4CCP1     	                (7U)            //PC1 
/***********PC2 modes**********/                     
#define PORT_PC2_DIO				(00U)
#define PORT_PC2_TDI				(01U)
#define PORT_PC2_T5CCP0     	                (07U)           //PC2 
/***********PC3 modes**********/                     
#define PORT_PC3_DIO				(00U)
#define PORT_PC3_TDOSWO				(01U)
#define PORT_PC3_T5CCP1     	                (07U)           //PC3 		
/***********PC4 modes**********/                     
#define PORT_PC4_DIO				(00U)
#define PORT_PC4_C1_NEG				(16U)
#define PORT_PC4_U4Rx 				(01U)
#define PORT_PC4_U1Rx				(02U)
#define PORT_PC4_M0PWM6				(04U)
#define PORT_PC4_IDX1				(06U)
#define PORT_PC4_WT0CCP0			(07U)
#define PORT_PC4_U1RTS         		        (08U)           //PC4 	
/***********PC5 modes**********/                     
#define PORT_PC5_DIO				(00U)
#define PORT_PC5_C1_POS				(16U)
#define PORT_PC5_U4Tx				(01U)
#define PORT_PC5_U1Tx				(02U)
#define PORT_PC5_M0PWM7				(04U)
#define PORT_PC5_PhA1				(06U)
#define PORT_PC5_WT0CCP1			(07U)
#define PORT_PC5_U1CTS         		        (08U)           //PC5 
/***********PC6 modes**********/                     
#define PORT_PC6_DIO				(00U)
#define PORT_PC6_C0_POS				(16U)
#define PORT_PC6_U3Rx				(01U)
#define PORT_PC6_PhB1				(06U)
#define PORT_PC6_WT1CCP0			(07U)
#define PORT_PC6_USB0EPEN       	        (08U)           //PC6 
/***********PC7 modes**********/                     
#define PORT_PC7_DIO				(00U)
#define PORT_PC7_C0_NEG 			(16U)
#define PORT_PC7_U3Tx				(01U)
#define PORT_PC7_WT1CCP1			(07U)
#define PORT_PC7_USB0PFLT      		        (08U)           //PC7 
/***********PD0 modes**********/                     
#define PORT_PD0_DIO				(00U)
#define PORT_PD0_AIN7				(16U)
#define PORT_PD0_SSI3Clk			(01U)
#define PORT_PD0_SSI1Clk			(02U)
#define PORT_PD0_I2C3SCL			(03U)
#define PORT_PD0_M0PWM6				(04U)
#define PORT_PD0_M1PWM0				(05U)
#define PORT_PD0_WT2CCP0  			(07U)           //PD0 
/***********PD1 modes**********/                     
#define PORT_PD1_DIO			        (00U)
#define PORT_PD1_AIN6			        (16U)
#define PORT_PD1_SSI3Fss		        (01U)
#define PORT_PD1_SSI1Fss		        (02U)
#define PORT_PD1_I2C3SDA		        (03U)
#define PORT_PD1_M0PWM7			        (04U)
#define PORT_PD1_M1PWM1			        (05U)
#define PORT_PD1_WT2CCP1 		        (07U)           //PD1 
/***********PD2 modes**********/                     
#define PORT_PD2_DIO			        (00U)
#define PORT_PD2_AIN5			        (16U)
#define PORT_PD2_SSI3Rx 		        (01U)
#define PORT_PD2_SSI1Rx			        (02U)
#define PORT_PD2_M0FAULT0		        (04U)
#define PORT_PD2_WT3CCP0		        (07U)
#define PORT_PD2_USB0EPEN		        (08U)           //PD2 		 
/***********PD3 modes**********/                     
#define PORT_PD3_DIO			        (00U)
#define PORT_PD3_AIN4			        (16U)
#define PORT_PD3_SSI3Tx			        (01U)
#define PORT_PD3_SSI1Tx			        (02U)
#define PORT_PD3_IDX0			        (04U)
#define PORT_PD3_WT3CCP1		        (07U)
#define PORT_PD3_USB0PFLT                       (08U)           //PD3 
/***********PD4 modes**********/                     
#define PORT_PD4_DIO			        (00U)
#define PORT_PD4_USB0DM			        (16U)
#define PORT_PD4_U6Rx			        (01U)
#define PORT_PD4_WT4CCP0                        (07U)           //PD4 
/***********PD5 modes**********/                     
#define PORT_PD5_DIO			        (00U)
#define PORT_PD5_USB0DP 		        (16U)
#define PORT_PD5_U6Tx 			        (01U)
#define PORT_PD5_WT4CCP1                        (07U)           //PD5 
/***********PD6 modes**********/                     
#define PORT_PD6_DIO			        (00U)
#define PORT_PD6_U2Rx			        (02U)
#define PORT_PD6_M0FAULT0		        (05U)
#define PORT_PD6_PhA0			        (06U)
#define PORT_PD6_WT5CCP0                        (07U)           //PD6 
/***********PD7 modes**********/                     
#define PORT_PD7_DIO			        (00U)
#define PORT_PD7_U2Tx			        (02U)
#define PORT_PD7_PhB0			        (06U)
#define PORT_PD7_WT5CCP1		        (07U)
#define PORT_PD7_NMI                            (08U)          //PD7 
/***********PE0 modes**********/                     
#define PORT_PE0_DIO			        (00U)
#define PORT_PE0_AIN3			        (16U)
#define PORT_PE0_U7Rx                           (01U)           //PE0 
/***********PE1 modes**********/                     
#define PORT_PE1_DIO			        (00U)
#define PORT_PE1_AIN2			        (16U)
#define PORT_PE1_U7Tx                           (01U)           //PE1 
/***********PE2 modes**********/                     
#define PORT_PE2_DIO			        (00U)
#define PORT_PE2_AIN1			        (16U)           //PE2 
/***********PE3 modes**********/                     
#define PORT_PE3_DIO			        (00U)
#define PORT_PE3_AIN0                           (16U)           //PE3  
/***********PE4 modes**********/                     
#define PORT_PE4_DIO			        (00U)
#define PORT_PE4_AIN9			        (16U)
#define PORT_PE4_U5Rx			        (01U)
#define PORT_PE4_I2C2SCL		        (03U)
#define PORT_PE4_M0PWM4			        (04U)
#define PORT_PE4_M1PWM2			        (05U)
#define PORT_PE4_CAN0Rx                         (08U)           //PE4 	 
/***********PE5 modes**********/                     
#define PORT_PE5_DIO			        (00U)
#define PORT_PE5_AIN8			        (16U)
#define PORT_PE5_U5Tx			        (01U)
#define PORT_PE5_I2C2SDA		        (03U)
#define PORT_PE5_M0PWM5			        (04U)
#define PORT_PE5_M1PWM3			        (05U)
#define PORT_PE5_CAN0Tx                         (08U)           //PE5 
/***********PF0 modes**********/                     
#define PORT_PF0_DIO			        (00U)
#define PORT_PF0_U1RTS			        (01U)
#define PORT_PF0_SSI1Rx			        (02U)
#define PORT_PF0_CAN0Rx			        (03U)
#define PORT_PF0_M1PWM4			        (05U)
#define PORT_PF0_PhA0			        (06U)
#define PORT_PF0_T0CCP0			        (07U)
#define PORT_PF0_NMI			        (08U)
#define PORT_PF0_C0o          	                (09U)           //PF0 
/***********PF1 modes**********/                     
#define PORT_PF1_DIO			        (00U)
#define PORT_PF1_U1CTS			        (01U)
#define PORT_PF1_SSI1Tx			        (02U)
#define PORT_PF1_M1PWM5			        (05U)
#define PORT_PF1_PhB0			        (06U)
#define PORT_PF1_T0CCP1 		        (07U)
#define PORT_PF1_C1o			        (09U)
#define PORT_PF1_TRD1			        (14U)           //PF1 
/***********PF2 modes**********/                     
#define PORT_PF2_DIO			        (00U)
#define PORT_PF2_SSI1Clk		        (02U)
#define PORT_PF2_M0FAULT0		        (04U)
#define PORT_PF2_M1PWM6			        (05U)
#define PORT_PF2_T1CCP0			        (07U)
#define PORT_PF2_TRD0                           (14U)           //PF2
/***********PF3 modes**********/                     
#define PORT_PF3_DIO			        (00U)
#define PORT_PF3_SSI1Fss		        (02U)
#define PORT_PF3_CAN0Tx			        (03U)
#define PORT_PF3_M1PWM7			        (05U)
#define PORT_PF3_T1CCP1 		        (07U)
#define PORT_PF3_TRCLK                          (14U)           //PF3 
/***********PF4 modes**********/                     
#define PORT_PF4_DIO			        (00U)
#define PORT_PF4_M1FAULT0		        (05U)
#define PORT_PF4_IDX0			        (06U)
#define PORT_PF4_T2CCP0			        (07U)
#define PORT_PF4_USB0EPEN                       (08U)           //PF4 



#endif  /* PORT_TYPES_H_ */

/**********************************************************************************************************************
*  END OF FILE: PORT_TYPES_H
*********************************************************************************************************************/
