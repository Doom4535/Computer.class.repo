#include <iostream>

using namespace std;

int main() {
    char b9, b8, b7, b6, b5, b4, b3, b2, b1, b0;

    cin >> b9 >> b8 >> b7 >> b6 >> b5 >> b4 >> b3 >> b2 >> b1 >> b0;

    int base10_value = 512 * (b9 - '0') + 256 * (b8 - '0') +
        128 * (b7 - '0') + 64 * (b6 - '0') + 32 * (b5 - '0')
        + 16 * (b4 - '0') + 8 * (b3 - '0')
        + 4 * (b2 - '0') + 2 * (b1 - '0')
        + (b0 - '0');


    

    cout << b9 << b8 << b7 << b6 << b5 << b4 << b3 << b2 << b1 << b0;
    cout << " (base 2) = " << base10_value
        << " (base 10)" << endl;

}