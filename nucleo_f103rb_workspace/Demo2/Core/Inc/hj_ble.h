/*
 * hj_ble.h
 *
 *  Created on: Jun 27, 2024
 *      Author: rlagh
 */

#ifndef INC_HJ_BLE_H_
#define INC_HJ_BLE_H_

#include "hj_def.h"

#include "rb.h"

#define STX		0x02
#define ETX		0x03

#define BLE_DEVICE_VAR			'V'
#define BLE_DEVICE_CDS			'P'
#define BLE_DEVICE_TC1047		'T'
#define BLE_DEVICE_ENCODER		'E'
#define BLE_DEVICE_SERVO		'S'
#define BLE_DEVICE_HDC1080		'I'
#define BLE_DEVICE_DAC			'D'
#define BLE_DEVICE_LED			'L'
#define BLE_DEVICE_RGB			'M'
#define BLE_DEVICE_TSWITCH		'R'
#define BLE_DEVICE_CLCD_L1		'1'
#define BLE_DEVICE_CLCD_L2		'2'

#define BLE_CMD_R				0x52
#define BLE_CMD_W				0x57

//extern RingFifo_t uart1Fifo;

int BLE_Tx_AT_command(UART_HandleTypeDef *huart, const char *pCommand, char *pBuffer, int buffer_size, int timeout);
void BLE_HM10_Init(UART_HandleTypeDef *huart);
int BLE_Wait_packet(int timeout);
uint8_t BLE_Check_Rx_start(void);
uint8_t BLE_Read_command(char *pBuf, size_t bufferSize);

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);

#endif /* INC_HJ_BLE_H_ */
