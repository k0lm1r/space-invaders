#include "game.h"

int main() {
    srand(time(0));
    system("cls");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {1000, 1000};
    SetConsoleScreenBufferSize(console, bufferSize);
    ShowCaret(0);
    ShowCursor(0);

    char choice = 0;
    int score = 0;
    do {
        system("cls");
        choice = 0;
        puts("1 - Start.\n2 - Exit.");
        while(choice < '1' || choice > '2') choice = _getch();
        if (choice == '1') score = game(score);        
    } while (choice != '2');
}