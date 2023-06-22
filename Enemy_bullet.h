#ifndef ENEMY_BULLET_H
#define ENEMY_BULLET_H

using namespace std;

class Enemy_bullet {
 public:
  int cell_speed = 1;
  int damage = 1;

  void increase_damage();
};
#endif