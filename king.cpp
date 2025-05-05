#include "king.h"
#include <cstdlib>
#include <ctime>

// --- Faction ---
Faction::Faction(string factionName, int inf, int loyal)
    : name(factionName), influence(inf), loyalty(loyal), rebellious(false) {}

string Faction::getName() const { return name; }
int Faction::getInfluence() const { return influence; }
int Faction::getLoyalty() const { return loyalty; }
bool Faction::isRebellious() const { return rebellious; }

void Faction::setLoyalty(int newLoyalty) {
    loyalty = max(0, min(100, newLoyalty));
    checkRebellion();
}

void Faction::increaseInfluence(int amount) {
    influence += amount;
}

void Faction::decreaseInfluence(int amount) {
    influence = max(0, influence - amount);
}

void Faction::acceptBribe(int amount) {
    loyalty = min(100, loyalty + amount);
    checkRebellion();
}

int Faction::voteWeight() const {
    return influence * (loyalty / 10);
}

void Faction::reduceLoyalty(int amount) {
    loyalty = max(0, loyalty - amount);
    checkRebellion();
}

void Faction::checkRebellion() {
    rebellious = (loyalty < 20);
}

void Faction::showStatus() const {
    cout << "Faction: " << name
         << " | Influence: " << influence
         << " | Loyalty: " << loyalty
         << " | Rebellious: " << (rebellious ? "Yes" : "No") << endl;
}

// --- Candidate ---
Candidate::Candidate(string candidateName, string style)
    : name(candidateName), leadershipStyle(style), alive(true), totalVotes(0) {}

string Candidate::getName() const { return name; }
string Candidate::getLeadershipStyle() const { return leadershipStyle; }
bool Candidate::isAlive() const { return alive; }
int Candidate::getTotalVotes() const { return totalVotes; }

void Candidate::receiveVotes(string factionName, int votes) {
    factionVotes[factionName] = votes;
    updateTotalVotes();
}

void Candidate::updateTotalVotes() {
    totalVotes = 0;
    for (const auto& pair : factionVotes) {
        totalVotes += pair.second;
    }
}

void Candidate::assassinate() {
    alive = false;
    cout << name << " has been assassinated!\n";
}

void Candidate::blackmail(string factionName, int extraVotes) {
    factionVotes[factionName] += extraVotes;
    updateTotalVotes();
    cout << factionName << " was blackmailed into supporting " << name << " more.\n";
}

void Candidate::resetVotes() {
    factionVotes.clear();
    totalVotes = 0;
}

void Candidate::showStatus() const {
    cout << "Candidate: " << name
         << " | Leadership Style: " << leadershipStyle
         << " | Alive: " << (alive ? "Yes" : "No")
         << " | Total Votes: " << totalVotes << endl;

    cout << "  Support by factions:\n";
    for (const auto& pair : factionVotes) {
        cout << "    " << pair.first << ": " << pair.second << " votes\n";
    }
}

// --- King ---
King::King(string kingName, LeadershipStyle kingStyle)
    : name(kingName), style(kingStyle), stability(100), alive(true) {}

string King::getName() const { return name; }
LeadershipStyle King::getStyle() const { return style; }
int King::getStability() const { return stability; }
bool King::isAlive() const { return alive; }

void King::decreaseStability(int amount) {
    stability = max(0, stability - amount);
    cout << name << "'s stability decreased by " << amount << ". Now: " << stability << endl;
}

void King::increaseStability(int amount) {
    stability = min(100, stability + amount);
    cout << name << "'s stability increased by " << amount << ". Now: " << stability << endl;
}

bool King::isOverthrown() const {
    return (stability <= 20);
}

void King::assassinate() {
    alive = false;
    cout << "King " << name << " has been assassinated!\n";
}

void King::dieInBattle() {
    alive = false;
    cout << "King " << name << " died in battle!\n";
}

string King::getStyleAsString() const {
    switch (style) {
        case Benevolent: return "Benevolent";
        case Tyrant: return "Tyrant";
        case Diplomatic: return "Diplomatic";
        case Militaristic: return "Militaristic";
        default: return "Unknown";
    }
}

void King::showStatus() const {
    cout << "=== KING STATUS ===\n";
    cout << "Name: " << name << "\n";
    cout << "Leadership Style: " << getStyleAsString() << "\n";
    cout << "Stability: " << stability << "\n";
    cout << "Alive: " << (alive ? "Yes" : "No") << "\n";
    cout << "====================\n";
}

// --- Kingdom ---
Kingdom::Kingdom() {
    king = nullptr;
    unstable = false;
    srand(time(0));
}

Kingdom::~Kingdom() {
    delete king;
}

void Kingdom::addFaction(const Faction& faction) {
    factions.push_back(faction);
}

void Kingdom::electKing(const Candidate& candidate) {
    if (king) delete king;
    king = new King(candidate.getName(), Benevolent); // Or map candidate style to enum
    unstable = false;
    cout << " New King elected: " << king->getName()
         << " (" << getStyleAsString(king->getStyle()) << ")" << endl;
}

void Kingdom::simulateTurn() {
    if (!king || !king->isAlive()) {
        unstable = true;
        cout << "\nThe kingdom is without a ruler. Political instability rises!\n";
        return;
    }

    cout << "\n🔄 Simulating turn for King " << king->getName() << "...\n";
    int eventRoll = rand() % 100;
    if (eventRoll < 10) {
        attemptAssassination();
    } else if (eventRoll < 20) {
        factionUnrest();
    } else {
        cout << "Peaceful turn.\n";
        king->decreaseStability(5);
    }

    if (king->isOverthrown()) {
        cout << " Coup! King " << king->getName() << " has been overthrown!\n";
        king->assassinate();
        unstable = true;
    }
}

void Kingdom::attemptAssassination() {
    cout << " An assassination attempt is underway...\n";
    if (rand() % 100 < 25) {
        king->assassinate();
        unstable = true;
    } else {
        cout << "The king survived the assassination attempt.\n";
        king->decreaseStability(10);
    }
}

void Kingdom::factionUnrest() {
    if (factions.empty()) return;
    int index = rand() % factions.size();
    Faction& f = factions[index];
    cout << "Fight " << f.getName() << " is stirring unrest!\n";
    f.increaseInfluence(10);
    king->decreaseStability(15);
}

bool Kingdom::isUnstable() const {
    return unstable;
}

void Kingdom::showStatus() const {
    cout << "\n=== KINGDOM STATUS ===\n";
    if (king && king->isAlive()) {
        king->showStatus();
    } else {
        cout << "No living king.\n";
    }

    cout << "Kingdom is " << (unstable ? "UNSTABLE ⚠️" : "stable ✅") << endl;
    cout << "\n--- Factions ---\n";
    for (const auto& f : factions) {
        cout << f.getName() << " | Influence: " << f.getInfluence() << endl;
    }
    cout << "======================\n";
}

string Kingdom::getStyleAsString(LeadershipStyle style) const {
    switch (style) {
        case Benevolent: return "Benevolent";
        case Tyrant: return "Tyrant";
        case Diplomatic: return "Diplomatic";
        case Militaristic: return "Militaristic";
        default: return "Unknown";
    }
}
