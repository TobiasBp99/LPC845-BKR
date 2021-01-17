/**
 \file		: PWM_FW.c
 \brief     : Firmware functions PWM
 \details   : 12 bits convertion
 \author    : Tobias Bavasso Piizzi
 \date 	    : 17/01/2021
 */
#include "Aplication.h"

/**
 * \fn 		: void PWM_Init(uint8_t port,uint8_t pin, uint8_t ena)
 * \brief 	: Initialize PWM on a pin
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 17/01/2021
 * \param 	: [in]  uint8_t port: PORT0,PORT1
 * \param 	: [in]  uint8_t pin: 0,31
 * \param 	: [in]  uint8_t en: bit to enable in PINENABLE (page 143 UM)
 * \return 	: void
 * */
void ADC_Init(uint8_t port, uint8_t pin, uint8_t ena) {
	PWM_Enable();		//!< Enable clock in PWM
	PWM_Preset();		//!< Clean the CLK
	SWM_Enable();		//!< Enable Switch Matrix
	SWM(PWM_OUT);		//!< Connects the out in the matrix
	SWM_Disable();		//!< Disable Switch Matrix
	//0b 0000 0000 0 0 0000 00 1
	SCTimerPWM_CONFIG |= 0x01;

}

/**
 * \fn 		: void PWM_Preset(void)
 * \brief 	: Clear SCT reset control
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 17/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void PWM_Preset(void) {
	PRESETCTRL0|= (1<<PWM_PRESETCTRL);
}

/**
 * \fn 		: void PWM_Enable(void)
 * \brief 	: Enable clock in PWM
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 17/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void PWM_Enable(void) {
	SYSAHBCLKCTRL0|= (1<<PWM_SYSAHB);
}

/**
 * \fn 		: void PWM_Disable(void)
 * \brief 	: Disable clock in PWM
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 17/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void PWM_Disable(void) {
	SYSAHBCLKCTRL0&= (~(1<<PWM_SYSAHB));
}

