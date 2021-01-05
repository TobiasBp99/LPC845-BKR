/**
 \file		: SwitchMatrix_FW.c
 \brief     : Firmware functions for SWM
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/
#include "Aplication.h"

/**
 * \fn 		: void SWM(uint8_t port, uint8_t pin, uint8_t assign, uint8_t byte)
 * \brief 	: Assign movable functions for pin
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \param	: [in]	uint8_t assign	:
 * \param	: [in]	uint8_t byte	: BYTE0,BYTE1,BYTE2,BYTE3
 * \return 	: void
 * */
void SWM(uint8_t port, uint8_t pin, uint8_t assign, uint8_t byte) {
	pin = pin + 0x20 * port; //PIO0[0:31] 0x00 to 0x1F PIO1[0:21] 0x1F to 0x35
	PINASSIGN[assign] |= (pin << byte);
}

/**
 * \fn 		: void SWM_PinEnable(uint8_t port, uint8_t pin, uint8_t ena)
 * \brief 	: Enable pin works as value passed in ena
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \param	: [in]	uint8_t ena		: READ Page 143 UserManual. There are multiple choices
 * \return 	: void
 * */
void SWM_PinEnable(uint8_t port, uint8_t pin, uint8_t ena) {
	if (port == PORT1)		//PIENABLE[0] -> PIO0_0 .... PIO1_2
		if (pin < 3)		//PIENABLE10] -> PIO1_3 .... PIO1_21
			port = PORT0;
	PINENABLE[port] |= (1 << ena);
}

/**
 * \fn 		: void SWM_Enable(void)
 * \brief 	: Enable SWM
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  void
 * \return 	: void
 * */
void SWM_Enable(void) {
	SYSAHBCLKCTRL0|= (1<<7);
}

/**
 * \fn 		: void SWM_Disable(void)
 * \brief 	: Disable SWM
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  void
 * \return 	: void
 * */
void SWM_Disable(void) {
	SYSAHBCLKCTRL0&= (~(1<<7));
}

