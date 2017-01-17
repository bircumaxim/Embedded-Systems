/*
 * src.c
 *
 * Created: 11/20/2016 3:59:23 PM
 *  Author: max
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "HAL/Core/headers/io.h"
#include "HAL/Core/headers/task.h"
#include "HAL/ESW/led/headers/led.h"

Led red_led;
Led yellow_led;
Led green_led;

Task toggle_red_led_task;
Task toggle_yellow_led_task;
Task toggle_green_led_task;

void toggle_red_led(){
	toggle_led(&red_led);
}

void toggle_yellow_led(){
	toggle_led(&yellow_led);
}

void toggle_green_led(){
	toggle_led(&green_led);
}

void init(){
	toggle_red_led_task.delay = 0;
	toggle_red_led_task.is_enabled = 1;
	toggle_red_led_task.interval = 300;
	toggle_red_led_task.handler = &toggle_red_led;
	
	toggle_yellow_led_task.delay = 100;
	toggle_yellow_led_task.is_enabled = 1;
	toggle_yellow_led_task.interval = 300;
	toggle_yellow_led_task.handler = &toggle_yellow_led;
		
	toggle_green_led_task.delay = 200;
	toggle_green_led_task.is_enabled = 1;
	toggle_green_led_task.interval = 300;
	toggle_green_led_task.handler = &toggle_green_led;
}

int main(void){
	red_led = create_led(0, &DDRA, &PORTA);
	yellow_led = create_led(1, &DDRA, &PORTA);
	green_led = create_led(2, &DDRA, &PORTA);

	init();

	scheduler_start();
	scheduler_add_task(&toggle_red_led_task);
	scheduler_add_task(&toggle_yellow_led_task);
	scheduler_add_task(&toggle_green_led_task);
	
	while(1) { };
	return 1;
}