/*
 * hw.c
 *
 *  Created on: 2019. 9. 10.
 *      Author: Marshall
 */


#include "hw.h"

void hwInit(void)
{
  bspInit();

  ledInit();
}

void delay(uint32_t time_ms)
{
  HAL_Delay(time_ms);
}

uint32_t millis(void)
{
  return HAL_GetTick();
}
