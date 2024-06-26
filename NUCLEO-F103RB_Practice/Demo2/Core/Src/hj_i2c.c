/*
 * hj_i2c.c
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */


#include "hj_i2c.h"

void I2C_Start(I2C_HandleTypeDef *hi2c)
{
	uint16_t i2c_id = 0;
	uint8_t bat_stat = 0;

	hdc1080_read_reg(hi2c, HDC1080_ID_DEV, &i2c_id);
	hdc1080_init(hi2c, HDC1080_T_RES_14, HDC1080_RH_RES_14, 1, &bat_stat);

	printf("HDC1080 ID : %X\n", i2c_id);
}
