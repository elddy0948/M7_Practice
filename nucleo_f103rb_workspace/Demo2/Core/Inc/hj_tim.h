/*
 * hj_tim.h
 *
 *  Created on: Jun 27, 2024
 *      Author: rlagh
 */

#ifndef INC_HJ_TIM_H_
#define INC_HJ_TIM_H_

#include "hj_def.h"

void Servo_Start(TIM_HandleTypeDef *htim);
void RGB_Start(TIM_HandleTypeDef *htim);
void TxTimer_Start(TIM_HandleTypeDef *htim);

uint8_t TIM_Check_TIM2_flag(void);
void TIM_Reset_TIM2_flag(void);

uint8_t PWM_Get_red_value(void);
uint8_t PWM_Get_green_value(void);
uint8_t PWM_Get_blue_value(void);

void PWM_Set_servo(TIM_HandleTypeDef *htim, short value);
void PWM_Set_RGB(TIM_HandleTypeDef *htim, char r, char g, char b);

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);

#endif /* INC_HJ_TIM_H_ */
