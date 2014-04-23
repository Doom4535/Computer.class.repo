#include <iostream>
#include <string>
#include <vector>
#include "account.h"

using namespace std;

//  Creates a new account object with client-supplied
//  values for the account holder's name, account number,
//  and initial funds in the account.
Account::Account(string n, int i, double b) : name(n), id(i), balance(b) {
}

//  Deposits a given amount of funds into an account object.
//  Returns true if successful.
//  This method currently always succeeds.
bool Account::deposit(double amount) {
	balance += amount;
	return true;
}

//  Withdraws a given amount of funds from an account
//  object, if possible.  Returns true id successful.
//  The method leaves the object unchanged and returns
//  false if the account object contains insufficient
//  funds to satisfy the desired withdraw amount.
bool Account::withdraw(double amount) {
	if (amount <= balance) {
		balance -= amount;
		return true;
	}
	else
		return false;
}

//  Prints data held by an account object.
void Account::print() {
	cout << "[Name: " << name << " | Account number: "
		<< id << " |  Balance: " << balance << "]" << endl;
}

//  Returns the account number of an account object.
int Account::get_id() {
	return id;
}


