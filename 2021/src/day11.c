#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"

// DAY 11 < Dumbo Octopus >

typedef struct mt{
    int m[10][10];
} MAT ;

void fill_MAT (MAT *mat, char *line, int index){
    for(int i=0; i<10; i++){
        mat->m[index][i] = line[i] - '0';
    }
}

int increase_adjacent(MAT *mat, int line, int col){
    int counter = 0;
    if (!col){
        if (!line){
            if (mat->m[0][0]++ == 9){ 
                counter++;
                counter += increase_adjacent(mat, 0, 1);
                counter += increase_adjacent(mat, 1, 1);
                counter += increase_adjacent(mat, 1, 0);
            }    
        }
        else if (line == 9) {
            if (mat->m[9][0]++ == 9){ 
                counter++;
                counter += increase_adjacent(mat, 9, 1);
                counter += increase_adjacent(mat, 8, 1);
                counter += increase_adjacent(mat, 8, 0);
            }    
        }
        else if (mat->m[line][0]++ == 9){
            counter++;
            counter += increase_adjacent(mat, line-1, 0);
            counter += increase_adjacent(mat, line-1, 1);
            counter += increase_adjacent(mat, line, 1);
            counter += increase_adjacent(mat, line+1, 1);
            counter += increase_adjacent(mat, line+1, 0);
        }
    }
    else if (col == 9){
        if (!line){
            if (mat->m[0][9]++ == 9){ 
                counter++;
                counter += increase_adjacent(mat, 0, 8);
                counter += increase_adjacent(mat, 1, 8);
                counter += increase_adjacent(mat, 1, 9);
            }    
        }
        else if (line == 9){
            if (mat->m[9][9]++ == 9){
                counter++;
                counter += increase_adjacent(mat, 8, 9);
                counter += increase_adjacent(mat, 8, 8);
                counter += increase_adjacent(mat, 9, 8);
            }    
        }
        else if (mat->m[line][9]++ == 9){
            counter++;
            counter += increase_adjacent(mat, line-1, 9);
            counter += increase_adjacent(mat, line-1, 8);
            counter += increase_adjacent(mat, line, 8);
            counter += increase_adjacent(mat, line+1, 8);
            counter += increase_adjacent(mat, line+1, 9); 
        }
    }
    else if (!line){
        if (mat->m[0][col]++ == 9){ 
            counter++;
            counter += increase_adjacent(mat, 0, col-1);
            counter += increase_adjacent(mat, 1, col-1);
            counter += increase_adjacent(mat, 1, col);
            counter += increase_adjacent(mat, 1, col+1);
            counter += increase_adjacent(mat, 0, col+1);
        }    
    }
    else if (line == 9){
        if (mat->m[9][col]++ == 9){ 
            counter++;
            counter += increase_adjacent(mat, 9, col-1);
            counter += increase_adjacent(mat, 8, col-1);
            counter += increase_adjacent(mat, 8, col);
            counter += increase_adjacent(mat, 8, col+1);
            counter += increase_adjacent(mat, 9, col+1);
        }    
    }
    else if (mat->m[line][col]++ == 9){
        counter++;
        counter += increase_adjacent(mat, line-1, col-1);
        counter += increase_adjacent(mat, line-1, col);
        counter += increase_adjacent(mat, line-1, col+1);
        counter += increase_adjacent(mat, line, col-1);
        counter += increase_adjacent(mat, line, col+1);
        counter += increase_adjacent(mat, line+1, col-1);
        counter += increase_adjacent(mat, line+1, col);
        counter += increase_adjacent(mat, line+1, col+1);
    }
    return counter;
}


int simulate_step(MAT *mat){
    int counter = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            counter += increase_adjacent(mat, i, j);            
        }
    }
    return counter;
}

void reset_energy(MAT *mat){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if (mat->m[i][j] > 9) mat->m[i][j] = 0;
        }
    }
}

void day11(){
    MAT *mat = calloc(1, sizeof(MAT));
    int i=0, counter = 0;
    char *line = NULL;
    size_t len = 0;
    FILE *day11_file = fopen("inputs/day11.txt", "r");
    while(getline(&line, &len, day11_file) != -1){
        fill_MAT(mat, line, i);
        i++;
    }
    fclose(day11_file);
    for(int j=0; j<100; j++) { counter += simulate_step(mat); reset_energy(mat); }
    printf("\nResult: %d\n\n", counter);
    free(mat);
}