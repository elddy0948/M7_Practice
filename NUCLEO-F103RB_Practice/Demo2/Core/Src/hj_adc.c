/*
 * hj_adc.c
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */

#include "hj_adc.h"

static volatile uint16_t adc_values[3] = {0};

void ADC_Start(ADC_HandleTypeDef *hadc)
{
	uint8_t res = 0;

	res = HAL_ADCEx_Calibration_Start(hadc);

	if (res != HAL_OK)
		Error_Handler();

	res = HAL_ADC_Start_DMA(hadc, (uint32_t*)&adc_values, 3);

	if (res != HAL_OK)
		Error_Handler();

	HAL_Delay(100);
}
