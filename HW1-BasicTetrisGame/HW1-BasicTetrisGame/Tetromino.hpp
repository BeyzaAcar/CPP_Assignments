#ifndef TETROMINO_HPP
# define TETROMINO_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class tetro
{
    I,O,T,J,L,S,Z
};


class Tetromino
{
    public:
        Tetromino(tetro);
        void rotate(char);
        void print_blocks() ;
        bool bosluk_silme();
        bool bosluk_kontrol( ) const;
        bool canFit();
        void birlestirme(int);
        bool cakisma_kontrol(int) const;
        void initializer();
        void geri_al();
        static void print_answer();
    private: 
        vector<vector<char>> block;
        static vector<vector<char>> answer;
};

#endif