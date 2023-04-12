#include "tetromino.hpp"

using namespace std;

char** Tetromino::get_block()
{
    return block;
}
Tetromino::Tetromino(gtu::tetro block_type)
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

    if(block_type == gtu::tetro::I)
    {
        block[0][0] = 'I';
        block[0][1] = 'I';
        block[0][2] = 'I';
        block[0][3] = 'I';
    }
    else if(block_type == gtu::tetro::O)
    {
        block[2][0] = 'O';
        block[2][1] = 'O';
        block[3][0] = 'O';
        block[3][1] = 'O';
    }
    else if(block_type == gtu::tetro::T)
    {
        block[2][0] = 'T';
        block[2][1] = 'T';
        block[2][2] = 'T';
        block[3][1] = 'T';
    }
    else if(block_type == gtu::tetro::J)
    {
        block[1][1] = 'J';
        block[2][1] = 'J';
        block[3][0] = 'J';
        block[3][1] = 'J';
    }
    else if(block_type == gtu::tetro::L)
    {
        block[1][0] = 'L';
        block[2][0] = 'L';
        block[3][0] = 'L';
        block[3][1] = 'L';
    }
    else if(block_type == gtu::tetro::S)
    {
        block[2][1] = 'S';
        block[2][2] = 'S';
        block[3][0] = 'S';
        block[3][1] = 'S';
    }
    else if(block_type == gtu::tetro::Z)
    {
        block[2][0] = 'Z';
        block[2][1] = 'Z';
        block[3][1] = 'Z';
        block[3][2] = 'Z';
    }
}

Tetromino::~Tetromino()
{
    int i;
    for(i=0;i<4;i++)
        delete[] block[i];
    delete [] block;
}

bool Tetromino::bosluk_silme()
{
    int i, flag1 = 0, flag2 = 0,j;

    for(i = 0;i<4;i++)
    {
        if(block[i][0] == ' ')
            flag1++;
        if(block[3][i] == ' ')
            flag2++;
    }
    if(flag2 == 4)
    {
        for(i=3;i>0;i--)
        {
            for(j=0;j<4;j++)
            {
                block[i][j] = block[i-1][j];
            }
        }
        for(i=0;i<4;i++)
        {
            block[0][i] = ' ';
        }
        return true;
    } 
    if(flag1 == 4)
    {
        for(i=0;i<3;i++)
        {
            for(j=0;j<4;j++)
            {
                block[j][i] = block[j][i+1];
            }
        }
        for(i=0;i<4;i++)
        {
            block[i][3] = ' ';
        }
        return true;
    }
    return false;
}

char** Tetromino::rotate(char direction, int dir_count)
{
    int i,j,k;
    char **temp_block = new char*[4];
    for(i=0;i<4;i++)
    {
        temp_block[i] = new char[4];
    }
    dir_count = dir_count%4;
    if(direction == 'l' || direction == 'L') dir_count = 4-dir_count;
    for(k=0;k<dir_count;k++)
    {
        for(i=0;i<4;i++)
        {
            for(j=3;j>=0;j--)
            {
                temp_block[i][3-j] = block[j][i];
            }
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                block[i][j] = temp_block[i][j];
            }
        }
    }

    while(bosluk_silme() == true);

    for(i=0;i<4;i++)
    {
        delete[] temp_block[i];
    }
    delete[] temp_block;
    return block;
}


