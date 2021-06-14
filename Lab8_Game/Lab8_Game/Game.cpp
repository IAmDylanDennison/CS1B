// Dylan Dennison
// Lab8_game
// creating main(game)
// 10/22/19

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "battleship.h"

using std::cin; using std::cout; using std::endl; using std::string;

int main() {
	srand(time(nullptr));
	Ship arrayship[fleetSize];
	initialize(arrayship);
	deploy(arrayship);
	printFleet(arrayship);
	
	while (operational(arrayship) == true) {
		Location shot = fire();

		if (check(arrayship, shot) != -1) {
			sink(arrayship[check(arrayship, shot)]);
			cout << "You hit! " << endl;

		}
		else {
			cout << "You missed " << endl;

		}
		
	}	
	
	printFleet(arrayship);
	cout << "congrats you won!" << endl;
	system("pause");
}


