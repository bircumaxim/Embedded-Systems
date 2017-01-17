/*
 * task.h
 *
 * Created: 1/17/2017 2:14:53 AM
 *  Author: bircumaxim
 */ 


#ifndef TASK_H_
#define TASK_H_

#include <avr/io.h>
#include <stdlib.h>
#include <avr/interrupt.h>


#define MAX_TASKS 20
#define MS_PER_CLOCK 10

typedef struct Task {
	uint32_t delay;
	uint32_t interval;
	uint8_t is_enabled;
	void (*handler)();
} Task;

void scheduler_start();
void scheduler_add_task(Task *task);

#endif /* TASK_H_ */