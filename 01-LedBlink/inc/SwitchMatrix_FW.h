/**
 \file		: SwitchMatrix_FW.h
 \brief     : Firmware functions for SWM
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/


#ifndef SWITCHMATRIX_FW_H_
#define SWITCHMATRIX_FW_H_

#define PINASSIGN	( ( __RW uint32_t *) 	0x4000C000UL)
/*
 * PINASSIGN[0:14]
 * 			BYTE0		BYTE1		BYTE3			BYTE4
 * [0]	:	UO_TXD,		U0_RXD,		UO_RTS,			UO_CTS
 * [1]	:	UO_SCLK,	U1_TXD,		U1_RXD,			U1_RTS
 * [2]	:	U1_CTS,		U0_SCLK,	U2_TXD,			UO_RXD
 * [3]	:	U2_RTS,		U2_CTS,		U2_SCLK,		SPIO_SCK
 * [4]	:	SPI0_MOSI, 	SPI0_MISO,	SPI0_SSEL0, 	SPI0_SSEL1
 * [5]	:	SPI0_SSEL2, SPI0_SSEL3,	SPI1_SCK, 		SPI1_MOSI
 * [6]	:	SPI1_MISO, 	SPI1_SSEL0,	SPI1_SSEL1, 	SCT0_IN0
 * [7]	:	SCT_IN1, 	SCT_IN2, 	SCT_IN3,		SCT_OUT0
 * [8]	:	SCT_OUT1, 	SCT_OUT2,	SCT_OUT3, 		SCT_OUT4
 * [9]	:	SCT_OUT5, 	SCT_OUT6,	I2C1_SDA, 		I2C1_SCL,
 * [10]	:	I2C2_SDA, 	I2C2_SCL, 	I2C3_SDA,		I2C3_SCL
 * [11]	:	COMP0_OUT, 	CLKOUT,		GPIO_INT_BMAT, 	UART3_TXD
 * [12]	:	UART3_RXD, 	UART3_SCLK,	UART4_TXD, 		UART4_RXD
 * [13]	:	UART4_SCLK, T0_MAT0,	T0_MAT1, 		T0_MAT2
 * [14]	:	 T0_MAT3, 	T0_CAP0, 	T0_CAP1,		T0_CAP2
 *
 */
void SWM(uint8_t port, uint8_t pin, uint8_t assign, uint8_t byte);
enum {
	BYTE0, BYTE1, BYTE2, BYTE3
};
enum {			//!< Possible assign
	UO_TXD,
	UO_SCLK,
	U1_CTS,
	U2_RTS,
	SPI0_MOSI,
	SPI0_SSEL2,
	SPI1_MISO,
	SCT_IN1,
	SCT_OUT1,
	SCT_OUT5,
	I2C2_SDA,
	COMP0_OUT,
	UART3_RXD,
	UART4_SCLK,
	T0_MAT3
};

enum {			//!< Possible assign
	U0_RXD,
	U1_TXD,
	U0_SCLK,
	U2_CTS,
	SPI0_MISO,
	SPI0_SSEL3,
	SPI1_SSEL0,
	SCT_IN2,
	SCT_OUT2,
	SCT_OUT6,
	I2C2_SCL,
	CLKOUT,
	UART3_SCLK,
	T0_MAT0,
	T0_CAP0
};

enum {			//!< Possible assign
	UO_RTS,
	U1_RXD,
	U2_TXD,
	U2_SCLK,
	SPI0_SSEL0,
	SPI1_SCK,
	SPI1_SSEL1,
	SCT_IN3,
	SCT_OUT3,
	I2C1_SDA,
	I2C3_SDA,
	GPIO_INT_BMAT,
	UART4_TXD,
	T0_MAT1,
	T0_CAP1
};

enum {			//!< Possible assign
	UO_CTS,
	U1_RTS,
	UO_RXD,
	SPIO_SCK,
	SPI0_SSEL1,
	SPI1_MOSI,
	SCT0_IN0,
	SCT_OUT0,
	SCT_OUT4,
	I2C1_SCL,
	I2C3_SCL,
	UART3_TXD,
	UART4_RXD,
	T0_MAT2,
	T0_CAP2
};

#define PINENABLE 	( ( __RW uint32_t *) 	0x4000C1C0UL)
/*
 * PIENABLE[0:1]
 */
void SWM_PinEnable(uint8_t port, uint8_t pin, uint8_t ena);
void SWM_Enable(void);
void SWM_Disable(void);
enum {
	ADC_0,
	ADC_1,
	ADC_2,
	ADC_3,
	ADC_4,
	ADC_5,
	ADC_6,
	ADC_7,
	ADC_8,
	ADC_9,
	ADC_10,
	ADC_11,
	DACOUT0,
	DACOUT1,
	CAPT_X0,
	CAPT_X1,
	CAPT_X2,
	CAPT_X3
};

enum {
	CAPT_X4, CAPT_X5, CAPT_X6, CAPT_X7, CAPT_X8, CAPT_YL, CAPT_YH
};

#endif /* SWITCHMATRIX_FW_H_ */
