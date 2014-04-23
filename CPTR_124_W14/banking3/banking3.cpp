#include <iostream>
#include <string>
#include <vector>
#include "account.h"

using namespace std;

//  Allows the user to enter via the keyboard information
//  about an account and adds that account to the database.
void add_account(vector<Account>& accts) {
	string name;
	int number;
	double amount;

	cout << "Enter name, account number, and account balance: ";
	cin >> name >> number >> amount;
	Account acct(name, number, amount);
	accts.push_back(acct);
}

//  Print all the accounts in the database
void print_accounts(const vector<Account>& accts) {
	for (Account acct : accts)
		acct.print();
}

//  Allow the user to make a deposit on behalf of a bank
//  customer
void make_deposit(vector<Account>& accts) {
	int number;
	double amount;

	cout << "Enter account number and amount to deposit: ";
	cin >> number >> amount;
	//  Find account, if possible
	int size = accts.size();
	for (int i = 0; i < size; i++) {
		if (accts[i].get_id() == number) {
			if (!accts[i].deposit(amount))
				cout << "Deposit not possible at this time." << endl;
			return;
		}
	}
	cout << "Account " << number << " does not exist.  "
		<< "Could not complete deposit" << endl;
}

//  Allow the user to withdraw funds from an account.
void make_withdrawal(vector<Account>& accts) {
	int number;
	double amount;

	cout << "Enter account number and amount to withdraw: ";
	cin >> number >> amount;
	//  Find account, if possible
	int size = accts.size();
	for (int i = 0; i < size; i++) {
		if (accts[i].get_id() == number) {
			if (!accts[i].withdraw(amount))
				cout << "Insufficient funds" << endl;
			return;
		}
	}
	cout << "Account  " << number << " does not exist.  "
		<< " Could not complete withdrawal" << endl;
}



//  Allows a user interact with a bank account database.
int main() {
	//  The simple database of bank accounts
	vector<Account> customers;

	//  User command
	char cmd;

	//  Are we done yet?
	bool done = false;

	do {
		cout << "[A]dd [P]rint [D]eposit [W]ithdraw [Q]uit==> ";
		cin >> cmd;
		switch (cmd) {
		case 'A':
		case 'a':
			//  Add an account
			add_account(customers);
			break;
		case 'P':
		case 'p':
			//  Print customer database
			print_accounts(customers);
			break;
		case 'D':
		case 'd':
			//  Deposit funds
			make_deposit(customers);
			break;
		case 'W':
		case 'w':
			//  Withdraw funds
			make_withdrawal(customers);
			break;
		case 'Q':
		case 'q':
			done = true;
			break;
		}
	} while (!done);
}

