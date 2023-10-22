#include <iostream>
#include "PizzaStore.h"

using namespace std;

PizzaStore::PizzaStore() { // Default constructor
	this->name = "";
	this->maxPizzas = 0;
	this->productionPerTick = 0.0;
	this->successRate = 0.0;
}

// overloaded constructor
PizzaStore::PizzaStore(string name, int maxPizzas, double productionPerTick, double successRate) {
	this->name = name;
	this->maxPizzas = maxPizzas;
	this->productionPerTick = productionPerTick;
	this->successRate = successRate;
	this->pizzas= new int[maxPizzas];

	for (int i = 0; i < maxPizzas; i++) {
		*(pizzas + i) = 8;
	}
}

// adds pizzas to store based on successRate and how many pizzas can be added 
int PizzaStore::tickUpdate() {
	int pizzasAdded = 0;
	for (int i = 0; i < productionPerTick; i++) {
		int number = rand() % (100 - 1) + 1;
		if (number < successRate*100) {
			for (int j = maxPizzas-1; j >= 0; j--) {
				if (*(pizzas + j) == 0) {
					*(pizzas + j) = 8;
					j = -1;
					pizzasAdded++;
				}
			}
		} 
	}
	return pizzasAdded;
}

// removes slices from pizza store; if more slices consumed then avaiable - then return false
bool PizzaStore::consumeSlices(int slices) {
	if (slices <= this->getTotalSlicesLeft()) {
		for (int i = 0; i < maxPizzas; i++) {
			while (slices > 0 && *(pizzas + i) > 0) {
				slices--;
				*(pizzas + i) = *(pizzas + i) - 1;
			}
		}
		return true;
	} else {
		for (int i = 0; i < maxPizzas; i++) {
			*(pizzas + i) = 0;
		}	
		return false;
	}
}

// prints how many slices the store has
void PizzaStore::showStatus() { 
	cout << setw(20);
	cout << name << ": ";
	for (int i = 0; i < maxPizzas; i++) {
		cout <<  *(pizzas + i) << " ";
	}
	cout << endl;
}

// return store name
std::string PizzaStore::getName() {
	return this->name;
}

// return total number of slices left
int PizzaStore::getTotalSlicesLeft() {
	int totalSlices = 0;
	for (int i = 0; i < maxPizzas; i++) {
		totalSlices += *(pizzas + i);
	}

	return totalSlices;
}
