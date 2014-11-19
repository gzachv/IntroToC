runDB: SortedList.o Student.o driver.o
	g++ -g SortedList.o Student.o driver.o -o runDB

SortedList.o: SortedList.cpp SortedList.h
	g++ -c SortedList.cpp -g

Student.o: Student.cpp Student.h
	g++ -c Student.cpp -g

driver.o: driver.cpp
	g++ -c -g driver.cpp

clean:
	rm *.o
