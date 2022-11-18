#include "Party.h"

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
int Party::get_timer(){return this->timer;}
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

void Party::step(Simulation &s)
{if(this->get_timer() == 2){

}
    // TODO: implement this method
}

int Party::getId() const {
    return mId;
}

const vector<Agent*> Party::getOffers() {
    return offers;
}