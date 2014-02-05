//  This program counts to 10
#include <iostream>

using namespace std;

int main() {
	int count = 1;
	while (count <= 100) {
		if (count % 3 == 0)
		    cout << count << endl;
		count++;
	}
}