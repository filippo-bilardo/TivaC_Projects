//==================================================================================================
//       _____   ____
//      |  ___| |  _ \
//      | |_    | |_| |
//      |  _|   |  _ /
//	    | |     | |_| |
//	www.|_|     |_____/-labs.blogspot.it
//
// Filename:    hwconfig.h
// Description: Hardware abstraction layer for LM4F120
//    
// Open Source Licensing 
//
// This program is free software: you can redistribute it and/or modify it under the terms of 
// the GNU General Public License as published by the Free Software Foundation, either version 3 
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,but WITHOUT ANY WARRANTY; without
// even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along with this program.  
// If not, see <http://www.gnu.org/licenses/>.
//
// Author:	Filippo Bilardo
//
// Ver		Date   		Comment
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// 1.0.0	12.11.12	Initial version
//
//==================================================================================================

// MOTBOARD_A10  HARDWARE
//
#define USE_MOTBOARD_A11
#ifdef USE_MOTBOARD_A11
#define USE_MTR_CONTROLLER1
#define USE_MTR_CONTROLLER2
#undef RED_LED_PIN

#define MTR_STBY_PIN				0x10	//J1.05 PE4 59 AIN9 U5Rx - I2C2SCL - CAN0Rx - -
#define MTR_DX_PWM_PIN				0x20	//J1.02 PB5 57 AIN11 - SSI2Fss - T1CCP1 CAN0Tx - -
#define MTR_DX_DIR1_PIN				0x02	//J1.04 PB1 46 - U1Tx - - T2CCP1 - - -
#define MTR_DX_DIR2_PIN				0x01	//J1.03 PB0 45 - U1Rx - - T2CCP0 - - -
#define MTR_SX_PWM_PIN				0x10	//J1.07 PB4 58 AIN10 - SSI2Clk - T1CCP0 CAN0Rx - -
#define MTR_SX_DIR1_PIN				0x20	//J1.06 PE5 60 AIN8 U5Tx - I2C2SDA - CAN0Tx - -
#define MTR_SX_DIR2_PIN				0x20	//J1.08 PA5 22 - - SSI0Tx - - - - -

#define IR_SX_PIN					0x40	//J1.09 PA6 23 - - - I2C1SCL - - - -
#define IR_CENTER_PIN				0x80	//J1.10 PA7 24 - - - I2C1SDA - - - -
#define IR_DX_PIN					0x02	//J3.10 PF1 29 - U1CTS SSI1Tx - T0CCP1 - C1o TD1

#define US_SX_TRIG_PIN				0x04	//J3.08 PE2 7 AIN1 - - - - - - -
#define US_SX_ECHO_PIN				0x02	//J3.07 PE1 8 AIN2 U7Tx - - - - - -
#define US_DX_TRIG_PIN				0x02	//J3.04 PD1 62 AIN6 SSI3Fss SSI1Fss I2C3SDA WT2CCP1 - - -
#define US_DX_ECHO_PIN				0x01	//J3.03 PD0 61 AIN7 SSI3Clk SSI1Clk I2C3SCL WT2CCP0 - - -
#define US_CNTR_TRIG_PIN			0x08	//J3.06 PD3 64 AIN4 SSI3Tx SSI1Tx - WT3CCP1 - - -
#define US_CNTR_ECHO_PIN			0x04	//J3.05 PD2 63 AIN5 SSI3Rx SSI1Rx - WT3CCP0 - - -

#define BAFFI_PIN					0x08	//J3.09 PE3 6 AIN0 - - - - - - -

#define US_SX_TRIG_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOE
#define US_SX_TRIG_PORT_DIR_R		GPIO_PORTE_DIR_R
#define US_SX_TRIG_PORT_AFSEL_R		GPIO_PORTE_AFSEL_R
#define US_SX_TRIG_PORT_DEN_R		GPIO_PORTE_DEN_R
#define US_SX_TRIG_PORT_AMSEL_R		GPIO_PORTE_AMSEL_R
#define US_SX_TRIG_PORT_DATA_R		GPIO_PORTE_DATA_R
#define US_SX_TRIG_PORT_PCTL_R		GPIO_PORTE_PCTL_R
#define US_SX_TRIG_PORT_PUR_R		GPIO_PORTE_PUR_R
#define US_SX_TRIG_PORT_PDR_R		GPIO_PORTE_PDR_R
#define US_SX_ECHO_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOE
#define US_SX_ECHO_PORT_DIR_R		GPIO_PORTE_DIR_R
#define US_SX_ECHO_PORT_AFSEL_R		GPIO_PORTE_AFSEL_R
#define US_SX_ECHO_PORT_DEN_R		GPIO_PORTE_DEN_R
#define US_SX_ECHO_PORT_AMSEL_R		GPIO_PORTE_AMSEL_R
#define US_SX_ECHO_PORT_DATA_R		GPIO_PORTE_DATA_R
#define US_SX_ECHO_PORT_PCTL_R		GPIO_PORTE_PCTL_R
#define US_SX_ECHO_PORT_PUR_R		GPIO_PORTE_PUR_R
#define US_SX_ECHO_PORT_PDR_R		GPIO_PORTE_PDR_R

#define US_CNTR_TRIG_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOD
#define US_CNTR_TRIG_PORT_DIR_R		GPIO_PORTD_DIR_R
#define US_CNTR_TRIG_PORT_AFSEL_R	GPIO_PORTD_AFSEL_R
#define US_CNTR_TRIG_PORT_DEN_R		GPIO_PORTD_DEN_R
#define US_CNTR_TRIG_PORT_AMSEL_R	GPIO_PORTD_AMSEL_R
#define US_CNTR_TRIG_PORT_DATA_R	GPIO_PORTD_DATA_R
#define US_CNTR_TRIG_PORT_PCTL_R	GPIO_PORTD_PCTL_R
#define US_CNTR_TRIG_PORT_PUR_R		GPIO_PORTD_PUR_R
#define US_CNTR_TRIG_PORT_PDR_R		GPIO_PORTD_PDR_R
#define US_CNTR_ECHO_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOD
#define US_CNTR_ECHO_PORT_DIR_R		GPIO_PORTD_DIR_R
#define US_CNTR_ECHO_PORT_AFSEL_R	GPIO_PORTD_AFSEL_R
#define US_CNTR_ECHO_PORT_DEN_R		GPIO_PORTD_DEN_R
#define US_CNTR_ECHO_PORT_AMSEL_R	GPIO_PORTD_AMSEL_R
#define US_CNTR_ECHO_PORT_DATA_R	GPIO_PORTD_DATA_R
#define US_CNTR_ECHO_PORT_PCTL_R	GPIO_PORTD_PCTL_R
#define US_CNTR_ECHO_PORT_PUR_R		GPIO_PORTD_PUR_R
#define US_CNTR_ECHO_PORT_PDR_R		GPIO_PORTD_PDR_R
#define US_DX_TRIG_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOD
#define US_DX_TRIG_PORT_DIR_R		GPIO_PORTD_DIR_R
#define US_DX_TRIG_PORT_AFSEL_R		GPIO_PORTD_AFSEL_R
#define US_DX_TRIG_PORT_DEN_R		GPIO_PORTD_DEN_R
#define US_DX_TRIG_PORT_AMSEL_R		GPIO_PORTD_AMSEL_R
#define US_DX_TRIG_PORT_DATA_R		GPIO_PORTD_DATA_R
#define US_DX_TRIG_PORT_PCTL_R		GPIO_PORTD_PCTL_R
#define US_DX_TRIG_PORT_PUR_R		GPIO_PORTD_PUR_R
#define US_DX_TRIG_PORT_PDR_R		GPIO_PORTD_PDR_R
#define US_DX_ECHO_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOD
#define US_DX_ECHO_PORT_DIR_R		GPIO_PORTD_DIR_R
#define US_DX_ECHO_PORT_AFSEL_R		GPIO_PORTD_AFSEL_R
#define US_DX_ECHO_PORT_DEN_R		GPIO_PORTD_DEN_R
#define US_DX_ECHO_PORT_AMSEL_R		GPIO_PORTD_AMSEL_R
#define US_DX_ECHO_PORT_DATA_R		GPIO_PORTD_DATA_R
#define US_DX_ECHO_PORT_PCTL_R		GPIO_PORTD_PCTL_R
#define US_DX_ECHO_PORT_PUR_R		GPIO_PORTD_PUR_R
#define US_DX_ECHO_PORT_PDR_R		GPIO_PORTD_PDR_R

#define MTR_STBY_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOE
#define MTR_STBY_PORT_DIR_R			GPIO_PORTE_DIR_R
#define MTR_STBY_PORT_AFSEL_R		GPIO_PORTE_AFSEL_R
#define MTR_STBY_PORT_DEN_R			GPIO_PORTE_DEN_R
#define MTR_STBY_PORT_AMSEL_R		GPIO_PORTE_AMSEL_R
#define MTR_STBY_PORT_DATA_R		GPIO_PORTE_DATA_R
#define MTR_STBY_PORT_PCTL_R		GPIO_PORTE_PCTL_R

//CONTROLLER1
#define MTR_DX_PWM_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOB
#define MTR_DX_PWM_PORT_DIR_R		GPIO_PORTB_DIR_R
#define MTR_DX_PWM_PORT_AFSEL_R		GPIO_PORTB_AFSEL_R
#define MTR_DX_PWM_PORT_DEN_R		GPIO_PORTB_DEN_R
#define MTR_DX_PWM_PORT_AMSEL_R		GPIO_PORTB_AMSEL_R
#define MTR_DX_PWM_PORT_DATA_R		GPIO_PORTB_DATA_R
#define MTR_DX_DIR1_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOB
#define MTR_DX_DIR1_PORT_DIR_R		GPIO_PORTB_DIR_R
#define MTR_DX_DIR1_PORT_AFSEL_R	GPIO_PORTB_AFSEL_R
#define MTR_DX_DIR1_PORT_DEN_R		GPIO_PORTB_DEN_R
#define MTR_DX_DIR1_PORT_AMSEL_R	GPIO_PORTB_AMSEL_R
#define MTR_DX_DIR1_PORT_DATA_R		GPIO_PORTB_DATA_R
#define MTR_DX_DIR2_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOB
#define MTR_DX_DIR2_PORT_DIR_R		GPIO_PORTB_DIR_R
#define MTR_DX_DIR2_PORT_AFSEL_R	GPIO_PORTB_AFSEL_R
#define MTR_DX_DIR2_PORT_DEN_R		GPIO_PORTB_DEN_R
#define MTR_DX_DIR2_PORT_AMSEL_R	GPIO_PORTB_AMSEL_R
#define MTR_DX_DIR2_PORT_DATA_R		GPIO_PORTB_DATA_R

//CONTROLLER2
#define MTR_SX_PWM_SYSCTL_RCGC2		SYSCTL_RCGC2_GPIOB
#define MTR_SX_PWM_PORT_DIR_R		GPIO_PORTB_DIR_R
#define MTR_SX_PWM_PORT_AFSEL_R		GPIO_PORTB_AFSEL_R
#define MTR_SX_PWM_PORT_DEN_R		GPIO_PORTB_DEN_R
#define MTR_SX_PWM_PORT_AMSEL_R		GPIO_PORTB_AMSEL_R
#define MTR_SX_PWM_PORT_DATA_R		GPIO_PORTB_DATA_R
#define MTR_SX_DIR1_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOE
#define MTR_SX_DIR1_PORT_DIR_R		GPIO_PORTE_DIR_R
#define MTR_SX_DIR1_PORT_AFSEL_R	GPIO_PORTE_AFSEL_R
#define MTR_SX_DIR1_PORT_DEN_R		GPIO_PORTE_DEN_R
#define MTR_SX_DIR1_PORT_AMSEL_R	GPIO_PORTE_AMSEL_R
#define MTR_SX_DIR1_PORT_DATA_R		GPIO_PORTE_DATA_R
#define MTR_SX_DIR2_SYSCTL_RCGC2	SYSCTL_RCGC2_GPIOA
#define MTR_SX_DIR2_PORT_DIR_R		GPIO_PORTA_DIR_R
#define MTR_SX_DIR2_PORT_AFSEL_R	GPIO_PORTA_AFSEL_R
#define MTR_SX_DIR2_PORT_DEN_R		GPIO_PORTA_DEN_R
#define MTR_SX_DIR2_PORT_AMSEL_R	GPIO_PORTA_AMSEL_R
#define MTR_SX_DIR2_PORT_DATA_R		GPIO_PORTA_DATA_R

#endif
//*****************************************************************************
