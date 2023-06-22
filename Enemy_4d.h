#ifndef ENEMY_4D_H
#define ENEMY_4D_H

using namespace std;

#include "Unit.h"

class Enemy_4d : public Unit {
 public:
  Enemy_4d(int y_value, int x_value) : Unit(y_value, x_value){};

  int hp = 5;
  int cell_speed = 3;  // The enemy moves 1 cell for every 0.3 seconds
  int score = 4;

  void move() {
    // Implement movement logic here
  }

  void create_bullet() {
    // Implement bullet creation logic here
  }
};
#endif