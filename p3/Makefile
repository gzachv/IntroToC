# Example Makefile for Programming Assignment 3

runMain: main.o SortedList.o Student.o
	g++ -g main.o SortedList.o Student.o -o runMain
	
runDB: SortedList.o Student.o driver.o
	g++ -g SortedList.o Student.o driver.o -o runDB

Student.o: Student.cpp Student.h
	g++ -g -c Student.cpp

SortedList.o: SortedList.cpp SortedList.h Student.h
	g++ -g -c SortedList.cpp
	
driver.o: driver.cpp
	g++ -c -g driver.cpp

valgrind: runMain
	valgrind --leak-check=full runMain

clean:
	rm *.o
