//  File menu.cpp

#include <iostream>
#include <iomanip>

using namespace std;

void times_table(int n) {
	//----------------------------------------
	//  Print column headers
	//  Print the number labels
	cout << "     ";
	for (int col = 1; col <= n; col++)
		cout << setw(4) << col;
	cout << endl;
	//  Print the line
	cout << "    +";
	for (int col = 1; col <= n; col++)
		cout << "----";
	cout << endl;

	//----------------------------------------
	//  Print the table itself, along with the row headers
	//  Print the rows of the table
	for (int row = 1; row <= n; row++) {
		//  Print the row header
		cout << setw(3) << row << " |";
		//  Print the contents of a row; that is, each column entry
		for (int col = 1; col <= n; col++)
			cout << setw(4) << row*col;
		cout << endl;
	}
}

//  Returs true, if n is a prime number; otherwise, 
//  returns false
bool is_prime(int n) {
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) //  Is i a factor of n?
			return false;
	return true;
}

//  Prints all the prime numbers in the range
//  begin to end, inclusive
void print_primes(int begin, int end) {
	for (int i = begin; i <= end; i++)
		if (is_prime(i))
			cout << i << ' ';
	cout << endl;
}

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
    //  Almost done
	cout << 45 << " is"
		<< (is_prime(45) ? " " : " not ")
		<< "prime" << endl;
}
