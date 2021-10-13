#include "ListExercise.h"

ListExercise::ListExercise() {
	pHead = nullptr;
	pTail = nullptr;
}

ListExercise::~ListExercise() {
	while (!isEmpty()) {
		ListNodeDiet* temp = pHead;
		pHead = pHead->getNextPointer();
		delete(temp);
	}
}

ListNodeDiet* ListExercise::getpHead() {
	return pHead;
}

ListNodeDiet* ListExercise::getpTail() {
	return pTail;
}

bool ListExercise::isEmpty() {
	return this->pHead == NULL;
}

void ListExercise::insert(ListNodeExercise* newNode) {
	if (isEmpty()) {
		pHead = newNode;
	}
	else {
		pTail->setNextPointer(newNode);
	}
	pTail = newNode;
}

ListNodeExercise* ListExercise::searchExercisePlan(string plan_name) {
	ListNodeExercise* curr = pHead;
	while (curr != nullptr) {
		if (curr->getData().getPlanName().compare(plan_name) == 0) {
			return curr;
		}
		curr = curr->getNextPointer();
	}
	return nullptr;
}