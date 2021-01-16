/**
 \file		: SysTick_FW.h
 \brief     : Firmware functions for SysTick
 \details   : Used for 30 MHz
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/

#ifndef SYSTICK_FW_H_
#define SYSTICK_FW_H_

#define TICK_OUT_1S 100		//!< Systick interrupt each 1 second

#define SysTick_	( ( __RW uint32_t *) 	0xE000E000UL)

#define SYST_CSR SysTick_[4]
/*SYST_CSR	[0]	: 	ENABLE
 * 			[1]	:	TICKINT
 *			[2]	:	CLKSOURCE:	1:CLK 0:CLK/2
 *			[16]:	COUNTFLAG:	Return 1 if systick counted 0
 */
#define SYST_RVR SysTick_[5]
/*SYST_RVR [23:0]: RELOAD
 *
 */
#define SYST_CVR SysTick_[6]
/*SYST_CVR [23:0]: CURRENT
 *
 */
#define SYST_CALIB SysTick_[7]
/*
 *
 */
#define SYSTICK_ENABLE_INTERRUPT_CLK 	0x07
#define SYSTICK_DISABLE					0x00
#define SYSTICK_INT_DIS					SYST_CSR &= ~0x02;
#define SYSTICK_INT_EN					SYST_CSR = SYSTICK_ENABLE_INTERRUPT_CLK;
#define FRE30MHz	30000U

void SysTick_Init(void);
void SysTick_Off(void);
void SysTick_Set(uint32_t freq);



#endif /* SYSTICK_FW_H_ */
