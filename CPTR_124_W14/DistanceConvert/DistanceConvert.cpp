#include <iostream>

using namespace std;

int main() {
    ////  Play with and without endl
    //cout << "x" << endl;
    //cout << "y" << endl;
    //cout << "-------" << endl;
    //cout << "x";
    //cout << "y" << endl;

    ////  Get a value from the user and display it
    ////  Showing off how to use cin
    //cout << "Please enter an integer value: ";
    //int num;
    //cin >> num;
    //cout << "You entered " << num << "." << endl;
    
    //  Do some distance conversions
    int miles, feet, inches;

    cout << "Please enter miles, feet, and inches: ";
    cin >> miles >> feet >> inches;
    int total_inches = 5280 * 12 * miles 
                       + 12 * feet + inches;
    cout << miles << " mi, " << feet << " ft, "
        << inches << " in = " << total_inches << " in"
        << endl;

    cout << "Please enter the total number of inches:";
    cin >> total_inches;
    miles = total_inches / (5280 * 12);
    total_inches = total_inches % (5280 * 12);
    feet = total_inches / 12;
    total_inches = total_inches % 12;
    cout << miles << " " << feet << " " 
        << total_inches << endl;



}