/*
 * thermometer.h
 *
 *  Created on: Mar 6, 2024
 *      Author: hojoon
 */

#ifndef INC_THERMOMETER_H_
#define INC_THERMOMETER_H_

#include "stm32f767xx.h"
#include "helper.h"

void Thermometer_Init(void);
void Thermometer_Start(void);
float Thermometer_GetTemperature(void);

#endif /* INC_THERMOMETER_H_ */
