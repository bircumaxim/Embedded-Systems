/*
 * driver.c
 *
 * Created: 10/23/2016 6:08:58 PM
 *  Author: max
 */ 
#include "../headers/driver.h"

driver registerNewDriver(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* inputBuffer,uint8_t volatile* outputBuffer){
	driver drv;
	drv.dataDirection = dataDirection;
	drv.inputBuffer  = inputBuffer;
	drv.outputBuffer = outputBuffer;
	drv.pinIndex = pinIndex;
	return drv;
}

void setPin(driver periferal, int pinValue){
	if(pinValue){
		*periferal.outputBuffer |= 1 << periferal.pinIndex;
		} else {
		*periferal.outputBuffer &= ~(1 << periferal.pinIndex);
	}
	
}

void setDataDirectionMode(driver periferal, dataDirectionMode directionMode){
	if(directionMode == inputMode){
		*periferal.dataDirection &= ~(1 << periferal.pinIndex);
		} else {
		*periferal.dataDirection |= 1 << periferal.pinIndex;
	}
}

char readInput(driver periferal) {
	return bit_is_clear(*periferal.inputBuffer, periferal.pinIndex);
}