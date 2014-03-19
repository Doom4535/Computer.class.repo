#include <iostream>

using namespace std;

int factorial(int n) {
    int product = 1;
    for (int i = n; i > 0; i--)
        product *= i;
    return product;
}

int factorial2(int n) {
    if (n > 0)
        return n * factorial2(n - 1);
    else
        return 1;
}

int main() {
    for (int i = 0; i < 10; i++)
        cout << i << "! = " << factorial(i) 
             << "   " << factorial2(i) << endl;
}