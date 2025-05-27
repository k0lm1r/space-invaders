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

void moveEnemies(List *enemies, bool isLeft) {
    int horizontalStep = isLeft ? -1 : 1, verticalStep = 0;
    Dot errase = {{0, 0}, ' '};
    LinkedList *currentEnemy = enemies->list->prev;

    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < enemies->count; currentEnemy = currentEnemy->prev, ++i) {
            Dot *alien = (Dot*)currentEnemy->data;
            errase.position = alien->position;
            printDot(errase);
            alien->position.X += horizontalStep, alien->position.Y += verticalStep;
            printDot(*alien);
            Sleep(10);
        }
        if (j == 3) verticalStep = 1;
    }
}

Dot enemiesShoot(List enemies) {
    COORD *patencialShotPos = (COORD*)calloc(10, sizeof(COORD)), defaultPos = {-1, -1};
    LinkedList *currentEnemy = enemies.list->prev;
    for (int i = 0; i < 10; ++i) patencialShotPos[i] = defaultPos;

    for (int i = 0; i < 10 && currentEnemy; currentEnemy = currentEnemy->prev) {
        Dot *alien = (Dot*)currentEnemy->data;
        int index = alien->position.X % 10;
        while (index < 10 && patencialShotPos[index].X != -1 && patencialShotPos[index].X != alien->position.X) index++;
        if (patencialShotPos[index].X != alien->position.X) patencialShotPos[index] = alien->position, ++i;
    }

    int shotPos = rand() % 10;
    while (patencialShotPos[shotPos].X == -1) shotPos = rand() % 10;
    patencialShotPos[shotPos].Y++;
    Dot shot = {patencialShotPos[shotPos], 'i'};
    free(patencialShotPos);
    return shot;
}