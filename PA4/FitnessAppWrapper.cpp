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
	if (!list_diet.isEmpty()) {
		storeWeeklyPlanDiet();
	}
	if (!list_exercise.isEmpty()) {
		storeWeeklyPlanExercise();
	}
}

void FitnessAppWrapper::methodChosen(int choice) {
	if (choice == 1) {
		loadWeeklyPlanDiet(diet, list_diet);
	}
	else if (choice == 2) {
		loadWeeklyPlanExercise(exercise, list_exercise);
	}
	else if (choice == 3) {
		storeWeeklyPlanDiet();
	}
	else if (choice == 4) {
		storeWeeklyPlanExercise();
	}
	else if (choice == 5) {
		displayWeeklyPlanDiet();
	}
	else if (choice == 6) {
		displayWeeklyPlanExercise();
	}
	else if (choice == 7) {
		ListNodeDiet* plan = getDietPlanEdit();
		if (plan != nullptr) {
			editDailyDietPlan(plan);
		}
	}
	else if (choice == 8) {
		ListNodeExercise* plan = getExercisePlanEdit();
		if (plan != nullptr) {
			editDailyExercisePlan(plan);
		}
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
	fileStream.open("dietPlans.txt");
	for (int i = 0; i < 7; i++) {
		ListNodeDiet* lnd = new ListNodeDiet();
		DietPlan* dp = new DietPlan();
		loadDailyPlanDiet(fileStream, (*dp));
		(*lnd).setData((*dp));
		list_diet.insert(lnd);
	}
	fileStream.close();
}

void FitnessAppWrapper::loadDailyPlanExercise(fstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlanExercise(fstream& fileStream, ListExercise weeklyPlan) {
	fileStream.open("exercisePlans.txt");
	for (int i = 0; i < 7; i++) {
		ListNodeExercise* lne = new ListNodeExercise();
		ExercisePlan* ep = new ExercisePlan();
		loadDailyPlanExercise(fileStream, (*ep));
		(*lne).setData((*ep));
		list_exercise.insert(lne);
	}
	fileStream.close();
}

void FitnessAppWrapper::displayDailyPlanDiet(ListNodeDiet* curr) {
	DietPlan list_diet = curr->getData();
	cout << list_diet;
	cout << endl;
}

void FitnessAppWrapper::displayWeeklyPlanDiet() {
	ListNodeDiet* curr = list_diet.getpHead();
	for (int i = 0; i < 7; i++) {
		displayDailyPlanDiet(curr);
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::displayDailyPlanExercise(ListNodeExercise* curr) {
	ExercisePlan ep = curr->getData();
	cout << ep;
	cout << endl;
}

void FitnessAppWrapper::displayWeeklyPlanExercise() {
	ListNodeExercise* curr = list_exercise.getpHead();
	for (int i = 0; i < 7; i++) {
		displayDailyPlanExercise(curr);
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::storeDailyPlanDiet(DietPlan plan) {
	diet << plan;
	diet << endl;
}

void FitnessAppWrapper::storeWeeklyPlanDiet() {
	ListNodeDiet* curr = list_diet.getpHead();
	diet.open("dietPlans.txt");
	for (int i = 0; i < 7; i++) {
		storeDailyPlanDiet(curr->getData());
		curr = curr->getNextPointer();
	}
	diet.close();
}

void FitnessAppWrapper::storeDailyPlanExercise(ExercisePlan plan) {
	exercise << plan;
	exercise << endl;
}

void FitnessAppWrapper::storeWeeklyPlanExercise() {
	ListNodeExercise* curr = list_exercise.getpHead();
	exercise.open("exercisePlans.txt");
	for (int i = 0; i < 7; i++) {
		storeDailyPlanExercise(curr->getData());
		curr = curr->getNextPointer();
	}
	exercise.close();
}

void FitnessAppWrapper::editDailyDietPlan(ListNodeDiet* plan) {
	dietPlanChange(plan);
}

void FitnessAppWrapper::editDailyExercisePlan(ListNodeExercise* plan) {
	exercisePlanChange(plan);
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

void FitnessAppWrapper::exercisePlanChange(ListNodeExercise* plan) {
	string choice = "";
	string change = "";

	cout << "1. Change plan name" << endl;
	cout << "2. Change steps goal" << endl;
	cout << "3. Change date" << endl;
	cout << "Please type in the number of the command: ";
	cin >> choice;
	cout << "Please type in the new value: ";
	cin >> change;

	ExercisePlan ep = plan->getData();
	if (stoi(choice) == 1) {
		ep.setPlanName(change);
	}
	else if (stoi(choice) == 2) {
		ep.editGoal(stoi(change));
	}
	else if (stoi(choice) == 3) {
		ep.setDate(change);
	}
	else {
		cout << "invalid command";
	}
	plan->setData(ep);
}

ListNodeDiet* FitnessAppWrapper::getDietPlanEdit() {
	string plan_name = "";
	ListNodeDiet* pDiet = nullptr;
	bool found = false;
	bool stop = false;
	displayWeeklyPlanDiet();

	while (!found && !stop) {
		cout << "Please type in the plan name of the diet plan you want to edit: ";
		cin >> plan_name;
		pDiet = list_diet.searchDietPlan(plan_name);
		if (pDiet == nullptr) {
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
	return pDiet;
}

ListNodeExercise* FitnessAppWrapper::getExercisePlanEdit() {
	string plan_name = "";
	ListNodeExercise* pExercise = nullptr;
	bool found = false;
	bool stop = false;
	displayWeeklyPlanExercise();

	while (!found && !stop) {
		cout << "Please type in the plan name of the exercise plan you want to edit: ";
		cin >> plan_name;
		pExercise = list_exercise.searchExercisePlan(plan_name);
		if (pExercise == nullptr) {
			cout << "Exercise plan not found, try again or enter exit: ";
			cin >> plan_name;
			if (plan_name.compare("exit") == 0) {
				stop = true;
			}
		}
		else {
			found = true;
		}
	}
	return pExercise;
}

