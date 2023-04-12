all : clear clean compile link run

clear :
	@clear

clean : 
	@rm -f *.o
	@rm -f *.out
	@rm -f *.exe
	
compile :
	@g++ -c DayOfYearSet.cpp -o DayOfYearSet.o -std=c++11
	@g++ -c driver.cpp -o driver.o -std=c++11
	
link : 
	@g++ driver.o DayOfYearSet.o -o driver.out
	
run :
	@./driver.out
	
