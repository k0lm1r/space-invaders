#pragma once 
#include "drawing.h"
#include "list.h"

List createEnemies();
void moveEnemy(Dot *alien, int way);
Dot enemiesShoot(List enemies);