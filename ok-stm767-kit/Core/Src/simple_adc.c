/*
 * simple_adc.c
 *
 *  Created on: Feb 26, 2024
 *      Author: hojoon
 */

#include "simple_adc.h"
#include "stm32f767xx.h"

void adc_init(void)
{
	GPIOA->MODER |= 0x000000FF;
	RCC->APB2ENR |= 0x00000100;

	ADC->CCR = 0x00800000;
	ADC1->SMPR1 = 0x07E00000;
	ADC1->SMPR2 = 0x00000249;
	ADC1->CR1 = 0x00000000;
	ADC1->CR2 = 0x00000001;
	ADC1->SQR1 = 0x00000000;
}

void temerature_setup(void)
{
	float temperature = 0.0f;
	unsigned short result = 0;

	ADC->CCR &= 0xFFBFFFFF;
	// Some Delay
	ADC1->SQR3 = 0x00000011;
	ADC1->CR2 |= 0x40000000;
	while(!(ADC1->SR & 0x00000002));
	result = ADC1->DR;

	ADC1->SQR3 = 0x00000012;
	ADC1->CR2 |= 0x40000000;
	while(!(ADC1->SR & 0x00000002));
	result = ADC1->DR;
	temperature = (float)result * 3.3 / 4095.;
	temperature = (temperature - 0.76) / 0.0025 + 25.;
}
