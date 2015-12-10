#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

// global list with characters 
char characters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

string getFilename() {
    // Read a filename from user input
    cout << "Please enter the file name (e.g. text_file.txt)\n: ";
    string filename;
    getline(cin, filename);
    return filename;
}

bool doesFileExist(string filename) {
    // check if a given file exists/ is accessible
    cout << "Checking that '" << filename << "' exists and is accessible...\n";
    if (ifstream(filename)) {
        return true;
    }
    else {
        return false;
    }
}

string readFileToBuffer(string filename) {
    // reads file into string buffer and returns this
    string buffer;
    ifstream infile;
    infile.open(filename);
    while (!infile.eof()) {
        string tmp;
        getline(infile, tmp);
        buffer.append(tmp + "\n");
    }
    infile.close();
    return buffer;
}

string stringToLower(string str) {
    // iterate over each char in str and convert to lowercase
    string final;
    for (int i = 0; i < str.length(); i++) {
        char tmp = tolower(str[i]);
        final += tmp;
    }
    return final;
}

map<char, int> initialiseCharCountMap() {
    // initialise map with all characters as keys
    map<char, int> charCounts;
    for (int i = 0; i < strlen(characters); i++) {
        charCounts[characters[i]] = 0;
    }
    return charCounts;
}

map<char, int> generateCharCountMap(string buffer) {
    // creates map entry for count of each character in buffer, returns map
    map<char, int> charCounts = initialiseCharCountMap();
    for (int i = 0; i < buffer.length(); i++) {
        char c = buffer[i];
        for (int j = 0; j < strlen(characters); j++) {
            if (c == characters[j]) {
                charCounts[c]++;
                break;
            }
        }
    }
    return charCounts;
}

void displayResults(map<char, int> charCounts) {
    // outputs counts for each character
    cout << "\n\nFinal counts:\n\n";
    for (int i = 0; i < strlen(characters); i++) {
        char c = characters[i];
        cout << c << " " << charCounts[c] << endl;
    }
    return; 
}

int processor() {
    // Read a user specified file and print out number of occurences of each character 
    // Return 1 for error or 0 for success

    // Get user to input filename to read
    string filename = getFilename();

    // validate file exists and is accessible
    bool fileExists = doesFileExist(filename);
    cout << "Validation check: ";
    if (fileExists) {
        cout << "OK\n";
    }
    else {
        cout << "File not found or not accessible!\n";
        return 1;
    }

    // read file into string buffer and convert to lowercase 
    string buffer = readFileToBuffer(filename);
    buffer = stringToLower(buffer);

    // Count characters in string
    map<char, int> charCounts = generateCharCountMap(buffer);

    // Output results
    displayResults(charCounts);

    return 0;
}

int main() {
    // main loop
    bool mainLoop = true;
    while (mainLoop) {
        // call main handler and check if program ran successfully
        int success = processor();
        if (success == 0) {
            mainLoop = false;
        }
        else {
            // give user option to quit progam, else continue looping 
            cout << "\nPlease try again with a valid file (press enter now) or type 'exit' to quit!\n";
            string choice;
            getline(cin, choice);
            if (choice.compare("exit") == 0 || choice.compare("quit") == 0) {
                mainLoop = false;
                cout << "Exiting now...\n";
            }
            else {
                cout << "\nLooping again...\n\n";
            }
        }
    }
    return 0;
}
