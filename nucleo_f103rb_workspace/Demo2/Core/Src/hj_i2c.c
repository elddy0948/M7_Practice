/*
 * hj_i2c.c
 *
 *  Created on: Jun 27, 2024
 *      Author: rlagh
 */


#include "hj_i2c.h"

static float hdc_temp = .0;
static uint8_t hdc_hum = 0;

void I2C_Start(I2C_HandleTypeDef *hi2c)
{
	uint16_t i2c_id = 0;
	uint8_t bat_stat = 0;

	hdc1080_read_reg(hi2c, HDC1080_ID_DEV, &i2c_id);
	hdc1080_init(hi2c, HDC1080_T_RES_14, HDC1080_RH_RES_14, 1, &bat_stat);
}

void I2C_HDC1080_Get_values(I2C_HandleTypeDef *hi2c)
{
	hdc1080_measure(hi2c, &hdc_temp, &hdc_hum);
}

uint32_t I2C_HDC1080_Get_temp(void) { return *(uint32_t*) &hdc_temp; }
uint8_t I2C_HDC1080_Get_hum(void) { return hdc_hum; }


