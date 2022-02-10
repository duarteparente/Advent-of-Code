#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"


// DAY 2 < Dive! >
void day2 (){
    int horizontal = 0, depth = 0;
    char *line = NULL;
    size_t len = 0;
    FILE *day2_file = fopen("inputs/day2.txt", "r");
    while(getline(&line, &len, day2_file) != -1){
        int t = strlen(line);
        switch (line[0]){
            case 'f': horizontal += (line[t-2] - '0'); break;
            case 'd': depth += (line[t-2] - '0'); break;
            default: depth -= (line[t-2] - '0'); break;
        }
    }
    fclose (day2_file);
    printf ("\nResult: %d\n\n", depth*horizontal);
}