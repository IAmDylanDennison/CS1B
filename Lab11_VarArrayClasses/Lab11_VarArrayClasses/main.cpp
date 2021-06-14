// Dylan Dennison
// creating main
// lab11_VarArrayClasses
// 11/12/19

#include <iostream>
#include "varArray.h"

using std::cin; using std::cout; using std::endl;



int main(){
	varArray myObj;
	double number;
	

	bool use = true;
	char operation;

	while (true) {

		cout << "enter operation [a/r/q] and a number: ";
		cin >> operation;

		switch (operation) {
		case 'a':
			cin >> number;
			myObj.addNumber(number);
			myObj.output();
			break;
		case 'r':
			cin >> number;
			myObj.removeNumber(number);
			myObj.output();
			break;
		case 'q':
			cout << "You have quit" << endl;
			use = false;
			return 0;

		}
	}
	myObj.~varArray();
}

