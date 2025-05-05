#include"population.h"
Population::Population() {
    total = 100;
    peasants = 60;
    merchants = 25;
    nobles = 15;
    happiness = 70.0; // 0 to 100 scale
    foodStock = 300;
}
void Population:: simulate() {
    cout << "Simulating Population Changes: \n";
    int foodConsumptionPerPerson = 2; // each person- 2 units
    int requiredFood;
    requiredFood = total * foodConsumptionPerPerson;
    cout << "Total population: " << total << endl;
    cout << "Food required: " << requiredFood << endl;
    cout << "Food available: " << foodStock << endl;
    if (foodStock >= requiredFood) {
        cout << "Everyone is having good food and population is growing.\n";
        foodStock -= requiredFood;
        total =total+ 10;
        happiness =happiness+ 5;
    }
    else{
        int shortage;
        shortage = requiredFood - foodStock;
        cout << "Food shortage of " << shortage << " units! People are starving.\n";
        int deaths = shortage / foodConsumptionPerPerson;
        total =total- deaths;
        happiness =happiness- 10;
        foodStock = 0;
    }

    // Clamp values
    if (happiness > 100) {
        happiness = 100;
    }
    if (happiness < 0) {
        happiness = 0;
    }
    if (total < 0) {
        total = 0;
    }
    peasants = total * 0.6;
    merchants = total * 0.25;
    nobles = total * 0.15;
    if (happiness < 30){
        cout << "Citizens are angry.\n";
        int revoltLoss = rand() % 10;
        total = total-revoltLoss;
        cout << revoltLoss << " people lost in revolt.\n";
    }
}
void Population::showStats() const {
    cout << " Population Stats: \n";
    cout << "Total Population: " << total << endl;
    cout << " Peasants: " << peasants << endl;
    cout << " Merchants: " << merchants << endl;
    cout << " Nobles: " << nobles << endl;
    cout << " Happiness: " << happiness << endl;
}
void Population::saveToFile() const {
    ofstream out("population.txt");
    if (!out){
        cerr << "Error: Unable to save population data.\n";
        return;
    }
    out <<"Total: "<< total << endl;
    out << "Peasants: "<<peasants << endl;
    out <<"Merchants: "<< merchants << endl;
    out << "Nobles: "<<nobles << endl;
    out << "happiness: "<<happiness << endl;
    out.close();
    cout << "Population data saved successfully.\n";
}
void Population::loadFromFile() {
    ifstream in("population.txt");
    if (!in){
        cerr << "Error: Unable to load population data.\n";
        return;
    }
    in >> total >> peasants >> merchants >> nobles >> happiness;
    in.close();
    cout << "Population data loaded successfully.\n";
}
int Population::getTotal() const {
    return total;
}
void Population::decrease(int amount) {
    total =total- amount;
    if (total < 0){
        total = 0;
    }

    peasants = total * 0.6;
    merchants = total * 0.25;
    nobles = total * 0.15;
}