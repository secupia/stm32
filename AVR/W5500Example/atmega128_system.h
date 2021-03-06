#ifndef  _ATMEGA128_SYSTEM_H_
#define  _ATMEGA128_SYSTEM_H_

#define W5500_SPI_PORT	PORTB
#define W5500_SPI_DDR	DDRB

#define W5500_SS	0	// PORTB.0
#define W5500_SCK	1	// PORTB.1
#define W5500_MOSI	2	// PORTB.2
#define W5500_MISO	3	// PORTB.3

#define W5500_IO_PORT	PORTE
#define W5500_IO_DDR	DDRE

#define W5500_INT	4	// PORTE.4, INT4
#define W5500_RESET 5	// PORTE.5

#endif   // _W5500_H_
