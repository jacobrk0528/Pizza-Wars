#include "PizzaWars.h"
#include <fstream>
using namespace std;

// constructor 
PizzaWars::PizzaWars() {
}

// main method to run simulation - calls all other methods
void PizzaWars::runSimulation() {
	int month = 0;
	int day = 0;
	int year = 0;
	
	cout << "Welcome to Pizza Wars!\nThis program simulates an epic battle between Core and Schilletter and their ability to keep up with the demand for pizza!\n" << endl;
	cout << "Please enter the date you'd like to start the simulation in MM DD YYYY format: ";
	cin >> month >> day >> year;
	Date d1(month, day, year);

	marchToSunday(&d1);
	
	Date *weekOfDays = allocateWeekOfDates(d1);
	
	runSeriesSimulation(weekOfDays, 7);

	delete[] weekOfDays;
}

// fill array with days simulation will run for based on starting date
Date * PizzaWars::allocateWeekOfDates(Date date) {
	Date* weekOfDays = new Date[7];
	for (int i = 0; i < 7; i++) {
		weekOfDays[i] = date++;
	}

	return weekOfDays;
}

// run simulation for each day
void PizzaWars::runSeriesSimulation(Date *dates, int length) {
	for (int i = 0; i < length; i++) {
		PizzaStore core("Core", 3, 2, .90);
		PizzaStore schilletter("Schilletter", 6, 1, .80);

		// call run simulation
		cout << "\n\nRunning simulation for " << (dates+i)->getDayOfWeek() << " " << (dates+i)->toString() << "\n\n" <<  endl;
		std::string winner = runDaySimulation((dates + i), &core, &schilletter);
		if (winner == "TIE") {
			cout << winner << "!" << endl;
		} else {
			cout << winner << " wins!" << endl;
		}	
		
		// write to file
		if (winner == "Core") {
			writeToFile((dates+i), &core);
		} else if (winner == "Schilletter") {
			writeToFile((dates+i), &schilletter);
		} else {
			writeToFile((dates+i), nullptr);
		}
		
	}
};

// run simulation for 1 day
std::string PizzaWars::runDaySimulation(Date *datePtr, PizzaStore* core, PizzaStore* schilletter) {
	usleep(50000);

	int hours = 11;
	int minutes = 0;
	
	while (hours <= 20 || minutes == 0) {
		if (hours > 12 && minutes == 0) {
			cout << (hours - 12) << ":" << minutes << minutes << endl;
		} else if (hours > 12 && minutes == 30) {
			cout << (hours - 12) << ":" << minutes << endl;
		}  else if (hours <= 12 && minutes == 0) {
			cout << hours << ":" << minutes << minutes << endl;
		} else {
			cout << hours << ":" << minutes << endl;
		}

		int coreSlicesEaten = rand() % (20-5) + 5;
		int schilletterSlicesEaten = rand() % (20-5) + 5;
		bool coreFail = false;
		bool schilletterFail = false;

		cout << coreSlicesEaten << " slice(s) are consumed at Core" << endl;
		cout << schilletterSlicesEaten << " slice(s) are consumed at Schilletter" << endl;
		
		coreFail = !core->consumeSlices(coreSlicesEaten);
		schilletterFail = !schilletter->consumeSlices(schilletterSlicesEaten);
		core->showStatus();
		schilletter->showStatus();
		
		if (coreFail && !schilletterFail) { // core lost
			return schilletter->getName();
		} else if (!coreFail && schilletterFail) { // schilletter lost
			return core->getName();
		} else if (coreFail && schilletterFail) { // both lost - tie
			return "TIE";
		}
		
		cout << core->tickUpdate() << " pizza(s) were added at Core" << endl;
		cout << schilletter->tickUpdate() << " pizza(s) were added at Schilletter" << endl;
		core->showStatus();
		schilletter->showStatus();

		if (minutes == 30) {
			hours ++;
			minutes = 0;
		} else {
			minutes = 30;
		}

		cout << endl;
	}

	return "TIE";
}

// go to next sunday if given date isnt a sunday
void PizzaWars::marchToSunday(Date* datePtr) {
	if ((*datePtr).getDayOfWeek() != "Sunday") {
		cout << "That day is not a Sunday, so we're moving to the nearest future Sunday to start" << endl;
		while ((*datePtr).getDayOfWeek() != "Sunday") {
			(*datePtr)++;
		}
		cout << "Starting on " << (*datePtr).toString() << endl;
	} else {
		cout << "Starting on " << (*datePtr).toString() << endl;
	}
}

void PizzaWars::writeToFile(Date *datePtr, PizzaStore *winner) {
	ofstream file("log.txt", ios::app);
    
	file << left << setw(10) << datePtr->getDayOfWeek() << datePtr->toString() << " ";
	if (winner != nullptr) {
		file << winner->getName() << " won with " << winner->getTotalSlicesLeft() << " slices left!" << endl;
	} else {
		file << "Tie!" << endl;
	}
	file.close();
}
