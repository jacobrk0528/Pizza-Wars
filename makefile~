compile:
	make date
	make pizzaWar
	make pizzaStore
	g++ driver.cpp Date.o PizzaWars.o PizzaStore.o MysteryMachine.o -Wall -o battle.exe
compile-intel:
	make date
	make pizzaWar
	make pizzaStore
	g++ driver.cpp Date.o PizzaWars.o PizzaStore.o MysteryMachine-intel.o -Wall -o battle.exe

clean:
	rm *.out
run:
	./battle.exe
date:
	g++ Date.cpp -c
pizzaWar:
	g++ PizzaWars.cpp -c
pizzaStore:
	g++ PizzaStore.cpp -c
