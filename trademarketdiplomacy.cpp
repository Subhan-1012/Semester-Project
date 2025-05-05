#include "trademarketdiplomacy.h"
#include <cstdlib>
#include <ctime>

// Constructor to initialize some default values
MarketDiplomacy::MarketDiplomacy() {
    // Initialize some basic goods and prices for demonstration
    supply["Wheat"] = 100;
    demand["Wheat"] = 80;
    prices["Wheat"] = 10;

    supply["Iron"] = 50;
    demand["Iron"] = 60;
    prices["Iron"] = 15;

    // Initialize trade agreements and sanctions
    tradeAgreements["KingdomA"] = false;
    tradeAgreements["KingdomB"] = false;
    sanctions["KingdomA"] = false;
    sanctions["KingdomB"] = false;

    // Initialize smuggling and merchant guild demands
    smugglingStatus["KingdomA"] = false;
    smugglingStatus["KingdomB"] = false;
    merchantGuilds["KingdomA"] = true;
    merchantGuilds["KingdomB"] = true;

    srand(time(0));
}

void MarketDiplomacy::fluctuateMarket() {
    // Randomly change the supply and demand by +/-10% to simulate market fluctuation
    for (auto& entry : supply) {
        int fluctuation = rand() % 20 - 10; // -10 to +10% fluctuation
        entry.second += entry.second * fluctuation / 100;
    }
    for (auto& entry : demand) {
        int fluctuation = rand() % 20 - 10; // -10 to +10% fluctuation
        entry.second += entry.second * fluctuation / 100;
    }
}

void MarketDiplomacy::updatePrices() {
    // Update prices based on supply/demand ratios (simple version)
    for (auto& entry : prices) {
        int supplyValue = supply[entry.first];
        int demandValue = demand[entry.first];
        if (supplyValue > demandValue) {
            entry.second -= 1;  // Price decreases if supply is more than demand
        } else if (demandValue > supplyValue) {
            entry.second += 1;  // Price increases if demand is more than supply
        }
    }
}

void MarketDiplomacy::handleSmuggling(string kingdom) {
    if (smugglingStatus[kingdom]) {
        // Penalize the kingdom for smuggling
        cout << "Smuggling detected in " << kingdom << "! A fine is imposed.\n";
        // Impose a penalty on the kingdom (e.g., losing some resources or stability)
    }
}

void MarketDiplomacy::imposeSanctions(string kingdom) {
    if (sanctions[kingdom]) {
        // Impose economic sanctions (reduce trade with the kingdom)
        cout << "Sanctions imposed on " << kingdom << ". Trade is severely reduced.\n";
        // Reduce or eliminate the kingdom's trading capabilities
    }
}

void MarketDiplomacy::enforceMerchantGuilds(string kingdom) {
    if (!merchantGuilds[kingdom]) {
        // If the kingdom is not following the guild's price demands, a boycott is initiated
        cout << "Boycott initiated by merchant guilds in " << kingdom << " for unfair prices.\n";
        // Reduce kingdom's income or stability as a consequence
    }
}

void MarketDiplomacy::checkTradeAgreement(string kingdom) {
    if (tradeAgreements[kingdom]) {
        cout << "Trade agreement with " << kingdom << " is active.\n";
    } else {
        cout << "No trade agreement with " << kingdom << " currently.\n";
    }
}

void MarketDiplomacy::formTradeAgreement(string kingdom) {
    tradeAgreements[kingdom] = true;
    cout << "Trade agreement formed with " << kingdom << ".\n";
}

void MarketDiplomacy::breakTradeAgreement(string kingdom) {
    tradeAgreements[kingdom] = false;
    cout << "Trade agreement with " << kingdom << " has been broken.\n";
}

void MarketDiplomacy::smuggleGoods(string kingdom) {
    smugglingStatus[kingdom] = true;
    cout << "Smuggling goods into " << kingdom << "...\n";
    handleSmuggling(kingdom);
}

void MarketDiplomacy::imposeTradeSanctions(string kingdom) {
    sanctions[kingdom] = true;
    cout << "Trade sanctions imposed on " << kingdom << ".\n";
    imposeSanctions(kingdom);
}

void MarketDiplomacy::demandFairPrice(string kingdom) {
    merchantGuilds[kingdom] = false;
    cout << "Merchant guilds demand fair prices from " << kingdom << ".\n";
    enforceMerchantGuilds(kingdom);
}

void MarketDiplomacy::simulateMarketTurn() {
    fluctuateMarket();
    updatePrices();

    // Simulate trade sanctions, smuggling, and market dynamics for each kingdom
    for (const auto& kingdom : tradeAgreements) {
        if (kingdom.second) {
            checkTradeAgreement(kingdom.first);
        }
    }

    // Handle economic consequences of smuggling and sanctions
    for (const auto& kingdom : smugglingStatus) {
        handleSmuggling(kingdom.first);
    }

    for (const auto& kingdom : sanctions) {
        imposeSanctions(kingdom.first);
    }

    // Enforce guild demands
    for (const auto& kingdom : merchantGuilds) {
        enforceMerchantGuilds(kingdom.first);
    }
}

void MarketDiplomacy::showMarketStatus() {
    cout << "\n=== Market Status ===\n";
    for (const auto& entry : prices) {
        cout << "Good: " << entry.first << " | Price: " << entry.second << "\n";
    }
    cout << "=====================\n";
}

// Check if trade agreement is active
bool MarketDiplomacy::isTradeAgreementActive(string kingdom) const {
    return tradeAgreements.at(kingdom);
}

// Check if sanctions are active
bool MarketDiplomacy::areSanctionsActive(string kingdom) const {
    return sanctions.at(kingdom);
}

// Check if smuggling is occurring
bool MarketDiplomacy::isSmuggling(string kingdom) const {
    return smugglingStatus.at(kingdom);
}

// Check if fair price is demanded
bool MarketDiplomacy::isFairPriceDemanded(string kingdom) const {
    return !merchantGuilds.at(kingdom);
}
