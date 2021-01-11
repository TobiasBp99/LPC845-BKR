/**
 \file		: 05-ConversionADC.c
 \brief     : Firmware functions ADC
 \details   : 12 bits convertion
 \author    : Tobias Bavasso Piizzi
 \date 	    : 08/01/2021
 */
#include "Aplication.h"

/**
 * \fn 		: int main (void)
 * \brief 	: Main Function
 * \details : initialize the system and stay in the while
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 08/01/2021
 * \param 	: [in] void
 * \return 	: int
 * */

uint32_t tick = 0; 				//!< Var for SysTick_Handler
uint32_t conv = 0;				//!< Var for ADC

int main(void) {
	uint8_t state = 1;
	LPC_Init();
	ADC_Init(ADC_0);

    while(1) {

    	if(state == 0){
    		if ( conv > (0xFFF/2)){
    			state ++;
    		    GPIO_SetPIN(LedGREEN, LED_OFF);
    		    GPIO_SetPIN(LedBLUE, LED_ON);
    		}
    	}
    	else if (state == 1){
    		if ( conv <= (0xFFF/2)){
    			state --;
    		    GPIO_SetPIN(LedGREEN, LED_ON);
    		    GPIO_SetPIN(LedBLUE, LED_OFF);
		    }
    	}

    }
    return 0 ;
}
