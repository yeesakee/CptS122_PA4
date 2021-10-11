#include "DietPlan.h"

DietPlan::DietPlan(){
	goal_calories = 0;
	plan_name = "";
	date = "";
}

DietPlan::~DietPlan() {
}

DietPlan::DietPlan(const DietPlan& dp) {
	goal_calories = dp.goal_calories;
	plan_name = dp.plan_name;
	date = dp.date;
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

ostream& operator << (ostream& out, DietPlan& d) {
	out << d.getPlanName() << endl;
	out << d.getGoalCalories() << endl;
	out << d.getDate() << endl;
	out << endl;
}

istream& operator >> (istream& in, DietPlan& d) {
	int goal_calories = 0;
	string plan_name = "";
	string date = "";

	std::getline(in, plan_name);
	in >> goal_calories;
	in >> date;
	in.ignore('\n');

	d.setPlanName(plan_name);
	d.editGoal(goal_calories);
	d.setDate(date);
}