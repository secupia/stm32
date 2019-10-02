#include <stm32f10x.h>
#include "usart.h"
//#define CTRT


uint8_t TxBuffer[] = "\n\rUSART Hyperterminal Hardware Flow Control Example: USART - \
Hyperterminal communication using hardware flow control\n\r";

#ifndef CTRT 
//����ʸ���жϣ�ʸ������˼������˳�����Ⱥ����˼��
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;	//�������ݽṹ��
  
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0000);//���ж�ʸ���ŵ�Flash��0��ַ

  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);//�������ȼ����õ�ģʽ���������Ķ�ԭ�����е�����

  //ʹ�ܴ����жϣ����������ȼ�
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;  
  NVIC_Init(&NVIC_InitStructure);	//���ṹ�嶪�����ú�������д�뵽��Ӧ�Ĵ�����
}
#endif

int main(void)
{
	u32 i=0xffffff;
	char c;
	
	SystemInit();

#ifdef CTRT		  /*ʹ��CTS RTSӲ����ģʽ*/
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
#else		/*��ͨ����ģʽ*/
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

