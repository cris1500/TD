#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "FSM.h"

extern AT at_data;

int main(int argc, char **argv){
    FILE * fin;
    unsigned char ch;
    
    if(argc != 2){
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    
    fin = fopen(argv[1], "rb");
    
    if(!fin){
        printf("Eroare la deschiderea fisierului %s\n", argv[1]);
        exit(2);
    }
    
    while(!feof(fin)){
        ch = fgetc(fin);
        if(parse(ch) == 0)
            break;
    }
    
    return 0;
}