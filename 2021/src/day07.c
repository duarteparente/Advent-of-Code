#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"


// DAY 7 < The Treachery of Whales > 

int get_max(int *positions, int N){
    int max = positions[0];
    for(int i=1; i<N; i++) {
        if (positions[i] > max) max = positions[i];
    }
    return max;
}

int count_fuel(int *positions, int N, int master){
    int sum = 0;
    for(int i=0; i<N; i++) sum += abs(positions[i] - master);
    return sum;
}

void day7(){
    int *positions = NULL; int counter = 0;
    char *line = NULL;
    size_t len = 0;
    FILE *day7_file = fopen("inputs/day7.txt", "r");
    getline(&line, &len, day7_file);
    fclose(day7_file);
    while(*line){
        if (!isdigit(*line));
        else {
            positions = realloc(positions, (counter+1)*sizeof(int));
            if (isdigit(*(line+1))) { positions[counter] = (*line -'0')*10 + (*(line+1) - '0'); line++; }
            else positions[counter] = *line -'0';
            counter ++;
        }
        line++;
    }
    int max = get_max(positions,counter);
    int minimum = count_fuel(positions, counter, 0);
    for(int i=1; i<=max; i++){
        int n = count_fuel(positions, counter, i);
        if (n<minimum) minimum = n;
    }
    printf("\nResult: %d\n\n", minimum);  
}