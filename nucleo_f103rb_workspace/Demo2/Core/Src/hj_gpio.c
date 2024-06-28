/*
 * hj_gpio.c
 *
 *  Created on: Jun 28, 2024
 *      Author: rlagh
 */

#include "hj_gpio.h"

volatile int ledState = 0;
volatile int switchState = 0;
volatile int encoderValue = 0;
char clcd[17] = {0};

void GPIO_CLCD_start(void)
{
	CLCD_Init(16, 2);
	printf("CLCD Start\n");
}

int GPIO_Get_LED_state(void)
{
	ledState = (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_6) << 24) |
			(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7) << 16) |
			(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11) << 8) |
			(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12));

	return ledState;
}

int GPIO_Get_SW_state(void)
{
	switchState = ((!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_1)) << 24) |
			((!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2)) << 16) |
			((!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_4)) << 8) |
			((!HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_5)));

	return switchState;
}

int GPIO_Get_Encoder_value(void) { return encoderValue; }

void GPIO_Set_Encoder_value(int value)
{
	encoderValue = value;
}

void GPIO_Set_LED(char led0, char led1, char led2, char led3)
{
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, led3);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, led2);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, led1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, led0);
}

void GPIO_Set_CLCD(const char *pBuf, int line)
{
	int j = 0;

	for (uint8_t i = 19; i >= 4; --i)
		clcd[j++] = (pBuf[i] == 0) ? 0x20 : pBuf[i];

	CLCD_Puts(0, line, clcd);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	switch (GPIO_Pin)
	{
	case GPIO_PIN_1:
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
		break;
	case GPIO_PIN_2:
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_7);
		break;
	case GPIO_PIN_4:
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_11);
		break;
	case GPIO_PIN_5:
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_12);
		break;
	case GPIO_PIN_8:
		encoderValue = 0;
		break;
	case GPIO_PIN_12:
		if (!HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15))
			encoderValue++;
		break;
	case GPIO_PIN_15:
		if (!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12))
			encoderValue--;
		break;
	default:
		break;
	}
}
