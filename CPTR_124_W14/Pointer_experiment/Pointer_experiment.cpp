#include <iostream>

using namespace std;

int main() {
	int x = 2, *p = &x;
	double d = 4.5;
	x = static_cast<int>(d);
	cout << x << endl;
	cout << reinterpret_cast<int>(p) << endl;
}