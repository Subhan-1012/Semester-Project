#include"resources.h"
ResourceManager::ResourceManager(int initialGold, int initialFood, int initialWood, int initialStone) {
    // Initialize resources with production and consumption rates
    gold = new Resource<int>("Gold", initialGold, 10, 5);       // Basic economy: produce 10, consume 5
    food = new Resource<int>("Food", initialFood, 20, 15);      // Basic food: produce 20, consume 15
    wood = new Resource<int>("Wood", initialWood, 15, 10);      // Basic wood: produce 15, consume 10
    stone = new Resource<int>("Stone", initialStone, 5, 3);     // Basic stone: produce 5, consume 3
}


ResourceManager::~ResourceManager() {
    delete gold;
    delete food;
    delete wood;
    delete stone;
}


void ResourceManager::update() {
    // Update all resources
    gold->update();
    food->update();
    wood->update();
    stone->update();
}


int ResourceManager::getGold() const {
    return gold->getQuantity();
}


int ResourceManager::getFood() const {
    return food->getQuantity();
}


int ResourceManager::getWood() const {
    return wood->getQuantity();
}


int ResourceManager::getStone() const {
    return stone->getQuantity();
}


bool ResourceManager::consumeGold(int amount) {
    return gold->consume(amount);
}


bool ResourceManager::consumeFood(int amount) {
    return food->consume(amount);
}


bool ResourceManager::consumeWood(int amount) {
    return wood->consume(amount);
}


bool ResourceManager::consumeStone(int amount) {
    return stone->consume(amount);
}


void ResourceManager::produceGold(int amount) {
    gold->produce(amount);
}


void ResourceManager::produceFood(int amount) {
    food->produce(amount);
}


void ResourceManager::produceWood(int amount) {
    wood->produce(amount);
}


void ResourceManager::produceStone(int amount) {
    stone->produce(amount);
}


void ResourceManager::showStatus() const {
    cout << "===== RESOURCES STATUS =====" << endl;
    cout << gold->getName() << ": " << gold->getQuantity()
        << " (+" << gold->getProductionRate() << "/-" << gold->getConsumptionRate() << ")" << endl;


    cout << food->getName() << ": " << food->getQuantity()
        << " (+" << food->getProductionRate() << "/-" << food->getConsumptionRate() << ")" << endl;


    cout << wood->getName() << ": " << wood->getQuantity()
        << " (+" << wood->getProductionRate() << "/-" << wood->getConsumptionRate() << ")" << endl;


    cout << stone->getName() << ": " << stone->getQuantity()
        << " (+" << stone->getProductionRate() << "/-" << stone->getConsumptionRate() << ")" << endl;
    cout << "===========================" << endl;
}
