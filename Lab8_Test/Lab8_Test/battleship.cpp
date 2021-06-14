// Dylan Dennison
// lab8_test
// 10/22/19
// creating/checking the functions

#include <iostream>
#include "battleship.h"
#include <cstdlib>
#include <ctime>

using std::cin; using std::cout; using std::endl; using std::string;

//return type name(parameters)
Location pick(){
	srand(time(0));// comment out srand for testing purposes!!!!!!!!!!

	Location mySpot;

	mySpot.x = rand() % fieldSize + 1;
	mySpot.y = rand() % fieldSize + 'a';

	return mySpot;
}
void initialize(Ship arrayship[]) {
	for (int i = 0; i < fleetSize; i++)
	{
		arrayship[i].loc.x = -1;
		arrayship[i].loc.y = '*';
		arrayship[i].sunk = false;

	}
}

bool match(const Ship& ship, const Location& loc) {
	if (ship.loc.x == loc.x && ship.loc.y == loc.y)
		return true;
	else
		return false;
}

int check(const Ship shiparray[], const Location& loc) {
	for (int i = 0; i < fleetSize; i++) {
		if (shiparray[i].loc.x == loc.x && shiparray[i].loc.y == loc.y)
			return i;

	}
	
	return -1;
}

void deploy(Ship arrayship[]) {
	
	int i = 0;
	while (i < fleetSize) {
		Location choice = pick();

		if (check(arrayship, choice) == -1) {
			arrayship[i].loc = choice;
			i++;
		}
	}
}
// display functions
void printShip(const Ship& ship) {
	cout << ship.loc.x << " : " << ship.loc.y << " " << endl;
	if (ship.sunk == true) {
		cout << " sunk" << endl;
	}
	else
		cout << " not sunk" << endl;
	
} 



void printFleet(const Ship arrayship[]) {
	for (int i = 0; i < fleetSize; i++) {
		
		printShip(arrayship[i]);
	}
}

// battle functions
bool operational(const Ship arrayship[]) {
	int i = 0;
	while (i < fleetSize) {
		if (arrayship[i].sunk == false) {
			return true;
		}
		else {
			i++;
		}
	}
	return false;

}

Location fire() {
	int x;
	char y;
		cout << "enter a number 1-6 and a letter a-f for a shot";
		cin >> x >> y;
	
	Location userPick;
		userPick.x = x;
		userPick.y = y;
	
	return userPick;
}

void sink(Ship& ship) {
	ship.sunk = true;
		
}



