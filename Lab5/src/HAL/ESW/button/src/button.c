/*
 * button.c
 *
 * Created: 12/17/2016 9:19:34 PM
 *  Author: bircumaxim
 */ 

#include <stdio.h>
#include "../headers/button.h"

Button create_button(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* readBuffer, uint8_t volatile* writeBuffer) {
	Button button;
	button.connection = registerConnection(pinIndex, dataDirection, readBuffer, writeBuffer);
	setDataDirectionMode(button.connection, read);
	writePin(button.connection, high);
	button.state = off;
	button.inited = 0;
	return button;
}

power_state get_button_state(Button *button) {
	return readPin(button->connection) == high ? off : on;
}

int button_release(Button *button){
	power_state current_state = get_button_state(button);
	if(button->inited){
		if(current_state == off && button->state == on) {
			button->state = off;
			return 1;
		}
		button->state = current_state;
	} else if(current_state == off) {
		button->inited = 1;
	}
	return 0;
}