/**
 \file		: Disp7Seg_SW.c
 \brief     : Software functions for DISP7SEG
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 07/01/2021
 */

#include "Aplication.h"

extern __RW uint8_t buff_Disp7[DIGITS];			//!< Buffer de display
/**
 Tabla de conversion bcd a 7 segmentos
 Codigo bcd		a	b	c	d	e	f	g   dp
 0				1	1	1	1	1	1	0   0
 1				0	1	1	0	0	0	0
 2				1	1	0	1	1	0	1
 3				1	1	1	1	0	0	1
 4				0	1	1	0	0	1	1
 5				1	0	1	1	0	1	1
 6				0	0	1	1	1	1	1
 7				1	1	1	0	0	0	0
 8				1	1	1	1	1	1	1
 9				1	1	1	0	0	1	1
 */
uint8_t Digits_to_BCD7seg[] = { 0x3f, 0x06, 0x5B, 0x4f, 0x66, 0x6D, 0x7C, 0x07,
		0x7f, 0x67 };
extern __RW uint8_t tick_Disp7;
/**
 * \fn 		: void Display(uint8_t val)
 * \brief 	: Writes on Disp7Seg
 * \details : High lever of layers
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 07/01/2021
 * \param 	: [in] uint8_t val: 0 to 99
 * \return 	: void
 * */
void Display(uint8_t val) {
	uint8_t i;
	uint8_t auxDisp[DIGITS];

	for (i = 0; i < DIGITS; i++) {
		auxDisp[i] = Digits_to_BCD7seg[val % 10];
		val /= 10;
	}
	for (i = 0; i < DIGITS; i++) {
		SYSTICK_INT_DIS; 				//!< Disable SysTick INT
		buff_Disp7[i] = auxDisp[i];
		SYSTICK_INT_EN;					//!< Enable SysTick INT
	}

}
