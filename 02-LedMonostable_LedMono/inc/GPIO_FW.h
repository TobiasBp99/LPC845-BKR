/**
 \file		: GPIO_FW.h
 \brief     : Firmware functions for GPIO
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/
#ifndef GPIO_FW_H_
#define GPIO_FW_H_

#define PORT0 	0
#define PORT1 	1

#define LedGREEN	PORT1 , 0 	//!< Led green in board
#define LedBLUE		PORT1 , 1	//!< Led blue in board
#define LedRED		PORT1 , 2	//!< Led red in board

#define	UserKEY		PORT0 , 4	//!< Key in board

#define INPUT		0
#define OUTPUT		1

#define LOW			0
#define HIGH		1

#define ACT_HIGH	1
#define ACT_LOW		0

#define LED_ON		0			//!< The led are active low
#define LED_OFF		1			//!< The led are active low

#define BOUNCE		10			//!< Times to check the bounce

/*-Function prototype-*/
void GPIO_Enable(void);
void GPIO_Disable(void);
void GPIO_SetDIR(uint8_t port, uint8_t pin, uint8_t dir);
void GPIO_SetPIN(uint8_t port, uint8_t pin, uint8_t state);
uint8_t GPIO_GetPIN(uint8_t port, uint8_t pin, uint8_t state);
void GPIO_SetOUT(uint8_t port, uint8_t pin);
void GPIO_ClearOUT(uint8_t port, uint8_t pin);
void GPIO_ToogleOUT(uint8_t port, uint8_t pin);

void GPIO_DebounceUserKEY(void);
void GPIO_Debounce(uint8_t port, uint8_t pin, uint8_t state);


/*--------------------*/

/*
 * This enable the clock in the gpio
 */
#define SYSAHBCLKCTRL	( ( __RW uint32_t *) 	0x40048080UL)
#define SYSAHBCLKCTRL0	SYSAHBCLKCTRL[0]
#define SYSAHBCLKCTRL1	SYSAHBCLKCTRL[1]

#define	GPIO_PBYTE	( ( __RW uint8_t *) 	0xA0000000UL)
/* PORT0: 0x0000 to 0x001F ; PORT: 0x0020 to 0x0035
 * B[0:53] => R: State of the pin	; W: Loads pin's out
 */

#define	GPIO_PWORD	( ( __RW uint32_t *) 	0xA0001000UL)
/* W0: 0x1000 to 0x10D4
 * W[0:31] =>	R: 0 pin is low	; W: != 0x00000000 set output bit
 * 				R: 0xFFFFFFFF pin is high
 */

#define	GPIO_DIRP	( ( __RW uint32_t *) 	0xA0002000UL)
/* PORT0: 0x2000	;	PORT: 0x2004
 * PIN[0:31] => R: 	;	W: 	0 input
 * 							1 output
 */

#define	GPIO_PORT	( ( __RW uint32_t *) 	0xA0002100UL)
/* PORT0: 0x2100	;	PORT1: 0x2104
 * PIN[0:31]	=> R:	0 pin is low	; 	W:	0 clear output
 * 					1 pin is high	;		1 set output
 */

#define	GPIO_SETP	( ( __RW uint32_t *) 	0xA0002200UL)
/* PORT0: 0x2200	;	PORT1: 0x2204
 * PIN[0:31]	=> R:	output bit	; 	W:	0
 * 						output bit	;		1 set output
 */

#define	GPIO_CLRP	( ( __RW uint32_t *) 	0xA0002280UL)
/* PORT0: 0x2280	;	PORT1: 0x2284
 * PIN[0:31]	=> R:		; 	W:	0
 * 							;		1 clear output
 */

#define	GPIO_NOTP	( ( __RW uint32_t *) 	0xA0002300UL)
/* PORT0: 0x2300	;	PORT1: 0x2304
 * PIN[0:31]	=> R:		; 	W:	0
 * 							;		1 toggle output
 */

/*--------------------*/
#define NO_PULL_UP_DOWN 0x00
#define PULL_DOWN 		0x01
#define PULL_UP 		0x02
#define REPEATER 		0x03

#define HYS_EN	 		0x01
#define HYS_DIS	 		0x00

#define INV_INPUT		0x01
#define NOT_INV_INPUT	0x00

#define OD_EN	 		0x01
#define OD_DIS	 		0x00

#define BYPASS_FILTER	0x00
#define CLK1_FILTER 	0x01
#define CLK2_FILTER  	0x02
#define CLK3_FILTER  	0x03

#define IOCONCLKDIV0	0x00
#define IOCONCLKDIV1	0x01
#define IOCONCLKDIV2	0x02
#define IOCONCLKDIV3	0x03
#define IOCONCLKDIV4	0x04
#define IOCONCLKDIV5	0x05
#define IOCONCLKDIV6	0x06

#define DAC_EN	 		0x01
#define DAC_DIS	 		0x00

#define STD_MODE		0x00
#define STD_GPIO	 	0x01
#define FAST_MODE	  	0x02




void IOCONEnable(void);
void IOCONDisable(void);

#define	IOCON_	( ( __RW uint32_t *) 	0x40044000UL)

uint8_t GetOFFSET(uint8_t port, uint8_t pin);
void GPIO_SetModeINPUT(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_SetModeHYS(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_SetModeINV(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_SetModeOD(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_SetModeFILTER(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_SetModeCLKDIV(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_SetModeDAC(uint8_t port, uint8_t pin, uint8_t mode);
void GPIO_SetModeI2C(uint8_t port, uint8_t pin, uint8_t mode);
//void SetIOCON(uint8_t port, uint8_t pin, uint8_t mode, uint8_t hys,uint8_t inv, uint8_t od, uint8_t s_mode, uint8_t clk_div);










#endif /* GPIO_FW_H_ */
