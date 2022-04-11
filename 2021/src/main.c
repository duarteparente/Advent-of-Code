#include <stdio.h>
#include "../include/clui.h"
#include "../include/days.h"


int main(){
    int day = menu();
    show_input(day);
    switch (day){
        case 1: day1(); break;
        case 2: day2(); break;
        case 3: day3(); break;
        case 4: day4(); break;
        case 5: day5(); break;
        case 6: day6(); break;
        case 7: day7(); break;
        case 8: day8(); break;
        case 9: day9(); break;
        case 10: day10(); break;
        case 11: day11(); break;
        case 12: day12(); break;
    }
    return 0;
}