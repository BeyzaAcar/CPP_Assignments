all : clean clear compile run


compile : driver.o
	@g++ driver.o -lm -o driver.out
	
driver.o :
	@g++ -g -std=c++11 -c driver.cpp -o driver.o
	
run :
	@./driver.out
	
	
clean :
	@rm -f *.out
	@rm -f *.o

clear : 
	@clear

