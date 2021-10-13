#ifndef LISTNODEEXERCISE_H
#define LISTNODEEXERCISE_H

#include <string>
#include "ExercisePlan.h"

using std::string;

class ListNodeExercise {
public:
	ListNodeExercise();

	void setNextPointer(ListNodeExercise* const newPointer);
	ListNodeExercise* getNextPointer();
	void setData(ExercisePlan data);
	ExercisePlan getData();

private:
	ExercisePlan ep;
	ListNodeExercise* pNext;
};

#endif