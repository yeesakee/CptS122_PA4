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

// DietPlan class, represents and stores one daily diet plan
class DietPlan {
public:
	// DietPlan constructor
	DietPlan();
	// DietPlan deconstructor
	~DietPlan();
	// DietPlan copy constructor
	DietPlan(const DietPlan& dp);

	// edit the goal_calories to the given calories
	void editGoal(int calores);
	// set the plan name to the given name
	void setPlanName(string name);
	// set the date to the given date
	void setDate(string date);

	// returns the goal calories of the daily plan
	int getGoalCalories();
	// returns the plan name of the daily plan
	string getPlanName();
	// returns the date of the daily plan
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
