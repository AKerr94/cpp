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
            if (num < 0) {
                cout << "\nEnter a value of 0 or more!\n";
                continue;
            }
            break;
        }
        catch(...) {
            cout << "\nInvalid input! Try again...\n";
        }
    }
    return num;
}

int fib(int n) {
    // Recursive function to return nth integer of the fibonacci sequence 
    if (n == 0 || n == 1) {
        return n;
    }
    return fib(n - 1) + fib(n -2);
}

int main() {
    // read user's choice n and get nth value in fibonacci sequence 
    cout << "Enter integer n to get value of #n in the fibonacci sequence\n";
    int n = readNum();
    int result = fib(n);
    cout << "fib(" << n << ") = " << result << endl;
    return 0;
}