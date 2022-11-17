#pragma once
#include <string>
#include <vector>
#include "Agent.h"
#include "Coalition.h"
using std::string,std::vector;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId() const;
    const vector<Agent*> getOffers();
    Coalition* getCoalition();

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<Agent*> offers;
    Coalition* coalition;
};
