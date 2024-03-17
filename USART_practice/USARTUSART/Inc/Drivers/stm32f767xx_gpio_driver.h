/*
 * stm32f767xx_gpio_driver.h
 *
 *  Created on: Mar 18, 2024
 *      Author: hojoon
 */

#ifndef DRIVERS_STM32F767XX_GPIO_DRIVER_H_
#define DRIVERS_STM32F767XX_GPIO_DRIVER_H_

#include "stm32f767xx.h"

typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunMode;
} GPIO_PinConfig_t;

typedef struct
{
	GPIO_RegDef_t* pGPIOx;	// this holds the base address of the GPIO port
	GPIO_PinConfig_t GPIO_PinConfig;
} GPIO_Handle_t;



#endif /* DRIVERS_STM32F767XX_GPIO_DRIVER_H_ */
