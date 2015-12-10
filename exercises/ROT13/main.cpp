#include <string>
#include <iostream>
using namespace std;

int cipherLength = 0;
char characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '-'};
char cipherOneChar(char ch) {
	// ROT13 - rotate char 13 places 
	// Used for both encoding and decoding 
	ch = tolower(ch);
	for (int i = 0; i < 13; ch++, i++) {
		if (ch == 'z' && i == 12) {
			return 'a';
		}
		if (ch > 'z')  {
			ch = 'a';
		}
		else if (ch == '-') {
			return ' ';
		}
	}
	return ch;
}

bool isCipherChar(char c) {
	// check if cipher applies to this char (i.e. is a letter of alphabet). If not return false
	for (int i = 0; i < sizeof(characters)/ sizeof(characters[0]); i++) {
		if ( c == characters[i]) {
			return true;
		}
	}
	return false;
}

string applyROT13(string input) {
	// iterate over string applying ROT13 to each char
	string output;
	for (int i = 0; i < input.length(); i++) {
		if (isCipherChar(input[i]) == false) {
			output[i] = input[i];
		}
		else {
			output[i] = cipherOneChar(input[i]);
		}
		cout << output[i] << " from " << input[i] << endl;
		cipherLength++;
	}
	cout << endl;
	return output;
}

void displayString(string input, int length) {
	// cout string 
	for (int i = 0; i < length; i++) {
		cout << input[i];
	}
	cout << endl;
}

int main(int argc, char **argv) {
	// main handler for inputting string (or reading from argv) and applying cipher then displaying result
	string clearText;
	if (argc > 1) {
		clearText = argv[1];
		cout << "Read '" << clearText << "' as cipher input from command line" << endl;
	}
	else {
		cout << "Input text to cipher: ";
		getline(cin, clearText);
	}
	string cipherText = applyROT13(clearText);
	displayString(cipherText, cipherLength);
}
