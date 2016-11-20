/*
 * main.c
 *
 * Created: 10/22/2016 8:39:04 PM
 *  Author: max
 */ 

#include <stdio.h>
#include "Core/headers/uart_stdio.h"
#include <util/delay.h>

int main(void)
{
    while(1)
    {
        uart_stdio_init();
        
        int i = 0;
        
        while(1){
	        i++;
	        printf("Counter %d \n",i);
	        _delay_ms(1000);
        }
        return 1;
    }
}