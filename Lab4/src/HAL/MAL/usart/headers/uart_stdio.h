/*
 * uart_stdio.h
 *
 * Created: 11/11/2016 9:32:32 AM
 *  Author: max
 */ 


#ifndef UART_STDIO_H_
#define UART_STDIO_H_

#include <stdio.h>
#include <avr/io.h>

int uart_stdio_putchar(char c, FILE *stream);
void uart_stdio_init();

#endif /* UART_STDIO_H_ */