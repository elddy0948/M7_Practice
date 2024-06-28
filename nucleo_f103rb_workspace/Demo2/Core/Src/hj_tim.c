/*
 * hj_tim.c
 *
 *  Created on: Jun 27, 2024
 *      Author: rlagh
 */

#include "hj_tim.h"

volatile uint8_t timer2Flag = 0;
uint8_t rgbPulse[3] = {0};

void Servo_Start(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_2);

	printf("Servo start\n");
}

void RGB_Start(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(htim, TIM_CHANNEL_3);

	printf("RGB start\n");
}

void TxTimer_Start(TIM_HandleTypeDef *htim)
{
	HAL_TIM_Base_Start_IT(htim);
	printf("TX Timer start\n");
}

uint8_t TIM_Check_TIM2_flag(void)
{
	return timer2Flag;
}

void TIM_Reset_TIM2_flag(void)
{
	timer2Flag = 0;
}

uint8_t PWM_Get_red_value(void) { return rgbPulse[0]; }
uint8_t PWM_Get_green_value(void) { return rgbPulse[1]; }
uint8_t PWM_Get_blue_value(void) { return rgbPulse[2]; }

void PWM_Set_servo(TIM_HandleTypeDef *htim, short value)
{
	int pulse = 0;

	if (value > 90)
		value = 90;
	else if (value < -90)
		value = -90;

	pulse = ((int)((value + 90) * 1000 / 180)) + 1000;
	__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2, pulse);
}

void PWM_Set_RGB(TIM_HandleTypeDef *htim, char r, char g, char b)
{
	__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_1, r);
	__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_3, g);
	__HAL_TIM_SET_COMPARE(htim, TIM_CHANNEL_2, b);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM2)
		timer2Flag = 1;
}

