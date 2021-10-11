#include "DietPlan.h"

DietPlan::DietPlan(){
	goal_calories = 0;
	plan_name = "";
	date = "";
}

DietPlan::~DietPlan() {
}

void DietPlan::editGoal(int calories) {

	goal_calories = calories;
}

void DietPlan::setPlanName(string name) {
	plan_name = name;
}

void DietPlan::setDate(string date) {
	this->date = date;
}

int DietPlan::getGoalCalories() {
	return goal_calories;
}

string DietPlan::getPlanName() {
	return plan_name;
}

string DietPlan::getDate() {
	return date;
}
