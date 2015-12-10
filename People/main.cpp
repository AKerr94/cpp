/* 
 * Author: Alastair Kerr
 */

#include <cstdlib>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "Student.h"

Student createStudent(std::string name, int age, int pointsPossible, int pointsEarned) {
    Student person;
    float pointsPercentage = (float(pointsEarned)/float(pointsPossible)) * 100;
    person.init(name, age, pointsPossible, pointsEarned, pointsPercentage);
    return person;
}

int defaultMethod() {
    std::cout << "Usage: Arg 1 - Name, Arg 2 - Age, Arg 3 - Total score possible, Arg 3 - Points earned" << std::endl;
    std::cout << "Running default method...\n\n";
    std::string name = "Bob";
    int age = 21;
    int pointsPossible = 100;
    int pointsEarned = 73;
    Student person = createStudent(name, age, pointsPossible, pointsEarned);
    std::string desc = person.description();
    std::cout << desc << std::endl;
    return 0;
}

int main(int argc, char** argv) {
    if (argc != 5) {
        defaultMethod();
    }
    else {
        Student person;
        try {
            std::string name = std::string(argv[1]);
            int age = boost::lexical_cast<int>(argv[2]);
            int pointsPossible = boost::lexical_cast<int>(argv[3]);
            int pointsEarned = boost::lexical_cast<int>(argv[4]);
            person = createStudent(name, age, pointsPossible, pointsEarned);
            std::cout << person.description() << std::endl;
        }
        catch(...) {
            std::cout << "Invalid input! Make sure the age and score entries are valid integers!" << std::endl;
            defaultMethod();
        }
    }
    return 0;
}

