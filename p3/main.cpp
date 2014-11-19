/*******************************************************************************
Author:        Gustavo Zach Vargas
CS Login:      gustavo

Pair Partner:  <name of your pair programming partner (if applicable)>
CS Login:      <your partner's login name>

Credits:       <name of anyone (other than your pair programming partner) who
                helped you write your program>

Course:         CS 368, Fall 2013
Assignment:     Programming Assignment 3
*******************************************************************************/

/*
 * The SortedList class and the Student class were both updated to contain the
 * 'big three' (copy constructor, destructor and operator=).
 * The implementation of the big three was not necessary for the student class
 * because a student only contains int and double types. These simple types do
 * not require a more complex version of the big three,other than what is
 * inherently provided in the C++ framework. As a result, the implementation of
 * the big three for the student class is fairly simple, strait forward and
 * unnecessary.
 *
 * when this main method is run utilizing the main method as a driver with the
 * code from program 2 (no big three implementation), the valgrind output is
 * as shown below:
 *
==22294== Memcheck, a memory error detector
==22294== Copyright (C) 2002-2012, and GNU GPL'd, by Julian Seward et al.
==22294== Using Valgrind-3.8.1 and LibVEX; rerun with -h for copyright info
==22294== Command: runMain
==22294==
==22294==
==22294== HEAP SUMMARY:
==22294==     in use at exit: 32 bytes in 2 blocks
==22294==   total heap usage: 7 allocs, 5 frees, 96 bytes allocated
==22294==
==22294== LEAK SUMMARY:
==22294==    definitely lost: 16 bytes in 1 blocks
==22294==    indirectly lost: 16 bytes in 1 blocks
==22294==      possibly lost: 0 bytes in 0 blocks
==22294==    still reachable: 0 bytes in 0 blocks
==22294==         suppressed: 0 bytes in 0 blocks
 *
 * One can immediately note that 32 bytes are lost with this execution.
 * This loss is due to the lack of implementation of a destructor.
 *
 * When this same main method (implemented below) is run using the newly
 * updated code. The result is as follows:
==21851== HEAP SUMMARY:
==21851==     in use at exit: 0 bytes in 0 blocks
==21851==   total heap usage: 19 allocs, 21 frees, 288 bytes allocated
==21851==
==21851== All heap blocks were freed -- no leaks are possible
==21851==
 *
 * This shows that the use of the big three results in the proper
 * deallocation of memory and means that there are not memory leaks.
 *
 */

#include <iostream>
#include "SortedList.h"
#include "Student.h"

using namespace std;

void copyAgain(SortedList L) {
	SortedList Lnew = L;
	Lnew.print();
	L.print();
}

int main() {


	SortedList* L1 = new SortedList();
	SortedList* L2 = new SortedList();

	Student* s1 = new Student(111111,1,1);
	Student* s2 = new Student(222222,2,2);

	Student* s3= new Student();
	*s3 = *s1;

	Student s4(*s3);

	L1->insert(s1);
	L1->insert(s2);

	SortedList L3(*L1);

	*L2 = *L1;

	copyAgain(*L1);
	delete L1;
	delete L2;

	delete s1;
	delete s2;
	delete s3;

	//delete s4;

	cout<<"done"<<endl;

	return 0;
}




