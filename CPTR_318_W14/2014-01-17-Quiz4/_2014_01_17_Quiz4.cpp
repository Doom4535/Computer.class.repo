#include <iostream>

using namespace std;

int random(int m, int n) {
    return rand() % (n - m) + m;
}

//  Is this a decent random function?
int other_random(int m, int n) {
    int result;
    do
        result = rand();
    while (result < m || result >= n);
    return result;
}


int main() {
    //  Test random
    for (int i = 0; i < 100; i++)
        cout << random(10, 20) << ' ';
    cout << endl;
    //  Test other_random
    for (int i = 0; i < 100; i++)
        cout << other_random(10, 20) << ' ';
    cout << endl;
}