/**
 \file		: GPIO_FW.c
 \brief     : Firmware functions for GPIO
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/
#include "Aplication.h"

/**
 * \fn 		: void GPIO_Enable(void)
 * \brief 	: Enable GPIO0 and GPIO1
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void GPIO_Enable(void) {
	SYSAHBCLKCTRL0|= (1<<6);
	SYSAHBCLKCTRL0 |= (1<<20);
}
/**
 * \fn 		: void GPIO_Disable(void)
 * \brief 	: Disable GPIO0 and GPIO1
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
void GPIO_Disable(void) {
	SYSAHBCLKCTRL0&= (~(1<<6));
	SYSAHBCLKCTRL0 &= (~(1<<20));
}

/**
 * \fn 		: void GPIO_SetDIR(uint8_t port, uint8_t pin, uint8_t dir)
 * \brief 	: Choose GPIO as Input/Output
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \param	: [in]	uint8_t dir		: INPUT,OUTPUT
 * \return 	: void
 * */
void GPIO_SetDIR(uint8_t port, uint8_t pin, uint8_t dir) {
	GPIO_DIRP[port] &= (~(1 << pin));
	GPIO_DIRP[port] |= (dir << pin);
}

/**
 * \fn 		: void GPIO_SetPIN(uint8_t port, uint8_t pin, uint8_t dir)
 * \brief 	: Choose GPIO's output state
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \param	: [in]	uint8_t state	: LOW,HIGH
 * \return 	: void
 * */
void GPIO_SetPIN(uint8_t port, uint8_t pin, uint8_t state) {
	port = port * 32 + pin;
	GPIO_PBYTE[port] &= (~1);
	GPIO_PBYTE[port] |= state;
}

/**
 * \fn 		: uint8_t GPIO_GetPIN(uint8_t port, uint8_t pin, uint8_t dir)
 * \brief 	: Return GPIO's input state
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \param	: [in]	uint8_t STATE	: ACT_LOW,ACT_HIGH
 * \return 	: uint8_t				: 1 pin == [state] , 0 pin != [state]
 * */
uint8_t GPIO_GetPIN(uint8_t port, uint8_t pin, uint8_t state) {
	port = port * 32 + pin;
	if ( GPIO_PBYTE[port] == state)
		return 1;
	else
		return 0;
}

/**
 * \fn 		: void GPIO_SetOUT(uint8_t port, uint8_t pin)
 * \brief 	: Put GPIO's out to 1
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \return 	: void
 * */
void GPIO_SetOUT(uint8_t port, uint8_t pin) {
	GPIO_SETP[port] |= (1 << pin);
}

/**
 * \fn 		: void GPIO_ClearOUT(uint8_t port, uint8_t pin)
 * \brief 	: Put GPIO's out to 0
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \return 	: void
 * */
void GPIO_ClearOUT(uint8_t port, uint8_t pin) {
	GPIO_CLRP[port] |= (1 << pin);
}

/**
 * \fn 		: void GPIO_ToogleOUT(uint8_t port, uint8_t pin)
 * \brief 	: Invert GPIO's out
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \return 	: void
 * */
void GPIO_ToogleOUT(uint8_t port, uint8_t pin) {
	GPIO_NOTP[port] |= (1 << pin);
}

/**
 * \fn 		: void GPIO_DebounceUserKEY(void)
 * \brief 	: Firmware debounce for user key in board
 * \details : Use in SysTick_Handler or in some timer interrupt
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]
 * \return 	: void
 * */
__RW uint8_t buff_UserKEY = 0;
void GPIO_DebounceUserKEY(void) {
	static uint8_t q = 0;	//Quantity of bounces
	uint8_t j = 0;			//It captures changes

	if (GPIO_GetPIN(UserKEY, ACT_LOW))	// The key is pushed?
		j = 0x01;				//Something is happening, the key is been pushed

	if (buff_UserKEY ^ j) {			// If the key is pushed while q != BOUNCE
		q++;						// I change the buffer
		if (q == BOUNCE) {
			q = 0;
			buff_UserKEY ^= 0x01;
		}
	} else
		q = 0;
}
/**
 * \fn 		: void GPIO_Debounce(uint8_t port, uint8_t pin, uint8_t state)
 * \brief 	: Firmware debounce for a GPIO
 * \details : Use in SysTick_Handler or in some timer interrupt
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \param	: [in]	uint8_t state	: ACT_LOW,ACT_HIGH
 * \return 	: void
 * */
__RW uint8_t buff_In = 0;
void GPIO_Debounce(uint8_t port, uint8_t pin, uint8_t state) {
	static uint8_t q = 0;	//Quantity of bounces
	uint8_t j = 0;			//It captures changes

	if (GPIO_GetPIN(port, pin, state))	// The key is pushed?
		j = 0x01;				//Something is happening, the key is been pushed

	if (buff_In ^ j) {			// If the key is pushed while q != BOUNCE
		q++;						// I change the buffer
		if (q == BOUNCE) {
			q = 0;
			buff_In ^= 0x01;
		}
	} else
		q = 0;
}

/**
 * \fn 		: void IOCONEnable(void)
 * \brief 	: Enable IOCON
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]
 * \return 	: void
 * */
void IOCONEnable(void) {
	SYSAHBCLKCTRL0|= (1<<18);
}

/**
 * \fn 		: void IOCONDisable(void)
 * \brief 	: Disable IOCON
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]
 * \return 	: void
 * */
void IOCONDisable(void) {
	SYSAHBCLKCTRL0&= (~(1<<18));
}

/*------------------------------*/

uint8_t offset[] = { 0x044, 0x02C, 0x018, 0x014, 0x010, 0x00C, 0x040, 0x03C,
		0x038, 0x034, 0x020, 0x01C, 0x008, 0x004, 0x048, 0x028, 0x024, 0x000,
		0x078, 0x074, 0x070, 0x06C, 0x068, 0x064, 0x060, 0x05C, 0x058, 0x054,
		0x050, 0x0C8, 0x0CC, 0x08C, 0x090, 0x094, 0x098, 0x0A4, 0x0A8, 0x0AC,
		0x0B8, 0x0C4, 0x07C, 0x080, 0x0DC, 0x0D8, 0x084, 0x088, 0x09C, 0x0A0,
		0x0B0, 0x0B4, 0x0BC, 0x0C0, 0x0D0, 0x0D4 };

/**
 * \fn 		: uint8_t GetOFFSET(uint8_t port, uint8_t pin)
 * \brief 	: Usefull for SetMode functions
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint8_t port	: PORT0,PORT1
 * \param	: [in]	uint8_t pin		: 0,31
 * \return 	: void
 * */
uint8_t GetOFFSET(uint8_t port, uint8_t pin) {
	uint8_t index;
	index = port * 32 + pin;
	return ((offset[index]) / 4);
}

/**
 * \fn 		: void GPIO_SetModeINPUT(uint8_t port, uint8_t pin, uint8_t mode)
 * \brief 	: on-chip pull-up/pull-down resistor
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] 	uint8_t port: PORT0,PORT1
 * 			: [in]	uint8_t pin: 0,31
 * 			: [in]  uint8_t mode:NO_PULL_UP_DOWN,PULL_DOWN,PULL_UP,REPEATER
 * \return 	: void
 * */
void GPIO_SetModeINPUT(uint8_t port, uint8_t pin, uint8_t mode) {
	uint8_t offset;
	offset = GetOFFSET(port, pin);
	IOCON_[offset] &= (~(0x03 << 3));
	IOCON_[offset] |= (mode << 3);
}

/**
 * \fn 		: void GPIO_SetModeHYS(uint8_t port, uint8_t pin, uint8_t mode)
 * \brief 	: Hysteresis
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] 	uint8_t port: PORT0,PORT1
 * 			: [in]	uint8_t pin: 0,31
 * 			: [in]  uint8_t mode:HYS_EN,HYS_DIS
 * \return 	: void
 * */
void GPIO_SetModeHYS(uint8_t port, uint8_t pin, uint8_t mode) {
	uint8_t offset;
	offset = GetOFFSET(port, pin);
	IOCON_[offset] &= (~(0x01 << 5));
	IOCON_[offset] |= (mode << 5);
}

/**
 * \fn 		: void GPIO_SetModeINV(uint8_t port, uint8_t pin, uint8_t mode)
 * \brief 	: Invert input
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] 	uint8_t port: PORT0,PORT1
 * 			: [in]	uint8_t pin: 0,31
 * 			: [in]  uint8_t mode: INV_INPUT,NOT_INV_INPUT
 * \return 	: void
 * */
void GPIO_SetModeINV(uint8_t port, uint8_t pin, uint8_t mode) {
	uint8_t offset;
	offset = GetOFFSET(port, pin);
	IOCON_[offset] &= (~(0x01 << 6));
	IOCON_[offset] |= (mode << 6);
}

/**
 * \fn 		: void GPIO_SetModeOD(uint8_t port, uint8_t pin, uint8_t mode)
 * \brief 	: Open drain
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] 	uint8_t port: PORT0,PORT1
 * 			: [in]	uint8_t pin: 0,31
 * 			: [in]  uint8_t mode: OD_EN,OD_DIS
 * \return 	: void
 * */
void GPIO_SetModeOD(uint8_t port, uint8_t pin, uint8_t mode) {
	uint8_t offset;
	offset = GetOFFSET(port, pin);
	IOCON_[offset] &= (~(0x01 << 10));
	IOCON_[offset] |= (mode << 10);
}

/**
 * \fn 		: void GPIO_SetModeFILTER(uint8_t port, uint8_t pin, uint8_t mode)
 * \brief 	: Digital filter sample mode
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] 	uint8_t port: PORT0,PORT1
 * 			: [in]	uint8_t pin: 0,31
 * 			: [in]  uint8_t mode: BYPASS_FILTER,CLK1_FILTER,CLK2_FILTER,CLK3_FILTER
 * \return 	: void
 * */
void GPIO_SetModeFILTER(uint8_t port, uint8_t pin, uint8_t mode) {
	uint8_t offset;
	offset = GetOFFSET(port, pin);
	IOCON_[offset] &= (~(0x03 << 11));
	IOCON_[offset] |= (mode << 11);
}

/**
 * \fn 		: void GPIO_SetModeCLKDIV(uint8_t port, uint8_t pin, uint8_t mode)
 * \brief 	: Select peripheral clock divider for input filter sampling clock
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] 	uint8_t port: PORT0,PORT1
 * 			: [in]	uint8_t pin: 0,31
 * 			: [in]  uint8_t mode: IOCONCLKDIV0 to IOCONCLKDIV6
 * \return 	: void
 * */
void GPIO_SetModeCLKDIV(uint8_t port, uint8_t pin, uint8_t mode) {
	uint8_t offset;
	offset = GetOFFSET(port, pin);
	IOCON_[offset] &= (~(0x07 << 13));
	IOCON_[offset] |= (mode << 13);
}

/**
 * \fn 		: void GPIO_SetModeDAC(uint8_t port, uint8_t pin, uint8_t mode)
 * \brief 	: Selects DAC mode
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] 	uint8_t port: PORT0,PORT1
 * 			: [in]	uint8_t pin: 0,31
 * 			: [in]  uint8_t mode: DAC_EN,DAC_DIS
 * \return 	: void
 * */
void GPIO_SetModeDAC(uint8_t port, uint8_t pin, uint8_t mode){
	uint8_t offset;
	offset = GetOFFSET(port, pin);
	IOCON_[offset] &= (~(0x01 << 16));
	IOCON_[offset] |= (mode << 16);
}

/**
 * \fn 		: void GPIO_SetModeI2C(uint8_t port, uint8_t pin, uint8_t mode)
 * \brief 	: Selects I2C mode
 * \details :
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] 	uint8_t port: PORT0,PORT1
 * 			: [in]	uint8_t pin: 0,31
 * 			: [in]  uint8_t mode:STD_MODE,STD_GPIO,FAST_MODE
 * \return 	: void
 * */
void GPIO_SetModeI2C(uint8_t port, uint8_t pin, uint8_t mode){
	uint8_t offset;
	offset = GetOFFSET(port, pin);
	IOCON_[offset] &= (~(0x03 << 8));
	IOCON_[offset] |= (mode << 8);
}
