#include <iostream>
#include <vector>

using namespace std;

int main() {
	int quantity = 5;
	vector<int> list;
	double input, sum = 0.0;
	cout << "Please enter " << quantity << " numbers: ";
	// Allow the user to enter in the values.
	for (int i = 0; i < quantity; i++) {
		cin >> input;
		sum += input;
		list.push_back(input);
		cout << "The vector's size is " << list.size() << endl;
	}
	cout << "The average of ";
	for (int i = 0; i < quantity; i++) {
		cout << list[i] << " ";
	}
	cout << " is " << sum / quantity << endl;
}