#ifndef EXERCISEPLAN_H
#define EXERCISEPLAN_H

#include <string>
using std::string;

class ExercisePlan {
public:
	ExercisePlan();

	void editGoal(int steps);
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