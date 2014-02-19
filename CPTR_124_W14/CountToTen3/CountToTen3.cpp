#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    //  Count to 10 with a while statement
	int count = 1;
	while (count <= 10) {
        cout << count << endl;
		count++;
	}

    //  Count to 10 with a for statement
	for (int cnt = 1; cnt <= 10; cnt++) {
        cout << cnt << endl;
	}

    //  Count to 100 by 3s
	for (int cnt = 3; cnt <= 100; cnt += 3) {
        cout << cnt << endl;
	}

    //  Print the powers of ten (left justified)
	for (int n = 1; n <= 1000000000; n *= 10)
        cout << n << endl;

    //  Print the powers of ten (right justified)
	for (int n = 1; n <= 1000000000; n *= 10)
        cout << setw(10) << n << endl;
}