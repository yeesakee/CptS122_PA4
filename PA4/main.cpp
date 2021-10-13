#include "FitnessAppWrapper.h"

int main(){
	FitnessAppWrapper faw;
	fstream f("dietPlan.txt");
	faw.methodChosen(1);
	//faw.methodChosen(5);
	faw.methodChosen(7);
}