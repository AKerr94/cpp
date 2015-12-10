#include "Person.h"

int Person::getAge() {
    return age;
}

std::string Person::getName() {
    return name;
}

void Person::setAge(int x) {
    age = x;
}

void Person::setName(std::string x) {
    name = x;
}

std::string Person::description() {
    return name + " is " + std::to_string(age) + " years old";
}

void Person::init(std::string initName, int initAge) {
    setName(initName);
    setAge(initAge);
}
