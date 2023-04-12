#include "tetris.hpp"
#include "tetromino.hpp"

using namespace std;

int main()
{ /*mainde sadece rowsize ve columnsize aldigim icin onlari sabitledim row ve column 20*/
    int i = 0;
    char choice = 'r';
    int rowsize=20, columnsize=20;
    rowsize += 2;
    columnsize += 2;
    Tetris *tetris_ptr = new Tetris(rowsize, columnsize);
    
    do
    {
        tetris_ptr->move();
        if(choice == 'q' || choice == 'Q') return 0;

    } while (1);

    return 0;

}
