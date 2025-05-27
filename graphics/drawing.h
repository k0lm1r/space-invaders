#include "libraries.h"

typedef struct dot {
    COORD position;
    char item;
} Dot;

void gotoxy(int x, int y);
void printDot(Dot printintItem);