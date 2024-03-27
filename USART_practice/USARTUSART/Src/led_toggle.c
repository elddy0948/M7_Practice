/*
 * led_toggle.c
 *
 *  Created on: Mar 26, 2024
 *      Author: hojoon
 */


#include "Drivers/stm32f767xx.h"

#define HIGH 1
#define BTN_PRESSED HIGH

void delay(void)
{
	for(uint32_t i = 0; i < 500000 / 2; ++i);
}

int main(void)
{
	// PB7 - LED
	// PC13 - BUTTON

	GPIO_Handle_t LED_GPIO;
	GPIO_Handle_t Button_GPIO;

	LED_GPIO.pGPIOx = GPIOB;
	LED_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUMBER_7;
	LED_GPIO.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	LED_GPIO.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	LED_GPIO.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUTPUT_TYPE_PP;
	LED_GPIO.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO_PUPD;

	Button_GPIO.pGPIOx = GPIOC;
	Button_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NUMBER_13;
	Button_GPIO.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	Button_GPIO.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	Button_GPIO.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PUPD_NO_PUPD;

	GPIO_PCLKControl(GPIOB, ENABLE);
	GPIO_PCLKControl(GPIOC, ENABLE);

	GPIO_Init(&LED_GPIO);
	GPIO_Init(&Button_GPIO);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NUMBER_13) == BTN_PRESSED)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOB, GPIO_PIN_NUMBER_7);
		}
	}

	return 0;
}
