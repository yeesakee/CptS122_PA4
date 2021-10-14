#include "ListDiet.h"

ListDiet::ListDiet() {
	pHead = nullptr;
	pTail = nullptr;
}

ListDiet::~ListDiet() {
	ListNodeDiet* prev = pHead;
	while (!isEmpty()) {
		ListNodeDiet* curr = pHead->getNextPointer();
		pHead = curr;
		delete(prev);
		prev = curr;
	}
	pTail = nullptr;
}

ListDiet::ListDiet(const ListDiet& list_diet) {
	this->pHead = list_diet.getpHead();
	this->pTail = list_diet.getpTail();
}

ListNodeDiet* ListDiet::getpHead() const{
	return pHead;
}

ListNodeDiet* ListDiet::getpTail() const{
	return pTail;
}

bool ListDiet::isEmpty() {
	return this->pHead == NULL;
}

void ListDiet::insert(ListNodeDiet* newNode) {
	if (isEmpty()) {
		pHead = newNode;
	}
	else {
		pTail->setNextPointer(newNode);
	}
	pTail = newNode;
}

ListNodeDiet* ListDiet::searchDietPlan(string plan_name) {
	ListNodeDiet* curr = pHead;
	while (curr != nullptr) {
		if (curr->getData().getPlanName().compare(plan_name) == 0) {
			return curr;
		}
		curr = curr->getNextPointer();
	}
	return nullptr;
}