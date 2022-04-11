#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"


// DAY 8 < Seven Segment Search >

void day8(){
    char *line = NULL;
    int counter = 0;
    size_t len = 0;
    FILE *day8_file = fopen("inputs/day08.txt", "r");
    while(getline(&line, &len, day8_file) != -1){
        for(int i=0; i<11;i++) strsep(&line, " ");
        for(int i=0; i<4; i++){
            char *s = strdup(strsep(&line, " "));
            if(i==3) s[strlen(s)-1] = '\0';
            switch (strlen(s)){
                case 2: case 3: case 4: case 7: counter++; break;
                default: break;  
            }
        }
    }
    fclose(day8_file);
    printf("\nResult: %d\n\n", counter);  
}