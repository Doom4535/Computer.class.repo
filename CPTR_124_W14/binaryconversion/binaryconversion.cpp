//  Decimal-tp-binary number conversion
#include <iostream>
using namespace std;

int main() {
    int value;
    // Get number from the user
    cout << "Please enter an integer value in the range 0...1023: ";
    cin >> value;
    // Integer must be less than 1024
    if (0 <= value && value < 1024) {
        if (value >= 512) {
            cout << 1;
            value %= 512;
        }
        else
            cout << 0;
        if (value >= 256) {
            cout << 1;
            value %= 256;
        }
        else
            cout << 0;
        if (value >= 128) {
            cout << 1;
            value %= 128;
        }
        else
            cout << 0;
        if (value >= 64) {
            cout << 1;
            value %= 64;
        }
        else
            cout << 0;
        if (value >= 32) {
            cout << 1;
            value %= 32;
        }
        else
            cout << 0;
        if (value >= 16) {
            cout << 1;
            value %= 16;
        }
        else
            cout << 0;
        if (value >= 8) {
            cout << 1;
            value %= 8;
        }
        else
            cout << 0;
        if (value >= 4) {
            cout << 1;
            value %= 4;
        }
        else
            cout << 0;
        if (value >= 2) {
            cout << 1;
            value %= 2;
        }
        else
            cout << 0;
        cout << value << endl;
    }
}