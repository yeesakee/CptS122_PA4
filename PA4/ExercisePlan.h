#ifndef EXERCISEPLAN_H
#define EXERCISEPLAN_H

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using namespace std;

class ExercisePlan {
public:
	ExercisePlan();
	~ExercisePlan();
	ExercisePlan(const ExercisePlan& dp);

	void editGoal(int calores);
	void setPlanName(string name);
	void setDate(string date);

	int getGoalSteps();
	string getPlanName();
	string getDate();

private:
	int goal_steps;
	string plan_name;
	string date;
};
#endif EXERCISEPLAN_H

// Overloaded stream insertion << to display to the screen
// Will insert the plan name, goal calories, and date from DietPlan& d.
ostream& operator << (ostream& out, ExercisePlan& d);

// Overloaded stream insertion << writing to a file
// Will insert the plan name, goal calories, and date from DietPlan& d.
fstream& operator << (fstream& out, ExercisePlan& d);

// Overloaded stream extraction << to read a plan from a file
// Will insert the plan name, goal calories, and date into DietPlan& d from the file
fstream& operator >> (fstream& in, ExercisePlan& d);