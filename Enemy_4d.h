#ifndef ENEMY_4D_H
#define ENEMY_4D_H

using namespace std;

#include "My_plane.h"
#include "Unit.h"

class Enemy_4d : public Unit {
 public:
  Enemy_4d(int y_value, int x_value, char character)
      : Unit(y_value, x_value, character){};

  int hp = 5;
  int cell_speed = 3;  // The enemy moves 1 cell for every 0.3 seconds
  int score = 4;

  void move() {
    // Implement movement logic here
  }

  void create_bullet() {
    // Implement bullet creation logic here
  }
  void crash(My_plane my_plane) { --my_plane.hp; }

  void print() { printw("%c", character); }
};
#endif