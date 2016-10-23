/*
 * main.c
 *
 * Created: 10/22/2016 8:39:04 PM
 *  Author: max
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "core/headers/driver.h"

void main(void)
{
	driver led = registerNewDriver(1, &DDRA, &PINA, &PORTA);
	driver button = registerNewDriver(0, &DDRA, &PINA, &PORTA );
	
	setDataDirectionMode(led, outputMode);
	setDataDirectionMode(button, inputMode);
	setPin(button,1);
	
    while(1){
		setPin(led, readInput(button));
    }   
}