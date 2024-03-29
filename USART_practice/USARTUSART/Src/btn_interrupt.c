/*
 * btn_interrupt.c
 *
 *  Created on: Mar 27, 2024
 *      Author: hojoon
 */


#include <string.h>
#include "Drivers/stm32f767xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000 / 2; ++i);
}

int main(void)
{
	GPIO_Handle_t LED_GPIO;
	GPIO_Handle_t Btn_GPIO;

	memset(&LED_GPIO, 0, sizeof(LED_GPIO));
	memset(&Btn_GPIO, 0, sizeof(Btn_GPIO));

	LED_GPIO.pGPIOx = GPIOB;
	LED_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUMBER_7;
	LED_GPIO.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	LED_GPIO.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	LED_GPIO.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP;
	LED_GPIO.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO_PUPD;

	Btn_GPIO.pGPIOx = GPIOC;
	Btn_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUMBER_13;
	Btn_GPIO.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FALLING;
	Btn_GPIO.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_PD;

	GPIO_PCLKControl(GPIOB, ENABLE);
	GPIO_PCLKControl(GPIOC, ENABLE);

	GPIO_Init(&LED_GPIO);
	GPIO_Init(&Btn_GPIO);

	GPIO_IRQPriorityConfig(IRQ_NUMBER_EXIT15_10, NVIC_IRQ_PRIORITY_15);
	GPIO_IRQInterruptConfig(IRQ_NUMBER_EXIT15_10, ENABLE);

	while(1);

	return 0;
}

void EXTI15_10_IRQHandler(void)
{
	delay();
	GPIO_IRQHandling(13);
	GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NUMBER_7);
}
