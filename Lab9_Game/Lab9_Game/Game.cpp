//Dylan Dennison
// lab 9 game
// 10/29/19
// creating game main

#include "battleship.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout; using std::cin; using std::endl; using std::string;

int main() {
	srand(time(nullptr));

	Fleet myFleet;
	myFleet.deployFleet();
	
	do
	{
		myFleet.printFleet(); // comment in for testing reasons
		Location loc;
		loc.fire();

		if (myFleet.isHitNSink(loc))
		{

			cout << "You hit!" << endl;
		}
		else
			cout << "You missed!" << endl;

	} while (myFleet.operational() == true);

	myFleet.printFleet();
	cout << "You have hit and sunk all the ships!!" << endl;
	system("pause");
}