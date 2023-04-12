#include "tetris.hpp"
#include "tetromino.hpp"

using namespace std;

int main()
{
    int i = 0;
    char choice;
    int rowsize, columnsize;
    cout<<"Enter the row size";
    cin>>rowsize;
    cout<<"Enter the column size";
    cin>>columnsize;
    rowsize += 2;
    columnsize += 2;
    Tetris *tetris_ptr = new Tetris(rowsize, columnsize);
    
    do
    {
        tetris_ptr->move();
        cout<<"if you want to quit please enter q or if you want to continue enter any letter"<<endl;
        cin>>choice;
        if(choice == 'q' || choice == 'Q') return 0;

    } while (1);

    return 0;

}
