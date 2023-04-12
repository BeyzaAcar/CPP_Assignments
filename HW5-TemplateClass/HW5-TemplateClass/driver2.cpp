#include    "TetrisVector.hpp"
#include    "Tetris1DArray.hpp"
#include    "TetrisAdapter.hpp"


using namespace std;

int main()
{
  
    //DRIVER2
    
    srand(time(NULL));
    int shift_right, dir_count, random_num=-1, row, column;
    char choice, dir, type;
    Tetromino block;
    cout<<"Please enter row ..:";
    cin>>row;
    cout<<"Please enter column ..:";
    cin>>column;
    row +=2;
    column +=2;
    AbstractTetris * tet_obj;
    cout<<"Please enter the type of the Tetris class (V for vector, 1 for array1D, A for adaptor) ..: ";
    cin>>type;
    if(type == 'v' || type == 'V') tet_obj = new TetrisVector(row, column);
    else if (type == '1') tet_obj = new Tetris1DArray(row, column);
    else if(type == 'A' || type == 'a') tet_obj = new TetrisAdapter<vector>(row, column);

    do
    {   
        cout<<"Please enter the tetromino type you want to add ... (if you want to quit enter letter q) ..:";
        cin>>choice;
        if(choice == 'q' || choice == 'Q') return 0;
        cout<<"Please enter which way to rotate the block.. (l for left and r for right ).. : ";
        cin>>dir;
        cout<<"Please enter how many times you want to rotate the block..:";
        cin>>dir_count;
        cout<<"Please enter how many times you want to swipe the block...: ";
        cin>>shift_right;
        tet_obj->set_shift_right(shift_right);
        if(choice == 'R' || choice == 'r') random_num = rand()%7;
        if(random_num == 0 || choice =='o' || choice == 'O')  block.set_data(dir_count, dir, tetro::O);
        else if(random_num == 1 || choice =='t' || choice == 'T')  block.set_data(dir_count, dir, tetro::T);
        else if(random_num == 2 || choice =='l' || choice == 'L')  block.set_data(dir_count, dir, tetro::L);
        else if(random_num == 3 || choice =='s' || choice == 'S')  block.set_data(dir_count, dir, tetro::S);
        else if(random_num == 4 || choice =='j' || choice == 'J')  block.set_data(dir_count, dir, tetro::J);
        else if(random_num == 5 || choice =='i' || choice == 'I')  block.set_data(dir_count, dir, tetro::I);
        else if(random_num == 6 || choice =='z' || choice == 'Z')  block.set_data(dir_count, dir, tetro::Z);

        *tet_obj += block; //we add the block to our baord
        tet_obj->animate();
        cout<<"last move is :"<<tet_obj->lastMove();
        random_num = -1;
    } while (1);
    
    return 0;
}

