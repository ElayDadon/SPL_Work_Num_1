#pragma once
#include <string>
#include <vector>
#include "Coalition.h"
using std::string;using std::vector;

class JoinPolicy;
class Simulation;
class Agent;
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
    void addOffer(Agent*);
    Coalition* getCoalition();
    void setCoalition(Coalition* set_coalition);
    void start_timer();
    int get_timer();
    void increase_timer();


private:
    bool is_timer_on=false;
    int mId;
    int timer=0; 
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    vector<Agent*> offers;
    Coalition* coalition;
};
