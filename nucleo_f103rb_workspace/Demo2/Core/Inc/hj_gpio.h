/*
 * hj_gpio.h
 *
 *  Created on: Jun 28, 2024
 *      Author: rlagh
 */

#ifndef INC_HJ_GPIO_H_
#define INC_HJ_GPIO_H_

#include "hj_def.h"
#include "clcd.h"

/**
 * LED, SW, ENCODER, CLCD
 * which is using GPIO OUTPUT or INPUT
 */

extern volatile int ledState;
extern volatile int switchState;
extern volatile int encoderValue;
extern char clcd[17];

void GPIO_CLCD_start(void);

int GPIO_Get_LED_state(void);
int GPIO_Get_SW_state(void);
int GPIO_Get_Encoder_value(void);

void GPIO_Set_Encoder_value(int value);
void GPIO_Set_LED(char led0, char led1, char led2, char led3);

void GPIO_Set_CLCD(const char *pBuf, int line);

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_HJ_GPIO_H_ */
