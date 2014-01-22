#include <iostream>

using namespace std;

int main() {
    int x, y, z;
    cout << "Please enter two integers: ";
    cin >> x >> y;
    if (y != 0) {
        z = x / y;
        cout << x << " / " << y << " = " << z << endl;
    }
    else {
        cout << "Cannot divide by zero!" << endl;
    }
    cout << "Program done." << endl;

}