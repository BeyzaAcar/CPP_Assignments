#ifndef _TETRIS_HPP
#define _TETRIS_HPP

#include "tetromino.hpp"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

class Tetris
{
    private:
        int row;
        int column;
        char **board;
    public:
        Tetris(int, int);
        ~Tetris();
        void move();
        void animate(int, char);
        void move_right(int, char, char**);
        void move_down(int, char, char**);
        void print_board(char);
        bool cakisma_kontrol(int,int, char**);
        char** operator+= (char**);
};

#endif
