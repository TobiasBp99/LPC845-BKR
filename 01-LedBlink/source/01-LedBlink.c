/**
 \file		: 01-LedBlink.c
 \brief     : Punto de entrada del programa
 \details   : Toggle LedRED after 1SEC
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
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

uint32_t tick = TICK_OUT_1S; //!< Var for SysTick_Handler

int main(void) {
	LPC_Init();
    while(1) {

    }
    return 0 ;
}
