#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Resource {
private:
    string name;
    T quantity;
    T productionRate;
    T consumptionRate;

public:
    Resource(string name, T initialQuantity, T prodRate, T consRate) {
        this->name = name;
        this->quantity = initialQuantity;
        this->productionRate = prodRate;
        this->consumptionRate = consRate;
    }

    ~Resource() {}

    string getName() const {
        return name;
    }

    T getQuantity() const {
        return quantity;
    }

    void setQuantity(T newQuantity) {
        quantity = newQuantity;
    }

    void update() {
        quantity += productionRate - consumptionRate;
        if (quantity < 0) quantity = 0;
    }

    bool consume(T amount) {
        if (quantity >= amount) {
            quantity -= amount;
            return true;
        }
        return false;
    }

    void produce(T amount) {
        quantity += amount;
    }

    T getProductionRate() const {
        return productionRate;
    }

    T getConsumptionRate() const {
        return consumptionRate;
    }
};

// ResourceManager is not templated, so it's fine to define it in the .cpp file.
class ResourceManager {
private:
    Resource<int>* gold;
    Resource<int>* food;
    Resource<int>* wood;
    Resource<int>* stone;

public:
    ResourceManager(int initialGold, int initialFood, int initialWood, int initialStone);
    ~ResourceManager();

    void update();
    int getGold() const;
    int getFood() const;
    int getWood() const;
    int getStone() const;
    bool consumeGold(int amount);
    bool consumeFood(int amount);
    bool consumeWood(int amount);
    bool consumeStone(int amount);
    void produceGold(int amount);
    void produceFood(int amount);
    void produceWood(int amount);
    void produceStone(int amount);
    void showStatus() const;
};
