/*
 * helper.c
 *
 *  Created on: Feb 29, 2024
 *      Author: hojoon
 */

#include "helper.h"

void Delay_us(unsigned int time_us)
{
	register unsigned int i;
	for (i = 0; i < time_us * 2; ++i)
	{
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP"); // 10
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP"); // 100
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP"); // 10
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP"); // 200
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP");
		asm("NOP"); // 210
		asm("NOP");
		asm("NOP");
		asm("NOP"); // 213
	}
}

void Delay_ms(unsigned int time_ms)
{
	register unsigned int i;

	for (i = 0; i < time_ms; ++i)
		Delay_us(1000);
}

void Initialize_MCU(void)
{
	SCB_EnableICache(); // enable L1 instruction cache
	SCB_EnableDCache(); // enable L1 data cache

	FLASH->ACR = 0x00000307;

	RCC->CR |= 0x00010001;
	while ((RCC->CR & 0x00000002) == 0)
		;
	RCC->CFGR = 0x00000000;
	while ((RCC->CFGR & 0x0000000C) != 0)
		;

	RCC->CR = 0x00010001;
	RCC->PLLCFGR = 0x09403608;
	RCC->CR = 0x01010001;
	while ((RCC->CR & 0x02000000) == 0)
		;

	RCC->APB1ENR |= 0x10000000;
	PWR->CR1 |= 0x00010000;
	while ((PWR->CSR1 & 0x00010000) == 0)
		;
	PWR->CR1 |= 0x00020000;
	while ((PWR->CSR1 & 0x00020000) == 0)
		;

	RCC->CFGR = 0x3040B402;
	while ((RCC->CFGR & 0x0000000C) != 0x00000008)
		;
	RCC->CR |= 0x00080000; // CSS on

	RCC->APB2ENR |= 0x00004000; // �ֺ���ġ Ŭ��(SYSCFG = 1)
	SYSCFG->CMPCR = 0x00000001; // enable compensation cell

	RCC->AHB1ENR |= 0x0000001F;
	RCC->AHB2ENR |= 0x00000000;

	GPIOC->MODER = 0x00150000;
	GPIOC->ODR = 0x00000000;
	GPIOC->OSPEEDR = 0x00550000;

	GPIOD->MODER = 0x55005555;
	GPIOD->ODR = 0x00000000;
	GPIOD->OSPEEDR = 0x55005555;
}
