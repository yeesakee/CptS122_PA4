#ifndef FITNESSAPPWRAPPER_H
#define FITNESSAPPWRAPPER_H

#include <iostream>
#include <fstream>

#include "DietPlan.h"
#include "ExercisePlan.h"
#include "ListDiet.h"
#include "ListNodeDiet.h"

class FitnessAppWrapper {
public:
	FitnessAppWrapper();
	
	// starts the main application
	void runApp(void);
	// Displays nine menu options for the user to choose from
	void displayMenu();
	// Calls the method that the user chose
	void methodChosen(int choice);
	// Store any edits made and exit the program
	void exit();

	// Loads the daily diet plans from fileStream
	void loadDailyPlanDiet(fstream& fileStream, DietPlan& plan);
	// Loads the weekly diet plan given 
	void loadWeeklyPlanDiet(fstream& fileStream, ListDiet weeklyPlan);
	
	// Loads the daily diet plan from input_diet
	void displayDailyPlanDiet(ListNodeDiet* curr);
	// Loads the weekly diet plan
	void displayWeeklyPlanDiet();

	// Store the daily diet plan to output_diet
	void storeDailyPlanDiet(DietPlan plan);
	// Store the weekly diet plan
	void storeWeeklyPlanDiet();

	// Edit the daily diet plan given
	void editDailyDietPlan(ListNodeDiet* plan);

	/*****	Helper Methods	*****/
	// Prompt the user for what they want to change from DietPlan
	// Update value to new value
	void dietPlanChange(ListNodeDiet* plan);
	// Return a ListNodeDiet pointer to the plan the user wants to change nullptr if not found
	ListNodeDiet* getDietPlanEdit();
private:
	string user_choice;
	ListDiet ld;
	fstream diet;
	fstream exercise;
};


#endif