/**
 \file		: SYSCON_FW.h
 \brief     : Firmware functions for SYSCON
 \details   :
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/


#ifndef SYSCON_FW_H_
#define SYSCON_FW_H_

#define SYSCON_ADD	( ( __RW uint32_t *) 	0x40048000UL)
#define SYSMEMREMAP	SYSCON_ADD [0]
#define SYSPLLCTRL 	SYSCON_ADD [2]
/*
 *
 */
#define SYSPLLSTAT 	SYSCON_ADD [3]
/*
 *
 */
#define SYSOSCCTRL 	SYSCON_ADD [8]
/*
 *
 */
#define WDTOSCCTRL 	SYSCON_ADD [9]
/*
 *
 */
#define FROOSCCTRL 		SYSCON_ADD [10]
/*
 *
 */
#define FRODIRECTCLKUEN	SYSCON_ADD [12]
/*
 *
 */
#define SYSRSTSTAT		SYSCON_ADD [14]
/*
 *
 */
#define SYSPLLCLKSEL	SYSCON_ADD [16]
/*
 *
 */
#define SYSPLLCLKUEN	SYSCON_ADD [17]
/*
 *
 */
#define MAINCLKPLLSEL	SYSCON_ADD [18]
/*
 *
 */
#define MAINCLKPLLUEN	SYSCON_ADD [19]
/*
 *
 */
#define MAINCLKSEL 		SYSCON_ADD [20]
/*
 *
 */
#define MAINCLKUEN		SYSCON_ADD [21]
/*
 *
 */
#define SYSAHBCLKDIV	SYSCON_ADD [22]
/*
 *
 */
#define CAPTCLKSEL		SYSCON_ADD [24]
/*
 *
 */
#define ADCCLKSEL		SYSCON_ADD [25]
/*
 *
 */
#define ADCCLKDIV		SYSCON_ADD [26]
/*
 *
 */
#define SCTCLKSEL 		SYSCON_ADD [27]
/*
 *
 */
#define SCTCLKDIV		SYSCON_ADD [28]
/*
 *
 */
#define EXTCLKSEL		SYSCON_ADD [29]
/*
 *
 */
#define _SYSAHBCLKCTRL0	SYSCON_ADD [32]
/*
 *
 */
#define _SYSAHBCLKCTRL1	SYSCON_ADD [33]
/*
 *
 */
#define PRESETCTRL0		SYSCON_ADD [34]
/*
 *
 */
#define PRESETCTRL1		SYSCON_ADD [35]
/*
 *
 */
#define UART0CLKSEL		SYSCON_ADD [36]
/*
 *
 */
#define UART1CLKSEL		SYSCON_ADD [37]
/*
 *
 */
#define UART2CLKSEL		SYSCON_ADD [38]
/*
 *
 */
#define UART3CLKSEL		SYSCON_ADD [39]
/*
 *
 */
#define UART4CLKSEL		SYSCON_ADD [40]
/*
 *
 */
#define I2C0CLKSEL		SYSCON_ADD [41]
/*
 *
 */
#define I2C1CLKSEL		SYSCON_ADD [42]
/*
 *
 */
#define I2C2CLKSEL		SYSCON_ADD [43]
/*
 *
 */
#define I2C3CLKSEL		SYSCON_ADD [44]
/*
 *
 */
#define SPI0CLKSEL		SYSCON_ADD [45]
/*
 *
 */
#define SPI1CLKSEL		SYSCON_ADD [46]
/*
 *
 */
#define FRG0DIV			SYSCON_ADD [52]
/*
 *
 */
#define FRG0MULT		SYSCON_ADD [53]
/*
 *
 */
#define FRG0CLKSEL		SYSCON_ADD [54]
/*
 *
 */
#define FRG1DIV			SYSCON_ADD [56]
/*
 *
 */
#define FRG1MULT		SYSCON_ADD [57]
/*
 *
 */
#define FRG1CLKSEL		SYSCON_ADD [58]
/*
 *
 */
#define CLKOUTSEL		SYSCON_ADD [60]
/*
 *
 */
#define CLKOUTDIV		SYSCON_ADD [61]
/*
 *
 */
#define EXTTRACECMD		SYSCON_ADD [63]
/*
 *
 */
#define PIOPORCAP0		SYSCON_ADD [64]
/*
 *
 */
#define PIOPORCAP1		SYSCON_ADD [65]
/*
 *
 */
#define _IOCONCLKDIV6	SYSCON_ADD [77]
/*
 *
 */
#define _IOCONCLKDIV5	SYSCON_ADD [78]
/*
 *
 */
#define _IOCONCLKDIV4	SYSCON_ADD [79]
/*
 *
 */
#define _IOCONCLKDIV3	SYSCON_ADD [80]
/*
 *
 */
#define _IOCONCLKDIV2		SYSCON_ADD [81]
/*
 *
 */
#define _IOCONCLKDIV1		SYSCON_ADD [82]
/*
 *
 */
#define _IOCONCLKDIV0		SYSCON_ADD [83]
/*
 *
 */
#define BODCTRL				SYSCON_ADD [84]
/*
 *
 */
#define SYSTCKCAL			SYSCON_ADD [85]
/*
 *
 */
#define IRQLATENCY			SYSCON_ADD [92]
/*
 *
 */
#define NMISRC				SYSCON_ADD [93]
/*
 *
 */
#define PINTSEL0			SYSCON_ADD [94]
/*
 *
 */
#define PINTSEL1			SYSCON_ADD [95]
/*
 *
 */
#define PINTSEL2			SYSCON_ADD [96]
/*
 *
 */
#define PINTSEL3			SYSCON_ADD [97]
/*
 *
 */
#define PINTSEL4			SYSCON_ADD [98]
/*
 *
 */
#define PINTSEL5			SYSCON_ADD [99]
/*
 *
 */
#define PINTSEL6			SYSCON_ADD [100]
/*
 *
 */
#define PINTSEL7			SYSCON_ADD [101]
/*
 *
 */
#define STARTERP0			SYSCON_ADD [129]
/*
 *
 */
#define STARTERP1			SYSCON_ADD [133]
/*
 *
 */
#define PDSLEEPCFG			SYSCON_ADD [140]
/*
 *
 */
#define PDAWAKECFG			SYSCON_ADD [141]
/*
 *
 */
#define PDRUNCFG			SYSCON_ADD [142]
/*
 *
 */
#define DEVICE_ID 			SYSCON_ADD [254]
/*
 *
 */


void BoardClockRUN();

#define	CLOCK_FRO_SETTING_API_ROM_ADDRESS		0x0F0026F5U


#define F30MHz				30000U
void ClockSetFroOscFREQ (uint32_t freq);

#define FRO_OUT_PowerDown	1
#define FRO_PD				2
void PowerDisablePD(uint8_t en);


#define SYSCON_FROOSCCTRL_FRO_DIRECT_MASK 			(0x20000U)
#define SYSCON_FROOSCCTRL_FRO_DIRECT_SHIFT       	(17U)

void CLOCK_SetFroOutClkSrc(uint32_t src);

#define kCLOCK_FroSrcFroOsc 1U << SYSCON_FROOSCCTRL_FRO_DIRECT_SHIFT
#define kPDRUNCFG_PD_SYSOSC 0x20


#define CLK_FROM_SYS_OSC	0x00
#define FREQ30MHz 			30000000U
#define CLK_SYS_PLLSRCFRODIV 0x03

void CLOCK_Select(uint8_t sel);
void CLOCK_InitSystemPll(uint32_t freq, uint8_t src);


uint32_t CLOCK_GetSystemPLLInClockRate(void);
uint32_t CLOCK_GetFroFreq(void);

#define CLOCK_FAIM_BASE 0x50010000U

uint32_t FindSyestemPllPsel(uint32_t outFreq);

#define SYSPLL_MIN_FCCO_FREQ_HZ 156000000U
#define SYSCON_SYSPLLCTRL_MSEL_MASK 0x1FU
#define SYSCON_SYSPLLCTRL_MSEL_SHIFT             (0U)
#define SYSCON_SYSPLLCTRL_PSEL_MASK 0x60U
#define SYSCON_SYSPLLCTRL_PSEL_SHIFT             (5U)
#define SYSCON_SYSPLLCTRL_MSEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_MSEL_SHIFT)) & SYSCON_SYSPLLCTRL_MSEL_MASK)
#define SYSCON_SYSPLLCTRL_PSEL(x)                (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSPLLCTRL_PSEL_SHIFT)) & SYSCON_SYSPLLCTRL_PSEL_MASK)

void CLOCK_SetMainClkSrc(uint32_t src);
#define CLK_MAIN_CLK_MUX_GET_MUX(x)             ((uint32_t)(x) & 0xFFU)
#define CLK_MAIN_CLK_MUX_GET_PRE_MUX(x)         (((uint32_t)(x) >> 8U) & 0xFFU)

#define SYSCON_MAINCLKSEL_SEL_MASK 0x03U
#define SYSCON_MAINCLKSEL_SEL_SHIFT              (0U)
#define SYSCON_MAINCLKSEL_SEL(x)                 (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKSEL_SEL_SHIFT)) & SYSCON_MAINCLKSEL_SEL_MASK)

#define SYSCON_MAINCLKPLLSEL_SEL_MASK            (0x3U)
#define SYSCON_MAINCLKPLLSEL_SEL_SHIFT           (0U)
#define SYSCON_MAINCLKPLLSEL_SEL(x)              (((uint32_t)(((uint32_t)(x)) << SYSCON_MAINCLKPLLSEL_SEL_SHIFT)) & SYSCON_MAINCLKPLLSEL_SEL_MASK)
#define kCLOCK_MainClkSrcFro 0

void CLOCK_SetCoreSysClkDiv (uint32_t value);
#define SYSCON_SYSAHBCLKDIV_DIV(x)               (((uint32_t)(((uint32_t)(x)) << SYSCON_SYSAHBCLKDIV_DIV_SHIFT)) & SYSCON_SYSAHBCLKDIV_DIV_MASK)
#define SYSCON_SYSAHBCLKDIV_DIV_MASK 0xFFU
#define SYSCON_SYSAHBCLKDIV_DIV_SHIFT            (0U)
#endif /* SYSCON_FW_H_ */
