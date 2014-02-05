#include <iostream>
using namespace std;
int main() {
    int value;
    // Get number from the user
    cout << "Please enter an integer value in the range 0...1023: ";
    cin >> value;
    // Integer must be less than 1024
    if (0 <= value && value < 1024) {
        cout << value / 512;
        value %= 512;
        cout << value / 256;
        value %= 256;
        cout << value / 128;
        value %= 128;
        cout << value / 64;
        value %= 64;
        cout << value / 32;
        value %= 32;
        cout << value / 16;
        value %= 16;
        cout << value / 8;
        value %= 8;
        cout << value / 4;
        value %= 4;
        cout << value / 2;
        value %= 2;
        cout << value << endl;
    }
}