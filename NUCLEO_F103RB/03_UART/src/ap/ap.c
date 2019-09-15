/*
 * ap.c
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */


#include "ap.h"



<<<<<<< HEAD
=======


>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
void apInit(void)
{
  uartOpen(_DEF_UART1, 115200);
}

void apMain(void)
{
  while(1)
  {
<<<<<<< HEAD
    //ledToggle(0);
    //delay(500);

    if(buttonGetPressed(0) == true)
=======
    if (buttonGetPressed(0) == true)
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
    {
      ledOn(0);
    }
    else
    {
      ledOff(0);
    }

<<<<<<< HEAD
    if(uartAvailable(_DEF_UART1)>0)
    {
      uartPrintf(_DEF_UART1, "rx: 0x%X \n", uartRead(_DEF_UART1));
=======
    if (uartAvailable(_DEF_UART1) > 0)
    {
      uartPrintf(_DEF_UART1, "rx : 0x%X\n", uartRead(_DEF_UART1));
>>>>>>> af0767fca0f1972362e5186eb10742e60df9d092
    }
  }
}
