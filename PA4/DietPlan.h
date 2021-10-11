#ifndef DIETPLAN_H
#define DIETPLAN_H

#include <vector>
#include <iostream>
#include <string>

using std::string;
using std::vector;

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

