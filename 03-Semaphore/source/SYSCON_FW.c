/**
 \file		: SYSCON_FW.c
 \brief     : Firmware functions for SYSCON
 \details   : Only starts the board at 30MHz
 \author    : Tobias Bavasso Piizzi
 \date 	    : 04/01/2021
*/
#include "Aplication.h"

/**
 * \fn 		: void BoardClockRUN(void)
 * \brief 	: Runs clock at 30MHz
 * \details : Select clock from fro
 * \author 	: Tobias Bavasso Piizzi
 * \date   	: 04/01/2021
 * \param 	: [in]  void
 * \return 	: void
 * */
void BoardClockRUN(void) {
	PowerDisablePD(FRO_OUT_PowerDown);
	PowerDisablePD(FRO_PD);
	ClockSetFroOscFREQ(F30MHz);
	CLOCK_SetFroOutClkSrc(kCLOCK_FroSrcFroOsc);
	PowerDisablePD(kPDRUNCFG_PD_SYSOSC);
	CLOCK_Select(CLK_FROM_SYS_OSC);
	CLOCK_InitSystemPll(FREQ30MHz, CLK_SYS_PLLSRCFRODIV);
	CLOCK_SetMainClkSrc(kCLOCK_MainClkSrcFro);
	CLOCK_SetCoreSysClkDiv(1U);
}

void ClockSetFroOscFREQ(uint32_t freq) {
	(*((void (*)(uint32_t freq)) (CLOCK_FRO_SETTING_API_ROM_ADDRESS)))(freq);
}

void PowerDisablePD(uint8_t en) {
	PDRUNCFG&= (~en);
}

void CLOCK_SetFroOutClkSrc(uint32_t src) {
	if (src != (FROOSCCTRL & SYSCON_FROOSCCTRL_FRO_DIRECT_MASK)) {

		FROOSCCTRL = (FROOSCCTRL & (~ SYSCON_FROOSCCTRL_FRO_DIRECT_MASK)) | src;
		FRODIRECTCLKUEN &= (~0x01);
		FRODIRECTCLKUEN |= 0x01;
		while( (FRODIRECTCLKUEN & 0x01) == 0 );

	}

}

void CLOCK_Select(uint8_t sel) {
	EXTCLKSEL&= (~0x01);
	EXTCLKSEL |= sel;
}

void CLOCK_InitSystemPll(uint32_t freq, uint8_t src) {
	uint32_t mSel = 0U;
	uint32_t pSel = 0U;
	uint32_t inputFreq = 0U;

	PDRUNCFG|= 0x80;

	SYSPLLCLKSEL|= (SYSPLLCLKSEL & (~0x3U)) | src;

	//CLOCK_UpdateClkSrc((__RW uint32_t *)(SYSPLLCLKUEN), 0x3U);
	SYSPLLCLKSEL&= (~0x3U);
	SYSPLLCLKSEL|= (0x3U);
	while ((SYSPLLCLKSEL& 0x3U) == 0 );

	inputFreq = CLOCK_GetSystemPLLInClockRate();

	mSel = freq / inputFreq;
	pSel = FindSyestemPllPsel(freq);

	SYSPLLCTRL= (SYSPLLCTRL & (~(SYSCON_SYSPLLCTRL_MSEL_MASK | SYSCON_SYSPLLCTRL_PSEL_MASK))) | SYSCON_SYSPLLCTRL_MSEL(mSel == 0U ? 0U : (mSel - 1U)) | SYSCON_SYSPLLCTRL_PSEL(pSel);

	PDRUNCFG&= ~0x80;

	while ((SYSPLLSTAT& 0x01) == 0 );

}

uint32_t CLOCK_GetSystemPLLInClockRate(void) {
	uint32_t freq = 0U;
	switch (SYSPLLCLKSEL) {
		case 0x03U:
		freq = CLOCK_GetFroFreq() >>1U;
		break;
		case 0x00U:
		break;
		case 0x01U:
		break;
		case 0x02U:
		break;
		default:
		break;
	}
	return (freq);
}

uint32_t CLOCK_GetFroFreq(void) {
	uint32_t froOscSel = FROOSCCTRL& 3U;
	uint32_t froOscFreq = 0U;

	if (froOscSel == 0U) {
		froOscFreq = 18000000U;
	}
	else {
		if (froOscSel == 1U) {
			froOscFreq = 24000000U;
		}
		else {
			froOscFreq = 30000000U;
		}
	}

	if( ((FROOSCCTRL & 0x20000U)>> 17U) == 0) {
		froOscFreq /= (*((__RW uint32_t *)(CLOCK_FAIM_BASE)) & 0x2U) ? 16U : 2U;
	}
	return froOscFreq;

}

uint32_t FindSyestemPllPsel(uint32_t outFreq) {
	uint32_t pSel = 0U;

	if (outFreq > (SYSPLL_MIN_FCCO_FREQ_HZ >> 1U)) {
		pSel = 0U;
	} else if (outFreq > (SYSPLL_MIN_FCCO_FREQ_HZ >> 2U)) {
		pSel = 1U;
	} else if (outFreq > (SYSPLL_MIN_FCCO_FREQ_HZ >> 3U)) {
		pSel = 2U;
	} else {
		pSel = 3U;
	}

	return pSel;

}

void CLOCK_SetMainClkSrc(uint32_t src) {

	uint32_t mainMux = CLK_MAIN_CLK_MUX_GET_MUX(src), mainPreMux =
			CLK_MAIN_CLK_MUX_GET_PRE_MUX(src);

	if (((MAINCLKSEL & SYSCON_MAINCLKSEL_SEL_MASK) != mainPreMux) && (mainMux == 0U))
	{
		MAINCLKSEL = (MAINCLKSEL & (~SYSCON_MAINCLKSEL_SEL_MASK)) | SYSCON_MAINCLKSEL_SEL(mainPreMux);
		//CLOCK_UpdateClkSrc((volatile uint32_t *)(&(SYSCON->MAINCLKUEN)), SYSCON_MAINCLKUEN_ENA_MASK);
		MAINCLKUEN &= ~(0x03);
		MAINCLKUEN |= (0x03);
		while( (MAINCLKUEN & 0x03) == 0);
	}

	if ((MAINCLKPLLSEL & SYSCON_MAINCLKPLLSEL_SEL_MASK) != mainMux)
	{
		MAINCLKPLLSEL = (MAINCLKPLLSEL & (~SYSCON_MAINCLKPLLSEL_SEL_MASK)) | SYSCON_MAINCLKPLLSEL_SEL(mainMux);
		//CLOCK_UpdateClkSrc((volatile uint32_t *)(&(SYSCON->MAINCLKPLLUEN)), SYSCON_MAINCLKPLLUEN_ENA_MASK);
		MAINCLKPLLUEN &= ~(0x01);
		MAINCLKPLLUEN |= (0x01);
		while( (MAINCLKUEN & 0x01) == 0);
	}

}

void CLOCK_SetCoreSysClkDiv (uint32_t value){
	SYSAHBCLKDIV = (SYSAHBCLKDIV & ~(0xFFU)) | SYSCON_SYSAHBCLKDIV_DIV(value);
}


