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
    ~Party();
    Party(const Party&);
    Party(Party&&) noexcept;
    Party& operator=(const Party&);
    Party& operator=(Party&&) noexcept;
    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    int getId() const;
    const vector<Agent> getOffers();
    void addOffer(Agent);
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
    vector<Agent> offers;
//need to chooose where the coaition will be, agent or party and then 
//refrence counter in agent, that says how many agent points to the same coalition on the heap. 
//only free the memory once the reference counter gets to 1 
//another solution is to allow a different class on the higher hiarcy to bbe in charge to free the memory. 
//vector of all the allocated coallitiin the simulation instance.

};
