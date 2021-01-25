/**
 \file		: PWM_FW.h
 \brief     : Firmware functions PWM
 \details   : 12 bits convertion
 \author    : Tobias Bavasso Piizzi
 \date 	    : 17/01/2021
 */

#ifndef PWM_FW_H_
#define PWM_FW_H_

#define SCT_ADD			( ( __RW uint32_t *) 	0x50004000UL) //!< Base address
#define SCT_CONFIG 		SCT_ADD[0]		//!< OFFSET 0x000

#define SCT_CTRL 		SCT_ADD[1]		//!< OFFSET 0x004
#define SCT_CTRL_L		( ( __RW uint16_t *) 	0x50004004UL)[0]
#define SCT_CTRL_H		( ( __RW uint16_t *) 	0x50004006UL)

#define SCT_LIMIT 		SCT_ADD[2]		//!< OFFSET 0x008
#define SCT_LIMIT_L		( ( __RW uint16_t *) 	0x50004008UL)
#define SCT_LIMIT_H		( ( __RW uint16_t *) 	0x5000400AUL)

#define SCT_HALT 		SCT_ADD[3]		//!< OFFSET 0x00C
#define SCT_HALT_L		( ( __RW uint16_t *) 	0x5000400CUL)
#define SCT_HALT_H		( ( __RW uint16_t *) 	0x5000400EUL)

#define SCT_STOP		SCT_ADD[4]		//!< OFFSET 0x010
#define SCT_STOP_L		( ( __RW uint16_t *) 	0x50004010UL)
#define SCT_STOP_H		( ( __RW uint16_t *) 	0x50004012UL)

#define SCT_START		SCT_ADD[5]		//!< OFFSET 0x014
#define SCT_COUNT 		SCT_ADD[16]		//!< OFFSET 0x040
#define SCT_STATE 		SCT_ADD[17]		//!< OFFSET 0x044
#define SCT_INPUT 		SCT_ADD[18]		//!< OFFSET 0x048
#define SCT_REGMODE 	SCT_ADD[19]	//!< OFFSET 0x04C
#define SCT_OUTPUT 		SCT_ADD[20]	//!< OFFSET 0x050
#define SCT_OUTPUTDIRCTRL SCT_ADD[21]	//!< OFFSET 0x054
#define SCT_RES 		SCT_ADD[22]		//!< OFFSET 0x058
#define SCT_DMAREQ0 	SCT_ADD[23]	//!< OFFSET 0x05C
#define SCT_DMAREQ1 	SCT_ADD[24]	//!< OFFSET 0x060
//Creo que las siguientes posiciones de memoria no son necesarias para usa PWM
#define SCT_EVEN 		SCT_ADD[60]		//!< OFFSET 0x0F0
#define SCT_EVFLAG		SCT_ADD[61]	//!< OFFSET 0x0F4
#define SCT_CONEN 		SCT_ADD[62]		//!< OFFSET 0x0F8
#define SCT_CONFLAG 	SCT_ADD[63]	//!< OFFSET 0x0FC
#define SCT_MATCH0 		SCT_ADD[64]	//!< OFFSET 0x100
#define SCT_MATCH0_L		( ( __RW uint16_t *) 	0x50004100UL)[0]


#define SCT_MATCH1 		SCT_ADD[65]	//!< OFFSET 0x104
#define SCT_MATCH2 		SCT_ADD[66]	//!< OFFSET 0x108
#define SCT_MATCH3 		SCT_ADD[67]	//!< OFFSET 0x10C
#define SCT_MATCH4 		SCT_ADD[68]	//!< OFFSET 0x110
#define SCT_MATCH5 		SCT_ADD[69]	//!< OFFSET 0x114
#define SCT_MATCH6 		SCT_ADD[70]	//!< OFFSET 0x118
#define SCT_MATCH7 		SCT_ADD[71]	//!< OFFSET 0x11C

//REVISAR
#define SCT_CAP0 		SCT_ADD[64]		//!< OFFSET 0x100
#define SCT_CAP1 		SCT_ADD[65]		//!< OFFSET 0x104
#define SCT_CAP2 		SCT_ADD[66]		//!< OFFSET 0x108
#define SCT_CAP3 		SCT_ADD[67]		//!< OFFSET 0x10C
#define SCT_CAP4 		SCT_ADD[68]		//!< OFFSET 0x110
#define SCT_CAP5 		SCT_ADD[69]		//!< OFFSET 0x114
#define SCT_CAP6 		SCT_ADD[70]		//!< OFFSET 0x118
#define SCT_CAP7 		SCT_ADD[71]		//!< OFFSET 0x11C

//Definir MATCHREL

#define SCT_MATCHREL0 	SCT_ADD[128]	//!< OFFSET 0x200
#define SCT_MATCHREL1 	SCT_ADD[129]	//!< OFFSET 0x204
#define SCT_MATCHREL2 	SCT_ADD[130]	//!< OFFSET 0x208
#define SCT_MATCHREL3 	SCT_ADD[131]	//!< OFFSET 0x20C
#define SCT_MATCHREL4 	SCT_ADD[132]	//!< OFFSET 0x210
#define SCT_MATCHREL5 	SCT_ADD[133]	//!< OFFSET 0x214
#define SCT_MATCHREL6 	SCT_ADD[134]	//!< OFFSET 0x218
#define SCT_MATCHREL7 	SCT_ADD[135]	//!< OFFSET 0x21C


#define SCT_EV0_STATE	SCT_ADD[192]	//!< OFFSET 0x300
#define SCT_EV0_CTRL	SCT_ADD[193]	//!< OFFSET 0x304
#define SCT_EV1_STATE	SCT_ADD[194]	//!< OFFSET 0x308
#define SCT_EV1_CTRL	SCT_ADD[195]	//!< OFFSET 0x30C
#define SCT_EV2_STATE	SCT_ADD[196]	//!< OFFSET 0x310
#define SCT_EV2_CTRL	SCT_ADD[197]	//!< OFFSET 0x314
#define SCT_EV3_STATE	SCT_ADD[198]	//!< OFFSET 0x318
#define SCT_EV3_CTRL	SCT_ADD[199]	//!< OFFSET 0x31C
#define SCT_EV4_STATE	SCT_ADD[200]	//!< OFFSET 0x320
#define SCT_EV4_CTRL	SCT_ADD[201]	//!< OFFSET 0x324
#define SCT_EV5_STATE	SCT_ADD[202]	//!< OFFSET 0x328
#define SCT_EV5_CTRL	SCT_ADD[203]	//!< OFFSET 0x32C
#define SCT_EV6_STATE	SCT_ADD[204]	//!< OFFSET 0x330
#define SCT_EV6_CTRL	SCT_ADD[205]	//!< OFFSET 0x334
#define SCT_EV7_STATE	SCT_ADD[206]	//!< OFFSET 0x338
#define SCT_EV7_CTRL	SCT_ADD[207]	//!< OFFSET 0x33C

#define SCT_OUT0SET		SCT_ADD[320]	//!< OFFSET 0x500
#define SCT_OUT0CLR		SCT_ADD[321]	//!< OFFSET 0x504
#define SCT_OUT1SET		SCT_ADD[322]	//!< OFFSET 0x508
#define SCT_OUT1CLR		SCT_ADD[323]	//!< OFFSET 0x50C
#define SCT_OUT2SET		SCT_ADD[324]	//!< OFFSET 0x510
#define SCT_OUT2CLR		SCT_ADD[325]	//!< OFFSET 0x514
#define SCT_OUT3SET		SCT_ADD[326]	//!< OFFSET 0x518
#define SCT_OUT3CLR		SCT_ADD[327]	//!< OFFSET 0x51C
#define SCT_OUT4SET		SCT_ADD[328]	//!< OFFSET 0x520
#define SCT_OUT4CLR		SCT_ADD[329]	//!< OFFSET 0x524
#define SCT_OUT5SET		SCT_ADD[330]	//!< OFFSET 0x528
#define SCT_OUT5CLR		SCT_ADD[331]	//!< OFFSET 0x52C
#define SCT_OUT6SET		SCT_ADD[332]	//!< OFFSET 0x530
#define SCT_OUT6CLR		SCT_ADD[333]	//!< OFFSET 0x534




// Hay muchas mas



#define SCT_SYSAHB			8
#define SCT_PRESETCTRL		8


void SCT_Init(uint8_t port, uint8_t pin, uint8_t assign, uint8_t byte);

void PWM_Set(uint8_t val);

void SCT_Preset(void);
void SCT_Enable(void);
void SCT_Disable(void);


#define PWM			PORT0,0,SCT_OUT0,BYTE3	//PWM at PIO0_0
#define OUT0		0						//SCT_OUT= as PWM
#define PWM_FREQ	10					//Freq = 10KHz
#define PWM_PERIOD	(1000000/(PWM_FREQ*2))	//PWM counter period
#define PWM_STEP	(PWM_PERIOD/100)


#endif /* PWM_FW_H_ */
