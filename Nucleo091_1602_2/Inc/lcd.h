/*
 * lcd.h
 *
 *  Created on: 2020. 4. 20.
 *      Author: Marshall
 */

#ifndef LCD_H_
#define LCD_H_

#include "main.h"

#define DISP_SEL_CMD_REG 		0
#define DISP_SEL_DATA_REG   1

void DispInit(uint8_t maxrows, uint8_t maxcols);
void DispChar(uint8_t row, uint8_t col, char c);
void DispStr(uint8_t row, uint8_t col, char *s);

#endif /* LCD_H_ */
