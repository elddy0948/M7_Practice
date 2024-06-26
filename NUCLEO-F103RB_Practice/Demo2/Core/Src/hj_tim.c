/*
 * hj_tim.c
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */


#include "hj_tim.h"

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
