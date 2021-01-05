/**
 \file		: 02-LedMonostable_LedMono.c
 \brief     : Entry point for the program
 \details   : Turn on LedRED for 5s when UserKey is pressed
 \author    : Tobias Bavasso Piizzi
 \date 	    : 05/01/2021
*/
#include "Aplication.h"

/**
 * \fn 		: int main (void)
 * \brief 	: Main Function
 * \details : initialize the system and stay in the while
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: int
 * */

uint32_t tick = 0; //!< Var for SysTick_Handler

#define WAITING	0	//!< State for the FMS
#define WORKING 1	//!< State for the FMS

int main(void) {
	uint8_t state = WAITING;
	LPC_Init();

	while (1) {
		if (state == WAITING) {
			if (GetUserKEY() == 1) {
				GPIO_SetPIN(LedRED, LED_ON);
				tick = 5 * TICK_OUT_1S; //!< Count 5s
				state = WORKING;
			}
		} else if (state == WORKING) {
			if (tick == 0) {
				GPIO_SetPIN(LedRED, LED_OFF);
				state = WAITING;
			}
		}
	}
	return 0;
}
