#include"economy.h"
<<<<<<< HEAD


Economy::Economy() {
    treasury = 1000;
    taxRate = 5;
    inflation = 100;
}
void Economy:: taxPopulation(const Population& pop) {
=======
Economy::Economy() {
    treasury = 1000;
    taxRate = 5;          
    inflation = 100;     
}
void Economy::taxPopulation(const Population& pop) {
>>>>>>> fatima
    cout << "\n--- Tax Collection ---\n";

    int populationSize;
    populationSize = pop.getTotal();
    int baseCollection;
    baseCollection = (populationSize * taxRate) / 100;
    int adjustedCollection;
    adjustedCollection = (baseCollection * inflation) / 100;

    treasury = treasury + adjustedCollection;

    cout << "Taxed " << populationSize << " people at " << taxRate << "% rate.\n";
    cout << "Collected: " << adjustedCollection << " gold\n";
    cout << "New Treasury: " << treasury << " gold\n";

<<<<<<< HEAD

=======
   
>>>>>>> fatima
    inflation = inflation + 5;
    if (inflation > 200) {
        inflation = 200;
    }
}
void Economy:: spend(int amount) {
    cout << "\n--- Spending Gold ---\n";

    if (amount <= 0) {
        cout << "Invalid amount. Must be greater than 0.\n";
        return;
    }

    if (amount > treasury) {
        cout << "Insufficient treasury. Available: " << treasury << " gold.\n";
        return;
    }

    treasury = treasury - amount;
    cout << "Spent: " << amount << " gold. Remaining Treasury: " << treasury << " gold\n";
}
void Economy:: showStats() const {
    cout << "\n====== Economy Stats ======\n";
    cout << "Treasury: " << treasury << " gold\n";
    cout << "Tax Rate: " << taxRate << "%\n";
    cout << "Inflation: " << inflation << " (x" << inflation / 100.0 << ")\n";
}
<<<<<<< HEAD
void Economy::saveToFile() const {
=======
void Economy:: saveToFile() const {
>>>>>>> fatima
    ofstream out("economy.txt");
    if (!out) {
        cout << "Error: Unable to open file for saving economy.\n";
        return;
    }

    out << "Treasury: " << treasury << endl;
    out << "Tax Rate: " << taxRate << endl;
    out << "Inflation: " << inflation << endl;
    out.close();

    cout << "Economy saved to file.\n";
}
<<<<<<< HEAD
void Economy::loadFromFile() {
=======
void Economy:: loadFromFile() {
>>>>>>> fatima
    ifstream in("economy.txt");
    if (!in) {
        cout << "Error: Unable to open file for loading economy.\n";
        return;
    }

    in >> treasury >> taxRate >> inflation;
    in.close();

    cout << "Economy loaded from file.\n";
}
<<<<<<< HEAD
void Economy::resetTreasury() {
    treasury = 0;
    cout << "Treasury collapsed! Set to 0.\n";
}
int Economy::getTreasury() const {
=======
int Economy:: getTreasury() const {
>>>>>>> fatima
    return treasury;
}
void Economy:: receiveLoan(int amount) {
    treasury = treasury + amount;
}