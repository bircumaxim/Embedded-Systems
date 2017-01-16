/*
 * motor.h
 *
 * Created: 12/17/2016 7:12:29 PM
 *  Author: bircumaxim
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_

#include "../../actuators/L293/headers/L293.h"
#include "../../../Core/headers/io.h"
#include "../motor_enums.h"
#include "../../state_enums.h"

typedef struct {
	L293Out l293out;
	int speed;
	power_state state;
	motor_direction direction;
} Motor;

Motor create_motor(L293Out l293out);

//Motor state
void start_motor(Motor *motor);
void stop_motor(Motor *motor);
void block_motor(Motor *motor);
void reset_motor(Motor *motor);

//Speed control 
void set_speed(Motor *motor, int speed);
void speed_up(Motor *motor);
void speed_down(Motor *motor);

//Motor direction
void switch_direction(Motor *motor);
void set_direction(Motor *motor, motor_direction direction);

#endif /* MOTOR_H_ */