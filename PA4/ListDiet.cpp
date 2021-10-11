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

bool ListDiet::isEmpty() {
	return this->pHead == NULL;
}