package tetris;

/**
 * Tests the functions by user input and runs the game function to start the Tetris game.
 *  @author BeyzaAcar
 */

public class Driver1
{

    public static Tetris tetrisObj;

    public static void main(String[] args)
    {
        tetrisObj = new Tetris(23, 12);
        System.out.println("random tetromino is going to add to the board ..:");
        while(true)
        {
            tetrisObj.game();
        }
    }
}
