/**
 \file		: ADC_FW.h
 \brief     : Firmware functions ADC
 \details   : 12 bits convertion
 \author    : Tobias Bavasso Piizzi
 \date 	    : 08/01/2021
 */

#ifndef ADC_FW_H_
#define ADC_FW_H_

#define MASK_ADC_SYSCON		4
#define ADC_SYSAHB			24

#define ADC_0				PORT0,7,14 //!< POT1 on board; 14 is the bit in PINENABLE

void ADC_Init(uint8_t port, uint8_t pin, uint8_t ena);
void ADC_Power(void);
void ADC_Enable(void);
void ADC_Disable(void);


#define ADC_ADD	( ( __RW uint32_t *) 	0x4001C000UL)

#define _ADC_CTRL 			ADC_ADD[0]	//0x00
#define _ADC_SEQA_CTRL 		ADC_ADD[2]	//0x08
#define _ADC_SEQB_CTRL 		ADC_ADD[3]	//0x0C
#define _ADC_SEQA_GDAT 		ADC_ADD[4]	//0x10
#define _ADC_SEQB_GDAT 		ADC_ADD[5]	//0x14
#define _ADC_DAT0	 		ADC_ADD[8]	//0x20
#define _ADC_DAT1	 		ADC_ADD[9]	//0x24
#define _ADC_DAT2	 		ADC_ADD[10]	//0x28
#define _ADC_DAT3	 		ADC_ADD[11]	//0x2C
#define _ADC_DAT4	 		ADC_ADD[12]	//0x30
#define _ADC_DAT5	 		ADC_ADD[13]	//0x34
#define _ADC_DAT6	 		ADC_ADD[14]	//0x38
#define _ADC_DAT7	 		ADC_ADD[15]	//0x3C
#define _ADC_DAT8	 		ADC_ADD[16]	//0x40
#define _ADC_DAT9	 		ADC_ADD[17]	//0x44
#define _ADC_DAT10	 		ADC_ADD[18]	//0x48
#define _ADC_DAT11	 		ADC_ADD[19]	//0x4C
#define _ADC_THR0_LOW 		ADC_ADD[20]	//0x50
#define _ADC_THR1_LOW 		ADC_ADD[21]	//0x54
#define _ADC_THR0_HIGH_ 	ADC_ADD[22]	//0x58
#define _ADC_THR1_HIGH_ 	ADC_ADD[23]	//0x5C
#define _ADC_CHAN_THRSEL	ADC_ADD[24]	//0x60
#define ADC_INTEN			ADC_ADD[25]	//0x64
#define ADC_FLAGS			ADC_ADD[26]	//0x68
#define ADC_TRM				ADC_ADD[27]	//0x60
//Debo mapear bien las cosas, quizá con struct

//1 definir la estructura de control


#define ADC_CTRL 		( ( __RW adc_ctrl_t *)	0x4001C000UL) //!< Pointer to a struct in that memory
typedef struct {	//!< Struct for handling adc configuration
	union {			//!< Union between _CTRL and bit field; They're overlapped
		__RW uint32_t _CTRL;
		struct {
			__RW uint32_t _CLKDIV 		:8;	//!< Clock divided by this + 1 to produce sampling clock <= 30MHz
			__RW uint32_t _ASYNCMODE	:1;	//!< Asyncronous operation mode
			__RW uint32_t _RESERVED_0 	:1;
			__RW uint32_t _LPWRMODE 	:1;	//!< Power down ADC while is not used
			__RW uint32_t _RESERVED_1 	:19;
			__RW uint32_t _CALMODE 		:1; //!< Self calibration
			__RW uint32_t _RESERVED_2 	:1;
		};
	};
} adc_ctrl_t;


#define ADC_SEQA_CTRL 	( ( __RW adc_seqX_ctrl *)	0x4001C008UL) //!< Pointer to a struct in that memory
#define ADC_SEQB_CTRL 	( ( __RW adc_seqX_ctrl *)	0x4001C00CUL) //!< Pointer to a struct in that memory
typedef struct {
	union {
		__RW uint32_t _SEQx_CTRL;
		struct {
			__RW uint32_t _CHANNELS 	:12;//!< Select which channel will be sampled
			__RW uint32_t _TRIGGER 		:3;	//!< Select which HW trigger will start convertion
			__RW uint32_t _RESERVED_0 	:3;	//!<
			__RW uint32_t _TRIGPOL 		:1;	//!< Polarity of the input trigger
			__RW uint32_t _SYNCBYPASS 	:1;	//!< Byspass syncronization FF, so is slower
			__RW uint32_t _TSAMP		:5;	//!<
			__RW uint32_t _RESERVED_1	:1;	//!<
			__RW uint32_t _START		:1;	//!< Launch one pass
			__RW uint32_t _BURST		:1;	//!< Sequence continuosly converted
			__RW uint32_t _SINGLESTEP	:1;	//!< When start in 1 this converts only the next channel
			__RW uint32_t _LOWPRIO		:1;	//!< Set priority for sequence A
			__RW uint32_t _MODE			:1;	//!< Read global data or individual channel
			__RW uint32_t _SEQx_ENA		:1;	//!< Enable sequence

		};
	};
} adc_seqX_ctrl;


#define ADC_SEQA_GDAT 	( ( __RW adc_seqX_gdat *)	0x4001C010UL) //!< Pointer to a struct in that memory
#define ADC_SEQB_GDAT 	( ( __RW adc_seqX_gdat *)	0x4001C014UL) //!< Pointer to a struct in that memory
#define ADC_DAT0		( ( __RW adc_seqX_gdat *)	0x4001C020UL) //!< Pointer to a struct in that memory
#define ADC_DAT1		( ( __RW adc_seqX_gdat *)	0x4001C024UL) //!< Pointer to a struct in that memory
#define ADC_DAT2		( ( __RW adc_seqX_gdat *)	0x4001C028UL) //!< Pointer to a struct in that memory
#define ADC_DAT3		( ( __RW adc_seqX_gdat *)	0x4001C02CUL) //!< Pointer to a struct in that memory
#define ADC_DAT4		( ( __RW adc_seqX_gdat *)	0x4001C030UL) //!< Pointer to a struct in that memory
#define ADC_DAT5		( ( __RW adc_seqX_gdat *)	0x4001C034UL) //!< Pointer to a struct in that memory
#define ADC_DAT6		( ( __RW adc_seqX_gdat *)	0x4001C038UL) //!< Pointer to a struct in that memory
#define ADC_DAT7		( ( __RW adc_seqX_gdat *)	0x4001C03CUL) //!< Pointer to a struct in that memory
#define ADC_DAT8		( ( __RW adc_seqX_gdat *)	0x4001C040UL) //!< Pointer to a struct in that memory
#define ADC_DAT9		( ( __RW adc_seqX_gdat *)	0x4001C044UL) //!< Pointer to a struct in that memory
#define ADC_DAT10		( ( __RW adc_seqX_gdat *)	0x4001C048UL) //!< Pointer to a struct in that memory
#define ADC_DAT11		( ( __RW adc_seqX_gdat *)	0x4001C04CUL) //!< Pointer to a struct in that memory
typedef struct {
	union {
		__RW uint32_t _SEQx_GDAT;
		struct {
			__RW uint32_t _RESERVED_0 	:4;
			__RW uint32_t _RESULT 		:12;//!< 12 bit A/D convertion
			__RW uint32_t _THCMPRANGE 	:2;	//!< Compare the result with thrn_low and thrn_high
			__RW uint32_t _THCMPCROSS 	:2;	//!< Indicates a crossing of the threshold
			__RW uint32_t _RESERVED_1 	:6;
			__RW uint32_t _CHN			:4; //!< Indicates the channel converted
			__RW uint32_t _OVERRUN		:1; //!< If a new convertion was loaded and the previous was not read
			__RW uint32_t _DATAVALID	:1; //!< There's a new result
		};
	};
} adc_seqX_gdat;


#define ADC_THR0_LOW 	( ( __RW adc_thr *)	0x4001C050UL) //!< Pointer to a struct in that memory
#define ADC_THR1_LOW 	( ( __RW adc_thr *)	0x4001C054UL) //!< Pointer to a struct in that memory
#define ADC_THR0_HIGH 	( ( __RW adc_thr *)	0x4001C058UL) //!< Pointer to a struct in that memory
#define ADC_THR1_HIGH 	( ( __RW adc_thr *)	0x4001C05CUL) //!< Pointer to a struct in that memory
typedef struct{
	union{
		__RW uint32_t _THRn_LH;
		struct{
			__RW uint32_t _RESERVED_0	:4;
			__RW uint32_t _THR			:12;//!< 12bits for compare
			__RW uint32_t _RESERVED_1	:16;
		};
	};
} adc_thr;


#define ADC_CHAN_THRSEL 	( ( __RW adc_chan *)	0x4001C060UL) //!< Pointer to a struct in that memory
typedef struct{
	union{
		__RW uint32_t _CHAN_THRSEL;
		struct{
			__RW uint32_t _CH0_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH1_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH2_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH3_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH4_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH5_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH6_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH7_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH8_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH9_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH10_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _CH11_THRSEL	:1;	//!< Compare against THR
			__RW uint32_t _RESERVED		:20;

		};
	};
} adc_chan;

#define MASK_SEQA_INTEN 	1<<0	//!< Interrupt after each conv
#define MASK_SEQB_INTEN 	1<<1	//!< Interrupt after each conv
#define MASK_ISE_ADC_SEQA	1<<16	//!< Enable Interrupt NVIC
#define MASK_ISE_ADC_SEQB	1<<17	//!< Enable Interrupt NVIC



#endif /* ADC_FW_H_ */
