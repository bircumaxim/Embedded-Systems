/*
 * main.c
 *
 * Created: 10/23/2016 8:42:35 PM
 *  Author: max
 */ 

#define DELAY_TIME_MS 1000

#include "core/headers/io.h"
#include "core/headers/uart_stdio.h"
#include "drivers/lcd/headers/lcd.h"

int main(void)
{
	
	IO button1 = registerConnection(0, &DDRA, &PINA, &PORTA);
	IO button2 = registerConnection(1, &DDRA, &PINA, &PORTA);
	setDataDirectionMode(button1, read);
	setDataDirectionMode(button2, read);
	
	writePin(button1, high);
	writePin(button2, high);
	
	uart_stdio_init();
	LCDInit(LS_ULINE);
	LM20_Init();
	
	int temperature;
	
    while(1)
    {
		temperature = LM20_GetTemperature();
		if(readPin(button1) == low){
			LCDClear();
			LCDWriteString("Kelvin");
			LCDWriteIntXY(1, 1, celsiusToKelvin(temperature),3);
			printf("Kelvin: %d\n", celsiusToKelvin(temperature));
		} else  {
			if(readPin(button2) == low){
				LCDClear();
				LCDWriteString("Fahrenheit");
				LCDWriteIntXY(1, 1, celsiusToFarenheit(temperature), 3);
				printf("Fahrenheit: %d\n", celsiusToFarenheit(temperature));
			} else {
				LCDClear();
				LCDWriteString("Celsius ");
				LCDWriteIntXY(1, 1, temperature,3);
				printf("Celsius : %d\n", temperature);
			}
		}
		_delay_ms(DELAY_TIME_MS);
	} 
}
