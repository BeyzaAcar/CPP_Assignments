all : all1 all2

all1 : clean clear compile1 run1
all2 : clean clear compile2 run2

compile1 : driver1.o Tetromino.o TetrisVector.o AbstractTetris.o Tetris1DArray.o
	@g++ -g driver1.o Tetromino.o TetrisVector.o AbstractTetris.o Tetris1DArray.o -lm -o driver1.out
compile2 : driver2.o Tetromino.o TetrisVector.o AbstractTetris.o Tetris1DArray.o
	@g++ -g driver2.o Tetromino.o TetrisVector.o AbstractTetris.o Tetris1DArray.o -lm -o driver2.out
	
	
driver1.o:
	@g++ -g -std=c++11 -c driver1.cpp -o driver1.o
driver2.o:
	@g++ -g -std=c++11 -c driver2.cpp -o driver2.o


Tetromino.o: Tetromino.hpp
	@g++ -g -std=c++11 -c Tetromino.cpp -o Tetromino.o

TetrisVector.o: TetrisVector.hpp
	@g++ -g -std=c++11 -c TetrisVector.cpp -o TetrisVector.o

AbstractTetris.o: AbstractTetris.hpp
	@g++ -g -std=c++11 -c AbstractTetris.cpp -o AbstractTetris.o

Tetris1DArray.o: Tetris1DArray.hpp
	@g++ -g -std=c++11 -c Tetris1DArray.cpp -o Tetris1DArray.o

run1 :
	@./driver1.out
run2 :
	@./driver2.out

clean :
	@rm -f *.out
	@rm -f *.o
clear :
	@clear
	
	

