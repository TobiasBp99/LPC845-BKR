/**
 \file		: Disp7Seg_FW.c
 \brief     : Firmware functions for DISP7SEG
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 07/01/2021
 */
#include "Aplication.h"

/**
 * \fn 		: void DISP7SEG_Init(void)
 * \brief 	: Set pins for display as out
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 07/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void DISP7SEG_Init(void) {
	GPIO_SetDIR(SEG_A, OUTPUT);
	GPIO_SetDIR(SEG_B, OUTPUT);
	GPIO_SetDIR(SEG_C, OUTPUT);
	GPIO_SetDIR(SEG_D, OUTPUT);
	GPIO_SetDIR(SEG_E, OUTPUT);
	GPIO_SetDIR(SEG_F, OUTPUT);
	GPIO_SetDIR(SEG_G, OUTPUT);
	GPIO_SetDIR(TR_D0, OUTPUT);
	GPIO_SetDIR(TR_D1, OUTPUT);

	GPIO_ClearOUT(SEG_A);
	GPIO_ClearOUT(SEG_B);
	GPIO_ClearOUT(SEG_C);
	GPIO_ClearOUT(SEG_D);
	GPIO_ClearOUT(SEG_E);
	GPIO_ClearOUT(SEG_F);
	GPIO_ClearOUT(SEG_G);
	GPIO_ClearOUT(TR_D0);
	GPIO_ClearOUT(TR_D1);
}

/**
 * \fn 		: void DISP_Sweep(void)
 * \brief 	: Refresh the display 7Seg (2 Disp)
 * \details : Is necessary to be used in SysTick_Handler
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 07/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
extern __RW uint8_t buff_Disp7[];		//!< Display buffer
void DISP_Sweep(void) {
	uint8_t aux;
	static uint8_t digit = 0;		//!< Number of disp

	GPIO_ClearOUT(TR_D0);			//!< Turn off transistor
	GPIO_ClearOUT(TR_D1);			//!< Turn off transistor

	aux = buff_Disp7[digit];

	GPIO_SetPIN( SEG_A, ((aux >> 0) & (uint8_t) 0x01));
	GPIO_SetPIN( SEG_B, ((aux >> 1) & (uint8_t) 0x01));
	GPIO_SetPIN( SEG_C, ((aux >> 2) & (uint8_t) 0x01));
	GPIO_SetPIN( SEG_D, ((aux >> 3) & (uint8_t) 0x01));
	GPIO_SetPIN( SEG_E, ((aux >> 4) & (uint8_t) 0x01));
	GPIO_SetPIN( SEG_F, ((aux >> 5) & (uint8_t) 0x01));
	GPIO_SetPIN( SEG_G, ((aux >> 6) & (uint8_t) 0x01));
	GPIO_SetPIN( SEG_DP, ((aux >> 7) & (uint8_t) 0x01));

	switch (digit) {
	case DIGIT_0:
		GPIO_SetOUT(TR_D0);
		break;
	case DIGIT_1:
		GPIO_SetOUT(TR_D1);
		break;
	default:
		digit = 0;
		GPIO_SetOUT(TR_D0);
		break;
	}

	digit++;			//!< Next time sweep other disp
	digit %= DIGITS;	//!< Reset the digits

}

