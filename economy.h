#pragma once
#include"population.h"
class Economy {
    private:
        int treasury;
        float taxRate;
        float inflation;
    public:
        Economy();
        void taxPopulation(const Population& pop);
        void spend(int amount);
        void showStats() const;
        void saveToFile() const;
        void loadFromFile();
        int getTreasury() const;
        void receiveLoan(int amount);
        void resetTreasury();  // subhan
    };