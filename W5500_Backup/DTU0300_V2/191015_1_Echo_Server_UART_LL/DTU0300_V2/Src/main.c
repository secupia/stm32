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
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include <w5500_initcode.h>
#include "w5500_initcode.h"
#include "socket.h"
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

volatile uint8_t buf_index = 0;
uint8_t Tx[] = {0xC0, 0x33, 0x9D, 0x37, 0x45, 0x2F};
uint8_t Rx[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
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

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  HAL_GPIO_TogglePin(LED_SOCKET_GPIO_Port, LED_SOCKET_Pin);
	  //printf("0x0A \r \n");
	  //w5500_s0_status = getSn_SR(0);
    //w5500_s1_status = getSn_SR(1);

	  //printf("W5500 Status Socket0 == 0x%X Socket1 == 0x%X \r \n", w5500_s0_status , w5500_s1_status);
	  printf("%d %d %d %d %d %d \r \n", Rx[0], Rx[1], Rx[2], Rx[3], Rx[4], Rx[5]);
	  HAL_Delay(100);
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

   switch(getSn_SR(sn))
   {
      case SOCK_ESTABLISHED :
         if(getSn_IR(sn) & Sn_IR_CON)
         {
            //myprintf("%d:Connected\r\n",sn);
            printf("%d:Connected\r\n",sn);

            setSn_IR(sn,Sn_IR_CON);
         }
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