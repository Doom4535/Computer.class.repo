#include <iostream>

using namespace std;

int main() {
	int quantity = 5;
	double input, sum = 0.0;
	cout << "Please enter " << quantity << " numbers: ";
	// Allow the user to enter in the values.
	for (int i = 0; i < quantity; i++) {
		cin >> input;
		sum += input;
	}
	cout << "The average of the " << quantity 
		 << " values is " << sum / quantity << endl;
}