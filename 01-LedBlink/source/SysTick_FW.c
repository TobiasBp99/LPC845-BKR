/**
 \file		: SysTick_FW.c
 \brief     : Firmware functions for SysTick
 \details   : Only develop for 30MHz
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/
#include "Aplication.h"

/**
 * \fn 		: void SysTick_Init(void)
 * \brief 	: Initialize the systick
 * \details : Enable SysTick, enable interrupt and set the counter
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  void
 * \return 	: void
 * */
void SysTick_Init(void){
	SysTick_Set(FRE30MHz);
	SYST_CSR = SYSTICK_ENABLE_INTERRUPT_CLK;
	SYST_CVR = 0;
}

/**
 * \fn 		: SysTick_Off(void)
 * \brief 	: Stops the systick
 * \details : disable SysTick, disable interrupt
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  void
 * \return 	: void
 * */
void SysTick_Off(void){
	SYST_CSR = SYSTICK_DISABLE;
}

/**
 * \fn 		: void SysTick_Set(uint32_t freq)
 * \brief 	: Set the counter as freq*10mS -1
 * \details : Always use at 30MHz
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  uint32_t freq: FRE30MHz
 * \return 	: void
 * */
void SysTick_Set(uint32_t freq){
	SYST_RVR = freq*10 - 1; // 30MHz*10mS-1
}

/**
 * \fn 		: void SysTick_Handler(void)
 * \brief 	: Interrupt each 10mS
 * \details : when the tick is out i know that happend time = tick*10mS
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: void
 * */
extern uint32_t tick;
void SysTick_Handler(void)
{
    if (tick != 0U)
    	tick--;
    else{
    	tick = TICK_OUT_1S;
    	GPIO_ToogleOUT(LedRED);
    }
}

