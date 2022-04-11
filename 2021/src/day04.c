#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"

// DAY 4 < Giant Squid >

typedef struct board_5x5{
    int board[5][5];
} BOARD;

int count_commas(char *line){
    int counter = 0;
    char *s = line;
    while(*s){
        if (*s == ',') counter++;
        s++;
    }
    return counter;
}

int *parse_line (char *line){
    int *v = malloc(5*sizeof(int));
    int counter = 0;
    char *s  = line;
    while(*s){
        if (!isdigit(*s));
        else {
            if (isdigit(*(s+1))) { v[counter] = (*s -'0')*10 + (*(s+1) - '0'); s++; }
            else v[counter] = *s -'0';
            counter ++;
        }
        s++;
    }
    return v;
}

int has_won (BOARD *b, int length){
    int r = -1;
    for (int l=0; l<length; l++){
        if (r!=-1) break;
        for (int i=0; i<5; i++){
            if (b[l].board[i][0] < 0 && b[l].board[i][1] < 0 && b[l].board[i][2] < 0 && b[l].board[i][3] < 0 && b[l].board[i][4] < 0) { r=l; break;}
        }
    }
    if (r!=-1) return r;
     for (int l=0; l<length; l++){
        if (r!=-1) break;
        for (int i=0; i<5; i++){
            if (b[l].board[0][i] < 0 && b[l].board[1][i] < 0 && b[l].board[2][i] < 0 && b[l].board[3][i] < 0 && b[l].board[4][i] < 0) { r=l; break;}
        }
    }
    return r;
}

void play(int x, BOARD *b, int length){
    for (int l=0; l<length; l++){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if (x == b[l].board[i][j]) b[l].board[i][j] = 0 - x;
            }
        }
    }
}

void final_result (BOARD *b, int r, int last){
    int sum = 0;
    for (int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if (b[r].board[i][j] >= 0) sum += b[r].board[i][j];
        }
    }
    printf ("\nResult: %d\n\n", sum*last); 
}


void day4(){
    BOARD *b = calloc(1, sizeof(BOARD));
    int counter = 0, n = 0, length = 1; 
    char *line = NULL;
    size_t len = 0;
    FILE *day4_file = fopen("inputs/day04.txt", "r");
    getline(&line, &len, day4_file);
    int t_draw = count_commas(line)+1;
    int draw[t_draw], j=0;
    for (int i=0; i<t_draw; i++){
        if (line[j+1] == ',' || line[j+1] == '\n') { draw[i] = line[j] - '0'; j+=2; }
        else { draw[i] = (line[j] - '0')*10 + line[j+1] - '0'; j+=3; } 
    }
    getline(&line, &len, day4_file); // skip empty line
    while(getline(&line, &len, day4_file) != -1){
        if(counter == 5) { length++; counter = 0; n++; b = realloc(b, (n+1)*sizeof(BOARD)); getline(&line, &len, day4_file); }
        int *v = parse_line(line);
        for(int c=0; c<5; c++){
            b[n].board[counter][c] = v[c];
        }
        counter++;
        free(v);
    }
    fclose(day4_file);
    int r, i; 
    for (i=0; i<t_draw; i++){
        play(draw[i], b, length);
        r = has_won(b,length);
        if (r!=-1) break;
    }
    final_result (b, r, draw[i]);
    free(b);
}
