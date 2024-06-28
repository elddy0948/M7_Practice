/*
 * hj_spi.c
 *
 *  Created on: Jun 28, 2024
 *      Author: rlagh
 */


#include "hj_spi.h"

unsigned short dacData = 4095;

uint8_t DAC7512_write(SPI_HandleTypeDef *hspi)
{
	uint8_t buf[2], res;

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);

	buf[0] = (uint8_t)(dacData >> 8);
	buf[1] = (uint8_t)dacData;

	res = HAL_SPI_Transmit(hspi, buf, 2, 1000);

	if (res)
		return res;

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);

	return 0;
}

void DAC7512_Set_data(unsigned short data)
{
	dacData = data;
}
