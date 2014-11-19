/*******************************************************************************
Author:        Gustavo Zach Vargas
CS Login:      gustavo

Pair Partner:  <name of your pair programming partner (if applicable)>
CS Login:      <your partner's login name>

Credits:       <name of anyone (other than your pair programming partner) who
                helped you write your program>

Course:         CS 368, Fall 2013
Assignment:     Programming Assignment 2
 *******************************************************************************/

#include <iostream>
#include "Student.h"
#include "SortedList.h"

using namespace std;

/*
 * SortedList implemented class
 *
 * A SortedList is an ordered collection of Students.  The Students are ordered
 * from lowest numbered student ID to highest numbered student ID.
 */

// Constructs an empty list.
SortedList::SortedList(){
	head = NULL;
}

// If a student with the same ID is not already in the list, inserts
// the given student into the list in the appropriate place and returns
// true.  If there is already a student in the list with the same ID
// then the list is not changed and false is returned.
bool SortedList::insert(Student *s){

	//if the list is empty, place the student at the top of the list
	if(head == NULL){
		head = new Listnode();
		head->student = s;
		head->next = NULL;
		return true;
	}

	Listnode* curr = head; //current node in execution
	Listnode* prev = NULL; //node previous to curr in iteration through list

	//if the student is smaller than the head
	if(s->getID() < curr->student->getID()){
		head = new Listnode();
		head->student = s;
		head->next = curr;
		return true;
	}

	else{
		while(curr != NULL){


			//if a student with the same id is already in the list, do not add
			if(s->getID() == curr->student->getID()){
				cout << "The student entered is already in the list. "
						"NO INSERT OCCURED";
				return false;
			}

			//if the student to be added is in middle of list
			else if(s->getID() < curr->student->getID()){
				prev->next = new Listnode();
				prev = prev->next;
				prev->student = s;
				prev->next = curr;
				return true;
			}

			//check if end of list has been reached
			else if(curr->next == NULL){
				curr->next = new Listnode();
				curr = curr->next;
				curr->student = s;
				curr->next = NULL;
				return true;
			}

			//increment iterating pointers
			prev = curr;
			curr = curr->next;
		}
	}

	return false;
}


// Searches the list for a student with the given student ID.  If the
// student is found, it is returned; if it is not found, NULL is returned.
Student* SortedList::find(int studentID){

	Listnode* curr = head;

	if(curr == NULL){
		return NULL;
	}

	while(curr != NULL){
		if(curr->student->getID() == studentID){
			return curr->student;
		}

		curr = curr->next;
	}

	return NULL;

}

// Searches the list for a student with the given student ID.  If the
// student is found, the student is removed from the list and returned;
// if no student is found with the given ID, NULL is returned.
// Note that the Student is NOT deleted - it is returned - however,
// the removed list node should be deleted.
Student* SortedList::remove(int studentID){

	Listnode* curr = head;
	Listnode* prev = head;
	Listnode* temp = NULL;
	Student* ret;

	//if the node to be removed is at the top of the list
	if(head->student->getID() == studentID){
		head = curr->next;
		ret = curr->student;
		delete curr;
		curr = NULL;
		return ret;
	}

	while(curr != NULL){
		if(curr->student->getID() == studentID){

			//if list node to be removed is at the end of the list
			if(curr->next == NULL){
				ret = curr->student;
				prev->next = NULL;
				delete curr;
				curr = NULL;
				return ret;
			}

			//list node to be removed is in the middle of list
			else{
				temp = prev->next;
				prev->next = curr->next;
				delete temp;
				temp = NULL;
				return curr->student;
			}

		}

		//increment pointers
		prev = curr;
		curr = curr->next;
	}

	return NULL;
}

// Prints out the list of students to standard output.  The students are
// printed in order of student ID (from smallest to largest), one per line
void SortedList::print() const{

	Listnode* tmp = head;

	while(tmp != NULL){
		tmp->student->print();
		tmp = tmp->next;
	}

}

