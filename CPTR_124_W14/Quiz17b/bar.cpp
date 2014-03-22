#include <iostream>
using namespace std;

void bar(int n) {
    cout << "[";
    for (int i = 0; i < n; i++)
        cout << "*";
    cout << "]" << endl;
}