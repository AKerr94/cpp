#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
    public:
        int getAge();
        std::string getName();
        void setAge(int x);
        void setName(std::string x);
        virtual std::string description();
        virtual void init(std::string initName, int initAge);
        
    private:
        int age;
        std::string name;
};

#endif /* PERSON_H */

