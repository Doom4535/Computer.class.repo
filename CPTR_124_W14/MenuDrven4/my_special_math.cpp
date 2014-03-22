//  File menu.cpp

#include "my_special_math.h"

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

