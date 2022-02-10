#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"

// DAY 10 < Syntax Scoring >

typedef struct s {
    int *elems;
    int size;
    int length;
} STACK ;

STACK *create_stack(){
    STACK *stack = calloc(1,sizeof(STACK));
    stack->size = 2;
    stack->elems = calloc(stack->size, sizeof(int));
    return stack;
}

void destroy_STACK (STACK *stack){
    free(stack->elems);
    free(stack);
}

void push (STACK *stack, char c){
    if (stack->size == stack->length){
        stack->size *= 2;
        stack->elems = realloc(stack->elems, stack->size*sizeof(int));
    }
    stack->elems[stack->length] = c;
    stack->length++; 
}

void pop (STACK *stack){
    stack->length--;
}

int top(STACK *stack){
    return stack->elems[stack->length-1];
}


int is_openingChar (char c){
    return (c == '(' || c == '{' || c == '<' || c == '[');
}

int pair_match(int c){
    int r;
    switch (c) {
        case ')': r = '('; break;
        case ']': r = '['; break;
        case '}': r = '{'; break;
        case '>': r = '<'; break;
        default: break;
    }
    return r;
}

int char_points(char c){
    int r = 0;
    switch(c){
        case ')': r = 3; break;
        case ']': r = 57; break;
        case '}': r = 1197; break;
        case '>': r = 25137; break;
        default: r = 0; break;
    }
    return r;
}

char check_syntax(char *line, STACK *stack){
    char r = 'e';
    while(*line){
        if (is_openingChar(*line)) push(stack, *line);
        else {
            if (top(stack) == pair_match(*line)) pop(stack);
            else { r = *line; break; }
        }
        line++;
    }
    return r;
}

void day10(){
    STACK *stack = create_stack();
    int sum = 0;
    char *line = NULL;
    size_t len = 0;
    FILE *day10_file = fopen("inputs/day10.txt", "r");
    while(getline(&line, &len, day10_file) != -1){
        sum += char_points(check_syntax(line, stack));
    }
    printf("\nResult: %d\n\n", sum); 
    fclose(day10_file);
    destroy_STACK(stack);
}