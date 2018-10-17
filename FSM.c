#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "FSM.h"

//---------Structura definita in FSM.h
AT at_data;

//--------Functie pentru parcurgerea caracterelor din fisier
// TO DO: salvare in at_data -> data
int parse(char current_char) {
	static uint16_t state = 0;
	switch (state) {
		case 0: 
			if (current_char == 13)
				state = 1;
			else
				state = 17;
			break;

		case 1: 
			if (current_char == 10)
				state = 2;
			else
				state = 17;
			break;

		case 2:
			if (current_char == 'O')
				state = 3;
			else if (current_char == 'E')
				state = 7;
			else if (current_char == '+')
				state = 11;
			else 
				state = 17;
			break;

		case 3:
			if (current_char == 'K')
				state = 4;
			else 
				state = 17;
			break;

		case 4:
			if (current_char == 13)
				state = 5;
			else
				state = 17;
			break;

		case 5: 
			if (current_char == 10)
				state = 6;
			else
				state = 17;
			break;

		case 6:
			return 1; //totul e ok(stare finala)
		
		case 7: 
			if (current_char == 'R')
				state = 8;
			else state = 17;
			break;

		case 8: 
			if (current_char == 'R')
				state = 9;
			else state = 17;
			break;

		case 9: 
			if (current_char == 'O')
				state = 10;
			else state = 17;
			break;

		case 10: 
			if (current_char == 'R')
				state = 4;
			else state = 17;
			break;

		case 11:
			if (current_char != 13) 
				state = 12;
			else state = 17;
			break;

		case 12: 
			if (current_char == 13)
				state = 13;
			else if (current_char != 13)
				if (current_char == '\n')
					at_data.line_count++;
				else
					state = 12;
			break;

		case 13: 
			if (current_char == 10)
				state = 14;
			else state = 17;
			break;

		case 14:
			if (current_char == 13)
				state = 15;
			else if (current_char == '+')
				state = 11;
			else state = 17;
			break;

		case 15: 
			if (current_char == 10)
				state = 16;
			else state = 17;
			break;

		case 16: 
			if (current_char == 'O')
				state = 3;
			else if (current_char == 'E')
				state = 7;
			else state = 17;
			break;

		case 17: 
			return 0; //eroare
	}
	
}

void print_state(AT* at_data) {
	uint16_t i;

	for (i = 0; i < MAX_LINE_COUNT; ++i) {
		printf("%s %d\n", at_data->data[i], at_data->line_count);
	}
}
