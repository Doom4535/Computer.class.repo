#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v1{ 1, 2, 3, 4, 5 },
                v2{ 10, 20, 30, 40, 50 },
                v3{ 100, 200, 300, 400, 500 };
    v2[5] = -1;  //  Undefined behavior
    cout << "Program finished" << endl;
}