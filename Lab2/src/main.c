/*
 * main.c
 *
 * Created: 10/22/2016 8:39:04 PM
 *  Author: max
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "core/headers/io.h"
#include "Drivers/lcd/headers/lcd.h"

void displayMsg(char* lcdMsg){
	LCDClear();
	LCDWriteString(lcdMsg);
}

void main(void)
{
	IO led = registerConnection(1, &DDRA, &PINA, &PORTA);
	IO button = registerConnection(0, &DDRA, &PINA, &PORTA );
	char isPressed = 0;
	LCDInit(LS_ULINE);
	setDataDirectionMode(led, write);
	setDataDirectionMode(button, read);
	writePin(button, high);
	
    while(1){
		if(readPin(button) == low && !isPressed){
			writePin(led, high);
			displayMsg("ON");
			isPressed = 1;
		} else if (readPin(button) == high && isPressed) {
			writePin(led, low);
			displayMsg("OFF");
			isPressed = 0;
		}
    }   
}