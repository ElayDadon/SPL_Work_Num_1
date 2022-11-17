#pragma once
#include <vector>

using std::vector;

class Coalition{
public:
    const vector<int> getParties();
    bool contains(int partyId);
    int*
private:
    int id;
    int* mandates;
    vector<int> parties;

};
