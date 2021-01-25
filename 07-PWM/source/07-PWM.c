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
uint32_t tick = TICK_OUT_1S;	//!< Var for systick
uint32_t conv = 0;	//!< Var for ADC

uint8_t duty = 0;

int main(void) {
	LPC_Init();
	SCT_Init(PWM);
	PWM_Set(duty);

    while(1) {

    	if(tick == 0){
    		tick = TICK_OUT_1S;
    		duty++;
    		PWM_Set(duty);
    		if( duty == 100)
    			duty = 0;
    	}

    }
    return 0 ;
}
