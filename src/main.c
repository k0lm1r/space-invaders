#include "drawing.h"
#include "enemies.h"

int main() {
    srand(time(0));
    system("cls");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {100, 100};
    SetConsoleScreenBufferSize(console, bufferSize);
    bool a = true;
    List ls = createEnemies();
    while (1) {
        moveEnemies(&ls, a);
        a = !a;
        printDot(enemiesShoot(ls));
    }
}