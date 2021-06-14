#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using std::cin; using std::cout; using std::string; using std::endl;
using std::ifstream; using std::ofstream;

const int lineSize = 75;

int main() {
	srand(time(0));
	ifstream infile("unjustified.txt");
	string string1;
	ofstream outfile("justified.txt");

	while (getline(infile, string1))
	{

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
		cout << string1 << endl;
		outfile << string1 << endl;
		string1 = "";

	}
	infile.close();
	outfile.close();

	return 0;
}