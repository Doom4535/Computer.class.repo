#include <iostream>

using namespace std;

int main() {
	int input = 0, sum = 0, count = 0;
	cout << "Please enter integers" << endl;
	cout << "999 ends the list" << endl;
	while (input != 999) {
		cin >> input;
		if (input != 999) {
			sum += input;
			count++;
		}
	}
	cout << "sum = " << sum << " and count = "
		 << count << endl;
	int quotient = sum / count, 
		remainder = sum % count;
	cout << "average = " << quotient;
	if (remainder != 0)
		cout << " " << remainder << "/" << count;
	cout << endl;

}