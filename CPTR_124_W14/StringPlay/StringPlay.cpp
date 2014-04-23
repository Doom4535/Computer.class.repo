#include <iostream>
#include <string>

using namespace std;

int main() {
	string word = "hello";
	cout << "The word \"" << word 
		 << "\" contains " << word.length()
		 << " letters." << endl;
	for (int i = 0; i < word.length(); i++)
		cout << "[" << word[i] << "]";
	cout << endl;
	for (char c : word)
		cout << "<" << c << ">";
	cout << endl;
	cout << "--------" << endl;
	cout << "Please enter your name: ";
	cin >> word;
	cout << "Your name \"" << word 
		 << "\" contains " << word.length()
		 << " letters." << endl;
	for (int i = 0; i < word.length(); i++)
		cout << "[" << word[i] << "]";
	cout << endl;
	for (char c : word)
		cout << "<" << c << ">";
	cout << endl;

	cout << word + " Halterman" << endl;
	word += "A";
	cout << word << endl;
}