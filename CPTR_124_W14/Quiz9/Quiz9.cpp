#include <iostream>
using namespace std;

int main() {
	cout << "Count down from what? ";
	int x;
	cin >> x;
	while (x >= 0) {
		cout << x << endl;
		x--;
	}
}