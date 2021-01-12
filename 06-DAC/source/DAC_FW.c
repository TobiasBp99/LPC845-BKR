/**
 \file		: DAC_FW.c
 \brief     : Firmware functions for DAC
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 12/01/2021
 */
#include "Aplication.h"
/*
 The DAC is configured using the following registers:
 1. Power: Use the PDRUNCFG register to power the DAC.
 2. Peripheral clock: Use the SYSAHBCLKCTRL register to enable the clock to the DAC
 register interface. See Section 8.6.22.
 3. Pins: Enable the DAC fixed-pin function in the relevant SWM PINENABLE register,
 and also set the DACENABLE bit in the relevant IOCON register.
 4. DMA: The DAC can be connected to the DMA controller (see Section 28.5.2). For
 DMA connections.
 */

/**
 * \fn 		: void DAC_Power(void)
 * \brief 	: Initialize DAC0
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 12/01/2021
 * \param 	: [in]  uint8_t port: PORT0,PORT1
 * \param 	: [in]  uint8_t pin: 0,31
 * \param 	: [in]  uint8_t en: bit to enable in PINENABLE (page 143 UM)
 * \return 	: void
 * */
void DAC0_Init(uint8_t port, uint8_t pin, uint8_t ena) {
	DAC_Power();						//Power DAC

	DAC_Enable();						// Enable clock for DAC

	SWM_Enable();						// Enable Switch Matrix
	SWM_PinEnable(port, pin, ena);		// Enable pin in SWN as AnalogOutput
	SWM_Disable();						// Disable Switch Matrix

	IOCONEnable();						//Enable clock for IOCON
	GPIO_SetModeDAC(port,pin,DAC_ENABLE_IOCON);
	IOCONDisable();						//Disable clock for IOCON
}

/**
 * \fn 		: void DAC0_SetValue(uint16_t val)
 * \brief 	: Writes the registers for load the output
 * \details : Neccesary using in SysTick
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 12/01/2021
 * \param 	: [in]  void
 * \return 	: void
 * */
extern uint16_t buffDac0;
void DAC0_SetValue(void){
	if( buffDac0 != DAC0_CR->_VALUE )
		DAC0_CR->_VALUE = buffDac0; 	//Change output
}

/**
 * \fn 		: void DAC_Power(void)
 * \brief 	: Power DAC0,DAC1
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 12/01/2021
 * \param 	: [in]  void
 * \return 	: void
 * */
void DAC_Power(void) {
	PDRUNCFG &= (~(1 << MASK_DAC0_SYSCON));
	PDRUNCFG &= (~(1 << MASK_DAC1_SYSCON));
}

/**
 * \fn 		: void DAC_Enable(void)
 * \brief 	: Enable clock in DAC0,DAC1
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 12/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void DAC_Enable(void) {
	SYSAHBCLKCTRL0 |= (1 << DAC0_SYSAHB);
	SYSAHBCLKCTRL1 |= (1 << DAC1_SYSAHB);
}

/**
 * \fn 		: void DAC_Disable(void)
 * \brief 	: Disable clock in DAC0,DAC1
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 12/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void DAC_Disable(void) {
	SYSAHBCLKCTRL0 &= (~(1 << DAC0_SYSAHB));
	SYSAHBCLKCTRL1 &= (~(1 << DAC1_SYSAHB));
}
