#include "FitnessAppWrapper.h"

int main(){
	FitnessAppWrapper faw;
	fstream f("dietPlan.txt");
	faw.runApp();
}