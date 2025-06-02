#include "game.h"

int main() {
    srand(time(0));
    system("cls");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {1000, 1000};
    SetConsoleScreenBufferSize(console, bufferSize);
    game();
    
}