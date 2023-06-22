#ifndef ENEMY_1N_H
#define ENEMY_1N_H

#include "Bullet.h"
#include "My_plane.h"

using namespace std;

class Enemy_1n {
 public:
  int hp = 10;
  int score = 1;
  // This enemy can't move, so no movement function is needed

  void shot(My_plane my_plane, Bullet bullet) { my_plane.hp -= bullet.level; }

  void crash(My_plane my_plane) { --my_plane.hp; }
};
#endif