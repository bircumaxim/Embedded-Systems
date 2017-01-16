/*
 * src.c
 *
 * Created: 11/20/2016 3:59:23 PM
 *  Author: max
 */ 


#include <avr/io.h>
#include <util/delay.h>
#include "HAL/ESW/motor/headers/motor.h"
#include "HAL/MAL/usart/headers/uart_stdio.h"
#include "HAL/ESW/led/headers/led.h"
#include "HAL/ESW/button/headers/button.h"
#include "ASW/car/headers/car.h"
#include "HAL/ESW/hmi/lcd/headers/lcd.h"

void displayMsg(char* direction, int speed){	
	LCDClear();
	LCDWriteString(direction);
	LCDGotoXY(0,1);
	LCDWriteString("SPEED = ");
	LCDWriteInt(speed,4);
}

void displayInfo(Car *car){
	if(car->motor1.direction == forward){
		displayMsg("FORWORD", car->motor1.speed);
	} else {
		displayMsg("BACKWARD", car->motor1.speed);
	}
}


int main(void)
{	
	Car car;
	init_car(&car);
	
	Button start_btn = create_button(0, &DDRA, &PINA, &PORTA);
	Button switch_direction_btn = create_button(3, &DDRA, &PINA, &PORTA);
	Button speed_up_btn = create_button(1, &DDRA, &PINA, &PORTA);
	Button speed_down_btn = create_button(2, &DDRA, &PINA, &PORTA);
		
	LCDInit(LS_ULINE);
	LCDWriteString("OFF");
	
	while(1)
	{
		if(button_release(&start_btn)){
			if(car_get_state(&car) == off){
				start_car(&car);
				displayInfo(&car);
			} else{
				stop_car(&car);
				LCDClear();
				LCDWriteString("OFF");
			}
		} 
		
		if(button_release(&switch_direction_btn)){
			car_switch_direction(&car);
			displayInfo(&car);
		}
		
		if(button_release(&speed_up_btn)){
			car_speed_up(&car);
			displayInfo(&car);
		}
		
		if(button_release(&speed_down_btn)){
			car_speed_down(&car);
			displayInfo(&car);
		}
	}
}