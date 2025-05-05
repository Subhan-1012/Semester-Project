#include "MultiplayerSystem.h"

// Constructor to initialize default values
MarketDiplomacy::MarketDiplomacy() {
    // Initialize kingdoms with no alliances, trade agreements, or sanctions
    alliances["KingdomA"] = false;
    alliances["KingdomB"] = false;
    tradeAgreements["KingdomA"] = false;
    tradeAgreements["KingdomB"] = false;
    sanctions["KingdomA"] = false;
    sanctions["KingdomB"] = false;
    smugglingStatus["KingdomA"] = false;
    smugglingStatus["KingdomB"] = false;
    fakeTradeRequests["KingdomA"] = false;
    fakeTradeRequests["KingdomB"] = false;
    treatyStatus["KingdomA"] = true;  // Assume treaties are valid by default
    treatyStatus["KingdomB"] = true;
    srand(time(0));
}

void MarketDiplomacy::fluctuateMarket() {
    // Simulate random market fluctuations
    // (e.g., supply/demand adjustments, price changes, etc.)
    cout << "Market is fluctuating due to economic conditions...\n";
}

void MarketDiplomacy::handleSmuggling(string kingdom) {
    if (smugglingStatus[kingdom]) {
        // Penalize the kingdom for smuggling
        cout << "Smuggling detected in " << kingdom << "! A fine is imposed.\n";
        // Impose a penalty (e.g., reduced resources, stability)
    }
}

void MarketDiplomacy::imposeSanctions(string kingdom) {
    if (sanctions[kingdom]) {
        // Sanctions reduce trade opportunities
        cout << "Sanctions imposed on " << kingdom << ". Trade is restricted.\n";
        // Impose penalties or trade restrictions
    }
}

void MarketDiplomacy::handleTradeRequest(string kingdom) {
    if (fakeTradeRequests[kingdom]) {
        cout << "Trade request from " << kingdom << " is fake. Trust is reduced.\n";
        // Reduce trust or affect diplomatic relations
    }
}

void MarketDiplomacy::breakTreaty(string kingdom) {
    if (treatyStatus[kingdom]) {
        treatyStatus[kingdom] = false;
        cout << "Treaty with " << kingdom << " has been broken.\n";
        // Impose consequences of breaking the treaty (e.g., trust reduction)
    }
}

void MarketDiplomacy::recordCommunication(string message) {
    communicationLog.push_back(message);
    cout << "Communication recorded: " << message << "\n";
}

void MarketDiplomacy::formAlliance(string kingdom) {
    alliances[kingdom] = true;
    cout << "Alliance formed with " << kingdom << ".\n";
}

void MarketDiplomacy::betrayAlliance(string kingdom) {
    alliances[kingdom] = false;
    cout << "Alliance with " << kingdom << " has been betrayed.\n";
}

void MarketDiplomacy::initiateTradeRequest(string kingdom, bool isFake) {
    fakeTradeRequests[kingdom] = isFake;
    cout << "Trade request from " << kingdom << (isFake ? " (Fake)" : "") << " initiated.\n";
    handleTradeRequest(kingdom);
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

void MarketDiplomacy::negotiate(string message) {
    // Simulate negotiation, which can involve lies or manipulations
    recordCommunication(message);
    cout << "Negotiation message: " << message << "\n";
}

void MarketDiplomacy::simulateMarketTurn() {
    fluctuateMarket();

    // Handle smuggling, trade sanctions, and alliance betrayals
    for (const auto& kingdom : smugglingStatus) {
        handleSmuggling(kingdom.first);
    }

    for (const auto& kingdom : sanctions) {
        imposeSanctions(kingdom.first);
    }

    for (const auto& kingdom : fakeTradeRequests) {
        handleTradeRequest(kingdom.first);
    }
}

void MarketDiplomacy::showMarketStatus() {
    cout << "\n=== Market Status ===\n";
    for (const auto& kingdom : tradeAgreements) {
        cout << "Trade agreement with " << kingdom.first << ": " 
             << (kingdom.second ? "Active" : "Inactive") << "\n";
    }
    cout << "=====================\n";
}

void MarketDiplomacy::showCommunicationLog() {
    cout << "\n=== Communication Log ===\n";
    for (const string& message : communicationLog) {
        cout << message << "\n";
    }
    cout << "=========================\n";
}

// Check if alliance is active
bool MarketDiplomacy::isAllianceActive(string kingdom) const {
    return alliances.at(kingdom);
}

// Check if trade agreement is active
bool MarketDiplomacy::isTradeAgreementActive(string kingdom) const {
    return tradeAgreements.at(kingdom);
}

// Check if smuggling is occurring
bool MarketDiplomacy::isSmuggling(string kingdom) const {
    return smugglingStatus.at(kingdom);
}

// Check if trade request is fake
bool MarketDiplomacy::isFakeTradeRequest(string kingdom) const {
    return fakeTradeRequests.at(kingdom);
}

// Check if treaty is valid
bool MarketDiplomacy::isTreatyValid(string kingdom) const {
    return treatyStatus.at(kingdom);
}
