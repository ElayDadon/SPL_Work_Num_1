#pragma once
#include <vector>

using std::vector;

class Coalition{
public:
    ~Coalition();
    const vector<int> getParties();
    bool contains(int partyId);
    int* getMandates();
    void addParty(int partyId);

private:
    int id;
    int* mandates;
    vector<int> parties;

};
