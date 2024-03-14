/*
 * temp_hum.c
 *
 *  Created on: Mar 9, 2024
 *      Author: hojoon
 */

#include "modules/temp_hum.h"

unsigned short adc1_channel10_result = 0;
unsigned short adc1_channel12_result = 0;
unsigned short adc1_channel13_result = 0;

void TempHum_Init(void)
{
	SCB_EnableICache();				// enable L1 instruction cache
	SCB_EnableDCache();				// enable L1 data cache

	FLASH->ACR = 0x00000307;

	RCC->CR |= 0x00010001;
	while((RCC->CR & 0x00000002) == 0);
	RCC->CFGR = 0x00000000;
	while((RCC->CFGR & 0x0000000C) != 0);

	RCC->CR = 0x00010001;
	RCC->PLLCFGR = 0x09403608;
	RCC->CR = 0x01010001;
	while((RCC->CR & 0x02000000) == 0);

	RCC->APB1ENR |= 0x10000000;
	PWR->CR1 |= 0x00010000;
	while((PWR->CSR1 & 0x00010000) == 0);
	PWR->CR1 |= 0x00020000;
	while((PWR->CSR1 & 0x00020000) == 0);

	RCC->CFGR = 0x3040B402;
	while((RCC->CFGR & 0x0000000C) != 0x00000008);
	RCC->CR |= 0x00080000;

	RCC->APB2ENR |= 0x00004000;
	SYSCFG->CMPCR = 0x00000001;
	RCC->APB2ENR |= 0x00000100;	// ADC1 Enable
	GPIOC->MODER |= 0x00000033;	// PC0, PC2 Analog mode

	ADC->CCR = 0x00000000;

	ADC1->SMPR1 = 0x00000041;	// CHANNEL 10, 12 = 15CYCLE
	ADC1->SMPR2 = 0x00000000;

	ADC1->CR1 = 0x00000100;		// 12-BIT RESOLUTION, SET SCAN
	ADC1->CR2 = 0x00000401;		// SET EOCS, ADON

	ADC1->SQR1 = 0x00200000;	// REGULAR CHANNEL SEQUENCE LENGTH = 2
	ADC1->SQR2 = 0x00000000;
	ADC1->SQR3 = 0x0000018A;	// CH 10 -> 12
}

void TempHum_Start(void)
{
	ADC1->CR2 |= 0x40000000;

	while(!(ADC1->SR & 0x00000002));
	adc1_channel10_result = ADC1->DR;
	float temp2 = ((float)adc1_channel10_result * 175. / 16383.);	// 제일 근접.

	while(!(ADC1->SR & 0x00000002));
	adc1_channel12_result = ADC1->DR;
	float humidity= ((float)adc1_channel12_result * 125. / 16383.);

	ADC1->CR2 &= 0x0FFFFFFF;
}
