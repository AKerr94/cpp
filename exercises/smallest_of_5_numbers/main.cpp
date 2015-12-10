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
            break;
        }
        catch(...) {
            cout << "\nInvalid input! Try again...\n";
        }
    }
    return num;
}

int returnSmallest(int inputNums[], int length) {
    // iterate over list of ints and return the smallest one
    int count = 0;
    int smallestSoFar = 0;
    for (int i = 0; i < length; i++) {
        if (count == 0) {
            smallestSoFar = inputNums[0];
        }
        else {
            if (smallestSoFar > inputNums[i]) {
                smallestSoFar = inputNums[i];
            }
        }
        count++;
    }
    return smallestSoFar;
}

int main() {
    // main function - read in 5 numbers and output the smallest one
    int numbers[5];
    int length = sizeof(numbers)/sizeof(numbers[0]);
    for (int i = 0; i < length; i++) {
        cout << "\nGetting value for #" << i + 1 << "\n";
        numbers[i] = readNum();
    }
    int smallest = returnSmallest(numbers, length);
    cout << "\nThe smallest number was: " << smallest << endl;
    return 0;
}