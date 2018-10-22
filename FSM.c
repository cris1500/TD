#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "FSM.h"

//---------Structura definita in FSM.h
AT at_data;
uint8_t i;

//--------Functie pentru parcurgerea caracterelor din fisier
// TO DO: salvare in at_data -> data
int parse(char current_char) {
	static uint16_t state = 0;
        
	switch (state) {
		case 0: 
			if (current_char == 13){
                                printf("Starea %d %c\n", state, current_char);
				state = 1;
                                at_data.data[at_data.line_count][i++]=current_char;
                                //printf("Starea %d %c\n", state, current_char);
                        }
			else
				state = 17;
			break;

		case 1: 
			if (current_char == 10){
				printf("Starea %d %c\n", state, current_char);
                                state = 2;
                                at_data.data[at_data.line_count][i++] = current_char;
                                at_data.line_count++; //urmeaza \n dupa <CR><LF> si se ignora
                                //printf("Starea %d %c\n", state, current_char);
                        }
			else
				state = 17;
                        
			break;

		case 2:
			if (current_char == 'O'){
                                printf("Starea %d %c\n", state, current_char);
				state = 3;
                                at_data.data[at_data.line_count][i++] = current_char;
                                
                        }
			else if (current_char == 'E'){
                                printf("Starea %d %c\n", state, current_char);
				state = 7;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else if (current_char == '+'){
                                printf("Starea %d %c\n", state, current_char);
				state = 11;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else 
				state = 17;
			break;

		case 3:
			if (current_char == 'K'){
                                printf("Starea %d %c\n", state, current_char);
				state = 4;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else 
				state = 17;
			break;

		case 4:
			if (current_char == 13){
                                printf("Starea %d %c\n", state, current_char);
				state = 5;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else
				state = 17;
			break;

		case 5: 
			if (current_char == 10){
                                printf("Starea %d %c\n", state, current_char);
				state = 6;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else
				state = 17;
			break;

		case 6:
                        printf("TOTUL E OK\n");
			return 1; //totul e ok(stare finala)
		
		case 7: 
			if (current_char == 'R'){
                                printf("Starea %d %c\n", state, current_char);
				state = 8;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else state = 17;
			break;

		case 8: 
			if (current_char == 'R'){
                                printf("Starea %d %c\n", state, current_char);
				state = 9;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else state = 17;
			break;

		case 9: 
			if (current_char == 'O'){
                                printf("Starea %d %c\n", state, current_char);
				state = 10;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else state = 17;
			break;

		case 10: 
			if (current_char == 'R'){
                                printf("Starea %d %c\n", state, current_char);
				state = 4;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else state = 17;
			break;

		case 11:
			if (current_char != 13) {
                                printf("Starea %d %c\n", state, current_char);
				state = 12;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else state = 17;
			break;

		case 12: 
			if (current_char == 13){
                                printf("Starea %d %c\n", state, current_char);
				state = 13;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else if (current_char != 13){
                            printf("Starea %d %c\n", state, current_char);
                            state = 12;
                            at_data.data[at_data.line_count][i++] = current_char;
                        }
			break;

		case 13: 
			if (current_char == 10){
                                printf("Starea %d %c\n", state, current_char);
				state = 14;
                                at_data.data[at_data.line_count][i++] = current_char;
                                at_data.line_count++;
                        }
			else state = 17;
			break;

		case 14:
			if (current_char == 13){
                                printf("Starea %d %c\n", state, current_char);
				state = 15;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else if (current_char == '+'){
                                printf("Starea %d %c\n", state, current_char);
				state = 11;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else state = 17;
			break;

		case 15: 
			if (current_char == 10){
                                printf("Starea %d %c\n", state, current_char);
				state = 16;
                                at_data.data[at_data.line_count][i++] = current_char;
                                at_data.line_count++;
                        }
			else state = 17;
			break;

		case 16: 
			if (current_char == 'O'){
                                printf("Starea %d %c\n", state, current_char);
				state = 3;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else if (current_char == 'E'){
                                printf("Starea %d %c\n", state, current_char);
				state = 7;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else state = 17;
			break;

		case 17: 
                    printf("UNDEVA E O EROARE \n");
			return 0; //eroare
	}
	
}

void print_state() {
	uint16_t i;
	for (i = 0; i < at_data.line_count; ++i) {
		printf("%s %d\n", at_data.data[i], at_data.line_count);
	}
}
