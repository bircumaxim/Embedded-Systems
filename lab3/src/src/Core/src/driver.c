/*
 * driver.c
 *
 * Created: 10/23/2016 6:08:58 PM
 *  Author: max
 */ 
#include "../include/driver.h"

driver registerNewDriver(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* inputBuffer,uint8_t volatile* outputBuffer){
	driver drv;
	drv.dataDirection = dataDirection;
	drv.inputBuffer  = inputBuffer;
	drv.outputBuffer = outputBuffer;
	drv.pinIndex = pinIndex;
	return drv;
}

void setDataDirectionMode(driver periferal, dataDirectionMode direction){
	if(direction == input){
		*periferal.dataDirection &= ~(1 << periferal.pinIndex);
		} else {
		*periferal.dataDirection |= 1 << periferal.pinIndex;
	}
}

void setPin(driver periferal, pinValue pinVal){
	if(pinVal == high){
		*periferal.outputBuffer |= 1 << periferal.pinIndex;
	} else {
		*periferal.outputBuffer &= ~(1 << periferal.pinIndex);
	}
	
}

pinValue readInput(driver periferal) {
	if(bit_is_clear(*periferal.inputBuffer, periferal.pinIndex))
		return zero;
	else
		return high;
}