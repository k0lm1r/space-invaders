#include "game.h"

void printBorders(int left, int right) {
    Dot border = {{left, MIN_Y}, '#'};
    for (int i = MIN_Y; i <= MAX_Y; ++i) {
        printDot(border);
        border.position.Y++;
    }
    border.position.X = right;
    border.position.Y--;
    for (int i = MAX_Y; i >= MIN_Y; --i) {
        printDot(border);
        border.position.Y--;
    }
}

void printScore(int score, int x, int y) {
    gotoxy(x, y);
    printf("Score: %d", score);
}

bool isDefeat(Dot hero, Dot lastEnemy, int score) {
    if (hero.item == 'X' || lastEnemy.position.Y == MAX_Y - 1) {
        system("cls");
        gotoxy((MAX_X - MIN_X) / 2, MAX_Y / 2);
        puts("GAME OVER!");
        printScore(score, (MAX_X - MIN_X) / 2, MAX_Y / 2 + 1); Sleep(10); _getch();
        return true;
    }
    return false;
}

int game(int score) {
    system("cls");
    Dot hero = {{(MAX_X - MIN_X) / 2, MAX_Y}, 'A'}, heroesShot = {{-1, MIN_Y}, '!'}, lastEnemy;
    List enemies = createEnemies(), enemiesShots = {0, NULL};
    int enemiesCountBefore = enemies.count, way = 0;
    printBorders(MIN_X, MAX_X);

    do {
        printScore(score, (MAX_X - MIN_X) / 2, MIN_Y - 1);

        way = chooseWay(enemies, way);
        for (int j = 1; j <= enemies.count; ++j) {
            Dot *currentEnemy = (Dot *)take(enemies, -j);
            moveEnemy(currentEnemy, way);
            COORD potencialShotPos = heroControl(&hero);

            if (heroesShot.position.Y == MIN_Y || heroesShot.item == 'X') {
                clean(heroesShot.position), heroesShot.position = potencialShotPos;
                if (heroesShot.item == 'X')
                    heroesShot.item = '!';
            }
            if (j % max(2, (enemies.count / 3)) == 0) {
                for (int k = 0; k < enemiesShots.count; k++) {
                    Dot *currentShot = (Dot *)take(enemiesShots, k);
                    moveEnemiesShot(&hero, currentShot, &heroesShot);
                    if (currentShot->position.Y == MAX_Y || currentShot->item == 'X')
                        clean(currentShot->position), delete(&enemiesShots, k--);
                    moveHeroesShot(&enemiesShots, &enemies, &heroesShot);
                }
                score += (enemiesCountBefore - enemies.count) * 100;
                enemiesCountBefore = enemies.count;
            }
            if (enemiesShots.count < min(3, enemies.count / 5)) {
                Dot *shot_p = (Dot *)malloc(sizeof(Dot));
                *shot_p = enemiesShoot(enemies);
                enemiesShots = append(enemiesShots, shot_p);
            }
        }
        lastEnemy = *(Dot *)take(enemies, -1);
    } while (enemies.count > 0 && !isDefeat(hero, lastEnemy, score));

    if (enemies.count == 0) {
        gotoxy((MAX_X - MIN_X) / 2, (MAX_Y - MIN_Y) / 2);
        puts("Congratulation!");
        printScore(score, (MAX_X - MIN_X) / 2, (MAX_Y - MIN_Y) / 2); Sleep(10); _getch();
        return score;
    }
    return 0;
}