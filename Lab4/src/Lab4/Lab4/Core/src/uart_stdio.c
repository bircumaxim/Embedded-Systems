/*
 * uart_stdio.c
 *
 * Created: 11/11/2016 9:32:49 AM
 *  Author: max
 */ 

#include <stdio.h>
#include <avr/io.h>

#define UART_BAUD  9600
#define F_CPU 1000000UL

int uart_stdio_putchar(char c, FILE *stream)
{
	if (c == '\n')
	uart_stdio_putchar('\r', stream);
	while(~UCSRA & (1 << UDRE));
	UDR = c;

	return 0;
}

FILE uart_str = FDEV_SETUP_STREAM(uart_stdio_putchar, NULL, _FDEV_SETUP_RW);

void uart_stdio_init(){
	stdout = stdin = &uart_str;
	
	#if F_CPU < 2000000UL && defined(U2X)
	UCSRA = _BV(U2X);             /* improve baud rate error by using 2x clk */
	UBRRL = (F_CPU / (8UL * UART_BAUD)) - 1;
	#else
	UBRRL = (F_CPU / (16UL * UART_BAUD)) - 1;
	#endif
	UCSRB = _BV(TXEN) | _BV(RXEN); /* tx/rx enable */
}