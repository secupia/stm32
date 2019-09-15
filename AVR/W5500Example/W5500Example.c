/*
 * W5500Example.c
 *
 * Created: 09.01.2016 15:57:03
 *  Author: Thomas
 */ 

//! Copyright (c)  2016 Thomas Oltzen
//! All rights reserved.
//!
//! Redistribution and use in source and binary forms, with or without
//! modification, are permitted provided that the following conditions
//! are met:
//!
//!     * Redistributions of source code must retain the above copyright
//! notice, this list of conditions and the following disclaimer.
//!     * Redistributions in binary form must reproduce the above copyright
//! notice, this list of conditions and the following disclaimer in the
//! documentation and/or other materials provided with the distribution.
//!     * Neither the name of the <ORGANIZATION> nor the names of its
//! contributors may be used to endorse or promote products derived
//! from this software without specific prior written permission.
//!
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//! AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//! IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
//! LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//! SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//! INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//! CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//! ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
//! THE POSSIBILITY OF SUCH DAMAGE.

#include <avr/io.h>
#include <util/delay.h>     /* for _delay_ms() */
#include <avr/interrupt.h>
#include "socket.h"
#include "wizchip_conf.h"
#include "spi_master.h"
#include "atmega128_system.h"
#include <avr/pgmspace.h>
#include <string.h>
#include <ctype.h>

#include <stdlib.h>
#include <stdio.h> // printf 함수를 사용하기 위하여 include.

#define GREETING_MSG 		 "Bye bye!\r\n"

#define DATA_BUF_SIZE 80

uint8_t read_buffer[DATA_BUF_SIZE] ;

uint8_t write_buffer_len = 0;
uint8_t write_buffer[DATA_BUF_SIZE] ;

#define IP_STATE_NO_SOCKET	0
#define IP_STATE_SOCKET		1
#define IP_STATE_LISTEN     2
#define IP_STATE_CLOSE		3
#define IP_STATE_ECHO		4
#define IP_STATE_GREETING   5
#define IP_STATE_DATA		IP_STATE_ECHO

uint8_t sock_state=IP_STATE_NO_SOCKET;

const wiz_NetInfo PROGMEM network_info  = { .mac 	= {0x00, 0x08, 0xdc, 0xFF, 0xFF, 0xFF},	// Mac address: Please use your own MAC address.
.ip 	= {192, 168, 0, 201},					// IP address
.sn 	= {255, 255, 255, 0},					// Subnet mask
.gw 	= {192, 168, 0, 1}};					// Gateway address
//==========================================================================================
// Serial: Printf Configuration
//==========================================================================================
static int TxChar0(char data, FILE *stream);
static FILE device = FDEV_SETUP_STREAM(TxChar0, NULL, _FDEV_SETUP_WRITE);
//==========================================================================================
// Serial: Printf Configuration for PC Communication
//==========================================================================================
#define BAUD_RATE	9600
void Init_uart0(void)
{
    unsigned int baud=1;   // 초기 baud값을 "1"로 설정한다. 

    baud = ((F_CPU+(BAUD_RATE*8L))/(BAUD_RATE*16L)-1);	// baud를 프로그램으로 계산 한다.
    UBRR0H=(unsigned char) (baud >>8);       			// baud 계산된 값으로  H레지스터 설정
    UBRR0L=(unsigned char) (baud & 0xFF);           	// baud 계산된 값으로  L레지스트  설정

    /* Enable receiver and transmitter */
    UCSR0B = (0<<RXCIE0)|(0<<TXCIE0)|(1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 2stop bit */
	baud = UDR0; // dummy read
} // USART0_Init 
//------------------------------------------------------------------------------------------
int TxChar0(char data, FILE * stream)
{
    while(!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
    return 0;
}
//==========================================================================================
void cs_sel(void) 
{
	W5500_SPI_PORT &= ~(1<<W5500_SS);	// Clear W5500 CS to Low
}

void cs_desel(void) 
{
	W5500_SPI_PORT |= (1<<W5500_SS);	// Set  W5500 CS to High
}

uint8_t spi_rb(void) {
	return SPI_TransferByte(0);
}

void spi_wb(uint8_t b) {
	SPI_TransferByte(b);
}


uint8_t echo (){
	int16_t size = getSn_RX_RSR(0);
	if (size == 0) return IP_STATE_ECHO;
	if(size > DATA_BUF_SIZE) size = DATA_BUF_SIZE;
	int32_t ret = recv(0,read_buffer,size);
	if (ret<=0)
	return IP_STATE_CLOSE;
	for (uint8_t i = 0 ; i < ret; i++){
		write_buffer[i]=toupper(read_buffer[i]);	//대문자로 반향
	}
	int32_t send_ret = send(0, write_buffer, ret);
	if (ret != send_ret){
		return IP_STATE_CLOSE;
	}
	
	for (int i=0; i< ret ; i++){
		if (read_buffer[i]=='.'){
			return IP_STATE_GREETING;
		}
	}
	return IP_STATE_ECHO;
}

uint8_t greeting(){
	send(0, GREETING_MSG, strlen(GREETING_MSG));
	return IP_STATE_CLOSE;
}

void ip_init(void){
	wiz_NetInfo netInfo;
	uint8_t  bufSize[] = {2, 2, 2, 2};
	reg_wizchip_cs_cbfunc(cs_sel, cs_desel);
	reg_wizchip_spi_cbfunc(spi_rb, spi_wb);
	wizphy_reset();
	wizchip_init(bufSize, bufSize);
	memcpy_P(&netInfo, &network_info, sizeof(wiz_NetInfo));
	wizchip_setnetinfo(&netInfo);
	sock_state=IP_STATE_NO_SOCKET;
}


void ip_task(void){
	switch(sock_state){
		case IP_STATE_NO_SOCKET:
			if(socket(0, Sn_MR_TCP, 5000, 0) == 0)
			sock_state = IP_STATE_SOCKET;
			break;
		case IP_STATE_SOCKET:
			switch (listen(0))
			{
				case SOCK_OK :
				sock_state = IP_STATE_LISTEN;
				printf("IP_STATE_LISTEN\n");
				break;

				case SOCKERR_SOCKCLOSED :
				sock_state = IP_STATE_CLOSE;
				printf("IP_STATE_CLOSE\n");
			}
			break;

		case IP_STATE_LISTEN :
			switch(getSn_SR(0))
			{
				case SOCK_LISTEN :
				_delay_ms(100);
				break;
				case SOCK_ESTABLISHED:
				sock_state = IP_STATE_ECHO;
				break;
				default:
				sock_state = IP_STATE_CLOSE;
			}
			break;
		case IP_STATE_CLOSE:
			disconnect(0);
			close(0);
			sock_state=IP_STATE_NO_SOCKET;
			break;
		case IP_STATE_ECHO:
			if (getSn_SR(0) == SOCK_ESTABLISHED) {
				sock_state = echo();
				} else {
				sock_state = IP_STATE_CLOSE;
			}
			break;
		case IP_STATE_GREETING:
			if (getSn_SR(0) == SOCK_ESTABLISHED) {
				sock_state = greeting();
				} else {
				sock_state = IP_STATE_CLOSE;
			}
			break;
	}

}

int main(void)
{	
	Init_uart0();stdout = &device;

	printf("setup \n\r");

	SPI_MasterInit();

	printf("SPI init \n\r");

	ip_init();

	printf("IP Init \n\r");

	while (1){
		ip_task();
	printf("sock_state = %d\r\n",sock_state);
	_delay_ms(500);
	}
}
