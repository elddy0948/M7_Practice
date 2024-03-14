/*
 * dust.c
 *
 *  Created on: Mar 11, 2024
 *      Author: hojoon
 */

#include "stm32f767xx.h"
#include "modules/dust.h"

void Dust_PWM_Init(void)
{
	RCC->APB2ENR |= 0x00000001;	// SET TIM1
	TIM1->PSC = 1079;
	TIM1->ARR = 49999;
	TIM1->CNT = 0;

	TIM1->CCMR1 |= 0x00000001;	// SET CC1 CHANNEL INPUT, IC1 - TI1
	TIM1->CCER = 0x00000000;	// RESET CC1P CC1NP

	TIM1->CCMR1 |= 0x00000200;	// SET CC2 CHANNEL INPUT, IC2 - TI1
	TIM1->CCER |= 0x00000020;	//SET CC2P RESET CC2NP

	TIM1->SMCR &= 0xFFFFFF80;
	TIM1->SMCR |= 0x00000054;	// TS 101,	SMS 0100

}
