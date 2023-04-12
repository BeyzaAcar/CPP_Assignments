#include "tetris.hpp"
#include "tetromino.hpp"

using namespace std;

Tetris::Tetris(int rowsize, int columnsize)
{
    int i,j;
    row = rowsize;
    column = columnsize;
    board = new char*[row];
    for(i=0;i<row;i++)
    {
        board[i] = new char[column];
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            board[i][j] = ' ';
        }
    }
}

Tetris::~Tetris()
{
    int i;
    for(i=0;i<row;i++)
        delete [] board[i];
    delete [] board;
}

void Tetris::print_board(char block_letter)
{
    cout<<"\033[2J" << "\033[0;0f";
    sleep(1);
    int i,j;
    for(i=0;i<column;i++) cout<<"-";
    cout<<endl;
    for(i=0;i<row;i++)
    {
        cout<<"|";
        for(j=0;j<column;j++)
        {
            if(board[i][j] == 'x')
                cout<<block_letter;
            else
                cout<<board[i][j];
        }
        cout<<"|";
        cout<<endl;
    }
    for(i=0;i<column;i++) cout<<"-"; 
    cout<<endl;
}

void Tetris::move()
{
    char direction;
    int dir_count, shift_right;
    srand(time(NULL));
    int random_num = -1;
    char block_type;
    gtu::tetro blockType;
    cout<<"enter the block type you want to add..:";
    cin>>block_type;
    if(block_type == 'R' || block_type == 'r') random_num = rand()%7;
    if(random_num == 0 || block_type == 'i' || block_type == 'I')blockType = gtu::tetro::I;
    else if(random_num == 1 || block_type == 'J' || block_type == 'j') blockType = gtu::tetro::J;
    else if(random_num == 2 || block_type == 'L' || block_type == 'l') blockType = gtu::tetro::L;
    else if(random_num == 3 || block_type == 'S' || block_type == 's') blockType = gtu::tetro::S;
    else if(random_num == 4 || block_type == 'T' || block_type == 't') blockType = gtu::tetro::T;
    else if(random_num == 5 || block_type == 'O' || block_type == 'o') blockType = gtu::tetro::O;
    else if(random_num == 6 || block_type == 'Z' || block_type == 'z') blockType = gtu::tetro::Z;
    Tetromino tetromino_obj(blockType);

    cout<<"ne tarafa dondurmek istersiniz (l for left and r for right) .. ?";
    cin>>direction;
    cout<<"kac kere dondurmek istersiniz ? ..:";
    cin>>dir_count;

    *this += tetromino_obj.rotate(direction, dir_count);

    cout<<"ne kadar saga kaydirmak istersiniz ? ..:";
    cin>>shift_right;
    animate(shift_right, tetromino_obj.get_block()[3][1]);
}

char** Tetris::operator+=(char** block_rotate)
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(block_rotate[i][j] != ' ')
                board[i][j] = 'x';
        }
    }
    return board;
}

bool Tetris::cakisma_kontrol(int shift_right, int shift_down, char**block_x)/*shift = kaydirma miktarini temsil ediyor*/
{   
    /*X LERI SILIYORUM ONLAR CAKISMA SAYILMASIN DIYE*/
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            if(board[i][j] == 'x') board[i][j] = ' ';
        }
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(i+shift_down>=row || j+shift_right>=column) /*segmentation fault almamak icin ne olur ne olmaz*/
            {
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {   
                        if(board[i+shift_down-1][j+shift_right] == ' ')
                            board[i+shift_down-1][j+shift_right] = block_x[i][j];
                    }
                }
                return false;
            }
            if(!(board[i+shift_down][j+shift_right] == ' ' || block_x[i][j] == ' '))
            {   /*cakisti*/
                for(i=0;i<4;i++)
                {
                    for(j=0;j<4;j++)
                    {
                        if(board[i+shift_down-1][j+shift_right] == ' ')
                            board[i+shift_down-1][j+shift_right] = block_x[i][j];
                    }
                }
                return false;
            }
        }
    }

    return true;
}

void Tetris::animate(int shift_right, char block_letter)
{
    int i,j;
    char **block_x;
    block_x = new char*[4];
    for(i=0;i<4;i++)
    {
        block_x[i] = new char [4];
        for(j=0;j<4;j++)
        {
            if(board[i][j] == 'x')
                block_x[i][j] = board[i][j]; /*block rotate edilmis tetrominonun x ile yazilmis hali oluyor*/
            else block_x[i][j] = ' ';
        }
    }
    move_right(shift_right, block_letter, block_x);
    move_down(shift_right, block_letter, block_x);
}

void Tetris::move_right(int shift_right, char block_letter, char **block_x)
{
    int i,j,k;
    for(k=0;k<=shift_right;k++)
    {
        
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {   
                if(board[i][j+k] == ' ')
                    board[i][j+k] = block_x[i][j];
            }
        }
        print_board(block_letter);

        /*SILME KİSMİ*/
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(board[i][j+k] == 'x')
                    board[i][j+k] = ' ';
            }
        }

        //sleep(1);
    }
}

void Tetris::move_down(int shift_right, char block_letter, char **block_x)
{
    int i,j,k;
    int shift_down = 0;

    while(cakisma_kontrol(shift_right, shift_down+1, block_x) == true)
    {
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(board[i][j] == 'x')
                    board[i][j] = ' '; /*x ler silindi*/
            }
        }

        shift_down++;

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(board[i+shift_down][j+shift_right] == ' ')
                    board[i+shift_down][j+shift_right] = block_x[i][j];
            }
        }
        print_board(block_letter);
        //sleep(1);
    }
    for(i=0;i<row;i++) /*son olarak tahtadaki x ler yerine gercek harfi yerlestiriyoruz*/
    {
        for(j=0;j<column;j++)
        {
            if(board[i][j] == 'x')
                board[i][j] = block_letter;
        }
    }
}

