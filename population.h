#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class Population {
    private:
        int total;
        int peasants, merchants, nobles, foodStock;
        float happiness;
    public:
        Population();
        void simulate();
        void showStats() const;
        void saveToFile() const;
        void loadFromFile();
        int getTotal() const;
        void decrease(int amount);
};

