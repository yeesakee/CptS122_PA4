/*
Yeesa Kee
CPTS 122
Lab 4
Represents a weekly exercise plan using ListNodeExercise pointers.
Keeps track of the weekly plan by storing the pHead and pTail pointers
to the linked list. Contains methods that allow the user to modify and search
the linked list.
*/
#ifndef LISTEXERCISE_H
#define LISTEXERCISE_H

#include <string>
#include <iostream>
#include "ListNodeExercise.h"

using std::string;

// ListExercise class that represents a linked list with a weekly exercise plan
// Stores the ListNodeExercise* head and tail pointers of the linked list
class ListExercise {
public:
	// ListExercise constructor
	ListExercise();
	// ListExercise deconstructor
	~ListExercise();
	// ListExercise copy constructor
	ListExercise(const ListExercise& list_exercise);

	// returns the pointer ListNodeDiet pHead
	ListNodeExercise* getpHead() const;
	// returns the pointer ListNodeDiet pTail
	ListNodeExercise* getpTail() const;

	// returns true if ListExercise is empty, false otherwise
	bool isEmpty();
	// inserts the given newNode to the end of the linked list
	void insert(ListNodeExercise* newNode);
	// searches the list to see if there is a diet plan with the plan name plan_name
	// return a pointer to the ListNodeDiet
	ListNodeExercise* searchExercisePlan(string plan_name);

private:
	ListNodeExercise* pHead;
	ListNodeExercise* pTail;
};
#endif