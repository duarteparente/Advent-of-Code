#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void show_input (int day){
    char file[30];
    snprintf(file, 30, "inputs/day%02d.txt", day);
    char opening[50];
    snprintf(opening, 50, "\n--------------- DAY %d ---------------\n", day);
    printf("%s" , opening);
    char *line = NULL;
    size_t len = 0;
    FILE *input_file = fopen(file, "r");
    printf ("\n Input:\n +------------------------+\n");
    while(getline(&line, &len, input_file) != -1) printf ("  %s", line);
    printf ("\n +------------------------+\n");
    fclose (input_file);
}

int menu(){
    system("clear");
    char *line = NULL;
    size_t len = 0;
    FILE *menu = fopen("inputs/menu.txt", "r");
    while(getline(&line, &len, menu) != -1) printf ("  %s", line);
    int id;
    printf ("\n >> Enter the day you want: ");
    scanf("%d", &id);
    fclose (menu);
    return id;
}