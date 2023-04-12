#ifndef ABSTRACTTETRIS_HPP
# define ABSTRACTTETRIS_HPP

#include<cstdlib>
#include<ctime>
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iterator>
#include<unistd.h>
# include "Tetromino.hpp"


using namespace std;

class AbstractTetris
{
    public:

        AbstractTetris();
        ~AbstractTetris();

        virtual void draw() =0;
        virtual void readFromFile (fstream &fileptr)  =0;
        virtual void writeToFile(fstream &fileptr) =0;
        virtual void  operator+=(const Tetromino &obj) =0;
        virtual void animate()=0;
        virtual string lastMove() =0;
        virtual int numberOfMoves ()  =0;
        virtual void set_shift_right(const int) =0;

};

#endif
