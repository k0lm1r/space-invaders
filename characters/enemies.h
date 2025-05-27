#pragma once 
#include "drawing.h"
#include "list.h"

List createEnemies();
void moveEnemies(List *enemies, bool isLeft);
Dot enemiesShoot(List enemies);