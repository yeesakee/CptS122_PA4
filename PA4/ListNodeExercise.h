/*
Yeesa Kee
CPTS 122
Lab 4
Represents a daily exercise plan.
Stores the Exercise Plan ep of the plan and the ListNodeExercise*
that stores the pointer to the next exercise plan.
User can use setter and getter methods to modify ListNodeExercise.
*/
#ifndef LISTNODEEXERCISE_H
#define LISTNODEEXERCISE_H

#include <string>
#include "ExercisePlan.h"

using std::string;

// ListNodeExercise class that represents a single node storing a daily exercise plan ep
class ListNodeExercise {
public:
	// ListNodeExercise constructor
	ListNodeExercise();
	// ListNodeExercise deconstructor
	~ListNodeExercise();
	// ListNodeExercise copy constructor
	ListNodeExercise(const ListNodeExercise& lde);

	// takes in a newPointer and sets the pNext pointer to new Pointer
	void setNextPointer(ListNodeExercise* const newPointer);
	// returns the pointer pNext
	ListNodeExercise* getNextPointer() const;
	// takes in an ExercisePlan data and set ep to data
	void setData(ExercisePlan data);
	// returns the ExercisePlan ep
	ExercisePlan getData() const;

private:
	ExercisePlan ep;
	ListNodeExercise* pNext;
};

#endif