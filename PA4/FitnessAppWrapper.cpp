#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper() {
	user_choice = "";
	ld = ListDiet();
	input_diet = fstream("dietPlans.txt");
	output_diet = fstream("dietPlans.txt");
}

void FitnessAppWrapper::runApp(void) {
	int choice = stoi(user_choice);
	while (choice != 9) {
		displayMenu();
		methodChosen(choice);
	}
}

void FitnessAppWrapper::exit() {
	storeWeeklyPlanDiet();
}

void FitnessAppWrapper::methodChosen(int choice) {
	if (choice == 1) {
		loadWeeklyPlanDiet(output_diet, ld);
	}
	else if (choice == 2) {

	}
	else if (choice == 3) {
		storeWeeklyPlanDiet();
	}
	else if (choice == 4) {

	}
	else if (choice == 5) {
		displayWeeklyPlanDiet();
	}
	else if (choice == 6) {

	}
	else if (choice == 7) {

	}
	else if (choice == 8) {

	}
	else if (choice == 9) {
		exit();
	}
	else {
		cout << "invalid command" << endl;
	}
}

void FitnessAppWrapper::displayMenu() {
	cout << "Please choose from the following nine options (enter number)" << endl;
	cout << "1. Load weekly diet plan from file" << endl;
	cout << "2. Load weekly exercise plan from file" << endl;
	cout << "3. Store weekly diet plan to file" << endl;
	cout << "4. Store weekly exercise plan to file" << endl;
	cout << "5. Display weekly diet plan to screen" << endl;
	cout << "6. Display weekly exercise plan to screen" << endl;
	cout << "7. Edit daily diet plan" << endl;
	cout << "8. Edit daily exercise plan" << endl;
	cout << "9. Exit." << endl;
	cin >> user_choice;
}

void FitnessAppWrapper::loadDailyPlanDiet(fstream& fileStream, DietPlan& plan) {
	ListNodeDiet* lnd = new ListNodeDiet();
	fileStream >> plan;
	(*lnd).setData(plan);
	ld.insert(lnd);
}

void FitnessAppWrapper::loadWeeklyPlanDiet(fstream& fileStream, ListDiet weeklyPlan) {
	ListNodeDiet* lnd = weeklyPlan.getpHead();
	for (int i = 0; i < 7; i++) {
		DietPlan dp = lnd->getData();
		loadDailyPlanDiet(fileStream, dp);
		lnd = lnd->getNextPointer();
	}
}

void FitnessAppWrapper::displayDailyPlanDiet(ListNodeDiet* curr) {
	DietPlan ld = curr->getData();
	cout << "Plan Name: " << ld.getPlanName() << endl;
	cout << "Goal Calories: " << ld.getGoalCalories() << endl;
	cout << "Date: " << ld.getDate() << endl;
}

void FitnessAppWrapper::displayWeeklyPlanDiet() {
	ListNodeDiet* curr = ld.getpHead();
	for (int i = 0; i < 7; i++) {
		displayDailyPlanDiet(curr);
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::storeDailyPlanDiet(DietPlan plan) {
	output_diet << plan;
}

void FitnessAppWrapper::storeWeeklyPlanDiet() {
	ListNodeDiet* curr = ld.getpHead();
	for (int i = 0; i < 7; i++) {
		storeDailyPlanDiet(curr->getData());
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::editDailyDietPlan(DietPlan plan) {

}

void FitnessAppWrapper::dietPlanChange(DietPlan plan) {
	string choice = "";
	string change = "";

	cout << "Please type in the number of the command: " << endl;
	cout << "1. Change plan name" << endl;
	cout << "2. Change calorie goal" << endl;
	cout << "3. Change date" << endl;
	cin >> choice;
	cout << "Please type in the new value";
	cin >> change;
	if (stoi(choice) == 1) {
		plan.setPlanName(change);
	}
	else if (stoi(choice) == 2) {
		plan.editGoal(stoi(change));
	}
	else if (stoi(choice) == 3) {
		plan.setDate(change);
	}
	else {
		cout << "invalid command";
	}
}