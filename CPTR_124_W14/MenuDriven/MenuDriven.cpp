//  File menu.cpp

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	bool done = false;
	do {
        //  User menu
		cout << "S)quare root P)rint C)ompile T)imes table Q)uit ==> ";
		char ch;
		cin >> ch;
		switch (ch) {
			case 'S':
			case 's': {  //  Compute square root
				double input;
				//  Get value from the user
				cout << "Enter number: ";
				cin >> input;
				double diff;
				//  Compute a provisional square root
				double root = 1.0;

				do {   //  Loop until the provisional root
				       //  is close enough to the actual root
					root = (root + input / root) / 2.0;
					//cout << "root is " << root << endl;
					//  How bad is the approximation?
					diff = root * root - input;
				} while (diff > 0.00001 || diff < -0.00001);

				//  Report approximate square root
				cout << "Square root of " << input << " = " << root << endl;

			}
				break;
			case 'P':
			case 'p':  //  Printing code (not yet implemented)
				cout << "You chose the \"Print\" option." << endl;
				break;
			case 'C':
			case 'c':  //  Compiling code (not yet implemented)
				cout << "You chose the \"Compile\" option." << endl;
				break;
			case 'T':
			case 't': {  //  Print a times table
				int size;
				cout << "Enter size: ";
				cin >> size;
				//----------------------------------------
				//  Print column headers
				//  Print the number labels
				cout << "     ";
				for (int col = 1; col <= size; col++)
					cout << setw(4) << col;
				cout << endl;
				//  Print the line
				cout << "    +";
				for (int col = 1; col <= size; col++)
					cout << "----";
				cout << endl;

				//----------------------------------------
				//  Print the table itself, along with the row headers
				//  Print the rows of the table
				for (int row = 1; row <= size; row++) {
					//  Print the row header
					cout << setw(3) << row << " |";
					//  Print the contents of a row; that is, each column entry
					for (int col = 1; col <= size; col++)
						cout << setw(4) << row*col;
					cout << endl;
				}
			}
				break;
			case 'Q':
			case 'q':  //  Quiz the program
				done = true;
				break;
		}
	} while (!done);
}
