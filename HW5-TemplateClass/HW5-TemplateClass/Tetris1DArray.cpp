#include "Tetris1DArray.hpp"

using namespace std;

Tetris1DArray::Tetris1DArray(int rowsize, int columnsize)
{
    row = rowsize;
    column = columnsize;
    if(row<=0 || column <=0) cerr<<"invalid input"<<endl;
    else
    {
        int i,j;
        board = new char [row*column];
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                board[ i * column + j] = ' ';
            }
        }

        set_last_block();
        move_count = 0;
    }
}
Tetris1DArray::~Tetris1DArray(){};
void Tetris1DArray::readFromFile(fstream& fileptr)
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
void Tetris1DArray::writeToFile(fstream& fileptr)
{
    fileptr.open("record.txt", ios::out);
    fileptr<<lastMove();
}
void Tetris1DArray::operator+=(const Tetromino &obj)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(obj.get_block()[i][j] != ' ')
            {
                board[ i*column + j] = 'x';
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
void Tetris1DArray::draw()
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
            if(board[ i*column + j] == 'x') cout<<block_letter;
            else cout<<board[i*column + j];
        }
        cout<<'|'<<endl;
    }
    for(i=0;i<row;i++) cout<<"-";
    cout<<endl;
}
void Tetris1DArray::animate()
{
    move_right();
    move_down();
}
void Tetris1DArray::move_right()
{
    int i,j,k;
    for(k=0;k<=shift_right;k++)
    {
        remove();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(board[i*column + j+k] == ' ')
                    board[i*column + j+k] = last_block.get_block()[i][j];
            }
        }
        draw();
    }
}
void Tetris1DArray::move_down()
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
                if(board[(i+shift_down)*column + j + shift_right] == ' ')
                    board[(i+shift_down)*column + j + shift_right] = last_block.get_block()[i][j];
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
bool Tetris1DArray::overlap_control(int shift_down)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            
            if(!(board[(i+shift_down)*column + j + shift_right] == ' ' || board[(i+shift_down)*column + j + shift_right] == 'x' || last_block.get_block()[i][j] == ' ' ))
            {   /*cakisti*/
                return false;
            }
        }
    }
    return true;
}
void Tetris1DArray::certain_merge()
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(board[ i*column + j] == 'x') board[ i*column + j] = block_letter;
        }
    }
    fstream fileptr_wr;
    fstream fileptr_r;
    writeToFile(fileptr_wr);
    fileptr_r.close();
    fileptr_wr.close();
}
void Tetris1DArray::remove()
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(board[ i*column + j] == 'x') board[ i*column + j] = ' ';
        }
    }
}
void Tetris1DArray::set_block_letter(const char type)
{
    block_letter = type;
}
void Tetris1DArray::set_shift_right(const int shift_r)
{
    shift_right = shift_r;
}
void Tetris1DArray::set_last_block()
{
    int i,j;
    char **temp_block;
    temp_block = new char*[4];
    for(i=0;i<4;i++)
    {
        temp_block[i] = new char[4];
        for(j=0;j<4;j++)
        {
            if(board[ i*column + j] == 'x')
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
string Tetris1DArray::lastMove()
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
int Tetris1DArray::numberOfMoves()
{
    return move_count;
}

