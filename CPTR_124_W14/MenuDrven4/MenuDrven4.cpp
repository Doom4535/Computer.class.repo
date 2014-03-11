//  File menu.cpp

#include <iostream>
#include <iomanip>
#include "my_special_math.h"

using namespace std;

int main() {
	bool done = false;
	do {
		//  User menu
		cout << "S)quare root P)rimes C)ompile T)imes table Q)uit ==> ";
		char ch;
		cin >> ch;
		switch (ch) {
			case 'S':
			case 's': {  //  Compute square root
				double input;
				cin >> input;
				cout << "Square root of " << input
					<< " = " << sqrt(input) << endl;
			}
				break;
			case 'P':
			case 'p':  {
				cout << "Enter low and high values for a range: ";
				int low, high;
				cin >> low >> high;
				print_primes(low, high);
			}
				break;
			case 'C':
			case 'c':  //  Compiling code (not yet implemented)
				cout << "You chose the \"Compile\" option." << endl;
				break;
			case 'T':
			case 't': {  //  Print a times table
				int size;
				cout << "Enter size of times table: ";
				cin >> size;
				times_table(size);
			}
				break;
			case 'Q':
			case 'q':  //  Quiz the program
				done = true;
				break;
		}
	} while (!done);
}