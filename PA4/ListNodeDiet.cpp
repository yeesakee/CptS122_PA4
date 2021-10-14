#include "ListNodeDiet.h"

ListNodeDiet::ListNodeDiet() {
	pNext = nullptr;
}

ListNodeDiet::~ListNodeDiet() {
	dp.~DietPlan();
	pNext = nullptr;
	delete(pNext);
}

ListNodeDiet::ListNodeDiet(const ListNodeDiet& lnd) {
	this->dp = lnd.getData();
	this->pNext = lnd.getNextPointer();
}

void ListNodeDiet::setNextPointer(ListNodeDiet* newPointer) {
	this->pNext = newPointer;
}

ListNodeDiet* ListNodeDiet::getNextPointer() const{
	return this->pNext;
}

void ListNodeDiet::setData(DietPlan dp) {
	this->dp = dp;
}
DietPlan ListNodeDiet::getData() const{
	return dp;
}