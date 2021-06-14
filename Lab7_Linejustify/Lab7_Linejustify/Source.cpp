#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using std::cin; using std::cout; using std::endl;
using std::string; 

const int lineSize = 75;

int main() {
	
	srand(time(0));
	string string1;
	cout << "Enter a sentence please with punctuations: " << endl;
	getline(cin, string1);
	int insertIndex = -1;
	while (string1.size() < lineSize && insertIndex != string::npos) {


		insertIndex = string1.find_first_of(".,;?!", insertIndex + 2);

		if (insertIndex != string::npos)

			string1.insert(insertIndex, 1, ' ');

	}

	insertIndex = -1;
	while (string1.size() < lineSize) {



		insertIndex = string1.find(' ', insertIndex + 2);
		bool in = rand() % 2;  // makes it 0 || 1  or 50% chance for it to add a space or not. 
		if (in) {
			if (insertIndex != string::npos)

				string1.insert(insertIndex, " ");
		}
	}

	cout << "Your line justified is:" << endl;
	cout << string1 << endl;
	cout << string1.size() << endl; // just to check if it is the right size.
}