#include <iostream>

using namespace std;

int main() {
    char b9, b8, b7, b6, b5, b4, b3, b2, b1, b0;

    cin >> b9 >> b8 >> b7 >> b6 >> b5 >> b4 >> b3 >> b2 >> b1 >> b0;

    int base10_value = 0;

    if (b9 == '1')
        base10_value += 512;
    if (b8 == '1')
        base10_value += 256;
    if (b7 == '1')
        base10_value += 128;
    if (b6 == '1')
        base10_value += 64;
    if (b5 == '1')
        base10_value += 32;
    if (b4 == '1')
        base10_value += 16;
    if (b3 == '1')
        base10_value += 8;
    if (b2 == '1')
        base10_value += 4;
    if (b1 == '1')
        base10_value += 2;
    if (b0 == '1')
        base10_value += 1;

    cout << b9 << b8 << b7 << b6 << b5 << b4 << b3 << b2 << b1 << b0;
    cout << " (base 2) = " << base10_value 
         << " (base 10)" << endl;

}