#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Prints the contents of vector v
template <typename T>
void print(const vector<T>& v) {
//    int n = v.size();
//    for (int i = 0; i < n; i++)
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    cout << endl;
}

// Prints the contents of vector v
template <typename T>
void print2(const vector<T>& v) {
    for (T i : v)
        cout << i << ' ';
    cout << endl;
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    int n = v.size();
    for (int i = 0; i < n; i++)
        os << v[i] << ' ';
    return os;
}

template <typename T>
void print3(T begin, T end) {
    for (auto p = begin; p != end; p++)
        cout << *p << ' ';
    cout << endl;
}

int main() {
    vector<int> int_vec{ 10, 20, 30, 40 };
    vector<string> str_vec{ "ABC", "DEF", "GHI" };

    print(int_vec);
    print(str_vec);
    cout << "------------" << endl;
    print2(int_vec);
    print2(str_vec);
    cout << "------------" << endl;
    cout << "[" << int_vec << "]" << endl;
    cout << "<" << str_vec << ">" << endl;
    cout << "------------" << endl;
    print3(begin(int_vec), end(int_vec));
    print3(begin(int_vec), begin(int_vec) + 2);
    print3(begin(str_vec), end(str_vec));

    int arr[] = { 50, 100, 150, 200, 250 };
    print3(arr, arr + 5);
}