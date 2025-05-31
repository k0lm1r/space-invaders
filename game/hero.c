#include "hero.h"

COORD heroShoot(COORD heroesPos) {
    Dot shot = {{heroesPos.X, heroesPos.Y - 1}, '!'};
    printDot(shot);
    return shot.position;
}

COORD heroControl(Dot *hero) {
    COORD shotPosition = {-1, -1}, errasePos = hero->position;
    if (_kbhit()) {
        int key = _getch();
        switch(key) {
            case 'a': case 75: hero->position.X = max(hero->position.X - 1, 0); break;
            case 'd': case 77: hero->position.X = min(hero->position.X + 1, 27); break;
            case 32: case 72: shotPosition = heroShoot(hero->position);
        }
    }
    clean(errasePos);
    printDot(*hero);
    return shotPosition;
}

bool wasHit(List *enemies, Dot *heroesShot) {
    LinkedList *currentNode = enemies->list;
    for (int i = 0; i < enemies->count; currentNode = currentNode->next, ++i) {
        Dot currentEnemy = *(Dot*)currentNode->data;
        if (heroesShot->position.Y == currentEnemy.position.Y + 1) {
            heroesShot->item = 'X';
            clean(currentEnemy.position);
            delete(enemies, i);
            return true;
        }
    }
    heroesShot->position.Y--;
    return false;
}

void moveHeroesShot(List *enemiesShotsList, List *enemies, Dot* heroesShot) {
    clean(heroesShot->position);
    wasHit(enemies, heroesShot);
    wasHit(enemiesShotsList, heroesShot);
    printDot(*heroesShot);
}