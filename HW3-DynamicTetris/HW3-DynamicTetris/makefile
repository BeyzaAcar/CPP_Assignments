all: clear clean compile1 link1 second clean compile2 link2 first

clear:
	@clear

compile1: driver2.cpp tetromino.cpp tetris.cpp tetromino.hpp tetris.hpp
	@g++ -c tetromino.cpp -o tetromino.o -std=c++11
	@g++ -c tetris.cpp -o tetris.o -std=c++11
	@g++ -c driver2.cpp -o driver2.o -std=c++11

link1: driver2.o tetromino.o tetris.o
	@g++ driver2.o tetromino.o tetris.o -o driver2.out

second:	compile1 link1
	@./driver2.out
	

clean:

	@rm -f *.o
	@rm -f *.out
	@rm -f *.exe
	

compile2: driver1.cpp tetromino.cpp tetris.cpp tetromino.hpp tetris.hpp
	@g++ -c tetromino.cpp -o tetromino.o -std=c++11
	@g++ -c tetris.cpp -o tetris.o -std=c++11
	@g++ -c driver1.cpp -o driver1.o -std=c++11

link2: driver1.o tetromino.o tetris.o
	@g++ driver1.o tetromino.o tetris.o -o driver1.out

first:	compile2 link2
	@./driver1.out
	
