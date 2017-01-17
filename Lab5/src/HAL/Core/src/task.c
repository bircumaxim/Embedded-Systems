/*
 * task.c
 *
 * Created: 1/17/2017 2:17:08 AM
 *  Author: bircumaxim
 */ 

#include "../headers/task.h"
#include "../headers/utils.h"

uint8_t tasks_count = 0;
Task **tasks;
int32_t tasks_remaining_time[MAX_TASKS];

void scheduler_start(){
	tasks = malloc(sizeof(Task*) * MAX_TASKS);

	bit_set_1(&TCCR1B,CS11);

	bit_set_1(&TCCR1B,WGM12);

	bit_set_1(&TIMSK,OCIE1A);


	TCNT1 = 0;
	OCR1A = 1250; // 0.01 ms

	sei();
}

void scheduler_add_task(Task *task){
	if(tasks_count < MAX_TASKS - 1){
		tasks[tasks_count] = task;
		tasks_remaining_time[tasks_count] = task->delay;
		tasks_count++;
	}
}

ISR(TIMER1_COMPA_vect){
	int i;
	for(i = 0; i < tasks_count;i++){
		// avoid overflow
		if(tasks_remaining_time[i] >= 0){
			tasks_remaining_time[i] -= MS_PER_CLOCK;
		}

		uint8_t should_run = tasks[i]->is_enabled && tasks_remaining_time[i] <= 0;
		if(should_run){
			tasks[i]->handler();
		}

		if(!tasks[i]->is_enabled || should_run){
			tasks_remaining_time[i] = tasks[i]->interval;
		}
	}
}