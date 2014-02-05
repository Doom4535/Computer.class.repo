#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y;
	if (x < y) {
		if (x <= 4)
			z = 3;
		else
			z = 0;
	}
	else {
		if (y <= 4)
			z = 2;
		else
			z = 1;
	}
	cout << z << endl;
}