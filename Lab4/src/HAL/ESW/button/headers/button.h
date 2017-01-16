/*
 * button.h
 *
 * Created: 12/17/2016 9:19:23 PM
 *  Author: bircumaxim
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../../Core/headers/io.h"
#include "../../state_enums.h"

typedef struct{
	power_state state;
	int inited;
	IO connection;
} Button;

Button create_button(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* readBuffer, uint8_t volatile* writeBuffer);
power_state get_button_state(Button *button);
int button_release(Button *button);

#endif /* BUTTON_H_ */