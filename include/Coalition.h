#pragma once
#include <vector>

using std::vector;

class Coalition{
public:
    Coalition(int id,int Mmandates);
    const vector<int> getParties();
    bool contains(int partyId);
    int getMandates();
    void addMandates(int mandates);
    void addParty(int partyId);

private:
    int id;
    int mandates;
    vector<int> parties;
};
