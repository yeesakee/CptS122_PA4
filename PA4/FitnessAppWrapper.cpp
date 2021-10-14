#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper() {
	user_choice = "0";
}

FitnessAppWrapper::~FitnessAppWrapper() {
	list_diet.~ListDiet();
	list_exercise.~ListExercise();
}

FitnessAppWrapper::FitnessAppWrapper(const FitnessAppWrapper& faw) {
	this->user_choice = faw.getUserChoice();
	this->list_diet = faw.list_diet;
	this->list_exercise = faw.list_exercise;
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
		storeWeeklyPlan(list_diet.getpHead());
	}
	if (!list_exercise.isEmpty()) {
		storeWeeklyPlan(list_exercise.getpHead());
	}
}

void FitnessAppWrapper::methodChosen(int choice) {
	diet.open("dietPlans.txt");
	exercise.open("exercisePlans.txt");
	if (choice == 1) {
		loadWeeklyPlan(diet, list_diet);
	}
	else if (choice == 2) {
		loadWeeklyPlan(exercise, list_exercise);
	}
	else if (choice == 3) {
		ListNodeDiet* pHead = list_diet.getpHead();
		storeWeeklyPlan(pHead);
	}
	else if (choice == 4) {
		ListNodeExercise* pHead = list_exercise.getpHead();
		storeWeeklyPlan(pHead);
	}
	else if (choice == 5) {
		ListNodeDiet* pHead = list_diet.getpHead();
		displayWeeklyPlan(pHead);
	}
	else if (choice == 6) {
		ListNodeExercise* pHead = list_exercise.getpHead();
		displayWeeklyPlan(pHead);
	}
	else if (choice == 7) {
		ListNodeDiet* plan = getDietPlanEdit();
		if (plan != nullptr) {
			editDailyPlan(plan);
		}
	}
	else if (choice == 8) {
		ListNodeExercise* plan = getExercisePlanEdit();
		if (plan != nullptr) {
			editDailyPlan(plan);
		}
	}
	else if (choice == 9) {
		exit();
	}
	else {
		cout << "invalid command" << endl;
	}
	diet.close();
	exercise.close();
}

void FitnessAppWrapper::displayMenu() {
	cout << endl;
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
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, DietPlan& plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ListDiet weeklyPlan) {
	for (int i = 0; i < 7; i++) {
		ListNodeDiet* lnd = new ListNodeDiet();
		DietPlan* dp = new DietPlan();
		loadDailyPlan(fileStream, (*dp));
		(*lnd).setData((*dp));
		list_diet.insert(lnd);
	}
}

void FitnessAppWrapper::loadDailyPlan(fstream& fileStream, ExercisePlan& plan) {
	fileStream >> plan;
}

void FitnessAppWrapper::loadWeeklyPlan(fstream& fileStream, ListExercise weeklyPlan) {
	for (int i = 0; i < 7; i++) {
		ListNodeExercise* lne = new ListNodeExercise();
		ExercisePlan* ep = new ExercisePlan();
		loadDailyPlan(fileStream, (*ep));
		(*lne).setData((*ep));
		list_exercise.insert(lne);
	}
}

void FitnessAppWrapper::displayDailyPlan(ListNodeDiet* curr) {
	DietPlan list_diet = curr->getData();
	cout << list_diet;
	cout << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(ListNodeDiet* pHead) {
	ListNodeDiet* curr = this->list_diet.getpHead();
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(curr);
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::displayDailyPlan(ListNodeExercise* curr) {
	ExercisePlan ep = curr->getData();
	cout << ep;
	cout << endl;
}

void FitnessAppWrapper::displayWeeklyPlan(ListNodeExercise* pHead) {
	ListNodeExercise* curr = this->list_exercise.getpHead();
	for (int i = 0; i < 7; i++) {
		displayDailyPlan(curr);
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::storeDailyPlan(DietPlan plan) {
	diet << plan;
	diet << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(ListNodeDiet* pHead) {
	ListNodeDiet* curr = this->list_diet.getpHead();
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(curr->getData());
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::storeDailyPlan(ExercisePlan plan) {
	exercise << plan;
	exercise << endl;
}

void FitnessAppWrapper::storeWeeklyPlan(ListNodeExercise* pHead) {
	ListNodeExercise* curr = this->list_exercise.getpHead();
	for (int i = 0; i < 7; i++) {
		storeDailyPlan(curr->getData());
		curr = curr->getNextPointer();
	}
}

void FitnessAppWrapper::editDailyPlan(ListNodeDiet* plan) {
	planChange(plan);
}

void FitnessAppWrapper::editDailyPlan(ListNodeExercise* plan) {
	planChange(plan);
}

void FitnessAppWrapper::planChange(ListNodeDiet* plan) {
	string choice = "";
	string change = "";

	cout << "1. Change plan name" << endl;
	cout << "2. Change calorie goal" << endl;
	cout << "3. Change date" << endl;
	cout << "Please type in the number of the command: ";
	cin >> choice;
	cout << "Please type in the new value: ";
	cin >> change;
	cout << endl;
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
	displayDailyPlan(plan);
}

void FitnessAppWrapper::planChange(ListNodeExercise* plan) {
	string choice = "";
	string change = "";

	cout << "1. Change plan name" << endl;
	cout << "2. Change steps goal" << endl;
	cout << "3. Change date" << endl;
	cout << "Please type in the number of the command: ";
	cin >> choice;
	cout << "Please type in the new value: ";
	cin >> change;
	cout << endl;

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
	displayDailyPlan(plan);
}

ListNodeDiet* FitnessAppWrapper::getDietPlanEdit() {
	string plan_name = "";
	ListNodeDiet* pDiet = nullptr;
	bool found = false;
	bool stop = false;
	displayWeeklyPlan(pDiet);

	while (!found && !stop) {
		cout << "Please type in the plan name of the diet plan you want to edit: ";
		cin >> plan_name;
		if (plan_name.compare("exit") == 0) {
			stop = true;
			break;
		}
		pDiet = list_diet.searchDietPlan(plan_name);
		if (pDiet == nullptr) {
			cout << "Diet plan not found, try again or enter exit" << endl;
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
	displayWeeklyPlan(pExercise);

	while (!found && !stop) {
		cout << "Please type in the plan name of the exercise plan you want to edit: ";
		cin >> plan_name;
		if (plan_name.compare("exit") == 0) {
			stop = true;
			break;
		}
		pExercise = list_exercise.searchExercisePlan(plan_name);
		if (pExercise == nullptr) {
			cout << "Exercise plan not found, try again or enter exit" <<endl;
		}
		else {
			found = true;
		}
	}
	return pExercise;
}

string FitnessAppWrapper::getUserChoice() const {
	return user_choice;
}

ListDiet FitnessAppWrapper::getListDiet() const {
	return list_diet;
}

ListExercise FitnessAppWrapper::getListExercise() const {
	return list_exercise;
}