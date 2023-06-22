#ifndef UNIT_H
#define UNIT_H

#include "My_plane.h"

using namespace std;

class Unit {
 public:
  Unit(int y_value, int x_value, char character)
      : y(y_value), x(x_value), character(character){};

  int y, x;
  char character;
  int hp;

  // virtual void crash(My_plane my_plane) = 0;

  virtual void shot(int bulletLevel) = 0;

  virtual void print() = 0;

  virtual ~Unit() {}
};
#endif