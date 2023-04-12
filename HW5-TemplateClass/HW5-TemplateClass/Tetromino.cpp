#include <iostream>
#include "Tetromino.hpp"

using namespace std;

Tetromino::Tetromino()
{
    int i,j;
    block = new char*[4];
    for(i=0;i<4;i++)
    {
        block[i] = new char[4];
        for(j=0;j<4;j++)
        {
            block[i][j] = ' ';
        }
    }
    dir_count = 0;
}
Tetromino::~Tetromino()
{
    int i;
    for(i=0;i<4;i++)
    {
        delete[] block[i];
    }
    delete[] block;
}
Tetromino::Tetromino(const Tetromino& obj)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            block[i][j] = obj.get_block()[i][j];
        }
    }
}
bool Tetromino::bosluk_silme()
{
    int i, flag1 = 0, flag2 = 0;
    for(i = 0;i<4;i++)
    {
        if(block[i][0] == ' ')
            flag1++;
        if(block[3][i] == ' ')
            flag2++;
    }
    if(flag1 == 4)
    {
        for(i=0;i<3;i++)
        {
            block[0][i] = block[1][i];
            block[1][i] = block[2][i];
            block[2][i] = block[3][i];
            block[3][i] = ' ';
        }
        return true;
    } 
    if(flag2 == 4)
    {
        for(i=0;i<3;i++)
        {
            block[3][i] = block[2][i];
            block[2][i] = block[1][i];
            block[1][i] = block[0][i];
            block[0][i] = ' ';
        }
        return true;
    }
    return false;
}
void Tetromino::rotate()
{
    vector<vector<char>> temp(4);
    int i, j;
    for(j=0;j<=3;j++)
    {
        for(i=3;i>=0;i--)
        {
            temp[j].push_back(block[i][j]);
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            block[i][j] = temp[i][j];
        }
    }
    while(bosluk_silme() == true);
}
char **Tetromino::get_block() const
{
    return block;
}
void Tetromino::set_data(const int dir_c, const char direction, const tetro block_type)
{
    dir_count = dir_c;
    dir = direction;
    int i,j;
    
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            block[i][j] = ' ';
        }
    }

    if(block_type == tetro::I)
    {
        block[0][0] = 'I';
        block[0][1] = 'I';
        block[0][2] = 'I';
        block[0][3] = 'I';
    }
    else if(block_type == tetro::O)
    {
        block[2][0] = 'O';
        block[2][1] = 'O';
        block[3][0] = 'O';
        block[3][1] = 'O';
    }
    else if(block_type == tetro::T)
    {
        block[2][0] = 'T';
        block[2][1] = 'T';
        block[2][2] = 'T';
        block[3][1] = 'T';
    }
    else if(block_type == tetro::J)
    {
        block[1][1] = 'J';
        block[2][1] = 'J';
        block[3][0] = 'J';
        block[3][1] = 'J';
    }
    else if(block_type == tetro::L)
    {
        block[1][0] = 'L';
        block[2][0] = 'L';
        block[3][0] = 'L';
        block[3][1] = 'L';
    }
    else if(block_type == tetro::S)
    {
        block[2][1] = 'S';
        block[2][2] = 'S';
        block[3][0] = 'S';
        block[3][1] = 'S';
    }
    else if(block_type == tetro::Z)
    {
        block[2][0] = 'Z';
        block[2][1] = 'Z';
        block[3][1] = 'Z';
        block[3][2] = 'Z';
    }
    dir_count = dir_count%4;
    if(dir == 'l') dir_count = 4-dir_count;
    for(i=0;i<dir_count;i++)
    {
        rotate();
    }
}
void Tetromino::set_block( char **temp_block)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            block[i][j] = temp_block[i][j];
        }
    }
}
int Tetromino::get_dir_count() const
{
    return dir_count;
}
char Tetromino::get_dir() const
{
    return dir;
}
void Tetromino::set_dir_count(const int a)
{
    dir_count = a;
}
void Tetromino::set_dir(const char a)
{
    dir = a;
}

