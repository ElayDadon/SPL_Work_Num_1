#include "../include/Coalition.h"

//this function returns the number of Mandates as a pointer 
int Coalition::getMandates() {
    return mandates;
}
Coalition::Coalition(int id,int Mmandates){
    this->id = id;
    this->mandates = Mmandates;
}

void Coalition::addMandates(int mandates){
    this->mandates += mandates;
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
