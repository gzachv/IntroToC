/*
 * driver.cpp
 *
 *  Created on: Oct 13, 2013
 *      Author: gzach
 */



#include <iostream>
#include "Student.h"
#include "SortedList.h"

using namespace std;

/**
 * Check if the given student ID is within valid range:
 * Positive six digit number, first digit is not 0
 *
 * @param (ID) the student ID of the student to be added
 * @return integer 0 if input is valid, 1 if input is not valid
 */
int checkID(int ID) {

	if(ID < 0){
		cout << "ERROR: student ID must be a non-negative int" << endl;
		return 1;
	}

	if(ID > 999999 | ID < 100000){
		cout << "ERROR: student ID must be a six digit number. "
				"The first digit of which can not be 0." << endl;
		return 1;
	}

	return 0;
}

/**
 * Check if the given credit number is within valid range:
 * Positive integer
 *
 * Check if the given GPA is valid: double 0.0 - 4.0 inclusive
 *
 * @param (credits) total credits taken my a student
 * @param (GPA) grade point avg of student
 * @return integer 0 if input is valid, 1 if input is not valid
 */
int checkCrtsGPA(char credits, double GPA) {

	if(credits < 0){
		cout << "ERROR: credits must be a non-negative integer" << endl;
		return 1;
	}

	if(GPA < 0.0 | GPA > 4.0){
		cout << "ERROR: GPA must be between 0.0 - 4.0 (inclusive)" << endl;
		return 1;
	}

	return 0;
}

int main(){

	Student* sptr = new Student();




	SortedList* list = new SortedList();


	bool done = false;
	char choice;
	int studentID;
	int credits;
	double GPA;
	char grade;


	cout << "Enter your commands at the > prompt:" << endl;
	while (!done) {
		cout << "> ";
		cin >> choice;

		switch (choice) {

		case 'a':
			cin >> studentID >> credits >> GPA;

			//check if all input is valid. If not, break
			if(checkID(studentID) == 1){
				break;
			}
			if(checkCrtsGPA(credits, GPA) == 1){
				break;
			}

			//if input is valid, add the student with given params
			sptr = new Student(studentID, credits, GPA);
			list->insert(sptr);
			break;

		case 'd':
			cin >> studentID;  // read in the integer ID

			//check if all input is valid. If not, break
			if(checkID(studentID) == 1){
				break;
			}

			list->remove(studentID);
			break;

		case 'u':
			cin >> studentID >> grade >> credits;

			//check if all input is valid. If not, break
			if(checkID(studentID) == 1){
				break;
			}
			if(checkCrtsGPA(credits, GPA) == 1){
				break;
			}


			sptr = list->find(studentID);
			sptr->update(grade, credits);
			break;

		case 'p':
			list->print();
			break;

		case 'q':
			done = true;
			cout << "quit" << endl;
			break;

			// If the command is not one listed in the specification, for the
			// purposes of this assignment, we will ignore it.  Note that you
			// will see multiple ?'s printed out if there is additional
			// information on the line (in addition to the unknown command
			// character).
		default: break;
		} // end switch

	} // end while

	return 0;
}// end main
