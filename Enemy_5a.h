#ifndef ENEMY_5A_H
#define ENEMY_5A_H

using namespace std;

#include "My_plane.h"
#include "Unit.h"

class Enemy_5a : public Unit {
 public:
  Enemy_5a(int y_value, int x_value, char character)
      : Unit(y_value, x_value, character){};
  int hp = 8;
  int buff_speed = 6;  // The enemy gives buffs every 0.6 seconds
  int score = 5;

  void crash(My_plane my_plane) { --my_plane.hp; }

  void print() { printw("%c", character); }
};
#endif