#include "Student.h"

int Student::getPointsPossible() {
    return score.getPointsPossible();
}

void Student::setPointsPossible(int x) {
    score.setPointsPossible(x);
}

int Student::getPointsEarned() {
    return score.getPointsEarned();
}

void Student::setPointsEarned(int x) {
    score.setPointsEarned(x);
}

float Student::getPercentage() {
    return score.getPointsPercentage();
}

void Student::setPercentage(float x) {
    score.setPointsPercentage(x);
}

std::string Student::description() {
    return Person::description() + ". " \
        + getName() + "'s grade is " + std::to_string(getPercentage()) + "%";
}

void Student::init(std::string initName, int initAge, int pPossible, int pEarned, float pPercentage) {
    // Initialise person details
    Person::init(initName, initAge);
    // initialise score object
    score.init(pPossible, pEarned, pPercentage);
}
