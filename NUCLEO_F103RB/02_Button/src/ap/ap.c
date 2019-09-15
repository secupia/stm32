/*
 * ap.c
 *
 *  Created on: 2018. 5. 12.
 *      Author: Baram
 */


#include "ap.h"



void apInit(void)
{

}

void apMain(void)
{
  while(1)
  {
    //ledToggle(0);
    //delay(500);

    if(buttonGetPressed(0) == true)
    {
      ledOn(0);
    }
    else
    {
      ledOff(0);
    }
  }
}
