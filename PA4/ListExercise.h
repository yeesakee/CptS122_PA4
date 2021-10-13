#ifndef LISTEXERCISE_H
#define LISTEXERCISE_H

#include <string>
#include <iostream>
#include "ListNodeExercise.h"

using std::string;

class ListExercise {
public:
	ListExercise();
	~ListExercise();

	ListNodeExercise* getpHead();
	ListNodeExercise* getpTail();

	bool isEmpty();
	void insert(ListNodeExercise* newNode);
	// searches the list to see if there is a diet plan with the plan name plan_name
	// return a pointer to the ListNodeDiet
	ListNodeExercise* searchExercisePlan(string plan_name);

private:
	ListNodeExercise* pHead;
	ListNodeExercise* pTail;
};
#endif