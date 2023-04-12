#include "TetrisVector.hpp"

using namespace std;

TetrisVector::TetrisVector(int rowsize, int columnsize)
{
    row = rowsize;
    column = columnsize;
    if(row<=0 || column <=0) cerr<<"invalid input"<<endl;
    else
    {
        int i,j;
        board.resize(row);
        for(i=0;i<row;i++)
        {
            board[i].resize(column);
            for(j=0;j<column;j++)
            {
                board[i].push_back(' ');
            }
        }
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                board[i][j] = ' ';
            }
        }

        set_last_block();
        move_count = 0;
    }
    
}
TetrisVector::~TetrisVector()
{
}
void TetrisVector::set_block_letter(const char type)
{
    block_letter = type;
}
void TetrisVector::set_last_block()
{
    int i,j;
    char **temp_block;
    temp_block = new char*[4];
    for(i=0;i<4;i++)
    {
        temp_block[i] = new char[4];
        for(j=0;j<4;j++)
        {
            if(board[i][j] == 'x')
            {
                temp_block[i][j] = 'x';
            }
            else temp_block[i][j] = ' ';
        }
    }
    last_block.set_block(temp_block);
    for(i=0;i<4;i++)
    {
        delete[] temp_block[i];
    }
    delete[] temp_block;

}
void TetrisVector::set_shift_right(const int shift_r)
{
    shift_right = shift_r;
}
void TetrisVector::operator+=(const Tetromino& obj)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(obj.get_block()[i][j] != ' ')
            {
                board[i][j] = 'x';
            }
        }
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(obj.get_block()[i][j] != ' ')
            {
                block_letter = obj.get_block()[i][j];
                i=4;
                break;
            }
        }
    }
    set_last_block();
    last_block.set_dir_count(obj.get_dir_count());
    last_block.set_dir(obj.get_dir());
}
void TetrisVector::draw()
{
    cout<<"\033[2J" << "\033[0;0f";
    sleep(1);
    int i,j;
    for(i=0;i<row;i++) cout<<"-";
    cout<<endl;
    for(i=0;i<row;i++)
    {
        cout<<'|';
        for(j=0;j<column;j++)
        {
            if(board[i][j] == 'x') cout<<block_letter;
            else cout<<board[i][j];
        }
        cout<<'|'<<endl;
    }
    for(i=0;i<row;i++) cout<<"-";
    cout<<endl;
}
bool TetrisVector::overlap_control(int shift_down)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            
            if(!(board[i+shift_down][j+shift_right] == ' ' || board[i+shift_down][j+shift_right] == 'x' || last_block.get_block()[i][j] == ' ' ))
            {   /*cakisti*/
                return false;
            }
        }
    }

    return true;
}
void TetrisVector::animate()
{
    move_right();
    move_down();
}
void TetrisVector::move_right()
{
    int i,j,k;
    for(k=0;k<=shift_right;k++)
    {
        remove();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(board[i][j+k] == ' ')
                    board[i][j+k] = last_block.get_block()[i][j];
            }
        }
        draw();
    }

}
void TetrisVector::move_down()
{
    int i,j;
    int shift_down = 0;
    do
    {
        remove();
        for (i=0;i<4;i++)
        {
            for (j=0;j<4;j++)
            {
                if(board[i + shift_down][j + shift_right] == ' ')
                    board[i + shift_down][j + shift_right] = last_block.get_block()[i][j];
            }
        }
        draw();
        shift_down++;
        if(shift_down > row-4) break;
        //sleep(1);
    } while(overlap_control(shift_down) == true);
    move_count = shift_right+last_block.get_dir_count(); /*because of finishing the action, code adjust move_count in here*/
    certain_merge();
}
void TetrisVector::certain_merge()
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(board[i][j] == 'x') board[i][j] = block_letter;
        }
    }
    fstream fileptr_wr;
    fstream fileptr_r;
    writeToFile(fileptr_wr);
    fileptr_r.close();
    fileptr_wr.close();
    
}
void TetrisVector::remove()
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(board[i][j] == 'x') board[i][j] = ' ';
        }
    }
}
string TetrisVector::lastMove()
{
    char dir = last_block.get_dir();
    try
    {
        if(dir == 'r') return "rotated to the right " + to_string(last_block.get_dir_count()) + " times. Total move is " + to_string(move_count) + '\n';
        else if(dir == 'l') return "rotated to the left " + to_string(4-last_block.get_dir_count()) + " times. Total move is " + to_string(move_count) + '\n';
        else throw dir;
    }
    catch(char dir)
    {
        cout<<"ERROR : there is a problem about direction of the move"<<endl;
        return "ERROR";
    }
}
void TetrisVector::writeToFile(fstream &fileptr)
{
    fileptr.open("record.txt", ios::out);
    fileptr<<lastMove();
}
void TetrisVector::readFromFile(fstream &fileptr)
{
    string dir;
    string garbage;
    int dir_c;
    fileptr.open("record.txt", ios::in);
    fileptr>>garbage;
    fileptr>>garbage;
    fileptr>>garbage;
    fileptr>>dir;
    fileptr>>dir_c;

}
int TetrisVector::numberOfMoves()
{
    return move_count;
}
