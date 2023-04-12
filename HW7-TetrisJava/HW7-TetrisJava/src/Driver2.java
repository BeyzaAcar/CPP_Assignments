import java.util.Scanner;

/**
 *  Runs the tetris game with user inputs.
 * @author BeyzaAcar
 */

public class Driver2
{
    public static void main(String[] args)
    {
        int row, column;
        char block_Type;
        Scanner scan = new Scanner(System.in);
        System.out.println("Please enter the row ..:");
        row = scan.nextInt();
        System.out.println("Please enter the column ..:");
        column = scan.nextInt();
        Tetris tetrisObj = new Tetris(row+3, column+3);
        while(true)
        {
            System.out.println("enter the type of the tetromino you want to add ..:");
            block_Type = scan.next().charAt(0);
            tetrisObj.set_last_block(block_Type);
            tetrisObj.animate();
        }
    }
}



