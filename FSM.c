#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include "FSM.h"

//---------Structura definita in FSM.h
AT at_data;
uint8_t i;

//--------Functie pentru parcurgerea caracterelor din fisier
int parse(char current_char) {
	static uint16_t state = 0;
	switch (state) {
		case 0: 
			if (current_char == 13){
				state = 1;
                                at_data.data[at_data.line_count][i++]=current_char;
                        }
			else{
                                printf("Lipseste <CR> la linia %d starea %d\n", at_data.line_count+1, state);
				state = 17;
                        }
			break;

		case 1: 
			if (current_char == 10){
                                state = 2;
                                at_data.data[at_data.line_count][i++] = current_char;
                                at_data.data[at_data.line_count][i] = '\0';
                                at_data.line_count++; //urmeaza \n dupa <CR><LF> si se ignora;
                                i = 0; //se trece pe randul urmator din matrice, la coloana 0;
                        }
			else{
                                printf("Lipseste <LF> la linia %d starea %d\n", at_data.line_count+1, state);
				state = 17;
                        }
                        
			break;

		case 2:
			if (current_char == 'O'){
				state = 3;
                                at_data.data[at_data.line_count][i++] = current_char;
                                
                        }
			else if (current_char == 'E'){
				state = 7;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else if (current_char == '+'){
				state = 11;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else {
                                printf("Lipseste 'O'/'E'/'+' la linia %d starea %d", at_data.line_count+1, state);
				state = 17;
                        }
			break;

		case 3:
			if (current_char == 'K'){
				state = 4;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else {
                                printf("Lipseste 'K' la linia %d starea %d", at_data.line_count+1, state);
				state = 17;
                        }
			break;

		case 4:
			if (current_char == 13){
				state = 5;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else{
                                printf("Lipseste <CR> la linia %d starea %d", at_data.line_count+1, state);
				state = 17;
                        }
			break;

		case 5: 
			if (current_char == 10){
				state = 6;
                                at_data.data[at_data.line_count][i++] = current_char;
                                at_data.data[at_data.line_count][i] = '\0';
                                at_data.line_count++;
                                i = 0;
                        }
			else{
                                printf("Lipseste <LF> la linia %d starea %d", at_data.line_count+1, state);
				state = 17;
                        }
			break;

		case 6:
                        at_data.data[at_data.line_count][i] = '\0';
                        print_state(&at_data);
			return 1; //totul e ok(stare finala)
		
		case 7: 
			if (current_char == 'R'){
				state = 8;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else {
                            printf("Lipseste 'R' la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 8: 
			if (current_char == 'R'){
				state = 9;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else {
                            printf("Lipseste 'R' la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 9: 
			if (current_char == 'O'){
				state = 10;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else {
                            printf("Lipseste 'O' la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 10: 
			if (current_char == 'R'){
				state = 4;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else {
                            printf("Lipseste 'R' la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 11:
			if (current_char != 13) {
				state = 12;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else {
                            printf("Lipseste un string la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 12: 
			if (current_char == 13){
				state = 13;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else if (current_char != 13){
                            state = 12;
                            at_data.data[at_data.line_count][i++] = current_char;
                        }
			break;

		case 13: 
			if (current_char == 10){
				state = 14;
                                at_data.data[at_data.line_count][i++] = current_char;
                                at_data.data[at_data.line_count][i] = '\0';
                                i=0;
                                at_data.line_count++;
                        }
			else {
                            printf("Lipseste <LF> la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 14:
			if (current_char == 13){
				state = 15;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else if (current_char == '+'){
				state = 11;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else {
                            printf("Lipseste <CR>/'+' la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 15: 
			if (current_char == 10){
				state = 16;
                                at_data.data[at_data.line_count][i++] = current_char;
                                at_data.data[at_data.line_count][i] = '\0';
                                at_data.line_count++;
                                i = 0;
                        }
			else {
                            printf("Lipseste <LF> la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 16: 
			if (current_char == 'O'){
				state = 3;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else if (current_char == 'E'){
				state = 7;
                                at_data.data[at_data.line_count][i++] = current_char;
                        }
			else{
                            printf("Lipseste 'O'/'E' la linia %d starea %d", at_data.line_count+1, state);
                            state = 17;
                        }
			break;

		case 17: 
                    print_state(&at_data);
                    return 0; //eroare
	}
	
}

void print_state(AT* at_data) {
	uint16_t i;
	for (i = 0; i < at_data->line_count; i++) {
		printf("%s", at_data->data[i]);
	}
}
