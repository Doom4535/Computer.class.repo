#include <iostream>
using namespace std;

int main() {
	int input = 0, x = 0;
	while (input >= 0) {
		cin >> input;
		if (input >= 0)
			x += input;
	}
	cout << x << endl;
}