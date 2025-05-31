#include "enemies.h"

List createEnemies() {
    int totalEnemiesCount = 30;
    char type = 'O';
    COORD currentAlienPos = {5, 1};
    List aliensList = {0, NULL};

    for (int i = 0; i < totalEnemiesCount; ++i) {
        if (i == 20) type = 'H';
        if (i % 10 == 0) currentAlienPos.X = 5, currentAlienPos.Y += 1; 
        Dot *alien = (Dot*)malloc(sizeof(Dot));
        alien->item = type, alien->position = currentAlienPos;
        aliensList = append(aliensList, alien);
        currentAlienPos.X += 2;
    }

    return aliensList;
}

void moveEnemy(Dot *alien, int way) {
    int horizontalStep = way, verticalStep = way == 0 ? 1 : 0;
    clean(alien->position);
    alien->position.X += horizontalStep, alien->position.Y += verticalStep;
    printDot(*alien);
    Sleep(1);
}

Dot enemiesShoot(List enemies) {
    COORD patencialShotPos[10], defaultPos = {-1, -1};
    LinkedList *currentEnemy = enemies.list->prev;
    for (int i = 0; i < 10; ++i) patencialShotPos[i] = defaultPos;

    for (int validPos = 0, allPos = 0; validPos < 10 && allPos < enemies.count; currentEnemy = currentEnemy->prev, allPos++) {
        Dot *alien = (Dot*)currentEnemy->data;
        int index = alien->position.X % 10;
        while (index < 10 && patencialShotPos[index].X != -1 && patencialShotPos[index].X != alien->position.X) index++;
        if (patencialShotPos[index].X != alien->position.X) patencialShotPos[index] = alien->position, ++validPos;
    }

    int shotPos = rand() % 10;
    while (patencialShotPos[shotPos].X == -1) shotPos = rand() % 10;
    patencialShotPos[shotPos].Y++;
    Dot shot = {patencialShotPos[shotPos], 'i'};
    printDot(shot);
    return shot;
}

void moveEnemiesShot(Dot *hero, Dot *enemiesShot, Dot *heroesShot) {
    clean(enemiesShot->position);
    if (enemiesShot->position.Y == hero->position.Y - 1) hero->item = 'X', enemiesShot->item = ' ';
    else {
        if (enemiesShot->position.Y == heroesShot->position.Y - 1) heroesShot->item = enemiesShot->item = 'X';
        enemiesShot->position.Y++;
    }
    printDot(*enemiesShot);
}