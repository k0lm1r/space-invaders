#include "drawing.h"

void gotoxy(int x, int y) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD position;
    position.X = x, position.Y = y;
    SetConsoleCursorPosition(console, position);
}

void printDot(Dot printingDot) {
    gotoxy(printingDot.position.X, printingDot.position.Y);
    printf("%c", printingDot.item);
}