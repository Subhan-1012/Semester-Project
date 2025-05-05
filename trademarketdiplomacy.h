#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

using namespace std;

class MarketDiplomacy {
private:
    map<string, int> supply;  // Supply for goods
    map<string, int> demand;  // Demand for goods
    map<string, int> prices;  // Current prices for goods
    map<string, bool> tradeAgreements;  // Trade agreement status with other kingdoms
    map<string, bool> sanctions;  // Sanctions imposed by enemy kingdoms
    map<string, bool> smugglingStatus;  // Whether smuggling is happening for a kingdom
    map<string, bool> merchantGuilds;  // Guild demands for fair prices

    void fluctuateMarket();  // Fluctuate supply/demand dynamically
    void updatePrices();  // Update prices based on supply/demand
    void handleSmuggling(string kingdom);  // Handle smuggling consequences
    void imposeSanctions(string kingdom);  // Impose trade sanctions
    void enforceMerchantGuilds(string kingdom);  // Enforce fair prices with guilds
    void checkTradeAgreement(string kingdom);  // Check status of trade agreements

public:
    MarketDiplomacy();

    void formTradeAgreement(string kingdom);  // Form a trade agreement with a kingdom
    void breakTradeAgreement(string kingdom);  // Break a trade agreement
    void smuggleGoods(string kingdom);  // Attempt smuggling goods
    void imposeTradeSanctions(string kingdom);  // Impose trade sanctions on a kingdom
    void demandFairPrice(string kingdom);  // Demand fair prices from a kingdom
    void simulateMarketTurn();  // Simulate the market for one turn
    void showMarketStatus();  // Show the current market status

    bool isTradeAgreementActive(string kingdom) const;  // Check if a trade agreement is active
    bool areSanctionsActive(string kingdom) const;  // Check if sanctions are active
    bool isSmuggling(string kingdom) const;  // Check if smuggling is occurring
    bool isFairPriceDemanded(string kingdom) const;  // Check if fair price is demanded
};
