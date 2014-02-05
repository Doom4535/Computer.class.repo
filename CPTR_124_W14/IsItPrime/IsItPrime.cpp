#include <iostream>

using namespace std;

int main() {
	int number;
    //  Get number from user
	cout << "Enter a number: ";
	cin >> number;
    //  Determine if the number is prime
	int potential_factor = 2;
	while (potential_factor < number) {
		if (number % potential_factor == 0) {
			cout << "Found a factor: "
				<< potential_factor << endl;
		}
        potential_factor++;
	}
}