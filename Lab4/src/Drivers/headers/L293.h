/*
 * L293.h
 *
 * Created: 11/11/2016 11:19:04 AM
 *  Author: max
 */ 


#ifndef L293_H_
#define L293_H_

#include "../../Core/headers/io.h"

typedef struct {
	IO in1;
	IO in2;
	IO en;
} L293Out;

typedef struct {
	L293Out out1;
	L293Out out2;
} L293;

L293Out registerL293Out(int ind1ID, int ind2ID, int enID, uint8_t volatile *writeBuffer, uint8_t volatile *dataDirection);
L293 registerL293(L293Out out1, L293Out out2);

void startWheel();



#endif /* L293_H_ */