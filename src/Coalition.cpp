#include "../include/Coalition.h"

//this function returns the number of Mandates as a pointer 
int Coalition::getMandates() {
    return mandates;
}
Coalition::Coalition(int id,int Mmandates): id(id), mandates(Mmandates){
   
}

void Coalition::addMandates(int mandates){
    this->mandates += mandates;
}

bool Coalition::removeParty(int partyId){
    bool found = false;
    for (vector<int>::iterator i = parties.begin(); !found & i < parties.end(); i++)
    {
        if(*i == partyId){
            parties.erase(i);
            found = true;
        }
    }
    return parties.size() == 0;
}
bool Coalition::contains(int partyId) {
    for (unsigned i = 0; i < parties.size(); ++i) {
        if(parties.at(i) == partyId)
            return true;
    }
    return false;
}
 void Coalition::setParties(vector<int> new_parties)
 {
this ->parties = new_parties;
 }
    void Coalition::setId(int new_Id){
        this ->id = new_Id;
    }
    void Coalition::setMandates(int Mandates){
        this ->mandates = Mandates;
    }

int Coalition::getId(){
    return id;
}

const vector<int> Coalition::getParties() {
    return parties;
}

void Coalition::addParty(int partyId) {
    parties.push_back(partyId);
}
