/*
 * L293.c
 *
 * Created: 11/11/2016 11:19:22 AM
 *  Author: max
 */ 

#include "../headers/L293.h"
#include <stdlib.h>

L293Out registerL293Out(int ind1ID, int ind2ID, int enID, uint8_t volatile *writeBuffer, uint8_t volatile *dataDirection){
	L293Out out;
	out.in1 = registerConnection(ind1ID, dataDirection, NULL, writeBuffer);
	out.in2 = registerConnection(ind2ID, dataDirection, NULL, writeBuffer);
	out.en = registerConnection(enID, dataDirection, NULL, writeBuffer);
	
	setDataDirectionMode(out.in1, write);
	setDataDirectionMode(out.in2, write);
	setDataDirectionMode(out.en, write);
}

L293 registerL293(L293Out out1, L293Out out2){
	L293 l293;
	l293.out1 = out1;
	l293.out2 = out2;
}

void startWheel(L293Out will){
	writePin(will.in1, high);
}



