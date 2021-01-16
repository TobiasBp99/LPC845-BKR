/**
 \file		: DAC_FW.h
 \brief     : Firmware functions for DAC 10 bits
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 12/01/2021
 */

#ifndef DAC_FW_H_
#define DAC_FW_H_


#define DAC0_CR 		( ( __RW dac_cr_t *)	0x40014000UL) //!< Pointer to a struct in that memory
#define DAC1_CR 		( ( __RW dac_cr_t *)	0x40018000UL) //!< Pointer to a struct in that memory
typedef struct {	//!< Struct for handling adc configuration
	union {			//!< Union between _CR and bit field; They're overlapped
		__RW uint32_t _CR;
		struct {
			__RW uint32_t _RESERVED_0 	:6;
			__RW uint32_t _VALUE		:10;//!< 3.3V*Value/1024 = VDAC
			__RW uint32_t _BIAS		 	:1;	//!< Settling time
			__RW uint32_t _LPWRMODE 	:15;
		};
	};
} dac_cr_t;


#define DAC0_CTRL 		( ( __RW dac_ctrl_t *)	0x40014004UL) //!< Pointer to a struct in that memory
#define DAC1_CTRL 		( ( __RW dac_ctrl_t *)	0x40018004UL) //!< Pointer to a struct in that memory
typedef struct {	//!< Struct for handling adc configuration
	union {			//!< Union between _CR and bit field; They're overlapped
		__RW uint32_t _CTRL;
		struct {
			__RW uint32_t _INT_DMA_REQ 	:1;	//!< DMA interrupt request
			__RW uint32_t _DBLBUF_ENA	:1;	//!< Double buffer
			__RW uint32_t _CNT_ENA	 	:1;	//!< Time-out counter operation
			__RW uint32_t _DMA_ENA	 	:1;	//!< DMA acces
			__RW uint32_t _RESERVED_0 	:28;
		};
	};
} dac_ctrl_t;

#define DAC0_CNTVAL 		( ( __RW dac_cntval_t *)	0x40014008UL) //!< Pointer to a struct in that memory
#define DAC1_CNTVAL			( ( __RW dac_cntval_t *)	0x40018008UL) //!< Pointer to a struct in that memory
typedef struct {	//!< Struct for handling adc configuration
	union {			//!< Union between _CR and bit field; They're overlapped
		__RW uint32_t _CNTVAL;
		struct {
			__RW uint32_t _VALUE	 	:16;//!< 16b reload value for DAC interrupt/DMA timer
			__RW uint32_t _RESERVED_0	:16;
		};
	};
} dac_cntval_t;


#define DACOUT0	PORT0,17,26	//!<  26 is the bit in PINENABLE

#define MASK_DAC0_SYSCON 	13
#define MASK_DAC1_SYSCON 	14
#define DAC0_SYSAHB			27
#define DAC1_SYSAHB			27
#define DACMODE_IOCON		1<<17
#define DAC_ENABLE_IOCON	1		//!< Enable DACOUT in IOCON

void DAC0_Init(uint8_t port, uint8_t pin, uint8_t ena);
void DAC_Power(void);
void DAC_Enable(void);
void DAC_Disable(void);
void DAC0_SetValue(void);


#endif /* DAC_FW_H_ */
