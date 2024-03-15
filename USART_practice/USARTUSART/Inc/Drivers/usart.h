/*
 * usart.h
 *
 *  Created on: Mar 15, 2024
 *      Author: hojoon
 */

#ifndef DRIVERS_USART_H_
#define DRIVERS_USART_H_

#include <stdint.h>

typedef struct
{
	uint8_t USART_Mode;	// RX TX RX&TX
	uint32_t USART_Baud;
	uint8_t USART_NoOfStopBits;
	uint8_t USART_WordLength;
	uint8_t USART_ParityControl;
	uint8_t USART_HWFlowControl;
} USART_Config_t;

typedef struct
{
	USART_RegDef_t *pUSARTx;
	USART_Config_t USART_Config;
} USART_Handle_t;


// USART Mode
#define USART_MODE_ONLY_TX 0
#define USART_MODE_ONLY_RX 1
#define USART_MODE_TXRX 2

// USART Baud
#define USART_STD_BAUD_9600		9600
#define USART_STD_BAUD_19200	19200
#define USART_STD_BAUD_38400	38400
#define USART_STD_BAUD_115200	115200

// USART ParityControl
#define USART_PARITY_EN_ODD		2
#define USART_PARITY_EN_EVEN	1
#define USART_PARITY_DISABLE	0

// USART WORD LENGTH
#define USART_WORDLEN_8BITS	0
#define USART_WORDLEN_9BITS	1

#define USART_STOPBITS_1	0
#define USART_STOPBITS_0_5	1
#define USART_STOPBITS_2	2
#define USART_STOPBITS_1_5	3

// USART HWFlowControl
#define USART_HW_FLOW_CTRL_NONE		0
#define USART_HW_FLOW_CTRL_CTS		1
#define USART_HW_FLOW_CTRL_RTS		2
#define USART_HW_CTRL_CTRL_CTS_RTS	3


#endif /* DRIVERS_USART_H_ */
