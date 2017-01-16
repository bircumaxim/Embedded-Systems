/*
 * adc.c
 *
 * Created: 11/21/2016 2:08:47 AM
 *  Author: max
 */ 
#include "../headers/adc.h"

void ADC_Init(){
	ADMUX = (1 << REFS0);
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

int ADC_GetData(){
	int adcData = 0;
	int port = 3;
	while(ADCSRA & 1 << ADSC);
	port &= 0x07;
	ADMUX = (ADMUX & ~(0x07)) | port;
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC));
	adcData = ADC;
	return adcData;
}