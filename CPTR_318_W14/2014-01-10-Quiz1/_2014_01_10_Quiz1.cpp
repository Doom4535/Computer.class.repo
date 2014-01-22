#include <iostream>
#include <vector>

using namespace std;

//  The function’s behavior is undefined when v.size() < 1
int process(const vector<int>& v) {
    int n = v.size();
    int result = v[0];
    for (int i = 1; i < n; i++)
    if (result > v[i])
        result = v[i];
    return result;
}

int main() {
    cout << process({ 2, 3, 1, 4, -1, 2, 0, 2 }) << endl;
    cout << process({}) << endl;

}