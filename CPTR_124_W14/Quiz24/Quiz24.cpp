#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v{ 5, 0, 1, 3, 2 };
	int i = 2;
	cout << v[i] << endl;  // 1.
	cout << v[i + 1] << endl;  // 2.
	cout << v[i] + 1 << endl;  // 3.
	cout << v.size() << endl;  // 4.
	cout << v[v[i]] << endl;  // 5.
}