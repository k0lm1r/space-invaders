#include "enemies.h"

List createEnemies() {
    int totalEnemiesCount = 30;
    char type = 'O';
    COORD currentAlienPos = {START_POS, MIN_Y};
    List aliensList = {0, NULL};

    for (int i = 0; i < totalEnemiesCount; ++i) {
        if (i == 20) type = 'H';
        if (i % 10 == 0) currentAlienPos.X = START_POS, currentAlienPos.Y += 1; 
        Dot *alien = (Dot*)malloc(sizeof(Dot));
        alien->item = type, alien->position = currentAlienPos;
        aliensList = append(aliensList, alien);
        currentAlienPos.X += 2;
    }

    return aliensList;
}

int chooseWay(List enemies, int prevStep) {
    int way = 0;
    Dot currentAlien = *(Dot *)take(enemies, 0);
    int mostLeftPos = currentAlien.position.X, mostRightPos = currentAlien.position.X;

    for (int i = 1; i < enemies.count; ++i) {
        currentAlien = *(Dot *)take(enemies, i);
        if (currentAlien.position.X < mostLeftPos) mostLeftPos = currentAlien.position.X;
        else if (currentAlien.position.X > mostRightPos) mostRightPos = currentAlien.position.X;
    }
    if (prevStep != 0 && mostLeftPos > MIN_X + 1 && mostRightPos < MAX_X - 2) way = prevStep;
    else if (prevStep == 0) way = mostLeftPos > MIN_X + 1 ? -1 : 1;
    return way;
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
    for (int i = 0; i < 10; ++i) patencialShotPos[i] = defaultPos;

    for (int validPos = 0, allPos = 0; validPos < 10 && allPos < enemies.count; allPos++) {
        Dot alien = *(Dot*)take(enemies, -allPos);
        int index = alien.position.X % 10;
        while (index < 10 && patencialShotPos[index].X != -1 && patencialShotPos[index].X != alien.position.X) index++;
        if (patencialShotPos[index].X != alien.position.X) patencialShotPos[index] = alien.position, ++validPos;
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
    if (enemiesShot->position.X == hero->position.X && enemiesShot->position.Y == hero->position.Y - 1) hero->item = enemiesShot->item = 'X';
    else if (enemiesShot->position.Y == heroesShot->position.Y - 1 && enemiesShot->position.X == heroesShot->position.X) 
        heroesShot->item = enemiesShot->item = 'X';
    enemiesShot->position.Y = min(enemiesShot->position.Y + 1, MAX_Y);
    if (enemiesShot->position.Y < MAX_Y) printDot(*enemiesShot);
    Sleep(1);
}