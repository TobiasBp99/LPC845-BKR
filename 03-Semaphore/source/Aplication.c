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
	/*
	 GPIO_SetDIR(LedRED, OUTPUT);
	 GPIO_SetDIR(LedGREEN, OUTPUT);
	 GPIO_SetDIR(LedBLUE, OUTPUT);
	 GPIO_SetDIR(UserKEY, INPUT);

	 GPIO_SetPIN(LedRED, LED_OFF);
	 GPIO_SetPIN(LedGREEN, LED_OFF);
	 GPIO_SetPIN(LedBLUE, LED_OFF);
	 */
	GPIO_SetDIR(RED_LIGTH, OUTPUT);
	GPIO_SetDIR(YELLOW_LIGTH, OUTPUT);
	GPIO_SetDIR(GREEN_LIGTH, OUTPUT);

	GPIO_SetPIN(RED_LIGTH, LOW);
	GPIO_SetPIN(YELLOW_LIGTH, LOW);
	GPIO_SetPIN(GREEN_LIGTH, LOW);
}

/**
 * \fn 		: void Semaphore(void)
 * \brief 	: Control of the ligths
 * \details : Finite state machine
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
extern uint32_t tick;	//!< Declared in main
void Semaphore(void) {
	static uint8_t state = RESET;
	switch (state) {
	case RESET:
		GPIO_SetPIN(RED_LIGTH, LOW);	//!< Reset condition
		GPIO_SetPIN(YELLOW_LIGTH, LOW);	//!< Reset condition
		GPIO_SetPIN(GREEN_LIGTH, LOW);	//!< Reset condition
		tick = R_TICK;
		GPIO_SetPIN(RED_LIGTH, HIGH);
		state = R_STAGE;
		break;
	case R_STAGE:
		if (tick == 0) {
			tick = RY_TICK;
			GPIO_SetPIN(YELLOW_LIGTH, HIGH);
			state = RY_STAGE;
		}
		break;
	case RY_STAGE:
		if (tick == 0) {
			tick = G_TICK;
			GPIO_SetPIN(RED_LIGTH, LOW);
			GPIO_SetPIN(YELLOW_LIGTH, LOW);
			GPIO_SetPIN(GREEN_LIGTH, HIGH);
			state = G_STAGE;
		}
		break;
	case G_STAGE:
		if (tick == 0) {
			tick = Y_TICK;
			GPIO_SetPIN(GREEN_LIGTH, LOW);
			GPIO_SetPIN(YELLOW_LIGTH, HIGH);
			state = Y_STAGE;
		}
		break;
	case Y_STAGE:
		if (tick == 0) {
			tick = R_TICK;
			GPIO_SetPIN(YELLOW_LIGTH, LOW);
			GPIO_SetPIN(RED_LIGTH, HIGH);
			state = R_STAGE;
		}
		break;

	}

}

