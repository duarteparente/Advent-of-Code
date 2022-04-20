#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"

// DAY 13 < Transparent Origami >

int m[20][20] = {0};

int count(int y, int xmax){
	int counter = 0;
	for(int i=0; i<=y; i++){
		for(int j=0; j<=xmax; j++){
			if(m[i][j]) counter++;
		}
	}
    return counter;
}

void fold(int y ,int xmax, int ymax){
	for(int i=y+1; i<=ymax; i++){
		for(int j=0; j<=xmax; j++){
			if(m[i][j]) m[i-(y+1)][j]++;
		}
	}
}

void day13(){
	FILE *day13_file = fopen("inputs/day13.txt", "r");
    char *line = NULL;
    size_t len = 0;
    int x, y, h, xmax = 0, ymax = 0;
    while( getline(&line, &len, day13_file) != -1){
    	if(!isdigit(*line)){
            if(*line != 'f') continue;
    		strsep(&line, "=");
    		h = atoi(strsep(&line, "\n"));
    		break;
    	}
    	x = atoi(strsep(&line, ","));
    	y = atoi(strsep(&line, "\n"));
    	if (x > xmax) xmax = x;
    	if (y > ymax) ymax = y;
    	m[y][x] = 1;
    }
    fold(h,xmax,ymax);
    printf("Number of dots after 1st fold -> %d\n", count(h,xmax));
}