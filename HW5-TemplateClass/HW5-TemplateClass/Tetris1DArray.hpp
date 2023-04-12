#ifndef TETRIS1DARRAY_HPP
# define TETRIS1DARRAY_HPP

# include "AbstractTetris.hpp"


class Tetris1DArray: public AbstractTetris
{
    public:
        Tetris1DArray();
        Tetris1DArray(int, int);
        ~Tetris1DArray();

        virtual void draw() ;
        virtual void readFromFile (fstream &fileptr)  ;
        virtual void writeToFile(fstream &fileptr) ;
        virtual void  operator+=(const Tetromino &obj);
        virtual void animate();
        virtual string lastMove() ;
        virtual int numberOfMoves ()  ;

        void set_last_block();
        void set_block_letter(const char);
        void move_right();
        void move_down();
        bool overlap_control(int);
        void set_shift_right(const int);
        void certain_merge();
        void remove();


    private:
        char *board;
        int move_count;
        int row;
        int column;
        Tetromino last_block;
        char block_letter;
        int shift_right;
};


#endif
