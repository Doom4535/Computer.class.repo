//  File:   2014-01-08-ReadTextFileVectors.cpp
//  Author: Rick Halterman
//  Date:   1/08/2014

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;


//  Reads n elements from file stream f
//  into vector vec.  vec must have allocated space at least as large as n.
template <typename T>
void read_file(istream& f, vector<T>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++)
        f >> vec[i];
}

//  Prints the elements of vector vec.
template <typename T>
void print_vector(const vector<T>& vec) {
    int n = vec.size();
    for (int i = 0; i < n; i++)
        cout << vec[i] << ' ';
    cout << endl;
}

int main() {
    //  File stream object
    ifstream fin("data1.text");
    //  Did the file open properly?
    if (fin.good()) {
        //  Read the number of integers in the file
        int count;
        fin >> count;
        if (count > 0) {
            //  Allocate space in a vector
            vector<int> list(count);
            //  Read elements from file into array
            read_file(fin, list);
            //  Print the contents of the array
            print_vector(list);
            //  Sort the array into descending order
            sort(begin(list), end(list), greater<int>());
            //  Print the sorted array
            print_vector(list);
            //  The vector cleans up itself
        }
        fin.close();
    }
    else
        cout << "Could not open file" << endl;
}

