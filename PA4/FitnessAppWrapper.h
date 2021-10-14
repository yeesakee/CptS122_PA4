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
	void runApp();
	// Displays nine menu options for the user to choose from
	void displayMenu();
	// Calls the method that the user chose
	void methodChosen(int choice);
	// Store any edits made and exit the program
	void exit();

	// Loads the daily diet plans from fileStream
	void loadDailyPlan(fstream& fileStream, DietPlan& plan);
	// Loads the weekly diet plan given 
	void loadWeeklyPlan(fstream& fileStream, ListDiet weeklyPlan);
	// Loads the daily diet plans from fileStream
	void loadDailyPlan(fstream& fileStream, ExercisePlan& plan);
	// Loads the weekly diet plan given 
	void loadWeeklyPlan(fstream& fileStream, ListExercise weeklyPlan);

	// Loads the daily diet plan from input_diet
	void displayDailyPlan(ListNodeDiet* curr);
	// Loads the weekly diet plan
	void displayWeeklyPlan(ListNodeDiet* pHead);
	// Loads the daily exercise plan from input_diet
	void displayDailyPlan(ListNodeExercise* curr);
	// Loads the weekly exercise plan
	void displayWeeklyPlan(ListNodeExercise* pHead);

	// Store the daily diet plan to output_diet
	void storeDailyPlan(DietPlan plan);
	// Store the weekly diet plan
	void storeWeeklyPlan(ListNodeDiet* pHead);
	// Store the daily exercise plan to output_diet
	void storeDailyPlan(ExercisePlan plan);
	// Store the weekly exercise plan
	void storeWeeklyPlan(ListNodeExercise* pHead);

	// Edit the daily diet plan given
	void editDailyPlan(ListNodeDiet* plan);
	// Edit the daily exercise plan given
	void editDailyPlan(ListNodeExercise* plan);

	/*****	Helper Methods	*****/
	// Prompt the user for what they want to change from DietPlan
	// Update value to new value
	void planChange(ListNodeDiet* plan);
	// Return a ListNodeDiet pointer to the plan the user wants to change nullptr if not found
	ListNodeDiet* getDietPlanEdit();
	// Prompt the user for what they want to change from ExercisePlan
	// Update value to new value
	void planChange(ListNodeExercise* plan);
	// Return a ListNodeDiet pointer to the plan the user wants to change nullptr if not found
	ListNodeExercise* getExercisePlanEdit();

	/*****	Getter Methods	*****/
	// return string of user_choice
	string getUserChoice() const;
	// return ListDiet of list_diet
	ListDiet getListDiet() const;
	// return ListExercist list_exercise
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