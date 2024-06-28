/*
 * hj_adc.h
 *
 *  Created on: Jun 26, 2024
 *      Author: rlagh
 */

#ifndef INC_HJ_ADC_H_
#define INC_HJ_ADC_H_

#include "hj_def.h"

/**
 * ADC related features
 *
 * VAR 		: 		ADC1_IN0(PA0)
 * CDS 		: 		ADC1_IN1(PA1)
 * TC1014 	: 		ADC1_IN4(PA4)
 */

extern volatile uint16_t adcValues[3];;

void ADC_Start(ADC_HandleTypeDef *hadc);

uint16_t ADC_Get_VAR(void);
uint16_t ADC_Get_CDS(void);
uint32_t ADC_Get_TC1014(void);

#endif /* INC_HJ_ADC_H_ */
