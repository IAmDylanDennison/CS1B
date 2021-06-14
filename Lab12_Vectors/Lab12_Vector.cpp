// Dylan Dennison
// creating number list with vectors
// lab12_vectors
// 11/19/19

#include <iostream>
#include <vector>
#include <algorithm>

using std::cin; using std::cout; using std::endl; using std::vector;

vector<double> vec;
vector<double>::iterator it;

char operation;
double num;
int main() {
  cout << "enter operation [a/r/q] and a number: ";
  cin >> operation;
  bool use = true;

  while (true) {

    if (operation == 'a') {
      cin >> num;
      it = find(vec.begin(), vec.end(), num);
      if (it == vec.end()) {
	vec.push_back(num);
      }
    }

    else if (operation == 'r') {
      cin >> num;
      it = find(vec.begin(), vec.end(), num);
      if (it != vec.end()) {
	vec.erase(it);
      }

    }

    else if (operation == 'q') {
      bool use = false;
      cout << "you have quit";
      return 0;
    }
    cout << "your numbers: "; 
    for (it = vec.begin(); it != vec.end(); ++it)
      cout << *it << " ";
    cout << endl;
    cout << "enter operation [a/r/q] and a number: ";
    cin >> operation;
  }
  
}
