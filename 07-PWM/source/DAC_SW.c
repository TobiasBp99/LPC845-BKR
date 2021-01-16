/**
 \file		: DAC_SW.c
 \brief     : Software functions for DAC
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 12/01/2021
 */
#include "Aplication.h"
/**
 * \fn 		: void SetDAC0(uint16_t val)
 * \brief 	: Select the voltage output
 * \details : Vout = (3.3V * val)/1024
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 12/01/2021
 * \param 	: [in]  uint16_t val: 10 bits
 * \return 	: void
 * */
extern uint16_t buffDac0;
void SetDAC0(uint16_t val){
	buffDac0 = (val & 0x3FF);	// To be sure buffDac0 is 10 bits
}
