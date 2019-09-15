/*
 * led.c
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */


#include "led.h"


<<<<<<< HEAD
=======



>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
void ledInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull  = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;

  GPIO_InitStruct.Pin = GPIO_PIN_5;
<<<<<<< HEAD
  //GPIO_InitStruct.Pin = GPIO_PIN_0;

=======
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
}

void ledOn(uint8_t ch)
{
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
<<<<<<< HEAD
  //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
=======
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
}

void ledOff(uint8_t ch)
{
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
<<<<<<< HEAD
  //HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
=======
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
}

void ledToggle(uint8_t ch)
{
  HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
<<<<<<< HEAD
  //HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_0);
=======
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
}
