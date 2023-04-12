package tetris;

import java.util.Random;

/**
 * This is the main class that holds the tetris board and the tetromino object.
 * @author BeyzaAcar
 */
public class Tetris
{
    private int row;
    private int column;
    private Tetromino tetromino_obj;
    private char[][] board;
    private Window window;
    private boolean flagNextTetromino = false;
    public static boolean flagGameOver = false;
    public static boolean flagGameStart = false;


    public Tetris(int row, int column)
    {
        flagNextTetromino = false;
        window = new Window();
        tetromino_obj = new Tetromino();
        this.row = row;
        this.column = column;
        board = new char[row][column];
        for(int i = 0;i<row;i++)
        {
            for(int j =0;j<column;j++)
            {
                board[i][j] = ' ';
            }
        }
        window.draw(board);
    }

    /**
     * Counts the number of spaces in the upper part of the tetromino object.
     */
    public int upper_space_count()
    {
        int i,j;
        int counter = 0;
        int upper_space = 0;
        for(i=0;i<3;i++)
        {
            for(j=0;j<4;j++)
            {
                if(tetromino_obj.getBlock()[i][j] == ' ')
                {
                    counter++;
                }
            }
            if(counter == 4)
            {
                upper_space++;
            }
            counter = 0;
        }
        return 3-upper_space;
    }

    /**
     * This is the function that prints the board in the terminal.
     */
    public void print_board()
    {
        window.draw(board);
        System.out.print("\033[2J");
        System.out.print("\033[0;0f");
        int i, j;

        for (i = 0; i < column; i++) System.out.print("-");
        System.out.printf("\n");
        for (i = 3; i < row; i++) {
            System.out.print("|");
            for (j = 0; j < column; j++) {
                if (board[i][j] == 'x')
                    System.out.print(tetromino_obj.getBlock_letter());
                else
                    System.out.print(board[i][j]);
            }
            System.out.print("|");
            System.out.println("");
        }
        for (i = 0; i < column; i++)  System.out.print("-");
        System.out.println("");
    }

    /**
     * Sets the tetromino object in the Tetris object to the given block type.
     */
    public void set_last_block(char block_type)
    {
        tetromino_obj.setData(block_type);

    }

    /**
     * Moves the tetromino object to the right.
     * if the tetromino object can not fit in the board, the game is over.
     */
    public void move_right()
    {
        int i,j;
        int upper_count = upper_space_count();
        int shift_down = tetromino_obj.getShift_down();
        int shift_right = tetromino_obj.getShift_right();
        tetromino_obj.set_shift_right(tetromino_obj.getShift_right()+1);
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(board[upper_count+i+shift_down][j+shift_right] == ' ')
                {
                    board[upper_count+i+shift_down][j+shift_right] = tetromino_obj.getBlock()[i][j];
                }
                /*else if(tetromino_obj.getBlock()[i][j] != ' ')
                {
                    System.out.println("Game Over");
                    System.exit(0);
                }*/
            }
        }

        print_board();

        /*DELETING PART*/
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(board[i][j] == 'x')
                    board[i][j] = ' ';
            }
        }
    }
    /**
    * Moves the tetromino object to the left.
    * if the tetromino object can not fit in the board, the game is over.
    */
    public void move_left()
    {
        tetromino_obj.set_shift_right(tetromino_obj.getShift_right()-1);
        int i,j;
        int upper_count = upper_space_count();
        int shift_down = tetromino_obj.getShift_down();
        int shift_right = tetromino_obj.getShift_right();
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(board[upper_count+shift_down+i][shift_right+j] == ' ')
                {
                    board[upper_count+shift_down+i][shift_right+j] = tetromino_obj.getBlock()[i][j];
                }

                /*else if(tetromino_obj.getBlock()[i][j] != ' ')
                {
                    System.out.println("Game Over");
                    System.exit(0);
                }*/
            }
        }

        print_board();

        /*DELETING PART*/
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(board[i][j] == 'x')
                    board[i][j] = ' ';
            }
        }
    }

    /**
     * This function moves the tetromino object down.
     */
    public void move_down()
    {
        int i,j;
        int shift_right = tetromino_obj.getShift_right();
        int shift_down = tetromino_obj.getShift_down();

        if(cakisma_kontrol(tetromino_obj.getShift_right(), tetromino_obj.getShift_down()+1) == true)
        {
            tetromino_obj.setShift_down(tetromino_obj.getShift_down()+1);
            for(i=0;i<row;i++)
            {
                for(j=0;j<column;j++)
                {
                    if(board[i][j] == 'x')
                        board[i][j] = ' '; /*xs are deleted*/
                }
            }

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(board[i+shift_down+1][j+shift_right] == ' ')
                        board[i+shift_down+1][j+shift_right] = tetromino_obj.getBlock()[i][j];
                }
            }
            print_board();
        }
        else final_merge();
    }

    /**
     * This function checks if the tetromino object collides with the board or another tetromino object.
     */
    public boolean cakisma_kontrol(int shift_right, int shift_down)
    {
        int i,j;
        if(shift_down+3>=row || shift_right+3>=column)
        {
            return false;
        }
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
            {
                if(!(board[i+shift_down][j+shift_right] == ' ' || board[i+shift_down][j+shift_right] == 'x' || tetromino_obj.getBlock()[i][j] == ' '))
                {   /*it collides*/
                    return false;
                }
            }
        }
        return true;
    }

    /**f
     * This function turns the x's in the board to the block letter.
     */
    public void final_merge() /*turning xs to block letter*/
    {
        int i,j;
        for(i=0;i<row;i++)
        {
            for(j=0;j<column;j++)
            {
                if(board[i][j] == 'x') board[i][j] = tetromino_obj.getBlock_letter();
            }
        }
        flagNextTetromino = true;
        clear_line();
    }
    /**
    *Clears the last line if the line is full
    */
    public boolean clear_line()
    {
        int i,j,k, counter = 0;
        for(k=0;k<row;k++)
        {
            counter = 0;
            for (i = 0; i < column - 2; i++)
            {
                if (board[row - 1][i] != ' ') counter++;
            }
            if(counter == 10)
            {
                for(i=k;i>2;i--)
                {
                    board[i] = board[i-1];
                }
                return true;
            }
        }

        return false;
    }
    /**
    *Starts the game loop
     */
    public void game()
    {
        while (!flagGameStart) {
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
        Random rand = new Random();
        int randomNum;
        while(!flagGameOver)
        {
            randomNum = rand.nextInt(7);
            if(randomNum == 0) tetromino_obj.setData('I');
            else if (randomNum == 1) tetromino_obj.setData('O');
            else if (randomNum == 2) tetromino_obj.setData('T');
            else if (randomNum == 3) tetromino_obj.setData('J');
            else if (randomNum == 4) tetromino_obj.setData('L');
            else if (randomNum == 5) tetromino_obj.setData('S');
            else if (randomNum == 6) tetromino_obj.setData('Z');

            while (!flagNextTetromino && !flagGameOver)
            {
                try {
                    Thread.sleep(500);
                } catch (Exception e) {
                    e.printStackTrace();
                }
                move_down();
            }
            flagNextTetromino = false;
        }
        flagNextTetromino = false;
    }
    /**
    *Rotates the last Tetromino in the Tetris board
     */
    public void rotate(char dir)
    {
        tetromino_obj.rotate(dir);
    }

}
