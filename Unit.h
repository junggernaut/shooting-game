#ifndef UNIT_H
#define UNIT_H

#include "Bullet.h"
#include "My_plane.h"

using namespace std;

class Unit {
 public:
  Unit(int y_value, int x_value) : y(y_value), x(x_value){};

  int y, x;
  void crash(My_plane my_plane);
};
#endif