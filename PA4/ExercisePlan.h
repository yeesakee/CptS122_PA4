/*
Yeesa Kee
CPTS 122
Lab 4
Represents a daily exercise plan. Including the goal steps, plan name, and date of the plan.
*/
#ifndef EXERCISEPLAN_H
#define EXERCISEPLAN_H

#include <iostream>
#include <string>
#include <fstream>

using std::string;
using namespace std;

// ExercisePlan class, represents and stores one daily exercise plan
class ExercisePlan {
public:

	// ExercisePlan constructor
	ExercisePlan();
	// ExercisePlan deconstructor
	~ExercisePlan();
	// ExercisePlan copy constructor
	ExercisePlan(const ExercisePlan& dp);

	// edit the goal_steps with the given steps
	void editGoal(int steps);
	// set the plan_name to the given name
	void setPlanName(string name);
	// set the date to the given date
	void setDate(string date);

	// return the goal_steps
	int getGoalSteps() const;
	// return the plan_name
	string getPlanName() const;
	// return the date
	string getDate() const;

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