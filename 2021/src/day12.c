#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "../include/days.h"

// DAY 12 < Passage Pathing >

typedef struct{
    char name[10];
    char neighbours[100][10];
    int number_neighbours;
} CAVE;

CAVE caves[100];

int find_cave(char *name, int number_caves){
    for(int i=0; i<number_caves; i++){
        if(!strcmp(name, caves[i].name)) return i;
    }
    return -1;
}

void insert_neighbour(int index, char *end){
    strcpy(caves[index].neighbours[caves[index].number_neighbours++], end);
}


void cave_controller(char *start, char *end, int *number_caves){
    int index = find_cave(start, *number_caves);
    if(index != -1) insert_neighbour(index, end);
    else{
        strcpy(caves[*number_caves].name, start);
        insert_neighbour(*number_caves, end);
        (*number_caves)++;
    }
}


int count_paths(char *node, int *visited, int number_caves){
    if(!strcmp(node, "end")) return 1;
    int index = find_cave(node, number_caves);

    // Lower cave already visited
    if(visited[index] && islower(*node)) return 0;
    int temp = visited[index], result = 0;
    visited[index] = 1;
    for(int i=0; i<caves[index].number_neighbours; i++){
        result += count_paths(caves[index].neighbours[i], visited, number_caves);
    }
    visited[index] = temp;
    return result;
}


void day12(){
    int *number_caves = calloc(1, sizeof(int));
    FILE *day12_file = fopen("inputs/day12.txt", "r");
    char from[10], to[10];
    char *line = NULL;
    size_t len = 0;
    while( getline(&line, &len, day12_file) != -1){
        strcpy(from, strsep(&line, "-"));
        strcpy(to, strsep(&line, "\n"));
        cave_controller(from, to, number_caves);
        cave_controller(to, from, number_caves);

    }
    fclose(day12_file);
    int *visited = calloc(*number_caves, sizeof(int));
    printf("\n\nNumber of paths: %d\n", count_paths("start", visited, *number_caves));
}
