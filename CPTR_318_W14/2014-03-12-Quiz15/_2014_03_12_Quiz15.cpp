#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
    os << '{';
    int n = vec.size();
    if (n > 0) {
        os << vec[0];
        for (int i = 1; i < n; i++)
            os << ',' << vec[i];
    }
    os << '}';
    return os;
}

void sort(vector<int>& vec) {
    for (auto iter = begin(vec); iter != end(vec); iter++)
        make_heap(iter, end(vec), greater<int>());
}

int main() {
    vector<int> vec{ 34, 2, 0, 45, 15, 3, 19, 45, 3, 30, 10 };
    cout << vec << endl;
    sort(vec);
    cout << vec << endl;
}
