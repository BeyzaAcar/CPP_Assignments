#ifndef TETRISVECTOR_HPP
# define TETRISVECTOR_HPP

# include "AbstractTetris.hpp"

class TetrisVector: public AbstractTetris
{
    public:
        TetrisVector();
        TetrisVector(int, int);
        ~TetrisVector();

        virtual void draw() ;
        virtual void readFromFile (fstream &fileptr)  ;
        virtual void writeToFile(fstream&) ;
        virtual void  operator+=(const Tetromino &);
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
        vector<vector<char >>board;
        int move_count;
        int row;
        int column;
        Tetromino last_block;
        char block_letter;
        int shift_right;
};

#endif
