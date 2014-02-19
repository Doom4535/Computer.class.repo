#include <iostream>

using namespace std;

int main() {
	////  Original code
	//int number;
	////  Get number from user
	//cout << "Enter a number: ";
	//cin >> number;
	////  Determine if the number is prime
	//int potential_factor = 2;
	//while (potential_factor < number) {
	//	if (number % potential_factor == 0) {
	//		cout << "Found a factor: "
	//			<< potential_factor << endl;
	//	}
	//	potential_factor++;
	//}


 //   //  Option #1: Count the number of factors
	//int number;
 //   //  Get number from user
	//cout << "Enter a number: ";
	//cin >> number;
 //   //  Determine if the number is prime
	//int potential_factor = 2, count = 0;
	//while (potential_factor < number) {
	//	if (number % potential_factor == 0) 
	//		count++;
 //       potential_factor++;
	//}
	//if (count > 0)
	//	cout << number << " is NOT prime" << endl;
	//else
	//	cout << number << " is prime" << endl;

    //  Option #2: Early exit from loop
	int number;
    //  Get number from user
	cout << "Enter a number: ";
	cin >> number;
    //  Determine if the number is prime
	int potential_factor = 2;
	bool found = false;
    //  Try all potential factors until we find one
    //  or determine that none exit
	while (potential_factor < number) {
		if (number % potential_factor == 0) {
			found = true;  //  We found a factor
			break;  //  Exit the loop
		}
        potential_factor++;
	}
	if (found)  //  Did we find a factor?
		cout << number << " is NOT prime" << endl;
	else        //  We did not find a factor
		cout << number << " is prime" << endl;
}