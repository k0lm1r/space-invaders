#pragma once 
#include "drawing.h"
#include "list.h"

List createEnemies();
void moveEnemies(List *enemies, int way);
Dot enemiesShoot(List enemies);