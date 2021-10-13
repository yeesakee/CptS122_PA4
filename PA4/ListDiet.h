#ifndef LISTDIET_H
#define LISTDIET_H

#include <string>
#include <iostream>
#include "ListNodeDiet.h"

using std::string;

class ListDiet {
public:
	ListDiet();
	~ListDiet();

	ListNodeDiet* getpHead();
	ListNodeDiet* getpTail();

	bool isEmpty();
	void insert(ListNodeDiet* newNode);
	// searches the list to see if there is a diet plan with the plan name plan_name
	// return a pointer to the ListNodeDiet
	ListNodeDiet* searchDietPlan(string plan_name);

private:
	ListNodeDiet* pHead;
	ListNodeDiet* pTail;
};
#endif