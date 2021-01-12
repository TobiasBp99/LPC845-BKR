/**
 \file		: ADC_FW.c
 \brief     : Firmware functions ADC
 \details   : 12 bits convertion
 \author    : Tobias Bavasso Piizzi
 \date 	    : 08/01/2021
 */
#include "Aplication.h"

extern uint32_t tick;

/**
 * \fn 		: void ADC_Init(uint8_t port,uint8_t pin, uint8_t ena)
 * \brief 	: Initialize ADC on a pin
 * \details : Continuos conversion of POTE in board
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 08/01/2021
 * \param 	: [in]  uint8_t port: PORT0,PORT1
 * \param 	: [in]  uint8_t pin: 0,31
 * \param 	: [in]  uint8_t en: bit to enable in PINENABLE (page 143 UM)
 * \return 	: void
 * */
void ADC_Init(uint8_t port, uint8_t pin, uint8_t ena) {

	ADC_Enable();						//!< Enable CLOCK in SYSAHB
	ISER0|= MASK_ISE_ADC_SEQA;			//!< Enable service interrupt
	ADC_INTEN|= MASK_SEQA_INTEN;		//!< Interrupt after conversion finish
	SWM_Enable();						//!< Enable Switch Matrix
	SWM_PinEnable(port, pin, ena);		//!< Enable pin in SWN as AnalogInput
	SWM_Disable();						//!< Disable Switch Matrix
	ADC_Power();						//!< Power in SYSCON



	ADC_CTRL->_CLKDIV = 0x00;		//!< Div = 0
	ADC_CTRL->_ASYNCMODE = 0;		//!< Sync
	ADC_CTRL->_LPWRMODE = 0;		//!< OFF
	ADC_CTRL->_CALMODE = 0;			//!< OFF

	ADC_SEQA_CTRL->_CHANNELS 		= 0x01;		//!< Sample CH0
	ADC_SEQA_CTRL->_TRIGGER 		= 0x00;		//!< No hardware trigger
	ADC_SEQA_CTRL->_TRIGPOL 		= 0x1;		//!< Positive trigger
	ADC_SEQA_CTRL->_SYNCBYPASS 		= 0x0;		//!< Enable sync
	ADC_SEQA_CTRL->_TSAMP 			= 0x00;
	ADC_SEQA_CTRL->_START 			= 0;
	ADC_SEQA_CTRL->_BURST 			= 0;
	ADC_SEQA_CTRL->_SINGLESTEP 		= 0x0;
	ADC_SEQA_CTRL->_LOWPRIO 		= 0x0;
	ADC_SEQA_CTRL->_MODE 			= 0;		//!< Individual end of conversion
	ADC_SEQA_CTRL->_SEQx_ENA 		= 0;
	_ADC_SEQA_CTRL |= ((0b100001) << 26);		//!< Start,enable set on the same line first time
}

/**
 * \fn 		: void ADC_Power(void)
 * \brief 	: Power ADC
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 08/01/2021
 * \param 	: [in]  void
 * \return 	: void
 * */
void ADC_Power(void) {
	PDRUNCFG&= (~(1 << MASK_ADC_SYSCON));

}

/**
 * \fn 		: void ADC_Enable(void)
 * \brief 	: Enable clock in ADC
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 08/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void ADC_Enable(void) {
	SYSAHBCLKCTRL0|= (1<<ADC_SYSAHB);
}

/**
 * \fn 		: void ADC_Disable(void)
 * \brief 	: Disable clock in ADC
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 08/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void ADC_Disable(void) {
	SYSAHBCLKCTRL0&= (~(1<<ADC_SYSAHB));
}

/**
 * \fn 		: void ADC0_SEQA_IRQHandler(void)
 * \brief 	: Interruption for ADC
 * \details : Interrupt when some channel finishes its conversion
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 10/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
extern uint32_t conv;
void ADC0_SEQA_IRQHandler(void) {
	static uint8_t i 	= 0;
	static uint32_t sum = 0;

	(void) _ADC_SEQA_GDAT; 				//!< Clean flags

	sum += ADC_SEQA_GDAT->_RESULT;		//!< Read global data
	i++;
	if( i == 0xFF ){
		conv 	= sum/i ;				//!< Make an average
		i 		= 0;
		sum 	= 0;
	}
	ADC_SEQA_CTRL->_START 	= 1;		//!< Start a new conversion
}

