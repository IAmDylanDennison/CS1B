//Dylan Dennison
// lab 9 test
// 10/29/19
// creating functions for main

#include "battleship.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl; using std::string;



Location::Location() {

	x_ = -1;
	y_ = '*';

}

void Location::pick() {
	srand(time(nullptr));

	x_ = rand() % fieldSize_ + 1;
	y_ = rand() % fieldSize_ + 'a';

}

void Location::fire() {
	cout << "please enter a number 1-6 and a letter a-f " << endl;
	cin >> x_ >> y_;
}


void Location::print() const {

	cout << x_ << " : " << y_ << endl;
}

bool compare(const Location& fire, const Location& loc) {
	if (fire.x_ == loc.x_ && fire.y_ == loc.y_)
		return true;
	else
		return false;

}

Ship::Ship() {

	sunk_ = false;
}

bool Ship::match(const Location& fire) const {

	return compare(loc_, fire);
}


void Ship::sink() {
	sunk_ = true;
}

void Ship::setLocation(const Location& loc) {
	loc_ = loc;
}

void Ship::printShip() const {
	loc_.print();
	if (sunk_ == true)
		cout << "the one above is SUNK" << endl;
	else
		cout << " ";
}

void Fleet::deployFleet() {
	for (int i = 0; i < fleetSize_;) {
		Location deploy;
		deploy.pick();
		if (check(deploy) == -1) {
			ships_[i].setLocation(deploy);
				i++;
		}
			
	}

}

bool Fleet::operational() const {
	for (int i = 0; i < fleetSize_; i++) {
		if (ships_[i].isSunk() == false)
			return true;
	}
	return false;
}

int Fleet::check(const Location& loc) const {
	int i = 0;
	for (i = 0; i < fleetSize_; i++) {
		if (ships_[i].match(loc) == true)
			return i;
	}
	return -1;
}

bool Fleet::isHitNSink(const Location& loc) {
	for (int i = 0; i < fleetSize_; i++)
		if (ships_[i].match(loc) == true) {
			ships_[i].sink();
			return true;
		}
	return false;
}

void Fleet::printFleet() const {
	for (int i = 0; i < fleetSize_; i++) {
		
		ships_[i].printShip();
	}

}