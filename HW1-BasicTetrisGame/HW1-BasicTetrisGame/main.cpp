#include "Tetromino.hpp" 


using namespace std;

vector<vector<char>> Tetromino::answer(4, vector<char>(20, ' '));

int main()
{
    vector<Tetromino> v1;
    int numberOfBlocks, i;
    char blockType;
    cout<<"How many tetrominos ? "<<endl;
    cin>>numberOfBlocks;
    for(i = 0;i<numberOfBlocks;i++)
    {
        cin>>blockType;
        if(blockType == 'I' || blockType == 'i') v1.push_back(Tetromino(tetro::I));
        else if(blockType == 'O' || blockType == 'o') v1.push_back(Tetromino(tetro::O));
        else if(blockType == 'T' || blockType == 't') v1.push_back(Tetromino(tetro::T));
        else if(blockType == 'J' || blockType == 'j') v1.push_back(Tetromino(tetro::J));
        else if(blockType == 'L' || blockType == 'l') v1.push_back(Tetromino(tetro::L));
        else if(blockType == 'S' || blockType == 's') v1.push_back(Tetromino(tetro::S));
        else if(blockType == 'Z' || blockType == 'z') v1.push_back(Tetromino(tetro::Z));
    }
    for(i=0;i<numberOfBlocks;i++)
        v1[i].print_blocks();

    v1[0].initializer();

    for(i=1;i<numberOfBlocks;i++)
        v1[i].canFit();
    Tetromino::print_answer();   


    return 0;
}