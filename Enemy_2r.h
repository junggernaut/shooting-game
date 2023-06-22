#ifndef ENEMY_2R_H
#define ENEMY_2R_H

using namespace std;

class Enemy_2r {
 public:
  int hp = 5;
  int cell_speed = 3;  // The enemy moves 1 cell for every 0.3 seconds
  int score = 2;

  void move() {
    // Implement movement logic here
  }
};
#endif