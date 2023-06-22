#ifndef ENEMY_1N_H
#define ENEMY_1N_H

#include <ncurses.h>

#include "Bullet.h"
#include "My_plane.h"
#include "Unit.h"

using namespace std;

class Enemy_1n : public Unit {
 public:
  Enemy_1n(int y_value, int x_value, char character)
      : Unit(y_value, x_value, character){};

  int hp = 10;
  int score = 1;

  void shot(My_plane my_plane, Bullet bullet) { my_plane.hp -= bullet.level; }

  void crash(My_plane my_plane) { --my_plane.hp; }

  void print() override { printw("Z"); }
};
#endif