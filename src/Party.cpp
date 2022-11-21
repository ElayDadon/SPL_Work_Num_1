#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include "Agent.h"
Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name), mMandates(mandates), mJoinPolicy(jp), mState(Waiting)
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}
void Party::start_timer(){
    //this function holds a boolean which says if the timer is on
    //this boolean is set to true when the timer is on
    this ->is_timer_on =true;
    this ->timer =0;
}
void Party::increase_timer(){
    this ->timer++;
}
int Party::get_timer(){
    return this->timer;
}
void Party::setState(State state)
{
    mState = state;
}
void Party::addOffer(Agent* offering_agent){
    this -> offers.push_back(offering_agent);
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}
 Coalition* Party::getCoalition(){
    return this->coalition;
 }
void Party::step(Simulation &s)
{
    if(this->is_timer_on&&this ->get_timer()<3){
        this->increase_timer();
    }
    if(this->get_timer() == 3){
this -> setState(Joined);
Agent* agent_to_join_by_coalition = mJoinPolicy -> join(this ->getOffers());
s.setAgents(agent_to_join_by_coalition);
agent_to_join_by_coalition ->getCoalition() ->addParty(mId);
agent_to_join_by_coalition ->getCoalition() ->addMandates(mMandates);

    }
    // TODO: implement this method
}

int Party::getId() const {
    return mId;
}

const vector<Agent*> Party::getOffers() {
    return offers;
}