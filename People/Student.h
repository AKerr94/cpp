#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include "Score.h"
#include <string>

class Student : public Person 
{
    public:
        int getPointsPossible();
        void setPointsPossible(int x);
        int getPointsEarned();
        void setPointsEarned(int x);
        float getPercentage();
        void setPercentage(float x);
        std::string description();
        void init(std::string initName, int initAge, int pPossible, int pEarned, float pPercentage);
    private:
        Score score;
};

#endif /* STUDENT_H */
