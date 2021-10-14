#include "ListExercise.h"

ListExercise::ListExercise() {
	pHead = nullptr;
	pTail = nullptr;
}

ListExercise::~ListExercise() {
	ListNodeExercise* prev = pHead;
	while (!isEmpty()) {
		ListNodeExercise* curr = pHead->getNextPointer();
		pHead = curr;
		delete(prev);
		prev = curr;
	}
	pTail = nullptr;
}

ListExercise::ListExercise(const ListExercise& list_exercise)
{
	this->pHead = list_exercise.getpHead();
	this->pTail = list_exercise.getpTail();
}

ListNodeExercise* ListExercise::getpHead() const {
	return pHead;
}

ListNodeExercise* ListExercise::getpTail() const {
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