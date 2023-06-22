#ifndef ENEMY_4D_H
#define ENEMY_4D_H

using namespace std;

class Enemy_4d {
 public:
  int hp = 8;
  int buff_speed = 6;  // The enemy gives buffs every 0.6 seconds
  int score = 5;
};
#endif