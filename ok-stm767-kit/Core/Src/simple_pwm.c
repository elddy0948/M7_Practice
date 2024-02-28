/*
 * simple_pwm.c
 *
 *  Created on: Feb 28, 2024
 *      Author: hojoon
 */

#include "simple_pwm.h"

void init_pwm(unsigned int pwm)
{
	/* Set timer pin to alternate function mode */
	/* TIM1_CH1 / STM32 PIN = PE9 / BOARD = D6 */
	GPIOE->MODER &= 0xFFF3FFFF;
	GPIOE->MODER |= 0x00080000;

	/* PE9 = TIM1_CH1 */
	GPIOE->AFR[1] &= 0xFFFFFF0F;
	// TODO: - CHECK BELOW
	GPIOE->AFR[1] |= 0x00000010;

	/* Enable TIM1 CLK */
	RCC->APB2ENR |= 0x00000001;

	TIM1->PSC = 107;	// MAX PRESCALER = 108MHz (107 + 1) = 1MHz
	TIM1->ARR = 999;	// 1MHz / (999 + 1) = 1kHz
	TIM1->CCR1 = pwm;
	TIM1->CNT = 0;
	// CCMR SETUP
	TIM1->CCER = 0x00000001;	// ENABLE OC1 OUTPUT
	TIM1->BDTR = 0x00008000;	// MOE = 1
	TIM1->CR1 = 0x0005;	// EDGE-ALIGNED, UP-COUNJTER, ENABLE TIM1
}
