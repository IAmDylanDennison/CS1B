// Dylan Dennison
// creating functions for main test
// Lab10_arrayTest
// 11/5/19

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "varArray.h"

using std::cin; using std::cout; using std::endl;

void output(double* arrayPtr, int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arrayPtr[i] << " " << endl;
	}

}

int check(double* arrayPtr, double num, int size) {
	for (int i = 0; i < size; i++)
	{
		if (arrayPtr[i] == num)
			return i;
	}
	return -1;
}

void addNumber(double*& arrayPtr, double num, int& size) {
	if (check(arrayPtr, num, size) == -1) {

		double* tmp = arrayPtr;
		arrayPtr = new double[size + 1];
		for (int i = 0; i < size; ++i) {
			arrayPtr[i] = tmp[i];
		}
		arrayPtr[size] = num;
		delete[] tmp;
		size++;
	}
}

void removeNumber(double*& arrayPtr, double num, int& size) {
	if (check(arrayPtr, num, size) != -1) {

		bool found = false;

		double* tmp = arrayPtr;
		arrayPtr = new double[size - 1];

		for (int i = 0; i < size; ++i) {
			if (tmp[i] == num)
				found = true;

			else {
				if (!found)
					arrayPtr[i] = tmp[i];
				else if (found)
					arrayPtr[i - 1] = tmp[i];
			}
		}
		delete[] tmp;
		--size;
	}
}