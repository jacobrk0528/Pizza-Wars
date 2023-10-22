#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

class PizzaStore {
	private:
		std::string name;
		int maxPizzas;
		double productionPerTick;
		double successRate;
		int *pizzas;
	public:
		PizzaStore(); // Default constructor
		PizzaStore(string name, int maxPizzas, double productionPerTick, double successRate);
		int tickUpdate(); // Bakes an adds pizzas
		bool consumeSlices(int slices); // Must return false if the
		void showStatus(); // Shows how many slices each pizza has. E.g.: Core: 0 4 8
		string getName();
		int getTotalSlicesLeft();
};
