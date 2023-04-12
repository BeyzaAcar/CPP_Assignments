#ifndef TETROMINO_HPP
# define TETROMINO_HPP

# include <vector>
# include <string>

using namespace std;

enum class tetro
{
    I,O,T,J,L,S,Z
};

class Tetromino
{
    public:
        Tetromino();
        ~Tetromino();
        char** get_block() const;
        void rotate();
        bool bosluk_silme();
        Tetromino(const Tetromino&);
        void set_data(const int, const char, const tetro); /*direction_count, direction, block_type*/
        void set_block( char**);
        int get_dir_count() const;
        char get_dir() const;
        void set_dir_count(const int);
        void set_dir(const char);

    private:
        char** block;
        int dir_count;
        char dir;

};

#endif
