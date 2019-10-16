/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
//#define RX_BUF_SIZE 256
//#define RX_BUF_SIZE 1024
//#define MAX_DMA_BUFFER_SIZE 1024
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint8_t buf_index = 0;
uint8_t Tx[] = {0xFE, 0xED, 0x50, 0x11, 0x00, 0x00};
uint8_t Rx[RX_BUF_SIZE] = {0x00,};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int _write(int file, char* ptr, int len)
{
  //HAL_UART_Transmit(&huart2, p, len, 10);
  int DataIdx;

  for(DataIdx = 0; DataIdx < len; DataIdx++)
  {
    while(!LL_USART_IsActiveFlag_TXE(USART2))
    {
      //We can put some timeout here
    }
    LL_USART_TransmitData8(USART2, *ptr++);
  }
  return len;
}

//void spi_proc(void);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint16_t i;
  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SPI2_Init();
  MX_USART2_UART_Init();
  MX_TIM7_Init();
  /* USER CODE BEGIN 2 */

  HAL_TIM_Base_Start_IT(&htim7);

  //SPI2->CR2 |= 0x0040;    // RXNE interrupt enable
  SPI2->CR1 |= 0x0040;    // SPI enable

  SPI2->DR = Tx[0];       // Write initial byte

  HAL_SPI_Receive_DMA(&hspi2, Rx, RX_BUF_SIZE);
  //HAL_TIM_Base_Start_IT(&htim7);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    //HAL_GPIO_TogglePin(SOCKET_LED_GPIO_Port, SOCKET_LED_Pin);
    //printf("%X %d %d %d %d %d \r \n", Rx[0], Rx[1], Rx[2], Rx[3], Rx[4], Rx[5]);
    //printf("%X %X %X %X %X %X \r \n", Rx[0], Rx[1], Rx[2], Rx[3], Rx[4], Rx[5]);
    /*
    for(i=0; i<RX_BUF_SIZE; i++)
    {
      //SPI2->DR = Rx[i];
      if(((i+1) % 4) == 0 )
        printf("%02X \r\n", Rx[i]);
      else
        printf("%02X ", Rx[i]);
    }
    printf("\r\n");
    */

    spi_proc();
    //printf("Hello IBM \r\n");
    //HAL_SPI_Transmit_IT(&hspi2, Rx, 6);

    //HAL_GPIO_TogglePin(COL_LED_GPIO_Port, COL_LED_Pin);
    //HAL_GPIO_TogglePin(SOCKET_LED_GPIO_Port, SOCKET_LED_Pin);

    HAL_Delay(200);
    //HAL_Delay(50);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/*
void spi_proc()
{
    //짜투�?????????? 처리?��
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
    //?��?��?���?????????? ?��?�� ?��?���??????????�?????????? ?��?�� DMA 버퍼 ?��치까�?????????? ?��?��?��?��.
    if(spiCurIndex != spiPrevIndex)
    {
        //?��?��까�? ?��?? ?��치�? DMA 버퍼 ?��치보?�� ?��?���??????????
        //?��바�?��? ?��?���?????????? 것이�?????????? ?��문에 ?��?��?? 같이 처리?���???????????��.
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
        //�??????????금까�?????????? ?��?? 버퍼 ?���?????????? 기억
        spiPrevIndex = spiCurIndex;

        //UART�?????????? ?��?��?�� 보냄.
        //HAL_UART_Transmit(&huart2, (uint8_t *)&spi_buf, rxlen, 0xFFFF);
        //
        for(i=0; i<MAX_DMA_BUFFER_SIZE; i++)
        {
          if(((i+1) % 4) == 0 )
            printf("%02X \r\n", Rx[i]);

          else
            printf("%02X ", Rx[i]);
            fflush (stdout);    // for HAL Delay
        }
        printf("\r\n");
        //
    }
}
*/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  if(htim->Instance==TIM7)
  {
    HAL_GPIO_TogglePin(COL_LED_GPIO_Port, COL_LED_Pin);
    HAL_GPIO_TogglePin(SOCKET_LED_GPIO_Port, SOCKET_LED_Pin);
  }
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
