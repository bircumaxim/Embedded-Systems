/*
 * L293.c
 *
 * Created: 11/11/2016 11:19:22 AM
 *  Author: max
 */ 

#include "../headers/L293.h"
#include <stdlib.h>

L293Out l293_register_out(int ind1ID, int ind2ID, int enID, uint8_t volatile *dataDirection, uint8_t volatile *writeBuffer, uint16_t volatile *ocr){
	L293Out out;
	out.in1 = registerConnection(ind1ID, dataDirection, NULL, writeBuffer);
	out.in2 = registerConnection(ind2ID, dataDirection, NULL, writeBuffer);
	out.en = registerConnection(enID, dataDirection, NULL, writeBuffer);
	
	out.ocr = ocr;
	*out.ocr = 0;
	
	setDataDirectionMode(out.in1, write);
	setDataDirectionMode(out.in2, write);
	setDataDirectionMode(out.en, write);
	
	writePin(out.in1, low);
	writePin(out.in2, low);
	writePin(out.en, low);
	init_pwm();
	return out;
}

void init_pwm(){
	TCCR1A |= (1 << WGM11) | (1 << WGM10) | (1 << COM1A1) | (1 << COM1B1);
	TCCR1B |= (1 << WGM12) | (1 << CS11) | (1 << CS10);
}






