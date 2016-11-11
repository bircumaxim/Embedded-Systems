/*
 * driver.h
 *
 * Created: 10/23/2016 6:08:37 PM
 *  Author: max
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_

#include <avr/io.h>
#include <avr/delay.h>

typedef enum dataDirectionMode{
	input,
	output
} dataDirectionMode;

typedef enum pinValue{
	high,
	zero
} pinValue;

typedef struct dirver
{
	uint8_t pinIndex;
	uint8_t volatile *dataDirection;
	uint8_t volatile *inputBuffer;
	uint8_t volatile *outputBuffer;
} driver;

driver registerNewDriver(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* inputBuffer, uint8_t volatile* outputBuffer);
void setDataDirectionMode(driver periferal, dataDirectionMode direction);
void setPin(driver periferal, pinValue pinVal);
pinValue readInput(driver periferal) ;

#endif /* INCFILE1_H_ */