/*
Yeesa Kee
CPTS 122
Lab 4
Represents a weekly diet and exercise plan.
Includes functions that allow the user to load, display, store, and edit diet and exercise plans
*/
#ifndef FITNESSAPPWRAPPER_H
#define FITNESSAPPWRAPPER_H

#include <iostream>
#include <fstream>

#include "DietPlan.h"
#include "ExercisePlan.h"
#include "ListDiet.h"
#include "ListExercise.h"

// FitnessAppWrapper class that stores data regarding weekly diet and exercise plans
// contains methods that allow the user to load, display, store, and edit the plans
class FitnessAppWrapper {
public:
	// FitnessAppWrapper constructor
	FitnessAppWrapper();
	// FitnessAppWrapper deconstructor
	~FitnessAppWrapper();
	// FitnessAppWrapper copy constructor
	FitnessAppWrapper(const FitnessAppWrapper& faw);

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
	// Loads the daily diet plans from fileStream
	void loadDailyPlanExercise(fstream& fileStream, ExercisePlan& plan);
	// Loads the weekly diet plan given 
	void loadWeeklyPlanExercise(fstream& fileStream, ListExercise weeklyPlan);

	// Loads the daily diet plan from input_diet
	void displayDailyPlanDiet(ListNodeDiet* curr);
	// Loads the weekly diet plan
	void displayWeeklyPlanDiet();
	// Loads the daily exercise plan from input_diet
	void displayDailyPlanExercise(ListNodeExercise* curr);
	// Loads the weekly exercise plan
	void displayWeeklyPlanExercise();

	// Store the daily diet plan to output_diet
	void storeDailyPlanDiet(DietPlan plan);
	// Store the weekly diet plan
	void storeWeeklyPlanDiet();
	// Store the daily exercise plan to output_diet
	void storeDailyPlanExercise(ExercisePlan plan);
	// Store the weekly exercise plan
	void storeWeeklyPlanExercise();

	// Edit the daily diet plan given
	void editDailyDietPlan(ListNodeDiet* plan);
	// Edit the daily exercise plan given
	void editDailyExercisePlan(ListNodeExercise* plan);

	/*****	Helper Methods	*****/
	// Prompt the user for what they want to change from DietPlan
	// Update value to new value
	void dietPlanChange(ListNodeDiet* plan);
	// Return a ListNodeDiet pointer to the plan the user wants to change nullptr if not found
	ListNodeDiet* getDietPlanEdit();
	// Prompt the user for what they want to change from ExercisePlan
	// Update value to new value
	void exercisePlanChange(ListNodeExercise* plan);
	// Return a ListNodeDiet pointer to the plan the user wants to change nullptr if not found
	ListNodeExercise* getExercisePlanEdit();

	/*****	Getter Methods	*****/
	string getUserChoice() const;
	ListDiet getListDiet() const;
	ListExercise getListExercise() const;

private:
	// store the command the user entered
	string user_choice;
	// store the ListDiet of the weekly diet plan
	ListDiet list_diet;
	// store the ListExercise of the weekly exercise plan
	ListExercise list_exercise;
	// fstream for diet, dietPlans.txt
	fstream diet;
	// fstream for exercise, exercisePlans.txt
	fstream exercise;
};


#endif