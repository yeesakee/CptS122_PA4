#include "ListNodeExercise.h"

ListNodeExercise::ListNodeExercise() {
	pNext = nullptr;
}

ListNodeExercise::~ListNodeExercise() {
	ep.~ExercisePlan();
	pNext = nullptr;
	delete(pNext);
}

ListNodeExercise::ListNodeExercise(const ListNodeExercise& lnd) {
	this->ep = lnd.getData();
	this->pNext = lnd.getNextPointer();
}

void ListNodeExercise::setNextPointer(ListNodeExercise* newPointer) {
	this->pNext = newPointer;
}

ListNodeExercise* ListNodeExercise::getNextPointer() const{
	return this->pNext;
}

void ListNodeExercise::setData(ExercisePlan ep) {
	this->ep = ep;
}
ExercisePlan ListNodeExercise::getData() const{
	return ep;
}