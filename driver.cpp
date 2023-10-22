#include <iostream>
#include "Date.h"
#include "PizzaWars.h"
#include <ctime>
using namespace std;

int main() {
	unsigned seed = time(0);
	srand(seed);

	PizzaWars p1;
	p1.runSimulation();
}
