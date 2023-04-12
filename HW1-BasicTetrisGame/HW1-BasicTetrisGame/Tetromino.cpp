#include "Tetromino.hpp"

using namespace std;

/*NOT !! : kod boyunca block[3][1] i cok kullandim sebebi, butun bloklarin orasinda harf var yani o hucreyi bloklarin imzasi gibi dusundum, block[3][1]i blok tipini taanimak icin kullaniyorum*/

void Tetromino::print_answer()
{
    int i, j;
    for(i = 0;i<4;i++)
    {
        for(j=0;j<20;j++)
        {
            cout<<answer[i][j];
        }
        cout<<endl;
    }
}


Tetromino::Tetromino(tetro block_type)
{
    int i,j;
    if(block_type == tetro::I)
    {
        block=
        {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {'I', 'I', 'I', 'I'}
        };
    }
    else if(block_type == tetro::O)
    {
        block=
        {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {'O', 'O', ' ', ' '},
            {'O', 'O', ' ', ' '}
        };
    }
    else if(block_type == tetro::T)
    {
        block=
        {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {'T', 'T', 'T', ' '},
            {' ', 'T', ' ', ' '}
        };
    }
    else if(block_type == tetro::J)
    {
        block=
        {
            {' ', ' ', ' ', ' '},
            {' ', 'J', ' ', ' '},
            {' ', 'J', ' ', ' '},
            {'J', 'J', ' ', ' '}
        };
    }
    else if(block_type == tetro::L)
    {
        block=
        {
            {' ', ' ', ' ', ' '},
            {'L', ' ', ' ', ' '},
            {'L', ' ', ' ', ' '},
            {'L', 'L', ' ', ' '}
        };
    }
    else if(block_type == tetro::S)
    {
        block=
        {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', 'S', 'S', ' '},
            {'S', 'S', ' ', ' '}
        };
    }
    else if(block_type == tetro::Z)
    {
        block=
        {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {'Z', 'Z', ' ', ' '},
            {' ', 'Z', 'Z', ' '}
        };
    }
    

}

void Tetromino::rotate(char dir)
{
    if(dir=='r')
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

void Tetromino::print_blocks()
{
    int i, j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            cout<<block[i][j];
        cout<<endl;
    }
    cout<<endl;
}


void Tetromino::birlestirme(int shift)
{
    int i,j;

    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(answer[i][j+shift]==' ')
            {
                answer[i][j+shift] = block[i][j];
            }
        }
    }
}


bool Tetromino::bosluk_kontrol() const /*son 2 satirin(3 ve 4) uzunlugunu buluyor hangisi daha buyukse max a esitliyor daha sonra max kadar bosluk kontrol ediyor bosluk varsa 0 donduruyor*/
{
    int j=0,max_row_length=0, third_row=0, fourth_row=0;
        
    while(!(answer[2][j+1]==' '&& answer[2][j+2]==' '))
        j++;
    third_row = j;
    j=0;
    while(!(answer[3][j+1]==' '&& answer[3][j+2]==' '))   
        j++;
    fourth_row = j;

    if(fourth_row>third_row) max_row_length = fourth_row;
    else max_row_length = third_row;

    for(j=0;j<max_row_length-1;j++) /*-1 in sebebi sonuncu sutunda bosluk olabilir o sorunlu bi bosluk degil cunku "doldurulabilir"*/
    {
        if(answer[3][j]==' ') return false;
    }
    return true;
}

bool Tetromino::cakisma_kontrol(int shift) const/*shift = kaydirma miktarini temsil ediyor*/
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(!(answer[i][j+shift] == ' ' || block[i][j] == ' '))
            {   /*cakisti*/
                return false;
            }
        }
    }
    return true;
}

void Tetromino::initializer()
{
    if(block[3][1] == 'T')
    {
        answer=
        {
            {' ', ' ', ' ', ' '},
            {'T', ' ', ' ', ' '},
            {'T', 'T', ' ', ' '},
            {'T', ' ', ' ', ' '}
        };
    }
    else if(block[3][1] == 'Z')
    {
        answer=
        {
            {' ', ' ', ' ', ' '},
            {' ', 'Z', ' ', ' '},
            {'Z', 'Z', ' ', ' '},
            {'Z', ' ', ' ', ' '}
        };
    }
    else if(block[3][1] == 'J')
    {
        answer=
        {
            {' ', ' ', ' ', ' '},
            {'J', 'J', ' ', ' '},
            {'J', ' ', ' ', ' '},
            {'J', ' ', ' ', ' '}
        };
    }
    else if(block[3][1] == 'O')
    {
        answer=
        {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {'O', 'O', ' ', ' '},
            {'O', 'O', ' ', ' '}
        };
    }
    else if(block[3][1] == 'L')
    {
        answer=
        {
            {' ', ' ', ' ', ' '},
            {'L', ' ', ' ', ' '},
            {'L', ' ', ' ', ' '},
            {'L', 'L', ' ', ' '}
        };
    }
    else if(block[3][1] == 'S')
    {
        answer=
        {
            {' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' '},
            {' ', 'S', 'S', ' '},
            {'S', 'S', ' ', ' '}
        };
    }
    else if(block[3][1] == 'I')
    {
        answer=
        {
            {'I', ' ', ' ', ' '},
            {'I', ' ', ' ', ' '},
            {'I', ' ', ' ', ' '},
            {'I', ' ', ' ', ' '}
        };
    }
}

void Tetromino::geri_al()
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<20;j++)
        {
            if(answer[i][j] == block[3][1]) answer[i][j] = ' ';
        }
    }
}

bool Tetromino::canFit()
{
    int shift = 0,i,j;
    for(i=0;i<20;i++)
    {
        for(j=0;j<4;j++) /*maks 4 kez donup bir kaydiracak*/
        {
            if(cakisma_kontrol(shift) && cakisma_kontrol(shift)) /*cakisma_kontrol cakismiyorsa 1 dondurecek ** bosluk_kontrol bosluk yoksa 1 dondurecek*/
            {
                birlestirme(shift);
                return true;
            }
            else rotate('r');
        }
        rotate('r'); /*tekrar baslangic konumuna gelmesi icin*/
        shift++;
    }
    return false;
}

