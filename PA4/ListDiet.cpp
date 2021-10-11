#include "ListDiet.h"

ListDiet::ListDiet() {
	pHead = NULL;
	pTail = NULL;
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
	pTail->setNextPointer(newNode);
}