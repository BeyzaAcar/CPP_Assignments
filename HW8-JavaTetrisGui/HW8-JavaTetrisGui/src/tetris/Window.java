package tetris;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

import static tetris.Driver1.tetrisObj;

/**
 * Creates the window that the game will be played on.
 * @author BeyzaAcar
 */

public class Window extends JFrame{

    private JPanel[] panels;
    private JButton[][] gridButtons;

    /**
     * Game window constructor
     */
    public Window() {
        super("Tetris");

        setFocusable(true);

        addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent e) {
                requestFocus();
            }
        });

        addKeyListener(new KeyListener() {
            public void keyPressed(KeyEvent e) {
                int key = e.getKeyCode();
                System.out.println("Key pressed: " + key);
                if(key == 37) tetrisObj.move_left();
                else if (key == 38) tetrisObj.rotate('l');
                else if (key == 39) tetrisObj.move_right();
                else if (key == 40) tetrisObj.rotate('r');
            }

            public void keyReleased(KeyEvent e) {}

            public void keyTyped(KeyEvent e) {}
        });

        setLayout(new GridLayout(21, 10));
        setSize(500, 1000);
        setResizable(false);
        setLocationRelativeTo(null);
        setVisible(true);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        panels = new JPanel[20];
        gridButtons = new JButton[20][10];

        for(int i = 0; i < 20; i++) {
            gridButtons[i] = new JButton[10];
            JPanel p = new JPanel();
            p.setLayout(new GridLayout(1, 10));
            for(int j = 0; j < 10; j++) {
                JButton b = new JButton();
                b.setBorder(BorderFactory.createBevelBorder(1));
                b.setBackground(Color.white);
                gridButtons[i][j] = b;
                p.add(gridButtons[i][j]);
            }
            panels[i] = p;
            add(p);
        }

        JPanel menuPanel = new JPanel();
        menuPanel.setLayout(new GridLayout(1, 3));
        menuPanel.setBorder(BorderFactory.createBevelBorder(1));

        JButton startButton = new JButton("Start");
        JButton endButton = new JButton("End");
        JButton resetButton = new JButton("Reset");

        startButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                tetrisObj.flagGameStart = true;
                tetrisObj.flagGameOver = false;
            }
        });

        endButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                tetrisObj.flagGameOver = true;
                tetrisObj.flagGameStart = false;
            }
        });

        resetButton.addActionListener(new ActionListener(){
            public void actionPerformed(ActionEvent e){
                tetrisObj.flagGameStart = false;
                tetrisObj.flagGameOver = true;
                try {
                    Thread.sleep(500);
                } catch (InterruptedException ex) {
                    ex.printStackTrace();
                }
                char[][] emptyBoard = new char[23][12];
                for(char[] i: emptyBoard) {
                    i = new char[10];
                }
                draw(emptyBoard);
            }
        });

        menuPanel.add(startButton);
        menuPanel.add(endButton);
        menuPanel.add(resetButton);

        add(menuPanel);
    }

    /**
     * Draws the game grid on the window
     * @param board the board to be drawn as a 2D char array
     */
    public void draw(char board[][]) {
        requestFocus();
        for(int i = 0; i < 20; i++) {
            for(int j = 0; j < 10; j++) {
                if(board[i+3][j] == 'I') gridButtons[i][j].setBackground(Color.blue);
                else if (board[i+3][j] == 'O') gridButtons[i][j].setBackground(Color.green);
                else if (board[i+3][j] == 'T') gridButtons[i][j].setBackground(Color.red);
                else if (board[i+3][j] == 'J') gridButtons[i][j].setBackground(Color.pink);
                else if (board[i+3][j] == 'L') gridButtons[i][j].setBackground(Color.yellow);
                else if (board[i+3][j] == 'S') gridButtons[i][j].setBackground(Color.orange);
                else if (board[i+3][j] == 'Z') gridButtons[i][j].setBackground(Color.black);
                else if (board[i+3][j] == 'x') gridButtons[i][j].setBackground(Color.gray);
                else gridButtons[i][j].setBackground(Color.white);
            }
        }
        validate();
        repaint();
    }

    /*
    public void keyTyped(KeyEvent e) {
        // Invoked when a key has been typed.
    }

    public void keyPressed(KeyEvent e) {
        // Invoked when a key has been pressed.
        if (e.getKeyCode() == KeyEvent.VK_ENTER && yourOtherCondition) {
            myMethod();
        }
    }

    public void keyReleased(KeyEvent e) {
        // Invoked when a key has been released.
    }
    */
}