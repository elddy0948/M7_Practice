/*
 * hj_adc.c
 *
 *  Created on: Jun 26, 2024
 *      Author: rlagh
 */

#include "hj_adc.h"

volatile uint16_t adcValues[3] = {0};

void ADC_Start(ADC_HandleTypeDef *hadc)
{
	uint8_t res = 0;

	res = HAL_ADCEx_Calibration_Start(hadc);

	if (res != HAL_OK)
		return;

	res = HAL_ADC_Start_DMA(hadc, (uint32_t*)&adcValues, 3);

	if (res != HAL_OK)
		return;

	HAL_Delay(100);
}


uint16_t ADC_Get_VAR(void)
{
	return adcValues[0];
}

uint16_t ADC_Get_CDS(void)
{
	return adcValues[1];
}

uint32_t ADC_Get_TC1014(void)
{
	float fTemp = (float)(((adcValues[2] * 3.3 / 4096 * 1000) - 500) / 10);
	uint32_t temp = *(uint32_t*)&fTemp;

	return temp;
}
