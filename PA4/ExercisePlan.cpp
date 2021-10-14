#include "ExercisePlan.h"

ExercisePlan::ExercisePlan() {
	goal_steps = 0;
	plan_name = "";
	date = "";
}

ExercisePlan::~ExercisePlan() {
}

ExercisePlan::ExercisePlan(const ExercisePlan& dp) {
	goal_steps = dp.getGoalSteps();
	plan_name = dp.getPlanName();
	date = dp.getDate();
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

int ExercisePlan::getGoalSteps() const{
	return goal_steps;
}

string ExercisePlan::getPlanName() const {
	return plan_name;
}

string ExercisePlan::getDate() const {
	return date;
}

ostream& operator << (ostream& out, ExercisePlan& d) {
	out << d.getPlanName() << endl;
	out << d.getGoalSteps() << endl;
	out << d.getDate() << endl;
	return out;
}

fstream& operator << (fstream& out, ExercisePlan& d) {
	out << d.getPlanName() << endl;
	out << d.getGoalSteps() << endl;
	out << d.getDate() << endl;
	return out;
}

fstream& operator >> (fstream& in, ExercisePlan& d) {
	int goal_calories = 100;
	string plan_name = "";
	string date = "";

	in >> plan_name;
	in >> goal_calories;
	in >> date;

	d.setPlanName(plan_name);
	d.editGoal(goal_calories);
	d.setDate(date);

	return in;
}