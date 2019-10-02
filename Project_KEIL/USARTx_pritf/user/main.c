#include <stm32f10x.h>
#include "usart.h"
//#define CTRT


uint8_t TxBuffer[] = "\n\rUSART Hyperterminal Hardware Flow Control Example: USART - \
Hyperterminal communication using hardware flow control\n\r";

#ifndef CTRT 
//配置矢量中断，矢量的意思就是有顺序，有先后的意思。
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;	//定义数据结构体
  
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0000);//将中断矢量放到Flash的0地址

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//设置优先级配置的模式，详情请阅读原材料中的文章

  //使能串口中断，并设置优先级
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
  NVIC_Init(&NVIC_InitStructure);	//将结构体丢到配置函数，即写入到对应寄存器中
}
#endif

int main(void)
{
	u32 i=0xffffff;
	char c;
	
	SystemInit();

#ifdef CTRT		  /*使用CTS RTS硬件流模式*/
	USART_CTRT_Configuartion();
	while(NbrOfDataToTransfer--)
  	{
    		USART_SendData(USART1, TxBuffer[TxCounter++]);
    		while(USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);          
  	}
  
  	/*Receive a string (Max RxBufferSize bytes) from the Hyperterminal ended by '\r' (Enter key) */
  	while(1)
  	{ 	
	    	if(USART_GetFlagStatus(USART1, USART_FLAG_RXNE) != RESET)
    		{
       		USART_SendData(USART1,USART_ReceiveData(USART1));
    		}   
  	}
#else		/*普通串口模式*/
	usart_Configuration();	
	//NVIC_Configuration();
  	while(1)
	{
		//printf("Waveshare!\r\n");
		//if(USART1->SR & 0x20)	// 0010 0000
		if(USART1->SR & USART_SR_RXNE)
		{
			c = USART_ReceiveData(USART1);
			USART_SendData(USART1, c);
		}
		
		
		
		//while(--i);
		//i=0xffffff;
	}
#endif
}

