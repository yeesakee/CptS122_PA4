#ifndef LISTNODEDIET_H
#define LISTNODEDIET_H

#include <string>
#include "DietPlan.h"

using std::string;

class ListNodeDiet {
public:
	ListNodeDiet();

	void setPointer(ListNodeDiet* const newPointer);
	ListNodeDiet* getNextPointer();
	void setData(DietPlan data);
	DietPlan getData();

private:
	DietPlan dp;
	ListNodeDiet* pNext;
};

#endif