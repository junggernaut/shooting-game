#ifndef MY_PLANE_H
#define MY_PLANE_H

#include <curses.h>
#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>

#include <fstream>
#include <iostream>
#include <vector>

#include "Bullet.h"
#include "Unit.h"

using namespace std;

class My_plane {
 public:
  My_plane(int y_value, int x_value, int frame_value)
      : y(y_value), x(x_value), create_frame_my_plane(frame_value){};

  int y, x;
  int shot_frame_my_plane = 1;
  int create_frame_my_plane;  // initialize when it creates
  int check_frame_my_plane = 0;
  int hp = 5;
  vector<Bullet> bullet;
};
#endif