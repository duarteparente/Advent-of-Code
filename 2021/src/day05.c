#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"



// DAY 5 < Hydrothermal Venture >

int count_overlaps(int m[10][10]){
    int counter = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if (m[i][j] >= 2) counter++;
        }
    }
    return counter;
}


void day5(){
    int m[10][10], x1, y1, x2, y2;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j+=2){
            m[i][j] = 0; m[i][j+1] = 0;
        }
    }
    char *line = NULL;
    size_t len = 0;
    FILE *day5_file = fopen("inputs/day5.txt", "r");
    while (getline(&line, &len, day5_file) != -1){
        x1 = line[0] - '0'; y1 = line[2] - '0';
        x2 = line[7] - '0'; y2 = line[9] - '0';
        if (x1 == x2 || y1 == y2){
            m[y1][x1]++;
            if (x1==x2){
                while (y1 != y2){
                    if (y1 < y2) { y1++; m[y1][x1]++; }
                    else { y1--; m[y1][x1]++; }
                }    
            }
            else {
                while (x1 != x2){
                    if (x1 < x2) { x1++; m[y1][x1]++; }
                    else { x1--; m[y1][x1]++; }
                }
            }    
        }
    }
    fclose (day5_file);
    printf ("\nResult: %d\n\n", count_overlaps(m));
}