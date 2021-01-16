/**
 \file		: 06-DAC.c
 \brief     : Firmware functions ADC
 \details   : 12 bits convertion
 \author    : Tobias Bavasso Piizzi
 \date 	    : 12/01/2021
 */
#include "Aplication.h"

/**
 * \fn 		: int main (void)
 * \brief 	: Main Function
 * \details : initialize the system and stay in the while
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 12/01/2021
 * \param 	: [in] void
 * \return 	: int
 * */

uint32_t tick = TICK_OUT_1S/8; 			//!< Var for SysTick_Handler
uint32_t conv = 0;						//!< Var for ADC (not used)

uint16_t buffDac0 = 0;					//!< Buffer for dac
uint16_t dacVal = 0;					//!< Current value to be edited

#define UP 0
#define DOWN 1

int main(void) {

	uint8_t wave = UP;

	LPC_Init();
	DAC0_Init(DACOUT0);


    while(1) {
    	if( tick == 0){

    		tick = TICK_OUT_1S/8;

    		if(dacVal == 0)
    			wave = UP;
    		else if(dacVal == 0x3FF)
    			wave = DOWN;

    		if(wave == UP)
    			dacVal++;
    		else if( wave == DOWN)
    			dacVal--;

    		SetDAC0(dacVal);

    	}

    }
    return 0 ;
}
