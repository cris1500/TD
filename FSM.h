#ifndef FSM_H
#define FSM_H

#include<stdint.h>
#include<stdbool.h>

#define MAX_LINE_COUNT 30
#define STR_SIZE 50

typedef struct FSM {
	char data[MAX_LINE_COUNT][STR_SIZE+1];
	uint16_t line_count;
	bool OK;
}AT;

extern AT at_data;

int parse(char current_char);
void print_state(AT* at_data);

#endif
