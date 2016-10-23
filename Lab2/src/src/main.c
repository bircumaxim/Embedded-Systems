/*
 * main.c
 *
 * Created: 10/22/2016 8:39:04 PM
 *  Author: max
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "core/include/driver.h"
#include "lcd/lcd.h"

void displayMsg(char* lcdMsg){
	LCDClear();
	LCDWriteString(lcdMsg);
}

void main(void)
{
	driver led = registerNewDriver(1, &DDRA, &PINA, &PORTA);
	driver button = registerNewDriver(0, &DDRA, &PINA, &PORTA );
	char isPressed = 0;
	LCDInit(LS_ULINE);
	setDataDirectionMode(led, output);
	setDataDirectionMode(button, input);
	setPin(button, high);
	
	
    while(1){
		if(readInput(button) == zero && !isPressed){
			setPin(led, high);
			displayMsg("ON");
			isPressed = 1;
			} else if (readInput(button) == high && isPressed) {
			setPin(led, zero);
			displayMsg("OFF");
			isPressed = 0;
		}
    }   
}