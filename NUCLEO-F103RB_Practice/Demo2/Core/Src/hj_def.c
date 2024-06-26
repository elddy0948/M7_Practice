/*
 * hj_def.c
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */

#include "hj_def.h"

extern UART_HandleTypeDef huart2;

PUTCHAR_PROTOTYPE
{
	if (ch == '\n')
		HAL_UART_Transmit(&huart2, (uint8_t*)"\r", 1, 0xFFFF);
	HAL_UART_Transmit(&huart2, (uint8_t*)&ch, 1, 0xFFFF);

	return ch;
}
