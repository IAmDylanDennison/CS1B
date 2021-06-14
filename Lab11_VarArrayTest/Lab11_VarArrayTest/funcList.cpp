// Dylan Dennison
// Lab11_VarArrayTest
// creating functions
// 11/12/19

#include <iostream>
#include "vararray.h"

using std::cin; using std::cout; using std::endl;

int varArray::check(double number) {
	for (int i = 0; i < size_; i++)
	
		if (array_[i] == number) {
			return i;
		}
	return -1;
}

void varArray::output() {
	for (int i = 0; i < size_; i++)
		
		cout << array_[i] << " ";
		cout << endl;
}

varArray::varArray() { 
	size_ = 0;
	array_ = new double[size_];
}

// big three
varArray::~varArray() {
	delete[] array_;
}

varArray& varArray::operator=(const varArray& rhs) {
	if (this != &rhs) {

		size_ = rhs.size_;
		delete[] array_;
		array_ = new double[size_];

		for (int i = 0; i < size_; i++) {
			array_[i] = rhs.array_[i];
		}
	}
	return *this;
}

varArray::varArray(const varArray& rhs) {
	size_ = rhs.size_;
	array_ = new double[size_];
	
	for (int i = 0; i < size_; i++) {
		array_[i] = rhs.array_[i];
	}
}
// main funcs
void varArray::addNumber(double number) {
	if (check(number) == -1) {
		double* tmp = array_;
		array_ = new double[size_ + 1];
		for (int i = 0; i < size_; i++) {
			array_[i] = tmp[i];
		}
		array_[size_] = number;
		delete[] tmp;
		size_++;
	}
}

void varArray::removeNumber(double number) {
	if(check(number) != -1) {
		bool found = false;
		double* tmp = array_;
		array_ = new double[size_ - 1];
		
		for (int i = 0; i < size_; i++) {
			if (tmp[i] == number)
				found = true;
			else {
				if (!found)
					array_[i] = tmp[i];
				else if (found)
					array_[i - 1] = tmp[i];
			}
		}
		delete[] tmp;
		--size_;
			  
	}
}