/*
 * hj_communication.c
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */

#include "hj_communication.h"

int Transmit_AT_command(UART_HandleTypeDef *huart, const char *pCommand, char *pBuffer, int buffer_size, int timeout)
{
	int res = 0;

	memset((void*)pBuffer, 0, buffer_size);

	res = HAL_UART_Transmit(huart, (uint8_t*)pCommand, strlen(pCommand), timeout);

	if (res != HAL_OK)
		return res;

	res = HAL_UART_Receive(huart, (uint8_t*)pBuffer, buffer_size, timeout);

	return res;
}


void HM10_Initialize(UART_HandleTypeDef *huart)
{
	char rx_buffer[32] = {0};

	__HAL_UART_DISABLE_IT(huart, UART_IT_RXNE);

	Transmit_AT_command(huart, "AT", rx_buffer, sizeof(rx_buffer), 500);

	if (!strcmp(rx_buffer, "OK")) {
		printf("\nAT Command available!\n");
		fflush(stdout);
	}

	HAL_Delay(1000);

	Transmit_AT_command(huart, "AT+ADDR?", rx_buffer, sizeof(rx_buffer), 100);
	printf("ADDR \t: %s\n", rx_buffer);

	Transmit_AT_command(huart, "AT+NAME?", rx_buffer, sizeof(rx_buffer), 100);
	printf("NAME \t: %s\n", rx_buffer);

	Transmit_AT_command(huart, "AT+PASS?", rx_buffer, sizeof(rx_buffer), 100);
	printf("PASSWORD \t: %s\n", rx_buffer);

	Transmit_AT_command(huart, "AT+TYPE?", rx_buffer, sizeof(rx_buffer), 100);
	printf("TYPE \t: %s\n", rx_buffer);

	__HAL_UART_ENABLE_IT(huart, UART_IT_RXNE);
}
