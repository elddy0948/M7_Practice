/*
 * hj_ble.c
 *
 *  Created on: Jun 26, 2024
 *      Author: rlagh
 */



#include "hj_ble.h"

RingFifo_t uart1Fifo = {};

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

	RB_init(&uart1Fifo, 64);

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

int WaitPacket(int timeout)
{
	if (!RB_isempty(&uart1Fifo))
		return 0;
	else {
		int timeout_count = 0;
		while (timeout_count <= timeout) {
			if (!RB_isempty(&uart1Fifo))
				break;
			timeout_count++;
			HAL_Delay(1);
		}

		if (timeout_count <= timeout)
			return 0;
		else
			return 1;
	}
}

uint8_t BLE_Check_Rx_start(void)
{
	uint8_t cmd = 0;

	if (!RB_isempty(&uart1Fifo)) {
		cmd = RB_read(&uart1Fifo);
		if (cmd == STX)
			return 1;
	}

	return 0;
}

uint8_t BLE_Read_command(char *pBuf, size_t bufferSize)
{
	memset((void*)pBuf, 0, bufferSize);

	uint8_t index = 0, i = 0;

	HAL_Delay(10);

	pBuf[index++] = STX;

	for (i = 0; i < 3; ++i) {
		if (!WaitPacket(TIMEOUT))
			pBuf[index++] = RB_read(&uart1Fifo);
		else
			return 0;
	}

	for (i = 0; i < pBuf[3] + 1; ++i) {
		if (!WaitPacket(TIMEOUT))
			pBuf[index++] = RB_read(&uart1Fifo);
		else
			return 0;
	}

	printf("Packet received complete : ");

	for (i = 0; i < index; ++i)
		printf("%02x ", pBuf[i]);

	printf("\n\n");
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	uint8_t data = 0;

	if (huart->Instance == USART1) {
		data = (uint8_t)(huart->Instance->DR & (uint8_t)0x00FF);
		RB_write(&uart1Fifo, data);
	}
}
