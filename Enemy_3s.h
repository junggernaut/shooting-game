#ifndef ENEMY_3S_H
#define ENEMY_3S_H

using namespace std;

#include "My_plane.h"
#include "Unit.h"

class Enemy_3s : public Unit {
 public:
  Enemy_3s(int y_value, int x_value, char character)
      : Unit(y_value, x_value, character){};

  int hp = 4;
  int cell_speed = 9;  // The enemy moves 1 cell for every 0.9 seconds
  int score = 3;

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