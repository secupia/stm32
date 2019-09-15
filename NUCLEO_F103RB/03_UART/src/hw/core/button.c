/*
 * button.c
 *
<<<<<<< HEAD
 *  Created on: 2019. 9. 11.
 *      Author: Marshall
 */

#include "button.h"

void buttonInit(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
=======
 *  Created on: 2018. 5. 15.
 *      Author: Baram
 */


#include "button.h"





void buttonInit(void)
{
  GPIO_InitTypeDef  GPIO_InitStruct;

  GPIO_InitStruct.Mode  = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull  = GPIO_NOPULL;
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

  GPIO_InitStruct.Pin = GPIO_PIN_13;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
<<<<<<< HEAD

=======
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
}

bool buttonGetPressed(uint8_t ch)
{
<<<<<<< HEAD

  if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
=======
  if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET)
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
  {
    return true;
  }
  else
  {
    return false;
  }
}
