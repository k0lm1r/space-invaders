#include "enemies.h"
#include "hero.h"

int main() {
    srand(time(0));
    system("cls");
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD bufferSize = {1000, 1000};
    SetConsoleScreenBufferSize(console, bufferSize);

    List ls = createEnemies();
    int i = 0, speed = 5000;
    Dot hero = {{10, 40}, 'A'};
    Dot shot = {{-1, -1}, 'i'}, a = {{0, 0}, '!'};

    while(1) {
        if (i % speed == 0) {
            int way = 0;
            if (i / speed % 10 > 0 && i / speed % 10 < 5) way = -1;
            else if (i / speed % 10 > 5) way = 1;
            for (int i = 0; i < ls.count; ++i) {
                ls.list = ls.list->prev;
                moveEnemy((Dot*)ls.list->data, way);
                heroControl(&hero);
                moveEnemiesShot(&hero, &shot, &a);
            }
            if (shot.position.Y == -1) shot = enemiesShoot(ls);
            
        } else heroControl(&hero), moveEnemiesShot(&hero, &shot, &a);
        
        i++;
        
    }
}