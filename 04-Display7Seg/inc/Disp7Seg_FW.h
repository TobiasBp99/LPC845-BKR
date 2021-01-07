/**
 \file		: Disp7Seg_FW.h
 \brief     : Firmware functions for DISP7SEG
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 07/01/2021
*/

#ifndef DISP7SEG_FW_H_
#define DISP7SEG_FW_H_

#define SEG_A 	PORT0,21 	//!< Pin to connect segA
#define SEG_B 	PORT0,22	//!< Pin to connect segB
#define SEG_C 	PORT0,16	//!< Pin to connect segC
#define SEG_D 	PORT0,17	//!< Pin to connect segD
#define SEG_E 	PORT0,18	//!< Pin to connect segE
#define SEG_F 	PORT0,20	//!< Pin to connect segF
#define SEG_G 	PORT0,19	//!< Pin to connect segG
#define SEG_DP	PORT0,23	//!< Pin to connect segDP


#define TR_D1	PORT0,0		//!< Pin to connect transistor DISP1
#define TR_D0	PORT0,1		//!< Pin to connect transistor DISP0

#define DIGITS	2			//!< Number of displays
#define DIGIT_0	0
#define DIGIT_1 1
void DISP7SEG_Init(void);
void DISP_Sweep(void);



#endif /* DISP7SEG_FW_H_ */
