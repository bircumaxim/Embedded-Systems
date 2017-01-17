/*
 * car.c
 *
 * Created: 12/18/2016 2:53:04 AM
 *  Author: bircumaxim
 */ 

#include "../headers/car.h"


void init_car(Car* car){
	car->motor1 = create_motor(l293_register_out(2, 3, 4, &DDRD, &PORTD, &OCR1B));
	car->motor2 = create_motor(l293_register_out(6, 7, 5, &DDRD, &PORTD, &OCR1A));
}

power_state car_get_state(Car *car){
	return car->motor1.state;
}

motor_direction car_get_direction(Car *car){
	return car->motor1.direction;
}

int car_get_speed(Car *car){
	return car->motor1.speed;
}

void start_car(Car *car){
	start_motor(&car->motor1);
	start_motor(&car->motor2);
}

void stop_car(Car *car){
	stop_motor(&car->motor1);
	stop_motor(&car->motor2);
}

void brake_car(Car *car){
	block_motor(&car->motor1);
	block_motor(&car->motor2);
}

void car_speed_up(Car *car){
	speed_up(&car->motor1);
	speed_up(&car->motor2);
}

void car_speed_down(Car *car){
	speed_down(&car->motor1);
	speed_down(&car->motor2);
}

void car_switch_direction(Car *car){
	switch_direction(&car->motor1);
	switch_direction(&car->motor2);
	start_car(car);
}


