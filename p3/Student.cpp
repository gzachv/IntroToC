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

#include <iostream>
#include "Student.h"

using namespace std;

/*
 * Student implemented class
 *
 * A Student object contains a student ID, the number of credits, and an
 * overall GPA.
 */

//Constructors:
// Constructs a default student with an ID of 0, 0 credits, and 0.0 GPA.
Student::Student(){
	GPA = 0;
	credits = 0;
	studentID = 0;
}

// Constructs a student with the given ID, 0 credits, and 0.0 GPA.
Student::Student(int ID){
	GPA = 0;
	credits = 0;
	studentID = ID;
}

// Constructs a student with the given ID, number of credits, and GPA.
Student::Student(int ID, int cr, double grPtAv){
	GPA = grPtAv;
	credits = cr;
	studentID = ID;
}

// Copy Constructor
Student::Student(const Student &s) :
		GPA(s.GPA), credits(s.credits), studentID(s.studentID)
{

}

// destructor
Student::~Student(){

}

// operator =
Student& Student::operator =(const Student &s){

	if(this == &s){
		return *this;
	}

	else{

		GPA = s.GPA;
		credits = s.credits;
		studentID = s.studentID;
	}

	return *this;
}

//Accessors:
// returns the student ID
int Student::getID() const{
	return studentID;
}

// returns the number of credits
int Student::getCredits() const{
	return credits;
}

// returns the GPA
double Student::getGPA() const{
	return GPA;
}

/**
 *Helper method that computes the integer grade point equivalent to a
 * given letter grade (grade).
 *
 * @param (grade) grade in the class the student recently took
 * @return the integer value corresponding to a letter grade.
 */
int grade2num(char grade){
	int grVal;

	switch(grade){
	case 'A':
		grVal = 4;
		break;

	case 'B':
		grVal = 3;
		break;

	case 'C':
		grVal = 2;
		break;

	case 'D':
		grVal = 1;
		break;

	case 'F':
		grVal = 0;
		break;

	default:
		cout << "ERROR: please retry student update with a grade letter"
		" (A,B,C,D or F)" << endl;
		grVal = -1;
		break;
	}

	return grVal;

}


/**
 * Updates the total credits and overall GPA to take into account the
* additions of the given letter grade in a course with the given number
* of credits.  The update is done by first converting the letter grade
* into a numeric value (A = 4.0, B = 3.0, etc.).  The new GPA is
* calculated using the formula:
*
*            (oldGPA * old_total_credits) + (numeric_grade * cr)
*   newGPA = ---------------------------------------------------
*                        old_total_credits + cr
*
* Finally, the total credits is updated (to old_total_credits + cr)
*
* @param (grade)  grade in the class the student recently took
* @param (cr) credits of class the student recently took
*/
void Student::update(char grade, int cr){

	grade = toupper(grade); //accept both lower and upper case letter grade

	//grVal will contain number equivalent value of grade
	int grVal = grade2num(grade);

	// if the grade entered is not recognized
	if(grVal == -1){ return;}

	// update the GPA with new class
	GPA = ((GPA*credits) + grVal*cr)/(credits + cr);

	// update total credits
	credits = credits + cr;
}

// Prints out the student to standard output in the format:
//   ID,credits,GPA
// Note: the end-of-line is NOT printed after the student information
void Student::print() const{
	cout << studentID << ", " << credits << ", " << GPA;
}



