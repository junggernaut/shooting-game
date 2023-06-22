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

#include "Enemy_1n.h"
#include "Enemy_2r.h"
#include "Enemy_3s.h"
#include "Enemy_4d.h"
#include "Enemy_5a.h"
#include "Screen_manager.h"
#include "keyboard_controller.cpp"

using namespace std;

// main function
int main(int argc, char *argv[]) {
  ifstream input;
  string input_file = string(argv[1]);
  if (argc != 2) {
    cerr << "Wrong arguments" << endl;
  }
  input.open(input_file);  // an input_file
  if (!(input.is_open())) {
    cerr << "Input missing" << endl;
    return 0;
  }

  Screen_manager manager;
  int num_event, frame_event, y_event, x_event;
  char type_event;
  input >> num_event;
  for (int i = 0; i < num_event; i++) {
    input >> frame_event >> type_event >> y_event >> x_event;
    manager.frame_event[i] = frame_event;
    manager.type_event[i] = type_event;
    manager.y_event[i] = y_event;
    manager.x_event[i] = x_event;
  }
  input.close();

  struct timeval tv;
  double start, end;
  double operation_time = 0;  // microseconds
  double frame_length = manager.frame_length;
  int event_index = 0;

  std::cout << "Start game~!" << endl;
  setlocale(LC_ALL, "");
  initscr();
  init_keyboard();
  refresh();
  manager.print();
  refresh();

  int ch = 0;
  bool pause = false;
  while (ch != 'x') {
    if (pause == false) {
      gettimeofday(&tv, NULL);
      start = tv.tv_sec * 1000000 + tv.tv_usec;
      if (kbhit()) {
        ch = readch();
        if (ch == 'p') {
          pause = true;
          continue;
        }
        manager.print(ch);
        if (ch == 'x') break;
      } else {
        manager.print();
      }
      gettimeofday(&tv, NULL);
      end = tv.tv_sec * 1000000 + tv.tv_usec;
      int prev_frame = operation_time / frame_length;
      operation_time += (end - start);
      manager.curr_frame = operation_time / frame_length;

      if (manager.curr_frame >= manager.frame_event[event_index]) {
        if (manager.type_event[event_index] == 'n') {
          manager.my_plane.units.push_back(Enemy_1n(
              manager.y_event[event_index], manager.x_event[event_index]));
        } else if (manager.type_event[event_index] == 'r') {
          manager.my_plane.units.push_back(Enemy_2r(
              manager.y_event[event_index], manager.x_event[event_index]));
        } else if (manager.type_event[event_index] == 's') {
          manager.my_plane.units.push_back(Enemy_3s(
              manager.y_event[event_index], manager.x_event[event_index]));
        } else if (manager.type_event[event_index] == 'd') {
          manager.my_plane.units.push_back(Enemy_4d(
              manager.y_event[event_index], manager.x_event[event_index]));
        } else if (manager.type_event[event_index] == 'a') {
          manager.my_plane.units.push_back(Enemy_5a(
              manager.y_event[event_index], manager.x_event[event_index]));
        }
      }

      /*Objects operate every 0.1 seconds.
      Call refresh() every 0.1 seconds(or every 0.1*n seconds if
      manager.print() takes a long time) ex) if operation_time changes to
      0.25->0.30, refresh()

      You can modify your manager.print() using multi-threading or not.
      If you use multi-threading, you may print more frequently.
      You can reduce the execution time of manager.print() using
      multi-threading*/
      if (manager.curr_frame - prev_frame > 0) {
        refresh();  // print the screen
      }
    } else {
      if (kbhit()) {
        ch = readch();
        if (ch == 'r') {
          pause = false;
          continue;
        }
      }
    }
  }
  close_keyboard();
  endwin();

  return 0;
}
