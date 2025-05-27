#include "hero.h"

COORD heroShoot(COORD heroesPos) {
    Dot shot = {{heroesPos.X, heroesPos.Y - 1}, '!'};
    printDot(shot);
    return shot.position;
}

COORD heroControl(Dot *hero) {
    COORD shotPosition = {-1, -1};
    Dot errase = {hero->position, ' '};
    if (_kbhit()) {
        int key = _getch();
        switch(key) {
            case 'a': case 75: hero->position.X = max(hero->position.X - 1, 0); break;
            case 'd': case 77: hero->position.X = min(hero->position.X + 1, 27); break;
            case 32: case 72: shotPosition = heroShoot(hero->position);
        }
    }
    printDot(errase);
    printDot(*hero);
    return shotPosition;
}