//  One possible solution

#include <iostream>
#include <string>

using namespace std;

//  Encode a plaintext message using a translation table.
//  Does NOT do any error checking for bad characters.
//  Returns the encoded message
string translate(string message, string from, string to) {
	string result = "";  //  Start with an empty string
	for (char letter : message)
		result += to[from.find(letter)];
	return result;
}

//  Allows the user to interactively encode messages
int main() {
	//  "Program" the translation tables
	string plain  = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ",
		   cipher = "GTSZ MHKALUNFQEPRVDBYXJCWOI";
	bool done = false;
	while (!done) {
		cout << "Enter messages (empty message quits): ";
		string message;         //  User's original message
		getline(cin, message);  //  Get message from user
		if (message == "")      //  Empty message quits
			done = true;        //  User finished
		else {                  //  Encrypt, then decrypt
			string encoded = translate(message, plain, cipher),
				   decoded = translate(encoded, cipher, plain);
			cout << "Encoded: " << encoded << endl;
			cout << "Decoded: " << decoded << endl;
			cout << "---------------------------------" << endl;
		}
	}
}

