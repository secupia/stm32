#ifndef W5500_INITCODE_H_
#define W5500_INITCODE_H_

//#include "stm32f0xx_hal.h"
#include "main.h"

uint8_t W5500_dataRead();
void W5500_dataSend(uint8_t Txdata);
void W5500_CS_select();
void W5500_CS_deselect();
int isLinked(void);
void W5500_hw_Rst(void);
void W5500_info();
uint8_t W5500_init();


#endif /* W5500_INITCODE_H_ */
