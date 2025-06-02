#ifndef LIBRARIES_H
#define LIBRARIES_H

#include "libraries.h"
#define MIN_Y 1
#define MAX_Y 30
#define MIN_X 0
#define MAX_X 27

typedef struct dot {
    COORD position;
    char item;
} Dot;

void gotoxy(int x, int y);
void printDot(Dot printintItem);
void clean(COORD position);
#endif