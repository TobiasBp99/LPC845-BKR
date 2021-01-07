/**
 \file		: 04-Display7Seg.c
 \brief     : Entry point for the program
 \details   : Counter 0-99 with UserKey
 \author    : Tobias Bavasso Piizzi
 \date 	    : 07/01/2021
*/
#include "Aplication.h"

/**
 * \fn 		: int main (void)
 * \brief 	: Main Function
 * \details : initialize the system and stay in the while
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 07/01/2021
 * \param 	: [in] void
 * \return 	: int
 * */

uint32_t tick = 0; 				//!< Var for SysTick_Handler
uint8_t buff_Disp7[DIGITS];		//!< Buffer for display 7Seg
uint8_t tick_Disp7 = 0;		//!< Var for SysTick_Handler

int main(void) {
	static uint8_t i = 0;
	LPC_Init();
	DISP7SEG_Init();

	Display(i);

    while(1) {
    	if(GetUserKEY() == 1){
    		i++;
    		Display(i);
    	}
    }
    return 0 ;
}
