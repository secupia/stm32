#include <w5500_initcode.h>
#include "main.h"
#include "socket.h"

extern SPI_HandleTypeDef hspi1;
extern wiz_NetInfo gWIZNETINFO;

static uint32_t randomKey;


uint8_t W5500_dataRead() // SPI ������ ����
{
	uint8_t Dummy = 0xFF;
	uint8_t RxData;
	while (HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	HAL_SPI_TransmitReceive(&hspi1,&Dummy,&RxData,1,10); // SPI�� ���Ž� ���̵����͸� ������� Ŭ���� �����ǰ� �����̺갡 ���� �ش�.
	return RxData;
}
void W5500_dataSend(uint8_t Txdata) // SPI ������ �۽�
{
	 while (HAL_SPI_GetState(&hspi1) != HAL_SPI_STATE_READY);
	 HAL_SPI_Transmit(&hspi1, (uint8_t *) &Txdata, 1, 10);
}

void W5500_CS_select()
{
	//GPIOA->BRR = GPIO_PIN_3; // CS���� Low
  GPIOA->BRR = GPIO_PIN_4;
}

void W5500_CS_deselect()
{
	//GPIOA->BSRR = GPIO_PIN_3; // CS���� High
  GPIOA->BSRR = GPIO_PIN_4;
}

int isLinked(void)
{
	return (getPHYCFGR() & PHYCFGR_LNK_ON);
}

void W5500_hw_Rst(void) // �ϵ���� ����
{
  uint32_t tempTick;
  //GPIOA->BRR = GPIO_PIN_4; // RST ���� Low�� ����
  GPIOC->BRR = GPIO_PIN_4;

  tempTick = HAL_GetTick();
  while((HAL_GetTick() - tempTick) < 1 ); // 1ms �� ������

  //GPIOA->BSRR = GPIO_PIN_4; // RST ���� High ��.
  GPIOC->BSRR = GPIO_PIN_4;
}

void W5500_info()
{
	wizchip_getnetinfo(&gWIZNETINFO); // W5500 ���� ���� ��������
}

uint8_t W5500_init() // �ʱ�ȭ �Լ�
{
	uint8_t W5500SockBufSize[2][8] = {{2,2,2,2,2,2,2,2},{2,2,2,2,2,2,2,2}};
	uint32_t tickStart;

	reg_wizchip_spi_cbfunc(W5500_dataRead, W5500_dataSend); // SPI ��� ����, �۽� ��ɵ�� (�ݹ��Լ�)
	reg_wizchip_cs_cbfunc(W5500_CS_select, W5500_CS_deselect); // CS �� ���� ��ɵ�� (�ݹ��Լ�)

	if(ctlwizchip(CW_INIT_WIZCHIP,(void*)W5500SockBufSize) == -1)
		{
			//printf("W5500 initialized fail.\r\n");
			return -1; // �ʱ�ȭ ����
		}
		/*Set network information by default*/
		wizchip_setnetinfo(&gWIZNETINFO);
		tickStart = HAL_GetTick();
		do{ // PHY ����üũ
			randomKey++;
			if((HAL_GetTick() - tickStart) > 3000 )
			{
				//printf("Ethernet Link timeout.\r\n");
				return -1; // �̴��� Ÿ�Ӿƿ� ����
			}
		}while(!isLinked());
		return 1;
}


