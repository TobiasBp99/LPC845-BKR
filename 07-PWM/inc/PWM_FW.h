/**
 \file		: PWM_FW.h
 \brief     : Firmware functions PWM
 \details   : 12 bits convertion
 \author    : Tobias Bavasso Piizzi
 \date 	    : 17/01/2021
 */

#ifndef PWM_FW_H_
#define PWM_FW_H_

#define SCTimerPWM_ADD	( ( __RW uint32_t *) 	0x50004000UL) //!< Base address
#define SCTimerPWM_CONFIG SCTimerPWM_ADD[0]		//!< OFFSET 0x000
#define SCTimerPWM_CTRL SCTimerPWM_ADD[1]		//!< OFFSET 0x004
#define SCTimerPWM_LIMIT SCTimerPWM_ADD[2]		//!< OFFSET 0x008
#define SCTimerPWM_HALT SCTimerPWM_ADD[3]		//!< OFFSET 0x00C
#define SCTimerPWM_STOP SCTimerPWM_ADD[4]		//!< OFFSET 0x010
#define SCTimerPWM_START SCTimerPWM_ADD[5]		//!< OFFSET 0x014
#define SCTimerPWM_COUNT SCTimerPWM_ADD[16]		//!< OFFSET 0x040
#define SCTimerPWM_STATE SCTimerPWM_ADD[17]		//!< OFFSET 0x044
#define SCTimerPWM_INPUT SCTimerPWM_ADD[18]		//!< OFFSET 0x048
#define SCTimerPWM_REGMODE SCTimerPWM_ADD[19]	//!< OFFSET 0x04C
#define SCTimerPWM_OUTPUT SCTimerPWM_ADD[20]	//!< OFFSET 0x050
#define SCTimerPWM_OUTPUTDIRCTRL SCTimerPWM_ADD[21]	//!< OFFSET 0x054
#define SCTimerPWM_RES SCTimerPWM_ADD[22]		//!< OFFSET 0x058
#define SCTimerPWM_DMAREQ0 SCTimerPWM_ADD[23]	//!< OFFSET 0x05C
#define SCTimerPWM_DMAREQ1 SCTimerPWM_ADD[24]	//!< OFFSET 0x060
//Creo que las siguientes posiciones de memoria no son necesarias para usa PWM
#define SCTimerPWM_EVEN SCTimerPWM_ADD[60]		//!< OFFSET 0x0F0
#define SCTimerPWM_EVFLAG SCTimerPWM_ADD[61]	//!< OFFSET 0x0F4
#define SCTimerPWM_CONEN SCTimerPWM_ADD[62]		//!< OFFSET 0x0F8
#define SCTimerPWM_CONFLAG SCTimerPWM_ADD[63]	//!< OFFSET 0x0FC
#define SCTimerPWM_MATCH0 SCTimerPWM_ADD[64]	//!< OFFSET 0x100
#define SCTimerPWM_MATCH1 SCTimerPWM_ADD[65]	//!< OFFSET 0x104
#define SCTimerPWM_MATCH2 SCTimerPWM_ADD[66]	//!< OFFSET 0x108
#define SCTimerPWM_MATCH3 SCTimerPWM_ADD[67]	//!< OFFSET 0x10C
#define SCTimerPWM_MATCH4 SCTimerPWM_ADD[68]	//!< OFFSET 0x110
#define SCTimerPWM_MATCH5 SCTimerPWM_ADD[69]	//!< OFFSET 0x114
#define SCTimerPWM_MATCH6 SCTimerPWM_ADD[70]	//!< OFFSET 0x118
#define SCTimerPWM_MATCH7 SCTimerPWM_ADD[71]	//!< OFFSET 0x11C
#define SCTimerPWM_CAP0 SCTimerPWM_ADD[64]		//!< OFFSET 0x100
#define SCTimerPWM_CAP1 SCTimerPWM_ADD[65]		//!< OFFSET 0x104
#define SCTimerPWM_CAP2 SCTimerPWM_ADD[66]		//!< OFFSET 0x108
#define SCTimerPWM_CAP3 SCTimerPWM_ADD[67]		//!< OFFSET 0x10C
#define SCTimerPWM_CAP4 SCTimerPWM_ADD[68]		//!< OFFSET 0x110
#define SCTimerPWM_CAP5 SCTimerPWM_ADD[69]		//!< OFFSET 0x114
#define SCTimerPWM_CAP6 SCTimerPWM_ADD[70]		//!< OFFSET 0x118
#define SCTimerPWM_CAP7 SCTimerPWM_ADD[71]		//!< OFFSET 0x11C
// Hay muchas mas



#define PWM_SYSAHB			8
#define PWM_PRESETCTRL		8
#define PWM_OUT				PORT0,0,7,BYTE3 //!< PIO0_00,7 is the PINASSIGN,BYTE3 is to be written

void PWM_Init(uint8_t port, uint8_t pin, uint8_t ena);
void PWM_Preset(void);
void PWM_Enable(void);
void PWM_Disable(void);


#endif /* PWM_FW_H_ */
