/*
 * hw.c
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */


#include "hw.h"





void hwInit(void)
{
  bspInit();

  ledInit();
  buttonInit();
  uartInit();
}

void delay(uint32_t time_ms)
{
  HAL_Delay(time_ms);
}

uint32_t millis(void)
{
  return HAL_GetTick();
}
