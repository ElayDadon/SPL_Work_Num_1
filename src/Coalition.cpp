#include "../include/Coalition.h"

Coalition::~Coalition() {
    delete mandates;
}

int *Coalition::getMandates() {
    return mandates;
}

bool Coalition::contains(int partyId) {
    for (int i = 0; i < parties.size(); ++i) {
        if(parties[i] == partyId)
            return true;
    }
    return false;
}

const vector<int> Coalition::getParties() {
    return parties;
}

void Coalition::addParty(int partyId) {
    parties.push_back(partyId);
}
