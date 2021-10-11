#include "ListNodeDiet.h"

ListNodeDiet::ListNodeDiet() {
	dp = DietPlan();
	pNext = nullptr;
}

void ListNodeDiet::setPointer(ListNodeDiet* const newPointer) {
	this->pNext = newPointer;
}

ListNodeDiet* ListNodeDiet::getNextPointer() {
	return this->pNext;
}

void ListNodeDiet::setData(DietPlan dp) {
	this->dp = dp;
}
DietPlan ListNodeDiet::getData() {
	return dp;
}