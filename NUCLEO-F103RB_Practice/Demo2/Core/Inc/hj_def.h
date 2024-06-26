/*
 * hj_def.h
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */

#ifndef INC_HJ_DEF_H_
#define INC_HJ_DEF_H_

#include <stdio.h>
#include <string.h>

#include "stm32f1xx_hal.h"

#ifdef __GNUC__
#define PUTCHAR_PROTOTYPE		int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE		int fputc(int ch, FILE *f)
#endif

PUTCHAR_PROTOTYPE;

#endif /* INC_HJ_DEF_H_ */
