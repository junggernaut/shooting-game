#include "Screen_manager.h"

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

// print sharing things.
void Screen_manager::print_share() {
  // Wall
  for (int i = 0; i < width; i++) {
    move(height - 1, i);
    printw("w");
  }
  for (int j = 0; j < height - 1; j++) {
    move(j, 0);
    printw("w");
    move(j, width - 1);
    printw("w");
  }

  int shot_frame, create_frame, check_frame;

  // Bullet part
  shot_frame = this->my_plane.shot_frame_my_plane;
  create_frame = this->my_plane.create_frame_my_plane;
  check_frame = this->my_plane.check_frame_my_plane;
  while ((curr_frame - create_frame) / shot_frame - check_frame >
         0) {  // bullet create
    Bullet bullet = Bullet(this->my_plane.y - 1 + shot_frame, this->my_plane.x,
                           check_frame);
    this->my_plane.bullet.push_back(bullet);

    for (auto iter = this->my_plane.bullet.begin();
         iter < this->my_plane.bullet.end();) {
      if (iter->y <= 0) {
        move(iter->y, iter->x);
        printw(" ");
        this->my_plane.bullet.erase(iter);
      } else {
        if (iter != (this->my_plane.bullet.end() - 1) && curr_frame != 1) {
          move(iter->y, iter->x);
          printw(" ");
        }
        iter->y -= shot_frame;
        move(iter->y, iter->x);

        for (auto currentUnit = this->units.begin();
             currentUnit < this->units.end(); currentUnit++) {
          if (iter->y == (*currentUnit)->y && iter->x == (*currentUnit)->x) {
            (*currentUnit)->shot(iter->damage);
            if ((*currentUnit)->hp <= 0) {
              this->units.erase(currentUnit);
            }
            this->my_plane.bullet.erase(iter);
          }
        }
        if (iter->level == 1) {
          printw("'");
        }
        iter++;
      }
    }
    this->my_plane.check_frame_my_plane += 1;
    check_frame++;
  }
  // Bullet part ends

  for (const auto& iter : this->units) {
    move(iter->y, iter->x);

    iter->print();
  }

  move(32, 0);
  printw("current frame: %d", curr_frame);
  move(33, 0);
  printw("%d", shot_frame);
  move(34, 0);
  printw("%d", check_frame);
  move(35, 0);
  printw("%d", this->my_plane.hp);
}

// print when key didn't pressed
void Screen_manager::print() {
  move(this->my_plane.y, this->my_plane.x);
  printw("M");

  print_share();
}

// print when key pressed
void Screen_manager::print(int ch) {  // ascii
  if (ch == 'd') {                    // right
    if (this->my_plane.y >= 0 && this->my_plane.y < (height - 1) &&
        this->my_plane.x > 0 && this->my_plane.x < (width - 2)) {
      move(this->my_plane.y, this->my_plane.x);
      printw(" ");
      this->my_plane.x += 1;
      move(this->my_plane.y, this->my_plane.x);

      printw("M");
    }
  } else if (ch == 'a') {  // left
    if (this->my_plane.y >= 0 && this->my_plane.y < (height - 1) &&
        this->my_plane.x > 1 && this->my_plane.x < (width - 1)) {
      move(this->my_plane.y, this->my_plane.x);
      printw(" ");
      this->my_plane.x -= 1;
      move(this->my_plane.y, this->my_plane.x);
      printw("M");
    }
  } else if (ch == 'w') {  // up
    if (this->my_plane.y > 0 && this->my_plane.y < (height - 1) &&
        this->my_plane.x > 0 && this->my_plane.x < (width - 1)) {
      move(this->my_plane.y, this->my_plane.x);
      printw(" ");
      this->my_plane.y -= 1;
      move(this->my_plane.y, this->my_plane.x);
      printw("M");
    }
  } else if (ch == 's') {  // down
    if (this->my_plane.y >= 0 && this->my_plane.y < (height - 2) &&
        this->my_plane.x > 0 && this->my_plane.x < (width - 1)) {
      move(this->my_plane.y, this->my_plane.x);
      printw(" ");
      this->my_plane.y += 1;
      move(this->my_plane.y, this->my_plane.x);
      printw("M");
    }
  }

  // iterate screenmanager's unit vector and check myplane.x, myplane.y is on
  // unit.x, unit.y (check my plane and unit crash)
  for (const auto& iter : this->units) {
    if (iter->y == this->my_plane.y && iter->x == this->my_plane.x) {
      this->my_plane.hp -= 1;
    }
  }

  print_share();
}