#include <iostream>
#include "Date.h"
#include "PizzaStore.h"
#include <ctime>
#include <iomanip>
#include <unistd.h>
class PizzaWars {
	private:
	public:
		PizzaWars(); // Constructor
		
		static void runSimulation(); //this is the only public method in PizzaWars.
		
	protected:
		static Date * allocateWeekOfDates(Date date);
		
		static void runSeriesSimulation(Date *dates, int length);
		static string runDaySimulation(Date *datePtr, PizzaStore*, PizzaStore*);
		static void marchToSunday(Date* datePtr);
		static void writeToFile(Date *datePtr, PizzaStore *winner);
};
