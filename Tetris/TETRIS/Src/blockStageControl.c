/*
 * blockStageControl.c
 *
 *  Created on: 2019. 11. 24.
 *      Author: Marshall
 */


#include "common.h"
#include "blockInfo.h"
#include "blockStageControl.h"
#include "stm32f429i_discovery_lcd.h"

#define GBOARD_WIDTH 22	//240/10=24 -2
#define GBOARD_WIDTH 31	//320/10=32-1

static int gameBoardInfo[GBOARD_HEIGHT+1][GBOARD_WIDTH+2] = {0,};

static int currentBlockModel;
static int curPosX, curPosY;
static int rotateSte;

void InitNewBlockPos(int x, int y)
{
	if(x<0 || y<0)
	{
		return;
	}

	curPosX = x;
	curPosY = y;

}

void ChooseBlock(void)
{
	currentBlockModel = (rand() % NUM_OF_BLOCK_MODEL) * 4;
}

int GetCurrentBlockIdx(void)
{
	return currentBlockModel;
}

void DrawBlock(uint16_t x, uint16_t y, uint32_t edge_color, uint32_t inner_color)
{
	BSP_LCD_SetTextColor(edge_color);
	BSP_LCD_FillRect(x*10, y*10, 10, 10);
	BSP_LCD_SetTextColor(inner_color);
	BSP_LCD_FillRect(x*10+1, y*10+1, 8, 8);
}

void ShowBlock(char blockInfo[][4])
{

	int x, y;

	for(y=0; y<4; y++)
	{
		for(x=0; x<4; x++)
		{
			if(blockInfo[y][x] ==1)
			{
				DrawBlock(curPosX+x, curPosY+y, LCD_COLOR_WHITE, LCD_COLOR_RED);
			}
		}
	}
}

void DeleteBlock(char blockInfo[][4])
{

	int x, y;

	for(y=0; y<4; y++)
	{
		for(x=0; x<4; x++)
		{
			if(blockInfo[y][x] ==1)
			{
				DrawBlock(curPosX+x, curPosY+y, LCD_COLOR_BLUE, LCD_COLOR_BLUE);
			}
		}
	}
}

void BlockDown(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosY += 1;
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void ShiftLeft(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX -= 1;
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void ShiftRight(void)
{
	DeleteBlock(blockModel[GetCurrentBlockIdx()]);
	curPosX += 1;
	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

void RotateBlock(void)
{
	int nextRotate;

	DeleteBlock(blockModel[GetCurrentBlockIdx()]);

	nextRotate = rotateSte+1;
	nextRotate %= 4;
	rotateSte = nextRotate;


	ShowBlock(blockModel[GetCurrentBlockIdx()]);
}

int DetectionCollision(int posX, int posY, char blockModel[][4])
{
	int x, y;

	int arrX = posX;
	int arrY = posY;

	for(x=0; x<4; x++)
	{
		for(y=0; y<4; y++)
		{
			if(blockModel[y][x]==1 && gameBoardInfo[arrY+y][arryX=x]==1)
				return 0;		// Collision detect
		}
	}

	return 1;		// collision x
}
