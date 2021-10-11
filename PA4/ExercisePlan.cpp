#include "ExercisePlan.h"

ExercisePlan::ExercisePlan() {
	goal_steps = 0;
	plan_name = "";
	date = "";
}

void ExercisePlan::editGoal(int steps) {
	goal_steps = steps;
}
void ExercisePlan::setPlanName(string name) {
	plan_name = name;
}

void ExercisePlan::setDate(string date) {
	this->date = date;
}

int ExercisePlan::getGoalSteps() {
	return goal_steps;
}

string ExercisePlan::getPlanName() {
	return plan_name;
}

string ExercisePlan::getDate() {
	return date;
}