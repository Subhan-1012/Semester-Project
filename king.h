#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum LeadershipStyle { Benevolent, Tyrant, Diplomatic, Militaristic };

class Faction {
private:
    string name;
    int influence;
    int loyalty;
    bool rebellious;

    void checkRebellion();

public:
    Faction(string factionName, int inf, int loyal);

    string getName() const;
    int getInfluence() const;
    int getLoyalty() const;
    bool isRebellious() const;

    void setLoyalty(int newLoyalty);
    void increaseInfluence(int amount);
    void decreaseInfluence(int amount);
    void acceptBribe(int amount);
    int voteWeight() const;
    void reduceLoyalty(int amount);
    void showStatus() const;
};

class Candidate {
private:
    string name;
    string leadershipStyle;
    bool alive;
    int totalVotes;
    map<string, int> factionVotes;

    void updateTotalVotes();

public:
    Candidate(string candidateName, string style);

    string getName() const;
    string getLeadershipStyle() const;
    bool isAlive() const;
    int getTotalVotes() const;

    void receiveVotes(string factionName, int votes);
    void assassinate();
    void blackmail(string factionName, int extraVotes);
    void resetVotes();
    void showStatus() const;
};

class King {
private:
    string name;
    LeadershipStyle style;
    int stability;
    bool alive;

    string getStyleAsString() const;

public:
    King(string kingName, LeadershipStyle kingStyle);

    string getName() const;
    LeadershipStyle getStyle() const;
    int getStability() const;
    bool isAlive() const;
    void decreaseStability(int amount);
    void increaseStability(int amount);
    bool isOverthrown() const;
    void assassinate();
    void dieInBattle();
    void showStatus() const;
};

class Kingdom {
private:
    King* king;
    vector<Faction> factions;
    bool unstable;

    void attemptAssassination();
    void factionUnrest();
    string getStyleAsString(LeadershipStyle style) const;

public:
    Kingdom();
    ~Kingdom();

    void addFaction(const Faction& faction);
    void electKing(const Candidate& candidate);
    void simulateTurn();
    bool isUnstable() const;
    void showStatus() const;
};
