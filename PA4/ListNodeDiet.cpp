#include "ListNodeDiet.h"

ListNodeDiet::ListNodeDiet() {
	pNext = nullptr;
}

void ListNodeDiet::setNextPointer(ListNodeDiet* const newPointer) {
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