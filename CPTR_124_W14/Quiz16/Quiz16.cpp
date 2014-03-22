#include <iostream>
using namespace std;

void bar(int n) {
    cout << "[";
    for (int i = 0; i < n; i++)
        cout << "=";
    cout << "]" << endl;
}

int main() {
    bar(0); //  1.
    bar(1); //  2.
    bar(2); //  3.
    bar(5); //  4.
}