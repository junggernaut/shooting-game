#ifndef ENEMY_5A_H
#define ENEMY_5A_H

using namespace std;

#include "Unit.h"

class Enemy_5a : public Unit {
 public:
  Enemy_5a(int y_value, int x_value) : Unit(y_value, x_value){};
  int hp = 8;
  int buff_speed = 6;  // The enemy gives buffs every 0.6 seconds
  int score = 5;
};
#endif