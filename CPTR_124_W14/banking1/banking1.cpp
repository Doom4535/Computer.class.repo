#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Account {
public:
	//  String representing the name of the account's owner
	string name;
	//  The account number
	int id;
	//  The current account balance
	double balance;
};

//  Allows the user to enter via the keyboard information
//  about an account and adds that account to the database.
void add_account(vector<Account>& accts) {
	string name;
	int number;
	double amount;

	cout << "Enter name, account number, and account balance: ";
	cin >> name >> number >> amount;
	Account acct;
	acct.name = name;
	acct.id = number;
	acct.balance = amount;
	accts.push_back(acct);
}

//  Print all the accounts in the database
void print_accounts(const vector<Account>& accts) {
	int n = accts.size();
	for (int i = 0; i < n; i++)
		cout << accts[i].name << "," << accts[i].id
		<< "," << accts[i].balance << endl;
}

bool less_than_by_name(const Account& e1, const Account& e2) {
	return e1.name < e2.name;
}


bool less_than_by_id(const Account& e1, const Account& e2) {
	return e1.id < e2.id;
}

bool less_than_by_balance(const Account& e1, const Account& e2) {
	return e1.balance < e2.balance;
}

//  Sorts a bank account database into ascending order
//  The comp parameter determines the ordering
void sort(vector<Account>& db,
	bool(*comp)(const Account&, const Account&)) {
	int size = db.size();
	for (int i = 0; i < size - 1; i++) {
		int smallest = i;
		for (int j = i + 1; j < size; j++)
			if (comp(db[j], db[smallest]))
				smallest = j;
		if (smallest != i)
			swap(db[i], db[smallest]);
	}
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
		if (accts[i].id == number) {
			accts[i].balance += amount;
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
		if (accts[i].id == number) {
			accts[i].balance -= amount;
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
		cout << "[A]dd [N]ame [I]D [B]alance [D]eposit [W]ithdraw [Q]uit==> ";
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
		case 'N':
		case 'n':
			//  Sort database by name
			sort(customers, less_than_by_name);
			print_accounts(customers);
			break;
		case 'I':
		case 'i':
			//  Sort database by ID (account number)
			sort(customers, less_than_by_id);
			print_accounts(customers);
			break;
		case 'B':
		case 'b':
			//  Sort database by account balance
			sort(customers, less_than_by_balance);
			print_accounts(customers);
			break;
		case 'D':
		case 'd':
			//  Deposit funds
			make_deposit(customers);
			print_accounts(customers);
			break;
		case 'W':
		case 'w':
			//  Withdraw funds
			make_withdrawal(customers);
			print_accounts(customers);
			break;
		case 'Q':
		case 'q':
			done = true;
			break;
		}
	} while (!done);
}

