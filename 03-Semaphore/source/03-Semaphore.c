/**
 \file		: 03-Semaphore.c
 \brief     : Entry point for the program
 \details   : Semaphore with 4 stages
 \author    : Tobias Bavasso Piizzi
 \date 	    : 05/01/2021
*/
#include "Aplication.h"

/**
 * \fn 		: int main (void)
 * \brief 	: Main Function
 * \details : initialize the system and stay in the while
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 05/01/2021
 * \param 	: [in] void
 * \return 	: int
 * */

uint32_t tick = 0; //!< Var for SysTick_Handler
int main(void) {
	LPC_Init();
    while(1) {
    	Semaphore();	//!< FSM in aplication.c
    }
    return 0 ;
}
