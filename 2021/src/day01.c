#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/days.h"

// DAY 1 < Sonar Sweep >
void day1 (){
    int contador = 0;
    char *line = NULL;
    size_t len = 0;
    FILE *day1_file = fopen("inputs/day01.txt", "r");
    getline(&line, &len, day1_file);
    int nr0 = atoi(line);
    while(getline(&line, &len, day1_file) != -1){
        int nr1 = atoi(line); 
        if(nr1>nr0) contador++;
        nr0 = nr1;
    }
    fclose (day1_file);
    printf("\nResult: %d\n\n", contador);
}