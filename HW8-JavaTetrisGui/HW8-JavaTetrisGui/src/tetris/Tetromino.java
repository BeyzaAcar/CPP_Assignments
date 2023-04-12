package tetris;

/**
 * Class for Tetromino blocks
 * @author BeyzaAcar
 */


public class Tetromino {
    private char[][] block;
    private char block_letter;
    private int shift_right;
    private int shift_down;

    public Tetromino()
    {
        block = new char[4][4];
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                block[i][j] = ' ';
            }
        }
    }

    /*
    public Tetromino(Tetromino obj)
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                block[i][j] = obj.getBlock()[i][j];
            }
        }
    }
    */

    /**
     * getter for block_letter
     * @return block_letter
     */
    public char getBlock_letter()
    {
        return block_letter;
    }

    /**
     * Changes the block according to the block_type
     * @param block_type type of the tetromino block
     */
    public void setData(char block_type) {
        shift_right = 0;
        shift_down = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                block[i][j] = ' ';
            }
        }
        block_letter = block_type;

        if(block_type == 'I')
        {
            block[0][0] = 'x';
            block[0][1] = 'x';
            block[0][2] = 'x';
            block[0][3] = 'x';
        }
        else if(block_type == 'O')
        {
            block[2][0] = 'x';
            block[2][1] = 'x';
            block[3][0] = 'x';
            block[3][1] = 'x';
        }
        else if(block_type == 'T')
        {
            block[2][0] = 'x';
            block[2][1] = 'x';
            block[2][2] = 'x';
            block[3][1] = 'x';
        }
        else if(block_type == 'J')
        {
            block[1][1] = 'x';
            block[2][1] = 'x';
            block[3][0] = 'x';
            block[3][1] = 'x';
        }
        else if(block_type == 'L')
        {
            block[1][0] = 'x';
            block[2][0] = 'x';
            block[3][0] = 'x';
            block[3][1] = 'x';
        }
        else if(block_type == 'S')
        {
            block[2][1] = 'x';
            block[2][2] = 'x';
            block[3][0] = 'x';
            block[3][1] = 'x';
        }
        else if(block_type == 'Z')
        {
            block[2][0] = 'x';
            block[2][1] = 'x';
            block[3][1] = 'x';
            block[3][2] = 'x';
        }
        System.out.println("set datadansonra blok : ");
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<4;j++)
            {
                System.out.print(block[i][j]);
            }
            System.out.println();
        }

    }
    /**
    *Sets the shift_right value
     */
    public void set_shift_right(int shift_right)
    {
        this.shift_right = shift_right;
    }

    /**
    *Allows us to access the shift_right variable.
     */
    public int  getShift_right()
    {
        return shift_right;
    }

    /**
     *Sets the shift_down value
     */
    public void setShift_down(int shift_down)
    {
        this.shift_down = shift_down;
    }

    /**
     *Allows us to access the shift_right variable.
     */
    public int getShift_down()
    {
        return shift_down;
    }
    
    /**
     * Moves the tetromino piece to the lower left corner of its own matrix.(4*4)
     */
    public boolean boslukSilme()
    {
        int flag1 = 0, flag2 = 0;
        int i;
        int j;
        for (i = 0; i < 4; i++)
        {
            if (block[i][0] == ' ') flag1++; /*leftside space*/
            if (block[3][i] == ' ') flag2++; /*downside space*/
        }
        if (flag2 == 4)
        {
            /*shifts down the block*/
            block[3] = block[2];
            block[2] = block[1];
            block[1] = block[0];
            block[0] = new char[]{' ', ' ', ' ', ' '};
            return true;
        }
        if (flag1 == 4)
        {
            for (i = 0; i < 4; i++)
            {
                for (j = 0; j < 3; j++)
                    block[i][j] = block[i][j + 1];
                block[i][3] = ' ';
            }
            return true;
        }
        return false;
    }

    /**
     * Rotates the tetromino block randomly
     */
    public void rotate(char dir)
    {
        char[][] temp_block = new char[4][4];
        int i,j,k;
        int dir_count = 1;
        if(dir == 'l') dir_count = 3;
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
        while(boslukSilme() == true);
    }

    /**
     * getter for block
     * @return block as a char matrix
     */
    public char[][] getBlock() {
        return block;
    }
}