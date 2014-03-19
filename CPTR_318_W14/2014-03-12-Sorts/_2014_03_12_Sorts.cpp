#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

/*
*   selection_sort(v)
*       Arranges the elements of v in ascending order.
*       v is a vector of ints.  The contents of v are
*       physically rearranged.
*/
template <typename T>
void selection_sort(vector<T>& v) {
    int n = v.size();
    //  Start at the beginning, but stop one position before the end of the vector
    for (int i = 0; i < n - 1; i++) {
        //  Note: i, small, and j represent positions within v.
        //  those positions.
        //  small is the position of the smallest value we've seen
        //  so far; we use it to find the smallest value less 
        //  than the value at position iter.
        int small = i;
        //  See if a smaller value can be found later in the vector
        //  Start one past iter, but go all the way to the end of the vector
        for (int j = i + 1; j < n; j++)
            if (v[j] < v[small])
                small = j;  //  Found a smaller value
        //  Swap elements at position iter and small, if a smaller value was found
        if (i != small)
            swap(v[i], v[small]);
    }
}


template <typename Iter>
void selection_sort(Iter begin, Iter end) {
    if (begin != end) {
        //  Start at the beginning, but stop one position before the end of the vector 
        for (auto iter = begin; iter != end - 1; iter++) {
            //  Note: iter, small, and rest represent positions within the vector.
            //  small is the position of the smallest value we've seen so far; we use it to
            //   find the smallest value less than the value at position iter.
            Iter small = iter;
            //  See if a smaller value can be found later in the vector
            //  Start one past iter, but go all the way to the end of the vector. 
            for (auto rest = iter + 1; rest != end; rest++)
                if (*rest < *small)
                    small = rest;  //  Found a smaller value
            //  Swap elements at position iter and small, if a smaller value was found
            if (iter != small)
                swap(*iter, *small);
        }
    }
}



template <typename T>
void insertion_sort(vector<T>& v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        T key = v[i];
        int pos = i;
        //  Shift larger values to the right
        while (pos > 0 && v[pos - 1] > key) {
            v[pos] = v[pos - 1];
            pos--;
        }
        v[pos] = key;
    }
}


template <typename Iter>
void insertion_sort(Iter begin, Iter end) {
    if (begin != end) {
        for (auto iter = begin + 1; iter != end; iter++) {
            auto key = *iter;
            Iter pos = iter;
            //  Shift larger values to the right
            while (pos > begin && *(pos - 1) > key) {
                *pos = *(pos - 1);
                pos--;
            }
            *pos = key;
        }
    }
}



template <typename T>
T partition(vector<T>& v, int p, int r) {
    T x = v[r];
    int i = p - 1;
    for (int j = p; j <= r - 1; j++) {
        if (v[j] <= x) {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[r]);  //  Move pivot to its proper place
    return i + 1;
}


template <typename T>
void quicksort(vector<T>& v, int p, int r) {
    if (p < r) {
        int j = partition(v, p, r);
        quicksort(v, p, j - 1);
        quicksort(v, j + 1, r);
    }
}

template <typename T>
void quicksort(vector<T>& v) {
    quicksort(v, 0, v.size() - 1);
}

template <typename Iter>
Iter partition(Iter p, Iter r) {
    auto x = *r;
    Iter i = p;
    for (Iter j = p; j <= r - 1; j++) {
        if (*j <= x) {
            swap(*i, *j);
            i++;
        }
    }
    swap(*i, *r);  //  Move pivot to its proper place
    return i;
}

template <typename Iter>
void qsort(Iter p, Iter r) {
    if (p != r) {
        Iter j = partition(p, r);
        if (j != p) qsort(p, j - 1);
        if (j != r) qsort(j + 1, r);
    }
}

template <typename Iter>
void quicksort(Iter p, Iter r) {
    if (distance(p, r) > 1) //  Nothing to do if the sequence has fewer than two elements
        qsort(p, r - 1);    //  Iterators set to first and last elements
}


template <typename Iter>
bool is_ascending(Iter p, Iter r) {
    if (p != r)
    while (++p != r)
        if (*p < *(p - 1))
            return false;
    return true;
}


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

int main() {
    cout << "----Selection sort: vector------------" << endl;
    vector<int> vec{ 34, 2, 0, 45, 15, 3, 19, 45, 3, 30, 10 };
    cout << vec << endl;
    selection_sort(vec);
    assert(is_ascending(begin(vec), end(vec)));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    cout << "----Selection sort: iterators------------" << endl;
    vec = { 34, 2, 0, 45, 15, 3, 19, 45, 3, 30, 10 };
    cout << vec << endl;
    selection_sort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));
    cout << "----Insertion sort: vector------------" << endl;
    vec = { 34, 2, 0, 45, 15, 3, 19, 45, 3, 30, 10 };
    cout << vec << endl;
    insertion_sort(vec);
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));
    cout << "----Insertion sort: iterators------------" << endl;
    vec = { 34, 2, 0, 45, 15, 3, 19, 45, 3, 30, 10 };
    cout << vec << endl;
    insertion_sort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));
    cout << "----Quicksort: vector------------" << endl;
    vec = { 34, 2, 0, 45, 15, 3, 19, 45, 3, 30, 10 };
    cout << vec << endl;
    quicksort(vec);
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));
    cout << "----Quicksort: iterators------------" << endl;
    vec = { 34, 2, 0, 45, 15, 3, 19, 45, 3, 30, 10 };
    cout << vec << endl;
    quicksort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));

    cout << "----Empty selection sort------------" << endl;
    vec = {};
    cout << vec << endl;
    selection_sort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));

    cout << "----Empty insertion sort------------" << endl;
    vec = {};
    cout << vec << endl;
    insertion_sort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));
    cout << "----Empty quicksort------------" << endl;
    vec = {};
    cout << vec << endl;
    quicksort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));

    cout << "----Singleton selection sort------------" << endl;
    vec = { 1 };
    cout << vec << endl;
    selection_sort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));

    cout << "----Singleton insertion sort------------" << endl;
    vec = { 1 };
    cout << vec << endl;
    insertion_sort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));
    cout << "----Singleton quicksort------------" << endl;
    vec = { 1 };
    cout << vec << endl;
    quicksort(begin(vec), end(vec));
    cout << vec << "  " << is_ascending(begin(vec), end(vec)) << endl;
    assert(is_ascending(begin(vec), end(vec)));
}
