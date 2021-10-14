/*
Yeesa Kee
CPTS 122
Lab 4
Represents a daily diet plan. Stores the DietPlan dp of the plan and the ListNodeDiet*
that stores the pointer to the next diet plan.
User can use setter and getter methods to modify ListNodeDiet.
*/
#ifndef LISTNODEDIET_H
#define LISTNODEDIET_H

#include <string>
#include "DietPlan.h"

using std::string;

// ListNodeDiet class that represents a single node storing a daily diet plan dp
class ListNodeDiet {
public:
	// ListNodeDiet constructor
	ListNodeDiet();
	// ListNodeDiet deconstructor
	~ListNodeDiet();
	// ListNodeDiet copy constructor
	ListNodeDiet(const ListNodeDiet& lnd);

	// takes a given newPointer and set pNext to newPointer
	void setNextPointer(ListNodeDiet* const newPointer);
	// returns a pointer pNext
	ListNodeDiet* getNextPointer() const;
	// takes a given DietPlan data and set dp to data
	void setData(DietPlan data);
	// returns the DietPlan dp
	DietPlan getData() const;

private:
	DietPlan dp;
	ListNodeDiet* pNext;
};

#endif