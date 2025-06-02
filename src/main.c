#include "game.h"

int main() {
    srand(time(0));
    system("cls");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {1000, 1000};
    SetConsoleScreenBufferSize(console, bufferSize);
    ShowCursor(0);

    char choice = 0;
    int score = 0;
    do {
        system("cls");
        choice = 0;
        
        puts("1 - Start.\n2 - Help.\n3 - Exit.");
        while(choice < '1' || choice > '3') choice = _getch();
        if (choice == '1') score = game(score);
        else if (choice == '2') puts("H, O - Enemies.\nA - Player.\ni - Enemies shots.\n! - Players shot.\n\nControls:\nLeft Arrow, Right Arrow, 'a', 'd' - Move.\nSpace, Up Arrow - Shoot.\nPress any key..."), _getch();     
    } while (choice != '3');
}