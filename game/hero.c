#include "hero.h"

COORD heroControl(Dot *hero) {
    COORD shotPosition = {-1, MIN_Y}, currentHeroPos = hero->position;
    if (kbhit()) {
        int key = _getch();
        switch(key) {
            case 'a': case 75: hero->position.X = max(hero->position.X - 1, MIN_X + 1); break;
            case 'd': case 77: hero->position.X = min(hero->position.X + 1, MAX_X - 2); break;
            case 32: case 72: shotPosition = currentHeroPos; shotPosition.Y--;
        }
    }
    clean(currentHeroPos);
    printDot(*hero);
    return shotPosition;
}

bool wasHit(List *enemies, Dot *heroesShot) {
    for (int i = 0; i < enemies->count; ++i) {
        Dot currentEnemy = *(Dot*)take(*enemies, i);
        if (heroesShot->position.Y == currentEnemy.position.Y && heroesShot->position.X == currentEnemy.position.X) {
            clean(currentEnemy.position);
            delete(enemies, i);
            return true;
        }
    }
    heroesShot->position.Y = max(heroesShot->position.Y - 1, MIN_Y);
    return false;
}

void moveHeroesShot(List *enemiesShotsList, List *enemies, Dot* heroesShot) {
    clean(heroesShot->position);
    if (wasHit(enemies, heroesShot) || wasHit(enemiesShotsList, heroesShot)) heroesShot->item = 'X';
    if (heroesShot->position.Y != MIN_Y) printDot(*heroesShot);
}