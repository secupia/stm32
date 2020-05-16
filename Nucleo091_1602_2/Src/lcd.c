/*
 * lcd.c
 *
 *  Created on: 2020. 4. 20.
 *      Author: Marshall
 */


#include "lcd.h"

#define DISP_CMD_CLS            0x01		// 1. Clear Display

//#define DISP_CMD_FNCT           0x3B
#define DISP_CMD_FNCT           0x2B		// 4 Bit Mode, 2 Line, 5x8 Font

#define DISP_CMD_MODE           0x06		// cursor[right], display shift[none]

//#define DISP_CMD_ON_OFF         0x0C
#define DISP_CMD_ON_OFF         0x0F		// Display[On], Cursor[On], Cursor Blink[On]

static uint8_t            DispMaxCols;
static uint8_t            DispMaxRows;

static void DispSel(uint8_t sel);
static void DispDataWr(uint8_t data);
static void DispCursorSet(uint8_t row, uint8_t col);

static void DispSel(uint8_t sel)
{
	if(sel == DISP_SEL_CMD_REG){
		HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_RESET);
	}else{
	  HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, GPIO_PIN_SET);
	}
}

static void DispDataWr(uint8_t data)		// Must be changed using 4 Bit Mode
{
    HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (GPIO_PinState)(data & 0x80));
    HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (GPIO_PinState)(data & 0x40));
    HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (GPIO_PinState)(data & 0x20));
    HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (GPIO_PinState)(data & 0x10));

    HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);

    HAL_GPIO_WritePin(LCD_D7_GPIO_Port, LCD_D7_Pin, (GPIO_PinState)(data & 0x08));
    HAL_GPIO_WritePin(LCD_D6_GPIO_Port, LCD_D6_Pin, (GPIO_PinState)(data & 0x04));
    HAL_GPIO_WritePin(LCD_D5_GPIO_Port, LCD_D5_Pin, (GPIO_PinState)(data & 0x02));
    HAL_GPIO_WritePin(LCD_D4_GPIO_Port, LCD_D4_Pin, (GPIO_PinState)(data & 0x01));

    HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
}
#if 1
static void DispCursorSet(uint8_t row, uint8_t col)
{
    DispSel(DISP_SEL_CMD_REG);
    switch(row){
    case 0:
        DispDataWr(0x80 + col);
        break;
    case 1:
        DispDataWr(0xC0 + col);
        break;
    }
}
#endif

void DispInit(uint8_t maxrows, uint8_t maxcols)
{
    DispMaxRows = maxrows;
    DispMaxCols = maxcols;

    DispSel(DISP_SEL_CMD_REG);
    HAL_Delay(50);

    DispDataWr(DISP_CMD_FNCT);
    HAL_Delay(5);
    DispDataWr(DISP_CMD_FNCT);
    HAL_Delay(5);
    DispDataWr(DISP_CMD_FNCT);
    HAL_Delay(5);
    DispDataWr(DISP_CMD_FNCT);
    HAL_Delay(5);

    DispDataWr(DISP_CMD_ON_OFF);
    HAL_Delay(5);
    DispDataWr(DISP_CMD_MODE);
    HAL_Delay(5);
    DispDataWr(DISP_CMD_CLS);
    HAL_Delay(5);

}

#if 1
void DispChar(uint8_t row, uint8_t col, char c)
{
    if(row < DispMaxRows && col < DispMaxCols){
        DispCursorSet(row, col);
        DispSel(DISP_SEL_DATA_REG);
        DispDataWr(c);
    }
}

void DispStr(uint8_t row, uint8_t col, char *s)
{
    uint8_t i;

    if(row < DispMaxRows && col < DispMaxCols){
        DispCursorSet(row, col);
        DispSel(DISP_SEL_DATA_REG);
        i = col;
        while(i < DispMaxCols && *s){
            DispDataWr(*s++);
            i++;
        }
    }
}
#endif
