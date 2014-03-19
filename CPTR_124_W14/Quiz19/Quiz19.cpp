#include <iostream>
using namespace std;

int main() {
	int x = 2, y = 3;
	int *p = &x, *q = &y;
	cout << *p << endl;   // 1.
	cout << *q << endl;  // 2.
	*p = *q;
	cout << *p << endl;  // 3.
	cout << *q << endl;  // 4.
	x = 4, y = 5;
	p = q;
	cout << *p << endl;  // 5.
}