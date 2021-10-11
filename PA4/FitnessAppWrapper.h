#ifndef FITNESSAPPWRAPPER_H
#define FITNESSAPPWRAPPER_H

#include "DietPlan.h";
#include "ExercisePlan.h";
#include "ListDiet.h";
#include "ListNodeDiet.h";
#include <iostream>;
#include <fstream>;

class FitnessAppWrapper {
public:
	// starts the main application
	void runApp(void);
	// Displays nine menu options for the user to choose from
	void displayMenu();

	// Loads the daily diet plans from fileStream
	void loadDailyPlanDiet(fstream& fileStream, DietPlan& plan);
	// Loads the weekly diet plan given 
	void loadWeeklyPlanDiet(fstream& fileStream, DietPlan weeklyPlan[]);
	
	// Loads the daily diet plan from input_diet
	void displayDailyPlanDiet(fstream& input_diet);
	// Loads the weekly diet plan
	void displayWeeklyPlanDiet();

	// Store the daily diet plan to output_diet
	void storeDailyPlanDiet(fstream& output_diet);
	// Store the weekly diet plan
	void storeWeeklyPlanDiet();


private:
	ListDiet ld;
	fstream input_diet;
	fstream output_diet;
};


#endif