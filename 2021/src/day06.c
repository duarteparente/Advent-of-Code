#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"


// DAY 6 < Lanternfish >

void day6(){
    int *fish = NULL;
    char *line = NULL;
    size_t len = 0;
    FILE *day6_file = fopen("inputs/day06.txt", "r");
    getline(&line, &len, day6_file);
    int lenght = 0, days = 1, r=0;
    int size = strlen(line)-1;
    for (int i=0; (2*i) < size; i++){
        fish = realloc(fish, (lenght+1)*sizeof(int));
        fish[i] = line[2*i] - '0';
        lenght++;
    }
    while(days <= 80){
        for(int i=0; i<lenght; i++){
            if (fish[i] == 0) { r++; fish[i] = 6; }
            else fish[i]-- ;
        }
        while(r!=0) { lenght++; fish = realloc(fish, (lenght+1)*sizeof(int)); fish[lenght-1] = 8; r--; }
        days++;
    }
    fclose (day6_file);
    printf("\nResult: %d\n\n", lenght);    
}