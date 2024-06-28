/*
 * hj_def.h
 *
 *  Created on: Jun 27, 2024
 *      Author: rlagh
 */

#ifndef INC_HJ_DEF_H_
#define INC_HJ_DEF_H_

#include <stdio.h>
#include <string.h>

#include "stm32f1xx_hal.h"

#define TX_VAR		0
#define TX_CDS		1
#define TX_TC1047	2
#define TX_ENCODER	3
#define TX_HDC1080	4
#define TX_LED		5
#define TX_RGB		6
#define TX_TSWITCH	7

#define TIMEOUT		1000

extern UART_HandleTypeDef huart2;

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE		int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE		int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE;

#endif /* INC_HJ_DEF_H_ */
