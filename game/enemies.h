#ifndef ENEMIES_H
#define ENEMIES_H

#include "drawing.h"
#include "list.h"
#define START_POS 8

List createEnemies();
void moveEnemy(Dot *alien, int way);
Dot enemiesShoot(List enemies);
void moveEnemiesShot(Dot *hero, Dot *enemiesShot, Dot *heroesShot);
int chooseWay(List enemies, int prevStep);
#endif