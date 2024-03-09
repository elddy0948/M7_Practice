/*
 * thermometer.c
 *
 *  Created on: Mar 6, 2024
 *      Author: hojoon
 */

#include "thermometer.h"

unsigned int i = 0, result = 0;
unsigned short adc1_channel10_result = 0;
unsigned short adc1_channel12_result = 0;
unsigned short adc1_channel13_result = 0;

// Sensor = ETH-01DV (resolution 14bit)
// Vcc = 3.3V
// RH = -12.5 + 125 x (VRHout÷VDD)
// T(°C) = -66.875 + 218.75 x (VTout÷VDD)

void Thermometer_Init(void)
{
	RCC->APB2ENR |= 0x00000100;	// ADC1 Enable
	GPIOC->MODER |= 0x000000F3;	// PC0, PC2, PC3 Analog mode

	ADC->CCR = 0x00000000;

	ADC1->SMPR1 = 0x00000241;	// CHANNEL 10, 12, 13 = 15CYCLE
	ADC1->SMPR2 = 0x00000000;

	ADC1->CR1 = 0x00000100;		// 12-BIT RESOLUTION, SET SCAN
	ADC1->CR2 = 0x00000401;		// SET EOCS, ADON

	ADC1->SQR1 = 0x00300000;	// REGULAR CHANNEL SEQUENCE LENGTH = 3
	ADC1->SQR2 = 0x00000000;
	ADC1->SQR3 = 0x0000358A;	// CH 10 -> 12 -> 13
}

void Thermometer_Start(void)
{
	ADC1->CR2 |= 0x40000000;

	while(!(ADC1->SR & 0x00000002));
	adc1_channel10_result = ADC1->DR;
	float temp2 = ((float)adc1_channel10_result * 175. / 16383.);	// 제일 근접.

	while(!(ADC1->SR & 0x00000002));
	adc1_channel12_result = ADC1->DR;
	float humidity= ((float)adc1_channel12_result * 125. / 16383.);

	//while(!(ADC1->SR & 0x00000002));
	//adc1_channel13_result = ADC1->DR;
}

float Thermometer_GetTemperature(void)
{
	result = 0;
	for(i = 0; i < 256; ++i)
	{
		ADC1->CR2 |= 0x40000000;	// Start conversion
		while(!(ADC1->SR & 0x00000002)); // End of conversion
		result += ADC1->DR;
		Delay_ms(1);
	}

	result >>= 8;	// average result

	float voltage = (float)result; // Convert raw value to voltage
	float temperature = -66.875 + 217.75 * (voltage / 330.); // Calculate temperature
	return temperature;
}

