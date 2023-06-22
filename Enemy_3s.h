#ifndef ENEMY_3S_H
#define ENEMY_3S_H

using namespace std;

class Enemy_3s {
 public:
  int hp = 4;
  int cell_speed = 9;  // The enemy moves 1 cell for every 0.9 seconds
  int score = 3;

  void move() {
    // Implement movement logic here
  }

  void create_bullet() {
    // Implement bullet creation logic here
  }
};
#endif