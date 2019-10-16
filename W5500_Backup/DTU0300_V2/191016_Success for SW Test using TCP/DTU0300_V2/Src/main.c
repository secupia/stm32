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
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include <w5500_initcode.h>
#include "w5500_initcode.h"
#include "socket.h"

#include <stdio.h>
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
uint8_t buf2[]   = "This is Echo Server using Wiznet W5500";
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
//
wiz_NetInfo gWIZNETINFO = {
    .mac = {0x00, 0x08, 0xdc, 0xab, 0xcd, 0x49},
    //.mac = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00},
    .ip  = {192,168,0,215},
    .sn  = {255,255,255,0},
    .gw  = {192,168,0,1},
    .dns = {8,8,8,8},
    .dhcp = NETINFO_STATIC
};
//

//volatile uint8_t buf_index = 0;
//uint8_t Tx[] = {0xC0, 0x33, 0x9D, 0x37, 0x45, 0x2F};
//uint8_t Rx[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

volatile uint8_t buf_index = 0;
//uint8_t Tx[] = {0xFE, 0xED, 0x50, 0x11, 0x00, 0x00};
//uint8_t Rx[RX_BUF_SIZE] = {0x00,};

uint8_t Tx[TX_BUF_SIZE] = {0x00,};
uint8_t Rx[RX_BUF_SIZE] = {0x00,};

uint8_t  gU8_buf_enable = 0;
uint16_t gU16_index_start = 0;
uint16_t gU16_index_length = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void updateWatchdog(void)
{

  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port, WATCHDOG_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port, WATCHDOG_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port, WATCHDOG_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port, WATCHDOG_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port, WATCHDOG_Pin, GPIO_PIN_RESET);

  HAL_GPIO_WritePin(WATCHDOG_GPIO_Port, WATCHDOG_Pin, GPIO_PIN_SET);

}
/*
int _write(int file, char* p, int len)
{
  HAL_UART_Transmit(&huart2, p, len, 10);
  return len;
}
*/
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

int32_t myLoopback_tcps(uint8_t sn, uint8_t* buf, uint16_t port);
void spi_proc(void);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
  uint8_t w5500_s0_status = 0x10;
  uint8_t w5500_s1_status = 0x10;

  //uint8_t buf2[]   = "This is DTU-3000 using W5500";
  uint8_t address_target[]  = {192,168,11,101};
  uint8_t count = 0;

  int ret;
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
  MX_SPI1_Init();
  MX_USART2_UART_Init();
  MX_SPI2_Init();
  /* USER CODE BEGIN 2 */
  W5500_hw_Rst();
  W5500_init();

  socket(0, Sn_MR_TCP, 5000, SF_TCP_NODELAY);
  listen(0);

  //SPI2->CR2 |= 0x0040;    // RXNE interrupt enable
  SPI2->CR1 |= 0x0040;    // SPI enable
  SPI2->DR = Tx[0];       // Write initial byte

  HAL_SPI_Receive_DMA(&hspi2, Rx, RX_BUF_SIZE);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  HAL_GPIO_TogglePin(SOCKET_LED_GPIO_Port, SOCKET_LED_Pin);
	  //printf("0x0A \r \n");
	  //w5500_s0_status = getSn_SR(0);
    //w5500_s1_status = getSn_SR(1);

	  //printf("W5500 Status Socket0 == 0x%X Socket1 == 0x%X \r \n", w5500_s0_status , w5500_s1_status);
	  //printf("%d %d %d %d %d %d \r \n", Rx[0], Rx[1], Rx[2], Rx[3], Rx[4], Rx[5]);

	  HAL_Delay(50);
    /*
	  //updateWatchdog();
	  //socket(0, Sn_MR_TCP, 5000, SF_TCP_NODELAY);
	  //listen(0);

	  w5500_s0_status = getSn_SR(0);
	  w5500_s1_status = getSn_SR(1);

	  if(w5500_s0_status == SOCK_ESTABLISHED)
	  {
	    printf("Welcome to W5500 \r \n");
	    send(0, buf, sizeof(buf));
	    //send(0, &count,1);
	    //count++;
	  }
	  else
	  {
	    printf("W5500 Status Socket0 == 0x%X Socket1 == 0x%X \r \n", w5500_s0_status , w5500_s1_status);
	  }
	  */

    // Loopback Test

    if((ret = myLoopback_tcps(SOCK_TCPS0, gDATABUF, 5000)) < 0)
    {
      printf("WSOCKET ERROR : %d \r \n", ret);
    }

    spi_proc();

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
int32_t myLoopback_tcps(uint8_t sn, uint8_t* buf, uint16_t port)
{
   int32_t ret;
   uint16_t size = 0, sentsize=0;
#ifdef _DEBUG_STX_
   uint8_t debug_buf[] = {0xCC, 0xEE};
#endif

   switch(getSn_SR(sn))
   {
      case SOCK_ESTABLISHED :
         if(getSn_IR(sn) & Sn_IR_CON)
         {
            //myprintf("%d:Connected\r\n",sn);
            printf("%d:Connected\r\n",sn);

            setSn_IR(sn,Sn_IR_CON);
         }
         ////////// 191015
         /*
         if((size = getSn_RX_RSR(sn)) > 0)
         {
            if(size > DATA_BUF_SIZE) size = DATA_BUF_SIZE;
            ret = recv(sn,buf,size);
            if(ret <= 0) return ret;

            //printf("%d:Receive message\r\n",sn);
            send(sn, buf2, sizeof(buf2));

            sentsize = 0;
            while(size != sentsize)
            {
               ret = send(sn,buf+sentsize,size-sentsize);
               if(ret < 0)
               {
                  close(sn);
                  return ret;
               }
               sentsize += ret; // Don't care SOCKERR_BUSY, because it is zero.
            }
         }
         */
         if(gU8_buf_enable)
         {
           gU8_buf_enable = 0;
           size = gU16_index_length;

           //if(size > DATA_BUF_SIZE) size = DATA_BUF_SIZE;
           if(size > TX_BUF_SIZE) size = TX_BUF_SIZE;
           //size = 10;


           //send(sn, Rx+gU16_index_start, size);

           sentsize = 0;
#ifdef _DEBUG_STX_
           send(sn,&debug_buf[0],1);
#endif
           while(size != sentsize)
           {
             //ret = send(sn,Rx+gU16_index_start+sentsize,size-sentsize);
             ret = send(sn,Tx+gU16_index_start+sentsize,size-sentsize);
             if(ret < 0)
             {
               close(sn);
               return ret;
             }
             sentsize += ret; // Don't care SOCKERR_BUSY, because it is zero.
           }
#ifdef _DEBUG_STX_
           sentsize = 0;
           while(1 != sentsize)
           {

             ret = send(sn,&debug_buf[1],1);

             if(ret < 0)
             {
               close(sn);
               return ret;
             }
             sentsize += ret; // Don't care SOCKERR_BUSY, because it is zero.
           }
           //send(sn,&debug_buf[1],1);
#endif
         }
         // //////// 191015
         break;

      case SOCK_CLOSE_WAIT :
         //myprintf("%d:CloseWait\r\n",sn);
         printf("%d:CloseWait\r\n",sn);

         if((ret=disconnect(sn)) != SOCK_OK) return ret;
         //myprintf("%d:Closed\r\n",sn);
         printf("%d:Closed\r\n",sn);
         break;

      case SOCK_INIT :
          //myprintf("%d:Listen, port [%d]\r\n",sn, port);
         printf("%d:Listen, port [%d]\r\n",sn, port);

         if( (ret = listen(sn)) != SOCK_OK) return ret;
         break;

      case SOCK_CLOSED:
         //myprintf("%d:LBTStart\r\n",sn);
         printf("%d:LBTStart\r\n",sn);

         if((ret=socket(sn,Sn_MR_TCP,port,0x00)) != sn)
            return ret;
         //myprintf("%d:Opened\r\n",sn);
         printf("%d:Opened\r\n",sn);
         break;

      default:
         break;
   }
   return 1;
}

void spi_proc(void)
{
    //짜투￿????????? 처리?��
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
    //?��?��?��￿????????? ?��?�� ?��?��￿?????????￿????????? ?��?�� DMA 버퍼 ?��치까￿????????? ?��?��?��?��.
    if(spiCurIndex != spiPrevIndex)
    {
        //?��?��까�? ?��?? ?��치�? DMA 버퍼 ?��치보?�� ?��?��￿?????????
        //?��바�?��? ?��?��￿????????? 것이￿????????? ?��문에 ?��?��?? 같이 처리?��￿??????????��.
        if(spiPrevIndex > spiCurIndex)
        {
            tail = (MAX_DMA_BUFFER_SIZE - spiPrevIndex);
            //191016 rxlen = spiCurIndex - tail;
            //memcpy(spi_buf, &spiDMABuf[spiPrevIndex], tail);
            //memcpy(spi_buf, &Rx[spiPrevIndex], tail);
            memcpy(Tx, &Rx[spiPrevIndex], tail);

            //memcpy(&spi_buf[tail], &Rx[0], spiCurIndex);
            memcpy(&Tx[tail], &Rx[0], spiCurIndex);
            rxlen = spiCurIndex + tail;
        }
        else
        {
            rxlen = spiCurIndex - spiPrevIndex;
            //memcpy(spi_buf, &Rx[spiPrevIndex], rxlen);
            memcpy(Tx, &Rx[spiPrevIndex], rxlen);
        }

        ////////// 191015 Start

        //for(i=spiPrevIndex ; i<MAX_DMA_BUFFER_SIZE; i++)
        {
          //if( (Rx[i+0] == 0xFE) && (Rx[i+1] == 0xED) &&(Rx[i+2] == 0x50) && (Rx[i+3] == 0x11) )
          {
            gU8_buf_enable = 1;
            //gU16_index_start = i;
            gU16_index_start = 0;
            //gU16_index_length = 8+4*6*Rx[i+7]+8;  // Start:8 + 4*6*Rx[i+7] * End:8
            gU16_index_length = rxlen;
          }
        }
        ////////// 191015 End


        //￿?????????금까￿????????? ?��?? 버퍼 ?��￿????????? 기억
        spiPrevIndex = spiCurIndex;

        //UART￿????????? ?��?��?�� 보냄.
        //HAL_UART_Transmit(&huart2, (uint8_t *)&spi_buf, rxlen, 0xFFFF);
        //
#ifdef _DEBUG_MAIN_
         for(i=0; i<rxlen; i++)
         {
           if(((i+1) % 4) == 0 )
             printf("%02X \r\n", Tx[i]);
           else
             printf("%02X ", Tx[i]);        //fflush (stdout);    // for HAL Delay
         }
         printf("\r\n");
#endif
        //

    }
    //else
    //{
    //  gU8_buf_enable = 0; // disable
    //}
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
