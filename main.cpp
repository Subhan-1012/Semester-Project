#include <iostream>
#include "army.h"
#include "population.h"
#include "economy.h"
#include "bankingcorruption.h"
#include "king.h"
#include "resources.h"
#include "trademarketdiplomacy.h"

using namespace std;

void displayMainMenu() {
    cout << "\n=== KINGDOM MANAGEMENT SIMULATOR ===" << endl;
    cout << "1. Manage Population & Economy" << endl;
    cout << "2. Army Management" << endl;
    cout << "3. Banking & Corruption" << endl;
    cout << "4. Kingdom Politics" << endl;
    cout << "5. Resource Management" << endl;
    cout << "6. Trade & Diplomacy" << endl;
    cout << "7. Next Turn" << endl;
    cout << "8. Show All Stats" << endl;
    cout << "9. Exit" << endl;
    cout << "Choice: ";
}

void handlePopulationEconomy(Population& pop, Economy& eco) {
    int choice;
    do {
        cout << "\n=== POPULATION & ECONOMY ===" << endl;
        cout << "1. Simulate Population Turn" << endl;
        cout << "2. Collect Taxes" << endl;
        cout << "3. Adjust Tax Rate" << endl;
        cout << "4. Show Stats" << endl;
        cout << "5. Back" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                pop.simulate();
                break;
            case 2:
                eco.taxPopulation(pop);
                break;
            case 3: {
                int newRate;
                cout << "Enter new tax rate (0-100): ";
                cin >> newRate;
                eco = Economy(); // Simplified adjustment
                break;
            }
            case 4:
                pop.showStats();
                eco.showStats();
                break;
        }
    } while(choice != 5);
}

void handleArmy(Army& army, Population& pop) {
    int choice;
    do {
        cout << "\n=== ARMY MANAGEMENT ===" << endl;
        cout << "1. Recruit Soldiers" << endl;
        cout << "2. Show Army Stats" << endl;
        cout << "3. Back" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                army.recruitAndTrain(pop);
                break;
            case 2:
                army.showStats();
                break;
        }
    } while(choice != 3);
}

void handleBanking(Banking& bank, Economy& eco) {
    int choice;
    do {
        cout << "\n=== BANKING & CORRUPTION ===" << endl;
        cout << "1. Take Loan" << endl;
        cout << "2. Audit Finances" << endl;
        cout << "3. Simulate Corruption" << endl;
        cout << "4. Show Banking Stats" << endl;
        cout << "5. Back" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                int amount, turns;
                cout << "Loan amount: ";
                cin >> amount;
                cout << "Repayment turns: ";
                cin >> turns;
                bank.takeLoan(amount, turns);
                break;
            }
            case 2:
                bank.audit();
                break;
            case 3:
                bank.simulateCorruption();
                break;
            case 4:
                bank.showBankingStats();
                break;
        }
    } while(choice != 5);
}

void handleKingdomPolitics(Kingdom& kingdom) {
    kingdom.simulateTurn();
    kingdom.showStatus();
}

void handleResources(ResourceManager& res) {
    res.showStatus();
}

void handleTrade(MarketDiplomacy& market) {
    int choice;
    do {
        cout << "\n=== TRADE & DIPLOMACY ===" << endl;
        cout << "1. Form Trade Agreement" << endl;
        cout << "2. Break Trade Agreement" << endl;
        cout << "3. Show Market Status" << endl;
        cout << "4. Back" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                market.formTradeAgreement("KingdomA");
                break;
            case 2:
                market.breakTradeAgreement("KingdomA");
                break;
            case 3:
                market.showMarketStatus();
                break;
        }
    } while(choice != 4);
}

int main() {
    Population population;
    Economy economy;
    Army army;
    Banking banking(&economy);
    ResourceManager resources(1000, 500, 300, 200);
    Kingdom kingdom;
    MarketDiplomacy market;

    // Initialize factions
    kingdom.addFaction(Faction("Nobles", 50, 70));
    kingdom.addFaction(Faction("Merchants", 40, 60));
    kingdom.addFaction(Faction("Peasants", 30, 40));

    int turn = 1;
    while(true) {
        cout << "\n=== TURN " << turn++ << " ===" << endl;
        int choice;
        displayMainMenu();
        cin >> choice;

        switch(choice) {
            case 1:
                handlePopulationEconomy(population, economy);
                break;
            case 2:
                handleArmy(army, population);
                break;
            case 3:
                handleBanking(banking, economy);
                break;
            case 4:
                handleKingdomPolitics(kingdom);
                break;
            case 5:
                handleResources(resources);
                break;
            case 6:
                handleTrade(market);
                break;
            case 7:
                // Progress all turn-based systems
                banking.nextTurn();
                market.simulateMarketTurn();
                population.simulate();
                break;
            case 8:
                population.showStats();
                economy.showStats();
                army.showStats();
                banking.showBankingStats();
                resources.showStatus();
                kingdom.showStatus();
                market.showMarketStatus();
                break;
            case 9:
                return 0;
        }

        // Check loss conditions
        if (population.getTotal() <= 0) {
            cout << "GAME OVER - Population has collapsed!" << endl;
            return 0;
        }
        if (kingdom.isUnstable()) {
            cout << "GAME OVER - Kingdom has fallen into chaos!" << endl;
            return 0;
        }
    }
}