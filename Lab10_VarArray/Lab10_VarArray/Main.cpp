// Dylan Dennison
// creating switch to manipulate a dynamic array
// Lab10_ VarArray
// 11/5/19

#include <iostream>
#include "varArray.h"


using std::cin; using std::cout; using std::endl;

int size = 0;
double* arrayPrt = new double[size];
double num;

int main() {
	bool use = true;
	char operation;

	while (true) {

		cout << "enter operation [a/r/q] and a number: ";
		cin >> operation;

		switch (operation) {
		case 'a':
			cin >> num;
			addNumber(arrayPrt, num, size);
			output(arrayPrt, size);
			break;
		case 'r':
			cin >> num;
			removeNumber(arrayPrt, num, size);
			output(arrayPrt, size);
			break;
		case 'q':
			cout << "You have quit" << endl;
			use = false;
			return 0;

		}
	}
	delete[] arrayPrt;
}
