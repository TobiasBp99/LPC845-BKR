/**
 \file		: GPIO_SW.c
 \brief     : Software functions for GPIO
 \details   : These functions avoid bouncing. Both must be used w/ GPIO_DebounceUserKEY or GPIO_Debounce
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/
#include "Aplication.h"


/**
 * \fn 		: uint8_t GetUserKEY(void)
 * \brief 	: State of the user key in board
 * \details : Is necessary using GPIO_DebounceUserKEY
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: uint8_t 1 if user key pressed, 0 if user key not
 * */
extern uint8_t buff_UserKEY;
uint8_t GetUserKEY(void){
	static uint8_t buff_before = 0x00;

	if ( buff_UserKEY == 0x01 && buff_before == 0x00 ){
		buff_before = 0x01;
		return (1);
	}
	else if ( buff_UserKEY == 0x01 && buff_before == 0x01 )
		return (0);
	else if ( buff_UserKEY == 0x00 && buff_before == 0x01 )
		return (0);
	else
		return (0);
}

/**
 * \fn 		: uint8_t GetInput(void)
 * \brief 	: State of the input
 * \details : Is necessary using GPIO_Debounce
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in] void
 * \return 	: uint8_t 1 if input pressed, 0 if input pressed
 * */
extern uint8_t buff_In;
uint8_t GetInput(void){
	static uint8_t buff_before = 0x00;

	if ( buff_In == 0x01 && buff_before == 0x00 ){
		buff_before = 0x01;
		return (1);
	}
	else if ( buff_In == 0x01 && buff_before == 0x01 )
		return (0);
	else if ( buff_In == 0x00 && buff_before == 0x01 ){
		buff_before = 0x00;
		return (0);
	}
	else
		return (0);
}




