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
#include "Disp7Seg_FW.h"
#include "Disp7Seg_SW.h"

void LPC_Init(void);
void GPIO_Init(void);


#endif /* APLICATION_H_ */
