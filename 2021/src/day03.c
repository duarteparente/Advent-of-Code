#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"

// DAY 3 < Binary Diagnostic >

typedef struct bit_vector{
    int lenght;
    int *bit_vector;
} BIT;

int *bit_vector (char *line){
    int t = strlen(line)-1, i=0;
    int *v = malloc(t*sizeof(int));
    while(*line){
        v[i] = *line - '0';
        i++; line++;
    }
    return v;
}

int create_gama(BIT *bit, int i){
    int gama = 0;
    int v[bit->lenght];
    for(int j=0; j<bit->lenght; j++){
        int count_1 = 0, count_0 = 0;
        for(int n=0; n<i; n++){
            if (bit[n].bit_vector[j] == 1) count_1++;
            else count_0++; 
        }
        if (count_1>count_0) v[j] = 1;
        else v[j] = 0;
    }
    for(int j=bit->lenght-1; j>=0; j--){
        if (v[j]) gama += pow(2,bit->lenght-1-j);
    }
    return gama;
}

int create_epsilon(BIT *bit, int i){
    int epsilon = 0;
    int v[bit->lenght];
    for(int j=0; j<bit->lenght; j++){
        int count_1 = 0, count_0 = 0;
        for(int n=0; n<i; n++){
            if (bit[n].bit_vector[j] == 1) count_1++;
            else count_0++; 
        }
        if (count_1>count_0) v[j] = 0;
        else v[j] = 1;
    }
    for(int j=bit->lenght-1; j>=0; j--){
        if (v[j]) epsilon += pow(2,bit->lenght-1-j);
    }
    return epsilon;
}


void day3(){
    BIT *bit = NULL;
    int i=0;
    char *line = NULL;
    size_t len = 0;
    FILE *day3_file = fopen("inputs/day3.txt", "r");
    while(getline(&line, &len, day3_file) != -1){
        bit = realloc(bit, (i+1)*sizeof(BIT));
        bit->lenght = strlen(line)-1;
        bit[i].bit_vector = bit_vector(line);
        i++;
    }
    fclose (day3_file);
    int gama = create_gama(bit,i);
    int epsilon = create_epsilon(bit,i);
    free(bit->bit_vector);
    free(bit);
    printf ("\nResult: %d\n\n", gama*epsilon);   
}