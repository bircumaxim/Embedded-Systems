/*
 * main.c
 *
 * Created: 10/23/2016 8:42:35 PM
 *  Author: max
 */ 


#include <avr/io.h>
#include "core/include/driver.h"
#include "core/include/uart_stdio.h"
#include "lcd/lcd.h"

int main(void)
{
	uart_stdio_init();
	LCDInit(LS_ULINE);
	
	LCDWriteString("Hello World");
	
    while(1)
    {
		
	}
    
}