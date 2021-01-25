/**
 \file		: PWM_FW.c
 \brief     : Firmware functions PWM
 \details   : 12 bits convertion
 \author    : Tobias Bavasso Piizzi
 \date 	    : 17/01/2021
 */
#include "Aplication.h"

/**
 * \fn 		: void SCT_Init(uint8_t port,uint8_t pin, uint8_t ena)
 * \brief 	: Initialize PWM on a pin
 * \details : There are states and events. When the counter matches, an event occurs
 * 			  what change the state and finally toggle the out
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 17/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \param	: [in]	uint8_t assign	:
 * \param	: [in]	uint8_t byte	: BYTE0,BYTE1,BYTE2,BYTE3
 * \return 	: void
 * */
void SCT_Init(uint8_t port, uint8_t pin, uint8_t assign, uint8_t byte) {
	SCT_Enable();
	SCT_Preset();
	SWM_Enable();
	SWM(port, pin, assign, byte);
	//SWM_Disable();

	SCTCLKDIV = 30;

	SCT_CONFIG			|=	(1 << 17);		// auto limit _L
	SCT_OUTPUT			|=	(1 << OUT0);	// preset OUT0 low

	SCT_OUTPUTDIRCTRL	|= 	(0x1 << 0);



	SCT_CTRL			|=	(1 << 4)|		// Counter bidirectional
							(1 << 3);

	SCT_MATCHREL0			= 	PWM_PERIOD-1;	// match 0 @PWM_FREQ
	SCT_MATCH1			= 	0;				// use match1 for PWM

	SCT_EV0_STATE		= 	0x03;			// event 0 happens in all states
	SCT_EV0_CTRL		=	(1 << 0)|		// related to match 1
							(0 << 4)|		// ev0 belongs to match 1
							(1 << 12)|		// match condition only
							(0 << 14)|		// statev is added to state
							(0 << 15);		// 0 (no change)

	SCT_OUT0CLR			=	(1 << 0);
	SCT_CTRL			&= ~(1 << 2);

}

/**
 * \fn 		: void PWM_Set(uint8_t val)
 * \brief 	: Set duty on PWM
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 25/01/2021
 * \param 	: [in]  uint8_t val	: 0 .... 100
 * \return 	: void
 * */
void PWM_Set(uint8_t val){
	if(val == 0)
		SCT_MATCHREL1 = 0;
	else if(val < 100)
		SCT_MATCHREL1 = ((PWM_STEP*val) - 1UL);
	else
		SCT_MATCHREL1 = PWM_PERIOD - 2;
}



/**
 * \fn 		: void SCT_Preset(void)
 * \brief 	: Clear SCT reset control
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 17/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void SCT_Preset(void) {
	PRESETCTRL0	&= (~(1<<SCT_PRESETCTRL));
	PRESETCTRL0	|= (1<<SCT_PRESETCTRL);
}

/**
 * \fn 		: void SCT_Enable(void)
 * \brief 	: Enable clock in PWM
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 17/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void SCT_Enable(void) {
	SYSAHBCLKCTRL0|= (1<<SCT_SYSAHB);
}

/**
 * \fn 		: void SCT_Disable(void)
 * \brief 	: Disable clock in PWM
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 17/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void SCT_Disable(void) {
	SYSAHBCLKCTRL0&= (~(1<<SCT_SYSAHB));
}

