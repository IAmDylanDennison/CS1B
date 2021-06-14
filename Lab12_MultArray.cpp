// Dylan Dennison
// lab 12 mult arrays
// 11/19/19

#include <iostream>

using std::cin; using std::cout; using std::endl;

// size of the ocean
const int oceanLength = 6;
const int oceanWidth = 6;

int main() {
	bool shots[oceanLength][oceanWidth];

	for (int i = 0; i < oceanLength; i++) {
		for (int j = 0; j < oceanWidth; j++) {
			shots[i][j] = 0;
		}
	}

	char choice;
	int row;
	char column;

	cout << "Another shot? [y/n]";
	cin >> choice;

	while (choice != 'n') {
		cout << "location?";
		cin >> row >> column;

		int rowi = row - 1;
		int columnj = int(column) - 'a'; 

		if (shots[rowi][columnj] == false) {
			shots[rowi][columnj] = true;
			cout << "you have fired all shots" << endl;

			for (int j = 0; j < oceanWidth; j++) {
				cout << " " << char('a' + j);
			}
			cout << endl;

			for (int i = 0; i < oceanLength; ++i) {
				cout << i + 1;
				for (int j = 0; j < oceanWidth; ++j) {
					(shots[i][j]) ? cout << "*" :cout << "  ";
				}
				cout << endl;
			}
		}
		cout << "Another shot? ";
		cin >> choice;
	}
	cout << "you have quit" << endl;
}
