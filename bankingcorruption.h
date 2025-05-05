#pragma once
#include "economy.h"

class Banking {
private:
    Economy* economy;
    int loanAmount;
    float interestRate;
    int turnsToRepay;
    int remainingTurns;
    bool loanTaken;
    bool defaulted;

public:
    Banking(Economy* eco);
    void takeLoan(int amount, int repayTurns);
    void nextTurn(); // simulates one turn, triggers repayment checks
    void audit();
    void simulateCorruption();
    void simulateHeist();
    void showBankingStats() const;
};
