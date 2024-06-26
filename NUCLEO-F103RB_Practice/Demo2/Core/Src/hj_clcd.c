/*
 * hj_clcd.c
 *
 *  Created on: Jun 26, 2024
 *      Author: HoJoon
 */

#include "hj_clcd.h"

void CLCD_Start(void)
{
	CLCD_Init(16, 2);
	printf("CLCD Start\n");
}
