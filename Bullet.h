#ifndef BULLET_H
#define BULLET_H

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

using namespace std;

class Bullet {
 public:
  Bullet(int y_value, int x_value, int frame_value)
      : y(y_value), x(x_value), create_frame_bullet(frame_value){};
  int damage = 1;
  int y, x;
  int create_frame_bullet;  // initialize when it creates
  int check_frame_bullet;
  int cell_speed_bullet = 2;
  int level = 1;
};
#endif