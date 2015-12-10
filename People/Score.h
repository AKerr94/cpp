#ifndef PEOPLE_SCORE_H
#define PEOPLE_SCORE_H


class Score {
    public:
        int getPointsPossible();
        void setPointsPossible(int x);
        int getPointsEarned();
        void setPointsEarned(int x);
        float getPointsPercentage();
        void setPointsPercentage(float x);
        void init(int pPossible, int pEarned, float pPercentage);
private:
        int pointsPossible;
        int pointsEarned;
        float pointsPercentage;
};


#endif //PEOPLE_SCORE_H
