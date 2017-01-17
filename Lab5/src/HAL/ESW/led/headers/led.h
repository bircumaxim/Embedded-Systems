/*
 * ledh.h
 *
 * Created: 12/17/2016 9:18:23 PM
 *  Author: bircumaxim
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../../Core/headers/io.h"
#include "../../state_enums.h"

typedef struct {
	power_state state;
	IO connection;
} Led;

Led create_led(uint8_t pinIndex, uint8_t volatile* dataDirection, uint8_t volatile* writeBuffer);
void set_led(Led *led, power_state state);
void toggle_led(Led *led);
power_state get_led_state(Led *led);

#endif /* LEDH_H_ */