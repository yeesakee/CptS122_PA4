#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper() {
	user_choice = "0";
}

void FitnessAppWrapper::runApp() {
	int choice = 0;
	while (choice != 9) {
		displayMenu();
		choice = stoi(user_choice);
		methodChosen(choice);
	}
}

void FitnessAppWrapper::exit() {
	storeWeeklyPlanDiet();
}

void FitnessAppWrapper::methodChosen(int choice) {
	if (choice == 1) {
		loadWeeklyPlanDiet(diet, ld);
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
		ListNodeDiet* plan = getDietPlanEdit();
		if (plan != nullptr) {
			editDailyDietPlan(plan);
		}
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
	cout << "1. Load weekly diet plan from file" << endl;
	cout << "2. Load weekly exercise plan from file" << endl;
	cout << "3. Store weekly diet plan to file" << endl;
	cout << "4. Store weekly exercise plan to file" << endl;
	cout << "5. Display weekly diet plan to screen" << endl;
	cout << "6. Display weekly exercise plan to screen" << endl;
	cout << "7. Edit daily diet plan" << endl;
	cout << "8. Edit daily exercise plan" << endl;
	cout << "9. Exit." << endl;
	cout << "Please choose from the following nine options (enter number): ";
	cin >> user_choice;
	cout << endl;
}

void FitnessAppWrapper::loadDailyPlanDiet(fstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlanDiet(fstream& fileStream, ListDiet weeklyPlan) {
	fileStream.open("dietPlan.txt");
	for (int i = 0; i < 7; i++) {
		ListNodeDiet* lnd = new ListNodeDiet();
		DietPlan* dp = new DietPlan();
		loadDailyPlanDiet(fileStream, (*dp));
		(*lnd).setData((*dp));
		ld.insert(lnd);
	}
	fileStream.close();
}

void FitnessAppWrapper::displayDailyPlanDiet(ListNodeDiet* curr) {
	DietPlan ld = curr->getData();
	cout << "Plan Name: " << ld.getPlanName() << endl;
	cout << "Goal Calories: " << ld.getGoalCalories() << endl;
	cout << "Date: " << ld.getDate() << endl;
	cout << endl;
}

void FitnessAppWrapper::displayWeeklyPlanDiet() {
	ListNodeDiet* curr = ld.getpHead();
	for (int i = 0; i < 7; i++) {
		displayDailyPlanDiet(curr);
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::storeDailyPlanDiet(DietPlan plan) {
	diet << plan;
	diet << endl;
}

void FitnessAppWrapper::storeWeeklyPlanDiet() {
	ListNodeDiet* curr = ld.getpHead();
	diet.open("dietPlan.txt");
	for (int i = 0; i < 7; i++) {
		storeDailyPlanDiet(curr->getData());
		curr = curr->getNextPointer();
	}
	diet.close();
}

void FitnessAppWrapper::editDailyDietPlan(ListNodeDiet* plan) {
	dietPlanChange(plan);
}

void FitnessAppWrapper::dietPlanChange(ListNodeDiet* plan) {
	string choice = "";
	string change = "";

	cout << "1. Change plan name" << endl;
	cout << "2. Change calorie goal" << endl;
	cout << "3. Change date" << endl;
	cout << "Please type in the number of the command: ";
	cin >> choice;
	cout << "Please type in the new value: ";
	cin >> change;

	DietPlan dp = plan->getData();
	if (stoi(choice) == 1) {
		dp.setPlanName(change);
	}
	else if (stoi(choice) == 2) {
		dp.editGoal(stoi(change));
	}
	else if (stoi(choice) == 3) {
		dp.setDate(change);
	}
	else {
		cout << "invalid command";
	}
	plan->setData(dp);
}

ListNodeDiet* FitnessAppWrapper::getDietPlanEdit() {
	string plan_name = "";
	ListNodeDiet* diet = nullptr;
	bool found = false;
	bool stop = false;
	displayWeeklyPlanDiet();

	while (!found && !stop) {
		cout << "Please type in the plan name of the diet plan you want to edit: ";
		cin >> plan_name;
		diet = ld.searchDietPlan(plan_name);
		if (diet == nullptr) {
			cout << "Diet plan not found, try again or enter exit: ";
			cin >> plan_name;
			if (plan_name.compare("exit") == 0) {
				stop = true;
			}
		}
		else {
			found = true;
		}
	}
	return diet;
}