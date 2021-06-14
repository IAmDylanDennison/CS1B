// Dylan Dennison
// Lab6_powerball
// Array size of 20 with random numbers 1-100
// 10/1/19

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <random>

using std::cin; using std::cout; using std::endl;

void assign(int[], int);
int entry();
bool check(int guess, int wins[], int arraySize);
void draw(int[], int arraySize);
void printOut(int wins[], int arraySize);


void assign(int wins[], int arraySize) {
	
	for (int i = 0; i < arraySize; i++)
	{
		wins[i] = 0;
	}
}
int entry() {
	int guess;
	cout << " input your number guess!";
		cin >> guess;
		return guess;
}
	
	
bool check(int guess, int wins[], int arraySize) {


	for (int i = 0; i < arraySize; ++i) {
		if (wins[i] == guess) {
			return true;
		}

	}
	return false;
}
void draw(int wins[], int arraySize) {
	int i = 0;
	srand(time(nullptr));
	
	
	while (i < arraySize) {

		int random = rand() % 100 + 1;

		if (!check(random, wins, arraySize)) {

			wins[i] = random;
			++i;
		}
	}
}
void printOut(int wins[], int arraySize) {

	for (int i = 0; i < arraySize; i++)
	{
		cout << wins[i] << " ";
	}
	
}
int main() {
	const int arraySize = 20;
	int wins[arraySize];
	int guess;
	int count;
	count = 1;

	cout << "Welcome to my lottery game!";

	assign(wins, arraySize);
	draw(wins, arraySize);
	while (count <= 3) {
		guess = entry();
	count++;
}
	if (check(guess, wins, arraySize)) {
		cout << "You are a winner!";
	}
	else {
		cout << "You Lost! no money for you!";
	}
	
	cout << "The lottery numbers are..";
	printOut(wins, arraySize);
}





