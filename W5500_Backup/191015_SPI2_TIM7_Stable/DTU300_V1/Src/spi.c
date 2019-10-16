/**
  ******************************************************************************
  * File Name          : SPI.c
  * Description        : This file provides code for the configuration
  *                      of the SPI instances.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "spi.h"

/* USER CODE BEGIN 0 */
#include <stdio.h>
#include <string.h>
/* USER CODE END 0 */

SPI_HandleTypeDef hspi2;
DMA_HandleTypeDef hdma_spi2_rx;

/* SPI2 init function */
void MX_SPI2_Init(void)
{

  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_SLAVE;
  hspi2.Init.Direction = SPI_DIRECTION_2LINES_RXONLY;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_HARD_INPUT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }

}

void HAL_SPI_MspInit(SPI_HandleTypeDef* spiHandle)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};
  if(spiHandle->Instance==SPI2)
  {
  /* USER CODE BEGIN SPI2_MspInit 0 */

  /* USER CODE END SPI2_MspInit 0 */
    /* SPI2 clock enable */
    __HAL_RCC_SPI2_CLK_ENABLE();
  
    __HAL_RCC_GPIOB_CLK_ENABLE();
    /**SPI2 GPIO Configuration    
    PB12     ------> SPI2_NSS
    PB13     ------> SPI2_SCK
    PB15     ------> SPI2_MOSI 
    */
    GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

    /* SPI2 DMA Init */
    /* SPI2_RX Init */
    hdma_spi2_rx.Instance = DMA1_Channel4;
    hdma_spi2_rx.Init.Direction = DMA_PERIPH_TO_MEMORY;
    hdma_spi2_rx.Init.PeriphInc = DMA_PINC_DISABLE;
    hdma_spi2_rx.Init.MemInc = DMA_MINC_ENABLE;
    hdma_spi2_rx.Init.PeriphDataAlignment = DMA_PDATAALIGN_BYTE;
    hdma_spi2_rx.Init.MemDataAlignment = DMA_MDATAALIGN_BYTE;
    hdma_spi2_rx.Init.Mode = DMA_CIRCULAR;
    hdma_spi2_rx.Init.Priority = DMA_PRIORITY_LOW;
    if (HAL_DMA_Init(&hdma_spi2_rx) != HAL_OK)
    {
      Error_Handler();
    }

    __HAL_LINKDMA(spiHandle,hdmarx,hdma_spi2_rx);

  /* USER CODE BEGIN SPI2_MspInit 1 */

  /* USER CODE END SPI2_MspInit 1 */
  }
}

void HAL_SPI_MspDeInit(SPI_HandleTypeDef* spiHandle)
{

  if(spiHandle->Instance==SPI2)
  {
  /* USER CODE BEGIN SPI2_MspDeInit 0 */

  /* USER CODE END SPI2_MspDeInit 0 */
    /* Peripheral clock disable */
    __HAL_RCC_SPI2_CLK_DISABLE();
  
    /**SPI2 GPIO Configuration    
    PB12     ------> SPI2_NSS
    PB13     ------> SPI2_SCK
    PB15     ------> SPI2_MOSI 
    */
    HAL_GPIO_DeInit(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_15);

    /* SPI2 DMA DeInit */
    HAL_DMA_DeInit(spiHandle->hdmarx);
  /* USER CODE BEGIN SPI2_MspDeInit 1 */

  /* USER CODE END SPI2_MspDeInit 1 */
  }
} 

/* USER CODE BEGIN 1 */
void spi_proc()
{
    //짜투�???? 처리?��
    uint16_t tail=0;
    uint16_t rxlen = 0;
    uint16_t i = 0;

    static uint16_t spiCurIndex = 0;
    static uint16_t spiPrevIndex = 0;

    //?��?�� 버퍼
    uint8_t spi_buf[MAX_DMA_BUFFER_SIZE];

    //DMA 버퍼 카운?��
    spiCurIndex = (uint16_t)(MAX_DMA_BUFFER_SIZE-hdma_spi2_rx.Instance->CNDTR);

    //for debugging
    //printf("%02X", (uint8_t)(spiCurIndex >> 8));  // Upper value of 16
    //printf("%02X", (uint8_t)(spiCurIndex & 0x00FF));  // Lower value of 16
    //printf("\r\n");

    //?��?��까�? ?��?? 버퍼 ?��치�? DMA 버퍼 ?��치�? ?��르면
    //?��?��?���???? ?��?�� ?��?���????�???? ?��?�� DMA 버퍼 ?��치까�???? ?��?��?��?��.
    if(spiCurIndex != spiPrevIndex)
    {
        //?��?��까�? ?��?? ?��치�? DMA 버퍼 ?��치보?�� ?��?���????
        //?��바�?��? ?��?���???? 것이�???? ?��문에 ?��?��?? 같이 처리?���?????��.
        if(spiPrevIndex > spiCurIndex)
        {
            tail = (MAX_DMA_BUFFER_SIZE - spiPrevIndex);
            rxlen = spiCurIndex - tail;
            //memcpy(spi_buf, &spiDMABuf[spiPrevIndex], tail);
            memcpy(spi_buf, &Rx[spiPrevIndex], tail);
            memcpy(&spi_buf[tail], &Rx[0], spiCurIndex);
            rxlen = spiCurIndex + tail;
        }
        else
        {
            rxlen = spiCurIndex - spiPrevIndex;
            memcpy(spi_buf, &Rx[spiPrevIndex], rxlen);
        }
        //�????금까�???? ?��?? 버퍼 ?���???? 기억
        spiPrevIndex = spiCurIndex;

        //UART�???? ?��?��?�� 보냄.
        //HAL_UART_Transmit(&huart2, (uint8_t *)&spi_buf, rxlen, 0xFFFF);
        //
        for(i=0; i<MAX_DMA_BUFFER_SIZE; i++)
        {
          if(((i+1) % 4) == 0 )
          {
            printf("%02X \r\n", Rx[i]);
          }
          else
          {
            printf("%02X ", Rx[i]);
            fflush (stdout);    // for HAL Delay
          }
        }
        printf("\r\n");
        //
    }
}
/* USER CODE END 1 */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
