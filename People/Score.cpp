#include "Score.h"

int Score::getPointsPossible() {
    return pointsPossible;
}

void Score::setPointsPossible(int x) {
    pointsPossible = x;
}

int Score::getPointsEarned() {
    return pointsEarned;
}

void Score::setPointsEarned(int x) {
    pointsEarned = x;
}

float Score::getPointsPercentage() {
    return pointsPercentage;
}

void Score::setPointsPercentage(float x) {
    pointsPercentage = x;
}

void Score::init(int pPossible, int pEarned, float pPercentage) {
    setPointsPossible(pPossible);
    setPointsEarned(pEarned);
    setPointsPercentage(pPercentage);
}
