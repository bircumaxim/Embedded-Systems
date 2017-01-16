/*
 * IO.h
 *
 * Created: 11/11/2016 8:16:37 AM
 *  Author: max
 */ 
#ifndef IO_H_
#define IO_H_

#include <avr/io.h>
#include <avr/delay.h>
#include "../enums.h"

typedef struct IO
{
	uint8_t pinIndex;
	uint8_t volatile *dataDirection;
	uint8_t volatile *readBuffer;
	uint8_t volatile *writeBuffer;
} IO;

IO registerConnection(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* readBuffer, uint8_t volatile* writeBuffer);
void setDataDirectionMode(IO connection, dataDirectionMode direction);
void writePin(IO connection, pinValue pinVal);
pinValue readPin(IO connection) ;

#endif /* IO_H_ */