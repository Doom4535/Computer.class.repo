#ifndef ACCOUNT_H_
#define ACCOUNT_H_

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
	//  String representing the name of the account's owner
	string name;
	//  The account number
	int id;
	//  The current account balance
	double balance;
public:
	//  Creates a new account object with client-supplied
	//  values for the account holder's name, account number,
	//  and initial funds in the account.
	Account(string n, int i, double b);
	//  Deposits a given amount of funds into an account object.
	//  Returns true if successful.
	//  This method currently always succeeds.
	bool deposit(double amount);
	//  Withdraws a given amount of funds from an account
	//  object, if possible.  Returns true id successful.
	//  The method leaves the object unchanged and returns
	//  false if the account object contains insufficient
	//  funds to satisfy the desired withdraw amount.
	bool withdraw(double amount);
	//  Prints data held by an account object.
	void print();
	//  Returns the account number of an account object.
	int get_id();
};

#endif

