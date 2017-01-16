/*
 * lm20.c
 *
 * Created: 11/21/2016 2:07:28 AM
 *  Author: max
 */ 
#include "../headers/lm20.h"

void LM20_Init(){
	ADC_Init();
}

int LM20_GetTemperature(){
	int temp = (382 - ADC_GetData()) / 3;
	return temp;
}

int celsiusToKelvin(int celsius){
	return celsius+273;
}

int celsiusToFarenheit(int celsius){
	return celsius*18/10 + 32;
}