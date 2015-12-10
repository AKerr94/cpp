#include <iostream>
#include <boost/lexical_cast.hpp>
#include <string>
using namespace std;

int readNum() {
    // loop until user has entered a valid integer 
    int num = 0;
    while (true) {
        cout << "Input an integer: ";
        string tmp;
        getline(cin, tmp);
        try {
            num = boost::lexical_cast<int>(tmp);
            cout << endl;
            break;
        }
        catch(...) {
            cout << "\nInvalid input! Try again...\n";
        }
    }
    return num;
}

int calculateFactors(int input, int *ptr) {
    // takes input, updates factors using pointer, returns total # of factors 
    int factorCount = 0;
    for (int i = input; i > 0; i--) {
        if (input % i == 0) {
            *(ptr + factorCount) = i;
            factorCount++;
        }
    }
    return factorCount;
}

int main() {
    // Ask user to input a number, calculate if this is prime and output all factors
    cout << "Which number should I check for being prime?\n";
    int num = readNum();
    int *factors = new int[num]; // generous array size 
    int factorCount = calculateFactors(num, factors);
    cout << "Number of factors: " << factorCount << endl;
    for (int i = 0; i < factorCount; i++) {
        cout << "Factor #" << i + 1 << " = " << *(factors + i) << endl;
    }
    if (factorCount == 2) {
        cout << num << " is a prime number!\n";
    }
}