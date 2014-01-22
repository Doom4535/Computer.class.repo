#include <iostream>

using namespace std;

int main() {
    int number;
    cout << "Enter a number in the range"
        << " 0...4:";
    cin >> number;
    if (number < 0)
        cout << "Number too small" << endl;
    else if (number == 0)
        cout << "zero" << endl;
    else if (number == 1)
        cout << "one" << endl;
    else if (number == 2)
        cout << "two" << endl;
    else if (number == 3)
        cout << "three" << endl;
    else if (number == 4)
        cout << "four" << endl;
    else 
        cout << "Number too big" << endl;
}