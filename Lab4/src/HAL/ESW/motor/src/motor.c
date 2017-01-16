/*
 * motor.c
 *
 * Created: 12/17/2016 7:12:37 PM
 *  Author: bircumaxim
 */ 
#include "../headers/motor.h"

Motor create_motor(L293Out l293out){
	Motor motor;
	motor.l293out = l293out;
	reset_motor(&motor);
	return motor;
}

void reset_motor(Motor *motor){
	motor->speed = 0;
	motor->state = off;
	motor->direction = forward;
}

//Motor state
void start_motor(Motor *motor){
	motor->state = on;
	if(motor->direction == forward){
		writePin(motor->l293out.in1, high);
		writePin(motor->l293out.in2, low);
	} else {
		writePin(motor->l293out.in1, low);
		writePin(motor->l293out.in2, high);
	}
	writePin(motor->l293out.en, low);
	*motor->l293out.ocr = motor->speed;
}

void stop_motor(Motor *motor){
	writePin(motor->l293out.in1, low);
	writePin(motor->l293out.in2, low);
	writePin(motor->l293out.en, low);
	motor->state = off;
}

void block_motor(Motor *motor){
	writePin(motor->l293out.in1, high);
	writePin(motor->l293out.in2, high);
}


//Speed control 
void set_speed(Motor *motor, int speed){
	motor->speed = (speed > 0 && speed <= 1000) ? speed : motor->speed;
	*motor->l293out.ocr = motor->speed;
}

void speed_up(Motor *motor){
	motor->speed = motor->speed <= 900 ? motor->speed + 100 : motor->speed;
	*motor->l293out.ocr = motor->speed;
}

void speed_down(Motor *motor){
	motor->speed = motor->speed >= 100 ? motor->speed - 100 : motor->speed;
	*motor->l293out.ocr = motor->speed;
}


//Motor direction
void switch_direction(Motor *motor){
	motor->direction = motor->direction == forward ? backward : forward;
}

void set_direction(Motor *motor, motor_direction direction){
	motor->direction = direction;
}




