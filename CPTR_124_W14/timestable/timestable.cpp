#include <iostream>
#include <iomanip>

using namespace std;

int main() {
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