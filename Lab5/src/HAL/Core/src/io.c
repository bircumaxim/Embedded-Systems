/*
 * IO.c
 *
 * Created: 11/11/2016 8:17:44 AM
 *  Author: max
 */ 

#include "../headers/io.h"

IO registerConnection(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* readBuffer, uint8_t volatile* writeBuffer){
	IO drv;
	drv.dataDirection = dataDirection;
	drv.readBuffer  = readBuffer;
	drv.writeBuffer = writeBuffer;
	drv.pinIndex = pinIndex;
	return drv;
}

void setDataDirectionMode(IO connection, dataDirectionMode direction){
	if(direction == read){
		*connection.dataDirection &= ~(1 << connection.pinIndex);
	} else {
		*connection.dataDirection |= 1 << connection.pinIndex;
	}
}

void writePin(IO connection, pinValue pinVal){
	if(pinVal == high){
		*connection.writeBuffer |= 1 << connection.pinIndex;
	} else {
		*connection.writeBuffer &= ~(1 << connection.pinIndex);
	}
}

pinValue readPin(IO connection) {
	if(bit_is_clear(*connection.readBuffer, connection.pinIndex))
		return low;
	else
		return high;
}