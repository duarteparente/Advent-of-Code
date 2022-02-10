#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"


// DAY 9 < Smoke Basin >

typedef struct input_matrix {
    int col, line;
    int **m;
} M ;

M *create_matrix (){
    M *mat = calloc(1, sizeof(M));
    mat->m = calloc(1,sizeof(int *));
    return mat;
}

void destroy_matrix (M *mat){
    free(mat->m);
    free(mat);
}

void fill_line(M *mat, char *line){
    mat->m[mat->line] = malloc(mat->col * sizeof(int));
    for(int i=0; i<mat->col; i++){
        mat->m[mat->line][i] = line[i] - '0'; 
    }
    mat->line++;
    mat->m = realloc(mat->m, (mat->line+1)*sizeof(int *));
}

int is_LowPoint(int **m, int line, int col){
    int pin = m[line][col];
    return (m[line-1][col] > pin && m[line+1][col] > pin && m[line][col-1] > pin && m[line][col+1]);
}

int get_CornerLowPoints(M *mat){
    int sum = 0;
    int l = mat->line-1;
    int c = mat->col-1;
    if ((mat->m[0][1] > mat->m[0][0]) && (mat->m[1][0] > mat->m[0][0])) sum += mat->m[0][0]+1;
    if ((mat->m[l][1] > mat->m[l][0]) && (mat->m[l-1][0] > mat->m[l][0])) sum += mat->m[l][0]+1;
    if ((mat->m[0][c-1] > mat->m[0][c]) && (mat->m[1][c] > mat->m[0][c])) sum += mat->m[0][c]+1;
    if ((mat->m[l][c-1] > mat->m[l][c]) && (mat->m[l-1][c] > mat->m[l][c])) sum += mat->m[l][c]+1;
    return sum;
}

int get_EdgeLowPoints(M *mat){
    int l = mat->line-1;
    int c = mat->col-1;
    int sum = 0;
    for(int i=1; i<c; i++){
        if ((mat->m[0][i-1] > mat->m[0][i]) && (mat->m[0][i+1] > mat->m[0][i]) && (mat->m[1][i] > mat->m[0][i])) sum += mat->m[0][i]+1;
    }
    for(int i=1; i<c; i++){
        if ((mat->m[l][i-1] > mat->m[l][i]) && (mat->m[l][i+1] > mat->m[l][i]) && (mat->m[l-1][i] > mat->m[l][i])) sum += mat->m[l][i]+1;
    }
    for(int i=1; i<l; i++){
        if ((mat->m[i-1][0] > mat->m[i][0]) && (mat->m[i+1][0] > mat->m[i][0]) && (mat->m[i][1] > mat->m[i][0])) sum += mat->m[i][0]+1;
    }
    for(int i=1; i<l; i++){
        if ((mat->m[i-1][c] > mat->m[i][c]) && (mat->m[i+1][c] > mat->m[i][c]) && (mat->m[i][c-1] > mat->m[i][c])) sum += mat->m[i][c]+1;
    }
    return sum;
}

int count_LowPoints(M *mat){
    int sum = 0;
    sum += get_CornerLowPoints(mat);
    sum += get_EdgeLowPoints(mat);
    for(int i=1; i<mat->line-2; i++){
        for(int j=1; j<mat->col-2; j++){
            if (is_LowPoint(mat->m, i, j)) sum += mat->m[i][j]+1;
        }
    }
    return sum;
}

void day9(){
    M *mat = create_matrix();
    char *line = NULL;
    size_t len = 0;
    FILE *day9_file = fopen("inputs/day9.txt", "r");
    getline(&line, &len, day9_file);
    int length = strlen(line)-1;
    mat->col = length;
    fill_line(mat, line);
    while( getline(&line, &len, day9_file) != -1){
        fill_line(mat, line);
    }
    printf("\nResult: %d\n\n", count_LowPoints(mat)); 
    destroy_matrix(mat);
    fclose(day9_file);
}
