#include "ListDiet.h"

ListDiet::ListDiet() {
	pHead = nullptr;
	pTail = nullptr;
}

ListDiet::~ListDiet() {
	while (!isEmpty()) {
		ListNodeDiet* temp = pHead;
		pHead = pHead->getNextPointer();
		delete(temp);
	}
}

ListNodeDiet* ListDiet::getpHead() {
	return pHead;
}

ListNodeDiet* ListDiet::getpTail() {
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