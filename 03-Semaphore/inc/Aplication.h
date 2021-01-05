/**
 \file		: Aplication.h
 \brief     : Functions used in main
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/

#ifndef APLICATION_H_
#define APLICATION_H_


#include "LPC845.h"
#include "GPIO_FW.h"
#include "GPIO_SW.h"
#include "SwitchMatrix_FW.h"
#include "SYSCON_FW.h"
#include "SysTick_FW.h"

void LPC_Init(void);
void GPIO_Init(void);
void Semaphore(void);

#define RED_LIGTH		PORT0,13
#define YELLOW_LIGTH	PORT0,14
#define GREEN_LIGTH		PORT0,15

#define RESET		0x00
#define R_STAGE		0x01	//!< Red on
#define RY_STAGE	0x02	//!< Red,Yellow on
#define G_STAGE		0x03	//!< Green on
#define Y_STAGE		0x04	//!< Yellow on

#define R_TICK		25*TICK_OUT_1S	//!< Red 25s
#define RY_TICK		2*TICK_OUT_1S	//!< Red,Yellow 2s
#define G_TICK		50*TICK_OUT_1S	//!< Green 50s
#define Y_TICK		5*TICK_OUT_1S	//!< Yellow 5s

#endif /* APLICATION_H_ */
