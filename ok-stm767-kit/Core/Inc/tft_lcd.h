/*
 * tft_lcd.h
 *
 *  Created on: Feb 27, 2024
 *      Author: hojoon
 */

#ifndef INC_TFT_LCD_H_
#define INC_TFT_LCD_H_

#include "helper.h"


#define BLUE 0x001F
#define GREEN 0x07E0
#define RED 0xF800

void setup_spi(void);
void TFT_init(void);

void TFT_write(unsigned short reg, unsigned short val);
void TFT_command(unsigned short IR);
void TFT_data(unsigned short data);
void TFT_GRAM_address(unsigned short xPos, unsigned short yPos);
void TFT_color_screen(unsigned short color);

#endif /* INC_TFT_LCD_H_ */
