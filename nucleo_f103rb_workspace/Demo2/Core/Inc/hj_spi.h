/*
 * hj_spi.h
 *
 *  Created on: Jun 28, 2024
 *      Author: rlagh
 */

#ifndef INC_HJ_SPI_H_
#define INC_HJ_SPI_H_

#include "hj_def.h"

uint8_t DAC7512_write(SPI_HandleTypeDef *hspi);
void DAC7512_Set_data(unsigned short data);

#endif /* INC_HJ_SPI_H_ */
