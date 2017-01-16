/*
 * uart_stdio.h
 *
 * Created: 11/11/2016 9:32:32 AM
 *  Author: max
 */ 


#ifndef UART_STDIO_H_
#define UART_STDIO_H_

#include <stdio.h>
#include <stdlib.h>

void uart_stdio_init();
int uart_stdio_putchar(char c, FILE *stream);

#endif /* UART_STDIO_H_ */