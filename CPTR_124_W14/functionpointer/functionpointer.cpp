#include <iostream>

using namespace std;

int add(int a, int b) {
	return a + b;
}

int multiply(int a, int b) {
	return a * b;
}

int increase(int a) {
	return a + 1;
}

int eval(int a, int b, int(*f)(int, int)) {
	return f(a, b);
}

int main() {
	cout << add(10, 20) << endl;
	cout << multiply(10, 20) << endl;
	cout << eval(1, 2, add) << endl;
	cout << eval(2000, 800, multiply) << endl;
	//  The following statement is illegal because
	//  the increase function's signature does not match
	//  the signature of eval's third parameter
	//cout << eval(2000, 800, increase) << endl;
}
