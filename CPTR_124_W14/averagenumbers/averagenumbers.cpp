#include <iostream>

using namespace std;

int main() {
	double n1, n2, n3, n4, n5;
	cout << "Please enter five numbers: ";
	// Allow the user to enter in the five values.
	cin >> n1 >> n2 >> n3 >> n4 >> n5;
	cout << "The average of " << n1 << ", " << n2 << ", "
		<< n3 << ", " << n4 << ", " << n5 << " is "
		<< (n1 + n2 + n3 + n4 + n5) / 5 << endl;;
}