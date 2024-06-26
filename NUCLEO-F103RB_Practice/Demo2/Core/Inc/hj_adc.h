/*
 * hj_adc.h
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */

#ifndef INC_HJ_ADC_H_
#define INC_HJ_ADC_H_

#include "hj_def.h"

static volatile uint16_t adc_values[3];

void ADC_Start(ADC_HandleTypeDef *hadc);

#endif /* INC_HJ_ADC_H_ */
