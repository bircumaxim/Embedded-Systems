/*
 * car.h
 *
 * Created: 12/18/2016 2:52:56 AM
 *  Author: bircumaxim
 */ 


#ifndef CAR_H_
#define CAR_H_

#include "../../../HAL/ESW/motor/headers/motor.h"

typedef struct  {
	Motor motor1;
	Motor motor2;
} Car;

void init_car(Car *car);

//Car info
power_state car_get_state(Car *car);
motor_direction car_get_direction(Car *car);
int car_get_speed(Car *car);

//Car state
void start_car(Car *car);
void stop_car(Car *car);
void brake_car(Car *car);

//Car speed
void car_speed_up(Car *car);
void car_speed_down(Car *car);

//Car direction
void car_switch_direction(Car *car);

#endif /* CAR_H_ */