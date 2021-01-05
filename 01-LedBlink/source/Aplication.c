/**
 \file		: Aplication.c
 \brief     : Functions used in main
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
 */
#include "Aplication.h"

/**
 * \fn 		: void LPC_Init(void)
 * \brief 	: Initialize the board
 * \details : It depends on each proyect
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void LPC_Init(void) {
	GPIO_Enable();
	BoardClockRUN();
	SysTick_Init();
	GPIO_Init();
}

/**
 * \fn 		: void GPIO_Init(void)
 * \brief 	: Initialize the GPIO
 * \details : It depends on each proyect
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void GPIO_Init(void) {
	GPIO_SetDIR(LedRED, OUTPUT);
	GPIO_SetDIR(LedGREEN, OUTPUT);
	GPIO_SetDIR(LedBLUE, OUTPUT);
	GPIO_SetDIR(UserKEY, INPUT);

	GPIO_SetPIN(LedRED, LED_OFF);
	GPIO_SetPIN(LedGREEN, LED_OFF);
	GPIO_SetPIN(LedBLUE, LED_OFF);
}

