#include <iostream>
using namespace std;

int main() {
	cout << "How long? ";
	int x;
	cin >> x;
	while (x > 0) {
		cout << "=";
		x--;
	}
	cout << endl;
}