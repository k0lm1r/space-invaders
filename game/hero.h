#ifndef HERO_H
#define HERO_H

#include "libraries.h"
#include "drawing.h"
#include "list.h"

COORD heroControl(Dot *hero);
void moveHeroesShot(List *enemiesShotsList, List *enemies, Dot* heroesShot);
#endif