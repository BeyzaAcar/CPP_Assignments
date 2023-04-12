#ifndef _TETROMINO_HPP
#define _TETROMINO_HPP

using namespace std;

#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

namespace gtu 
{
    enum class tetro
    {
        I,O,T,J,L,S,Z
    };
}

class Tetromino
{
    public:
        char** get_block();
        char** rotate(char, int);
        bool bosluk_silme();
        void pseudo_constructer(gtu::tetro);
        Tetromino(gtu::tetro);
        ~Tetromino();
        

    private: 
        char** block;
};

#endif
