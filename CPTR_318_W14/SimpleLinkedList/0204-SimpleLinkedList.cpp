//  File:   0204-SimpleLinkedList.cpp
//  Author: Rick Halterman

#include <iostream>
#include "simplellist.h"

using namespace std;

typedef int TYPE;

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
               if ( !list.remove(value) )
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
}

