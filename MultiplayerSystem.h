#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class MarketDiplomacy {
private:
    map<string, bool> alliances;  // Alliances between kingdoms (true if allied)
    map<string, bool> tradeAgreements;  // Trade agreements with other kingdoms
    map<string, bool> sanctions;  // Sanctions imposed by enemy kingdoms
    map<string, bool> smugglingStatus;  // Smuggling status
    map<string, bool> fakeTradeRequests;  // Fake trade requests to manipulate trust
    map<string, bool> treatyStatus;  // Status of treaties (true if valid)
    vector<string> communicationLog;  // Text-based communication log

    void fluctuateMarket();  // Simulate market fluctuation
    void handleSmuggling(string kingdom);  // Handle consequences of smuggling
    void imposeSanctions(string kingdom);  // Handle trade sanctions
    void handleTradeRequest(string kingdom);  // Handle trade requests, including fake ones
    void breakTreaty(string kingdom);  // Handle the breaking of treaties
    void recordCommunication(string message);  // Record communication for negotiations and lies

public:
    MarketDiplomacy();

    void formAlliance(string kingdom);  // Form an alliance with another kingdom
    void betrayAlliance(string kingdom);  // Betray an existing alliance
    void initiateTradeRequest(string kingdom, bool isFake = false);  // Initiate a trade request, can be fake
    void breakTradeAgreement(string kingdom);  // Break a trade agreement
    void smuggleGoods(string kingdom);  // Attempt smuggling goods
    void imposeTradeSanctions(string kingdom);  // Impose trade sanctions on a kingdom
    void negotiate(string message);  // Negotiation message to other kingdoms (can be a lie)
    void simulateMarketTurn();  // Simulate the market for one turn
    void showMarketStatus();  // Show the current market status
    void showCommunicationLog();  // Show the communication log

    bool isAllianceActive(string kingdom) const;  // Check if an alliance exists
    bool isTradeAgreementActive(string kingdom) const;  // Check if trade agreement is active
    bool isSmuggling(string kingdom) const;  // Check if smuggling is occurring
    bool isFakeTradeRequest(string kingdom) const;  // Check if a trade request is fake
    bool isTreatyValid(string kingdom) const;  // Check if a treaty is valid
};
