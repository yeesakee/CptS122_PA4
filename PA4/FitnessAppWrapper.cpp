#include "FitnessAppWrapper.h"

FitnessAppWrapper::FitnessAppWrapper() {
	user_choice = "";
	ld = ListDiet();
	input_diet = fstream("dietplan.txt");
	output_diet = fstream("dietplan.txt");
}

void FitnessAppWrapper::runApp(void) {
	int choice = stoi(user_choice);
	while (choice != 9) {
		displayMenu();
		methodChosen(choice);
	}
}

void FitnessAppWrapper::methodChosen(int choice) {
	if (choice == 1) {

	}
	else if (choice == 2) {

	}
	else if (choice == 3) {

	}
	else if (choice == 4) {

	}
	else if (choice == 5) {

	}
	else if (choice == 6) {

	}
	else if (choice == 7) {

	}
	else if (choice == 8) {

	}
	else if (choice == 9) {

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
	
}

void FitnessAppWrapper::loadWeeklyPlanDiet(fstream& fileStream, DietPlan weeklyPlan[]) {

}

void FitnessAppWrapper::displayDailyPlanDiet(fstream& input_diet) {

}