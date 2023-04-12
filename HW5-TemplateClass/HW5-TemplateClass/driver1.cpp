#include   "TetrisVector.hpp"
#include "AbstractTetris.hpp"
#include "Tetris1DArray.hpp"
#include "TetrisAdapter.hpp"


using namespace std;

int main()
{
/*
    block type = L
    row = 10, column = 10
    shift_right = 3
    dir = right (r)
    direction_count = 3
    It will work with this informations 3 times, first for 1darray, second for vector and third for adaptor.
    */
    sleep(2);
    cout<<"block type = L \nrow = 10, column = 10\nshift_right = 3\ndir = right (r)\ndirection_count = 3\nIt will work with this informations 3 times, first for 1darray, second for vector and third for adaptor.\n";
    srand(time(NULL));
    int shift_right, dir_count, random_num=-1;
    char dir = 'r';
    Tetromino block;
    Tetris1DArray tet_vect_obj(10+2, 10+2);
    tet_vect_obj.set_shift_right(3); 
    block.set_data(dir_count, dir, tetro::L);
    tet_vect_obj += block; 
    tet_vect_obj.animate();
    tet_vect_obj.lastMove(); 
    fstream fileptr;
    fileptr.open("record.txt", ios::in);
    tet_vect_obj.readFromFile(fileptr);
    fileptr.close();
    cout<<"tetris1darray bitti\n";
    sleep(2);

    TetrisVector tet_vect_obj2(10+2, 10+2);
    tet_vect_obj2.set_shift_right(3); 
    tet_vect_obj2 += block; 
    tet_vect_obj2.animate();
    tet_vect_obj2.lastMove(); 
    fstream fileptr2;
    fileptr2.open("record.txt", ios::in);
    tet_vect_obj2.readFromFile(fileptr2);
    fileptr2.close();
    cout<<"tetrisvector bitti\n";
    sleep(2);

    TetrisAdapter<vector> tet_vect_obj3(10+2, 10+2);
    tet_vect_obj3.set_shift_right(3); 
    tet_vect_obj3 += block; 
    tet_vect_obj3.animate();
    tet_vect_obj3.lastMove(); 
    fstream fileptr3;
    fileptr3.open("record.txt", ios::in);
    tet_vect_obj3.readFromFile(fileptr3);
    fileptr3.close();
    cout<<"tetrisadapter bitti\n";
    sleep(2);
    return 0;
}
