/*
Yeesa Kee
CPTS 122
Lab 4
Represents a weekly diet plan using ListNodeDiet pointers.
Keeps track of the weekly plan by storing the pHead and pTail pointers
to the linked list. Contains methods that allow the user to modify and search
the linked list.
*/
#ifndef LISTDIET_H
#define LISTDIET_H

#include <string>
#include <iostream>
#include "ListNodeDiet.h"

using std::string;

// ListDiet class that represents a linked list with a weekly diet plan
// Stores the ListNodeDiet* head and tail pointers of the linked list
class ListDiet {
public:
	// ListDiet constructor
	ListDiet();
	// ListDiet deconstructor
	~ListDiet();
	// ListDiet copy constructor
	ListDiet(const ListDiet& list_diet);

	// returns the pointer ListNodeDiet pHead
	ListNodeDiet* getpHead() const;
	// returns the pointer ListNodeDiet pTail
	ListNodeDiet* getpTail() const;

	// returns true if ListDiet is empty, false otherwise
	bool isEmpty();
	// inserts the given newNode to the back of the linked list
	void insert(ListNodeDiet* newNode);
	// searches the list to see if there is a diet plan with the plan name plan_name
	// return a pointer to the ListNodeDiet
	ListNodeDiet* searchDietPlan(string plan_name);

private:
	ListNodeDiet* pHead;
	ListNodeDiet* pTail;
};
#endif