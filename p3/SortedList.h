#ifndef SORTEDLIST_H
#define SORTEDLIST_H

#include "Student.h"

/*
 * SortedList class
 *
 * A SortedList is an ordered collection of Students.  The Students are ordered
 * from lowest numbered student ID to highest numbered student ID.
 */
class SortedList {

  public:

    SortedList();
    // Constructs an empty list.

    //Big 3
    SortedList(const SortedList &L);  			// copy constructor
    ~SortedList();								// destructor
    SortedList & operator=(const SortedList &L);  // assignment

    bool insert(Student *s);
    // If a student with the same ID is not already in the list, inserts
    // the given student into the list in the appropriate place and returns
    // true.  If there is already a student in the list with the same ID
    // then the list is not changed and false is returned.

    Student *find(int studentID);
    // Searches the list for a student with the given student ID.  If the
    // student is found, it is returned; if it is not found, NULL is returned.

    Student *remove(int studentID);
    // Searches the list for a student with the given student ID.  If the
    // student is found, the student is removed from the list and returned;
    // if no student is found with the given ID, NULL is returned.
    // Note that the Student is NOT deleted - it is returned - however,
    // the removed list node should be deleted.

    void print() const;
    // Prints out the list of students to standard output.  The students are
    // printed in order of student ID (from smallest to largest), one per line

  private:

    // Since Listnodes will only be used within the SortedList class,
    // we make it private.
    struct ListNode {
      Student *student;
      ListNode *next;
    };

    ListNode *head; // pointer to first node in the list

    static void freeList (ListNode *L);
    static ListNode *copyList (ListNode *L);

};

#endif
