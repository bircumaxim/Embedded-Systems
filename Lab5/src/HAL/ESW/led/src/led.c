/*
 * led.h
 *
 * Created: 12/17/2016 9:18:39 PM
 *  Author: bircumaxim
 */ 

#include <stdio.h>
#include "../headers/led.h"

Led create_led(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* writeBuffer){
	Led led;
	led.connection = registerConnection(pinIndex, dataDirection, NULL, writeBuffer);
	setDataDirectionMode(led.connection, write);
	writePin(led.connection, low);
	led.state = off;
	return led;
}

void set_led(Led *led, power_state state){
	writePin(led->connection, state == on? high : low);
	led->state = state;
}

void toggle_led(Led *led){
	set_led(led, led->state == on ? off : on);
}

power_state get_led_state(Led *led){
	return led->state;
}