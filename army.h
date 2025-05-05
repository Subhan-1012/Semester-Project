#pragma once
#include"population.h"
class Army {
    private:
        int soldiers;
        int morale;
        int foodSupply;
    public:
        Army();
        void recruitAndTrain(Population& pop);
        void showStats() const;
        void saveToFile() const;
        void loadFromFile();
        void lowerMorale(int amount);
};