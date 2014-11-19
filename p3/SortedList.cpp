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

// Frees all nodes in a linked list and returns the nodes to free storage
void SortedList::freeList(ListNode *L){
	if(L == NULL) return;

	ListNode* curr = L->next;

	while(L != NULL){
		delete L->student;
		delete L;
		L = curr;

		if(curr == NULL) return;

		curr = curr->next;
	}

}

SortedList::ListNode* SortedList::copyList(ListNode *L){

	if(L == NULL) return NULL;

	ListNode* copy_head = new ListNode;
	ListNode* curr = copy_head;

	while(L != NULL){
		curr->student = new Student(*(L->student));

		L = L->next;

		if(L != NULL){ //TODO should be able to do this better
			curr->next = new ListNode;
			curr = curr->next;
		}
	}

	return copy_head;
}

// Copy constructor
SortedList::SortedList(const SortedList &L)
{
	head = copyList(L.head);
}

// destructor
SortedList::~SortedList(){
	freeList(head);
}

// operator =
SortedList & SortedList::operator =(const SortedList &L){

	if(this == &L){ //check for self assignment
		return *this;
	}
	else{
		freeList(head); // free old heap memory
		head = copyList(L.head);
	}

	return *this;
}

// If a student with the same ID is not already in the list, inserts
// the given student into the list in the appropriate place and returns
// true.  If there is already a student in the list with the same ID
// then the list is not changed and false is returned.
bool SortedList::insert(Student *s){

	//if the list is empty, place the student at the top of the list
	if(head == NULL){
		head = new ListNode();
		head->student = s;
		head->next = NULL;
		return true;
	}

	ListNode* curr = head; //current node in execution
	ListNode* prev = NULL; //node previous to curr in iteration through list

	//if the student is smaller than the head
	if(s->getID() < curr->student->getID()){
		head = new ListNode();
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
				prev->next = new ListNode();
				prev = prev->next;
				prev->student = s;
				prev->next = curr;
				return true;
			}

			//check if end of list has been reached
			else if(curr->next == NULL){
				curr->next = new ListNode();
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

	ListNode* curr = head;

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

	ListNode* curr = head;
	ListNode* prev = head;
	ListNode* temp = NULL;
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

	ListNode* tmp = head;

	while(tmp != NULL){

		if(tmp->student != NULL){
			tmp->student->print();
		}

		tmp = tmp->next;
	}

}



