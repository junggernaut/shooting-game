#ifndef ENEMY_2R_H
#define ENEMY_2R_H

#include "Enemy_1n.h"

using namespace std;

class Enemy_2r : Enemy_1n {
 public:
  int hp = 5;
  int cell_speed = 3;  // The enemy moves 1 cell for every 0.3 seconds
  int score = 2;

  void move() {
    // Implement movement logic here
  }
};
#endif