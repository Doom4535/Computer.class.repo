#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

int calc(int n) {
	return 10 * n + 1;
}

int main() {
	double num = sqrt(4);
	char ch = toupper('e');
	cout << num << endl;
	cout << ch << endl;
	cout << pow(2, 3) << endl;
	cout << calc(5) << endl;
	cout << calc(0) << endl;
}