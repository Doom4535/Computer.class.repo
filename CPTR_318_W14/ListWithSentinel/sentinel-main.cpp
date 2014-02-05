//  File:   SentinelLinkedList.cpp
//  Author: Rick Halterman

#include <iostream>
#include "llsentinel.h"

#include <list>
#include <vector>
#include <algorithm>

using namespace std;

typedef int TYPE;

void print(int n) {
	cout << n << ' ';
}

int main() {
	List<TYPE> list;
	bool done = false;
	TYPE value;
	char command;
	while (!done) {
		cin >> command;
		switch (command) {
			case 'I':
			case 'i':
			case '+':
				cin >> value;
				cout << "Inserting " << value << endl;
				list.insert(value);
				break;
			case 'D':
			case 'd':
			case '-':
				cin >> value;
				if (!list.remove(value))
					cout << "Cannot remove " << value << endl;
				else
					cout << "Removed " << value << endl;
				break;
			case 'P':
			case 'p':
				//list.print();
				cout << list << endl;
				break;
			case 'R':
			case 'r':
				list.print_reverse(cout);
				cout << endl;
				break;
			case '?':
				cout << "Insert (Ii+), Delete (Dd-), "
					<< "Print (Pp), Reverse print (Rr), "
					<< "Quit (Qq)" << endl;
				break;
			case 'Q':
			case 'q':
				done = true;
				break;
		}
	}


	std::list<int> llist;
	vector<int> vec;
	llist.push_back(2);
	llist.push_back(4);
	llist.push_back(6);
	vec.push_back(1);
	vec.push_back(3);
	vec.push_back(5);

	for_each(begin(llist), end(llist), print);
	cout << endl;
	for_each(begin(vec), end(vec), print);
	cout << endl;
}

