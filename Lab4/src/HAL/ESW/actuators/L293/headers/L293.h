/*
 * L293.h
 *
 * Created: 11/11/2016 11:19:04 AM
 *  Author: max
 */ 


#ifndef L293_H_
#define L293_H_

#include "../../../../Core/headers/io.h"

typedef struct {
	IO in1;
	IO in2;
	IO en;
	uint8_t volatile * ocr;
} L293Out;

void init_pwm();
L293Out l293_register_out(int ind1ID, int ind2ID, int enID, uint8_t volatile *dataDirection, uint8_t volatile *writeBuffer, uint16_t volatile *ocr);


#endif /* L293_H_ */