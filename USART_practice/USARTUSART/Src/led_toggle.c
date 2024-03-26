/*
 * led_toggle.c
 *
 *  Created on: Mar 26, 2024
 *      Author: hojoon
 */


#include "Drivers/stm32f767xx.h"

void delay(void)
{
	for(uint32_t i = 0; i < 500000; ++i);
}

int main(void)
{
	// PB7

	GPIO_Handle_t LED_GPIO;

	LED_GPIO.pGPIOx = GPIOB;
	LED_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUMBER_7;
	LED_GPIO.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	LED_GPIO.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	LED_GPIO.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP;
	LED_GPIO.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO_PUPD;

	GPIO_PCLKControl(GPIOB, ENABLE);

	GPIO_Init(&LED_GPIO);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NUMBER_7);
		delay();
	}

	return 0;
}
