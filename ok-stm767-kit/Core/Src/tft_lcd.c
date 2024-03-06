/*
 * tft_lcd.c
 *
 *  Created on: Feb 27, 2024
 *      Author: hojoon
 */

/* TFT-LCD = HX8347-A */

#include "tft_lcd.h"
#include "stm32f767xx.h"

void setup_spi(void)
{
	// PA5 = SPI1_SCK, PA6 = SPI1_MISO, PA7 = SPI1_MOSI
	GPIOA->MODER |= 0x0000A800;
	// PA5 = AF5, PA6 = AF5, PA7 = AF5
	GPIOA->AFR[0] |= 0x55500000;

	// PB3 = SPI3_SCK, PB4 = SPI3_MISO, PB5 = SPI3_MOSI
	GPIOB->MODER |= 0x00000A80;
	// PB3 = AF6, PB4 = AF6, PB5 = AF6
	GPIOB->AFR[0] |= 0x00066600;

	// PA3 = TS_INT, PA4 = TS_CS
	GPIOA->MODER |= 0x00000040; // PA3 = INPUT, PA4 = OUTPUT
	GPIOA->ODR |= 0x00000010;		// PA4 = 1

	// PB1 = SD_OK(INPUT), PB2 = SD_CS(OUTPUT)
	GPIOB->MODER |= 0x00000008; // PB1 = INPUT, PB2 = OUTPUT
	GPIOB->ODR |= 0x00000004;		// PB2 = 1
}

void TFT_init(void)
{
	RCC->AHB1ENR |= 0x00000018;
	GPIOC->ODR = 0x00000000;
	GPIOC->OSPEEDR = 0x00550000;

	GPIOD->ODR = 0x00000000;
	GPIOD->OSPEEDR = 0x55005555;

	GPIOE->MODER &= 0xFFFFF00F;
	GPIOE->MODER |= 0x00000550;
	GPIOE->ODR |= 0x00000034;
	GPIOE->OSPEEDR &= 0xFFFF00F;
	GPIOE->OSPEEDR |= 0x00000550;

	GPIOE->BSRR = 0x00200000;
	Delay_ms(1);
	GPIOE->BSRR = 0x00000020;
	Delay_ms(120);

	TFT_write(0x02, 0x0000); // window setting
	TFT_write(0x03, 0x0000); // x = 0~319
	TFT_write(0x04, 0x0001);
	TFT_write(0x05, 0x003F);
	TFT_write(0x06, 0x0000); // y = 0~239
	TFT_write(0x07, 0x0000);
	TFT_write(0x08, 0x0000);
	TFT_write(0x09, 0x00EF);

	TFT_write(0x01, 0x0006); // display setting
	TFT_write(0x16, 0x0068); // MV=1, MX=1, MY=0, BGR=1
	TFT_write(0x18, 0x0000); // SM=0
	TFT_write(0x70, 0x0065); // GS=1, SS=1, 16 bit/pixel
	TFT_write(0x23, 0x0095);
	TFT_write(0x24, 0x0095);
	TFT_write(0x25, 0x00FF);
	TFT_write(0x27, 0x0002);
	TFT_write(0x28, 0x0002);
	TFT_write(0x29, 0x0002);
	TFT_write(0x2A, 0x0002);
	TFT_write(0x2C, 0x0002);
	TFT_write(0x2D, 0x0002);
	TFT_write(0x3A, 0x0001);
	TFT_write(0x3B, 0x0001);
	TFT_write(0x3C, 0x00F0);
	TFT_write(0x3D, 0x0000);
	Delay_ms(20);
	TFT_write(0x35, 0x0038);
	TFT_write(0x36, 0x0078);
	TFT_write(0x3E, 0x0038);
	TFT_write(0x40, 0x000F);
	TFT_write(0x41, 0x00F0);

	TFT_write(0x19, 0x0049); // power setting
	TFT_write(0x93, 0x000F);
	Delay_ms(10);
	TFT_write(0x20, 0x0040);
	TFT_write(0x1D, 0x0007);
	Delay_ms(10);
	TFT_write(0x1E, 0x0000);
	TFT_write(0x1F, 0x0004);
	TFT_write(0x44, 0x0040); // VCom control for 3.3V
	TFT_write(0x45, 0x0012);
	Delay_ms(10);
	TFT_write(0x1C, 0x0004);
	Delay_ms(20);
	TFT_write(0x43, 0x0080);
	Delay_ms(5);
	TFT_write(0x1B, 0x0018);
	Delay_ms(40);
	TFT_write(0x1B, 0x0010);
	Delay_ms(40);

	TFT_write(0x46, 0x00A4); // gamma setting
	TFT_write(0x47, 0x0053);
	TFT_write(0x48, 0x0010);
	TFT_write(0x49, 0x005F);
	TFT_write(0x4A, 0x0004);
	TFT_write(0x4B, 0x003F);
	TFT_write(0x4C, 0x0002);
	TFT_write(0x4D, 0x00F6);
	TFT_write(0x4E, 0x0012);
	TFT_write(0x4F, 0x004C);
	TFT_write(0x50, 0x0046);
	TFT_write(0x51, 0x0044);

	TFT_write(0x90, 0x007F); // display on setting
	TFT_write(0x26, 0x0004);
	Delay_ms(40);
	TFT_write(0x26, 0x0024);
	TFT_write(0x26, 0x002C);
	Delay_ms(40);
	TFT_write(0x26, 0x003C);

	TFT_write(0x57, 0x0002); // internal VDDD setting
	TFT_write(0x55, 0x0000);
	TFT_write(0xFE, 0x005A);
	TFT_write(0x57, 0x0000);

	TFT_color_screen(BLUE); // clear screen
}

void TFT_command(unsigned short IR) /* write IR to TFT-LCD */
{
	GPIOE->BSRR = 0x00060000; // -CS = 0, Rs = 0
	GPIOD->ODR = IR;
	GPIOE->BSRR = 0x00010000; // -WR = 0
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	GPIOE->BSRR = 0x00000001; // -WR = 1
	asm("NOP");
	GPIOE->BSRR = 0x00000004; // -CS = 1
}

void TFT_data(unsigned short data) /* write data to TFT-LCD */
{
	GPIOE->BSRR = 0x00040002; // -CS = 0, RS = 1
	GPIOD->ODR = data;
	GPIOE->BSRR = 0x00010000; // -WR = 0
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	asm("NOP");
	GPIOE->BSRR = 0x00000001; // -WR = 1
	asm("NOP");
	GPIOE->BSRR = 0x00000004; // -CS = 1
}

void TFT_write(unsigned short reg, unsigned short val) /* write TFT-LCD register */
{
	TFT_command(reg);
	TFT_data(val);
}

void TFT_GRAM_address(unsigned short xPos, unsigned short yPos)
{
	if ((xPos > 319) || (yPos > 239))
		return;

	TFT_write(0x02, xPos >> 8);
	TFT_write(0x03, xPos & 0x00FF);
	TFT_write(0x06, 0x0000);
	TFT_write(0x07, yPos);

	TFT_command(0x22);
}

void TFT_color_screen(unsigned short color)
{
	unsigned short i, j;
	TFT_GRAM_address(0, 0);
	for (i = 0; i < 320; ++i)
	{
		for (j = 0; j < 240; ++j)
		{
			TFT_data(color);
		}
	}
}
