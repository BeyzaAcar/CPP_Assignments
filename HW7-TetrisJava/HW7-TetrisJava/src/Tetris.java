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

    public Tetris(int row, int column)
    {
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
        try {
            Thread.sleep(500);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }

    /**
     * Sets the tetromino object in the Tetris object to the given block type.
     */
    public void set_last_block(char block_type)
    {
        tetromino_obj.setData(block_type);

    }

    /**
     * This function animates the tetromino object in the board by calling the move_right and move_down methods.
     */
    public void animate()
    {
        Random rand = new Random();
        int shift_right = rand.nextInt(column-5);
        move_right(shift_right);
        move_down(shift_right);
    }

    /**
     * This function moves the tetromino object to the right.
     * if the tetromino object can not fit in the board, the game is over.
     */
    public void move_right(int shift_right)
    {
        int i,j,k;
        int upper_count = upper_space_count();
        for(k=0;k<=shift_right;k++)
        {
            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(board[upper_count+i][j+k] == ' ')
                    {
                        board[upper_count+i][j + k] = tetromino_obj.getBlock()[i][j];
                    }

                    else if(tetromino_obj.getBlock()[i][j] != ' ')
                    {
                        System.out.println("Game Over");
                        System.exit(0);
                    }
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
    }

    /**
     * This function moves the tetromino object down.
     */
    public void move_down(int shift_right)
    {
        int i,j;
        int shift_down = 0;
        while(cakisma_kontrol(shift_right, shift_down+1) == true)
        {
            for(i=0;i<row;i++)
            {
                for(j=0;j<column;j++)
                {
                    if(board[i][j] == 'x')
                        board[i][j] = ' '; /*xs are deleted*/
                }
            }

            shift_down++;

            for(i=0;i<4;i++)
            {
                for(j=0;j<4;j++)
                {
                    if(board[i+shift_down][j+shift_right] == ' ')
                        board[i+shift_down][j+shift_right] = tetromino_obj.getBlock()[i][j];
                }

            }
            print_board();
            //sleep(1);
        }
        final_merge();
    }

    /**
     * This function checks if the tetromino object collides with the board or another tetromino object.
     */
    public boolean cakisma_kontrol(int shift_right, int shift_down)
    {
        int i,j;
        if(shift_down+3>=row || shift_right+3>=column) return false;
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
    }

}
