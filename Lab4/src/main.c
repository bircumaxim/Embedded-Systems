/*
 * src.c
 *
 * Created: 11/20/2016 3:59:23 PM
 *  Author: max
 */ 


#include <avr/io.h>
#include "Drivers/headers/L293.h"

int main(void)
{
	L293Out l293Out1 = registerL293Out(2, 3, 4, &DDRD, &PORTD);
	L293Out l293Out2 = registerL293Out(5, 6, 7, &DDRD, &PORTD);
	
	L293 l293 = registerL293(l293Out1, l293Out2);
	
	
	while(1)
	{
		startWheel(l293.out1);
	}
}