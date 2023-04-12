import java.util.Random;

/**
 * Tests the functions by generating random inputs without any user action.
 *  @author BeyzaAcar
 */

public class Driver1
{
    public static void main(String[] args)
    {
        Random rand = new Random();
        int random_num;
        System.out.printf("the row of the tetris board is %d\n", 10);
        System.out.printf("the column of the tetris board is %d\n", 10);
        Tetris tetrisObj = new Tetris(20, 20);
        System.out.println("random tetromino is going to add to the board ..:");
        int i = 0;
        while(i!=5)
        {
            System.out.printf("");
            random_num = rand.nextInt(7);
            char block_Type = 0;
            if(random_num == 0) block_Type = 'O';
            else if(random_num == 1) block_Type = 'L';
            else if(random_num == 2) block_Type = 'S';
            else if(random_num == 3) block_Type = 'Z';
            else if(random_num == 4) block_Type = 'T';
            else if(random_num == 5) block_Type = 'J';
            else if(random_num == 6) block_Type = 'I';

            tetrisObj.set_last_block(block_Type);
            tetrisObj.animate();
            i++;
        }
    }
}
