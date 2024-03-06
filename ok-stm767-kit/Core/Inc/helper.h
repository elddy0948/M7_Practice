/*
 * helper.h
 *
 *  Created on: Feb 29, 2024
 *      Author: hojoon
 */

#ifndef INC_HELPER_H_
#define INC_HELPER_H_

#include "stm32f7xx.h"
#include "stm32f767xx.h"
#include "stm32f7xx_hal.h"

void Delay_us(unsigned int time_us);
void Delay_ms(unsigned int time_ms);

void Initialize_MCU(void);

#endif /* INC_HELPER_H_ */
