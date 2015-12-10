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

char readChar() {
    // read a char from user input
    char c;
    cout << "Input a character: ";
    string tmp;
    getline(cin, tmp);
    c = tmp[0];
    return c;
}

bool isOperator(char op) {
    // checks if the input op is an operator, returns true or false
    int numOps = 4;
    char validOps[] = {'+', '-', '/', '*'};
    for (int i = 0; i < numOps; i++) {
        if (validOps[i] == op) {
            return true;
        }
    }
    return false;
    
}

int add(int x, int y) {
    // add two numbers
    return x + y;
}

int subtract(int x, int y) {
    // subtract y from x
    return x - y;
}

int divide(int x, int y) {
    // divide x by y
    return x / y;
}

int multiply(int x, int y) {
    // multiply x by y
    return x * y;
}

int calculator() {
    // calculator - take two numbers and an operator and calculate result
    cout << "Welcome to the calculator!\n";
    cout << "\nWhat is the first number?\n";
    int firstNum = readNum();
    cout << "\nWhat operator (e.g. + - / *)\n";
    int validOp = false;
    char op;
    while (!validOp) {
        op = readChar();
        if (isOperator(op) == 1) {
            validOp = true;
        }
        else {
            cout << "Please try again with a valid operator...\n";
        }
    }
    cout << "\nWhat is the second number?\n";
    int secondNum = readNum();
    
    int result = 0;
    cout << "\n" << firstNum << " " << op << " " << secondNum << " = "; 
    switch(op) {
        case '+': cout << add(firstNum, secondNum) << endl;
            break;
        case '-': cout << subtract(firstNum, secondNum) << endl;
            break;
        case '/': cout << divide(firstNum, secondNum) << endl;
            break;
        case '*': cout << multiply(firstNum, secondNum) << endl;
            break;
    }
    cout << endl;
    
    return 0;    
}

int main() {
    // mainloop
    while(true) {
        cout << "Hit enter to continue or input 'exit' to quit...\n";
        string choice;
        getline(cin, choice);
        if (choice == "exit" || choice == "quit") {
            break;
        }
        calculator();
    }
    return 0;
}