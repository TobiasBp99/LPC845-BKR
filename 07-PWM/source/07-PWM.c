/**
 \file		: 07-PWM.c
 \brief     : Example of PWM use
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 13/01/2021
 */
#include "Aplication.h"

/**
 * \fn 		: int main (void)
 * \brief 	: Main Function
 * \details : initialize the system and stay in the while
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 13/01/2021
 * \param 	: [in] void
 * \return 	: int
 * */
uint32_t tick = 0;	//!< Var for systick
uint32_t conv = 0;	//!< Var for ADC
int main(void) {
	LPC_Init();
    while(1) {


    }
    return 0 ;
}
