all: clean clear compile run

clean:
	@rm -f *.out
	@rm -f *.o

clear:
	@clear

compile: main.o Tetromino.o
	@g++ main.o Tetromino.o -lm -o main.out

run:
	./main.out

main.o:
	@g++ -c main.cpp -o main.o

Tetromino.o:
	@g++ -c Tetromino.cpp -o Tetromino.o