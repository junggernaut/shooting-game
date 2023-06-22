#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H

#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <fstream>
#include <sys/time.h>
#include <vector>
#include "My_plane.h"

using namespace std;

//Screen manager.
class Screen_manager{
    public:
        int frame_length=100000; //each frame's length == 0.1sec(10,000 microseconds)
        int curr_frame=0; //1frame=0.1sec

        int y, x;
        int width=60;
        int height=30;
        int frame_event[300]={0,}, y_event[300]={0,}, x_event[300]={0,};
        char type_event[300] = {' ',};

        void print(int ascii);
        void print();
        void print_share();
        My_plane my_plane = My_plane(height-2, 1, 0);
};
#endif