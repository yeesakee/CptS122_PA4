/*
Yeesa Kee
CPTS 122
Lab 4
Represents a daily diet plan. Including the goal calories, plan name, and date of the plan.
*/
#ifndef DIETPLAN_H
#define DIETPLAN_H

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using namespace std;

class DietPlan {
public:
	DietPlan();
	~DietPlan();
	DietPlan(const DietPlan& dp);

	void editGoal(int calores);
	void setPlanName(string name);
	void setDate(string date);

	int getGoalCalories();
	string getPlanName();
	string getDate();

private:
	int goal_calories;
	string plan_name;
	string date;
};


#endif DIETPLAN_H

// Overloaded stream insertion << to display to the screen
// Will insert the plan name, goal calories, and date from DietPlan& d.
ostream& operator << (ostream& out, DietPlan& d);

// Overloaded stream insertion << writing to a file
// Will insert the plan name, goal calories, and date from DietPlan& d.
fstream& operator << (fstream& out, DietPlan& d);

// Overloaded stream extraction << to read a plan from a file
// Will insert the plan name, goal calories, and date into DietPlan& d from the file
fstream& operator >> (fstream& in, DietPlan& d);
