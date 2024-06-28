/*
 * hj_i2c.h
 *
 *  Created on: Jun 27, 2024
 *      Author: rlagh
 */

#ifndef INC_HJ_I2C_H_
#define INC_HJ_I2C_H_

#include "hj_def.h"

#include "hdc1080.h"

extern float hdc_temp;
extern uint8_t hdc_hum;

void I2C_Start(I2C_HandleTypeDef *hi2c);
void I2C_HDC1080_Get_values(I2C_HandleTypeDef *hi2c);
uint32_t I2C_HDC1080_Get_temp(void);
uint8_t I2C_HDC1080_Get_hum(void);

#endif /* INC_HJ_I2C_H_ */
