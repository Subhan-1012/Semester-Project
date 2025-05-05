#include "bankingcorruption.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Banking::Banking(Economy* eco) {
    economy = eco;
    loanAmount = 0;
    interestRate = 0.1f;  // 10% interest
    turnsToRepay = 0;
    remainingTurns = 0;
    loanTaken = false;
    defaulted = false;
}

void Banking::takeLoan(int amount, int repayTurns) {
    if (loanTaken && !defaulted) {
        cout << "You already have a pending loan. Repay or default first.\n";
        return;
    }
    loanAmount = amount;
    turnsToRepay = repayTurns;
    remainingTurns = repayTurns;
    loanTaken = true;
    defaulted = false;

    economy->receiveLoan(amount);
    cout << "Loan of " << amount << " gold taken. Repay in " << repayTurns << " turns with interest.\n";
}

void Banking::nextTurn() {
    if (!loanTaken) return;

    remainingTurns--;
    if (remainingTurns <= 0) {
        int repayment = loanAmount + static_cast<int>(loanAmount * interestRate);
        if (economy->getTreasury() >= repayment) {
            economy->spend(repayment);
            cout << "Loan repaid: " << repayment << " gold.\n";
        } else {
            cout << "Loan defaulted! You couldn't repay " << repayment << " gold.\n";
            economy->spend(economy->getTreasury()); // Treasury collapse
            defaulted = true;
        }
        loanTaken = false;
    }
}

void Banking::audit() {
    int auditCost = 50;
    cout << "\n--- Auditing Finances ---\n";
    economy->spend(auditCost);

    int chance = rand() % 100;
    if (chance < 25) {
        cout << "Corruption detected! Recovering stolen funds.\n";
        economy->receiveLoan(100);
    } else {
        cout << "No issues found. Audit clean.\n";
    }
}

void Banking::simulateCorruption() {
    int stolen = 75;
    cout << "\n--- Corrupt Official Stole Funds ---\n";
    economy->spend(stolen);
}

void Banking::simulateHeist() {
    int stolen = 150;
    cout << "\n--- Bank Heist Occurred ---\n";
    economy->spend(stolen);
    cout << "Security measures increased. You may want to audit.\n";
}

void Banking::showBankingStats() const {
    cout << "\n====== Banking Stats ======\n";
    if (loanTaken) {
        cout << "Active Loan: " << loanAmount << " gold\n";
        cout << "Turns left to repay: " << remainingTurns << "\n";
        cout << "Interest rate: " << (interestRate * 100) << "%\n";
    } else {
        cout << "No active loans.\n";
    }
    cout << "Defaulted before: " << (defaulted ? "Yes" : "No") << "\n";
}
