#include "ListNodeExercise.h"

ListNodeExercise::ListNodeExercise() {
	pNext = nullptr;
}

void ListNodeExercise::setNextPointer(ListNodeExercise* newPointer) {
	this->pNext = newPointer;
}

ListNodeExercise* ListNodeExercise::getNextPointer() {
	return this->pNext;
}

void ListNodeExercise::setData(ExercisePlan ep) {
	this->ep = ep;
}
ExercisePlan ListNodeExercise::getData() {
	return ep;
}