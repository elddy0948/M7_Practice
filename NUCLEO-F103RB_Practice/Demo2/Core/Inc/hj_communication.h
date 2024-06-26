/*
 * hj_communication.h
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */

#ifndef INC_HJ_COMMUNICATION_H_
#define INC_HJ_COMMUNICATION_H_

#include "hj_def.h"

/**
 * Using HM-10
 *
 */

#define STX		0x02
#define ETX		0x03

#define COMMUNICATION_DEVICE_VAR		'V'
#define COMMUNICATION_DEVICE_CDS		'P'
#define COMMUNICATION_DEVICE_TC1047		'T'
#define COMMUNICATION_DEVICE_ENCODER	'E'
#define COMMUNICATION_DEVICE_SERVO		'S'
#define COMMUNICATION_DEVICE_HDC1080	'I'
#define COMMUNICATION_DEVICE_DAC		'D'
#define COMMUNICATION_DEVICE_LED		'L'
#define COMMUNICATION_DEVICE_RGB		'M'
#define COMMUNICATION_DEVICE_TSWITCH	'R'
#define COMMUNICATION_DEVICE_CLCD_L1	'1'
#define COMMUNICATION_DEVICE_CLCD_L2	'2'

#define COMMUNICATION_CMD_R				0x52
#define COMMUNICATION_CMD_W				0x57

int Transmit_AT_command(UART_HandleTypeDef *huart, const char *pCommand, char *pBuffer, int buffer_size, int timeout);
void HM10_Initialize(UART_HandleTypeDef *huart);

#endif /* INC_HJ_COMMUNICATION_H_ */
