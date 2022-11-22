#include "Party.h"
#include "JoinPolicy.h"
#include "Simulation.h"
#include "Agent.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : is_timer_on(false), mId(id),timer(0), mName(name), mMandates(mandates), mJoinPolicy(jp),mState(Waiting) ,offers(), coalition(nullptr)
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
    timer++;
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
void Party::setCoalition(Coalition* set_coalition){
    this-> coalition = set_coalition;
}
 Coalition* Party::getCoalition(){
    return this->coalition;
 }
Party::Party(const Party& other): is_timer_on(other.is_timer_on),mId(other.mId), timer(other.timer), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), offers(other.offers), coalition(other.coalition){
    
}
Party::Party(Party&& other) noexcept : is_timer_on(other.is_timer_on), mId(other.mId), timer(other.timer), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy), mState(other.mState), offers(other.offers), coalition(other.coalition){
    other.mJoinPolicy = nullptr;
    other.coalition = nullptr;
}
Party& Party::operator=(const Party& other){
    if(this != &other) {
        if(mJoinPolicy!=nullptr)
            delete mJoinPolicy;
        if(coalition)
            delete coalition;
    
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->clone();
        offers = other.offers;
        timer = other.timer;
        is_timer_on = other.is_timer_on;
        coalition = other.coalition;
    }
    return *this;
}
Party& Party::operator=(Party&& other) noexcept{
    if(this != & other) {
         if(mJoinPolicy)
            delete mJoinPolicy;
        if(coalition)
            delete coalition;

        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->clone();
        offers = other.offers;
        timer = other.timer;
        is_timer_on = other.is_timer_on;
        coalition = other.coalition;
        //move other
        other.mJoinPolicy = nullptr;
        other.coalition = nullptr;
    }
    return *this;
}
void Party::addCoalition(Coalition* col_to_update){
this ->coalition = col_to_update;
}
void Party::step(Simulation &s)
{
    if(this->is_timer_on&&this ->get_timer()<3){
        this->increase_timer();
    }
    if((this->get_timer() == 3) & (this->getState() != Joined)){
      this -> setState(Joined);
      Agent agent_to_join_by_coalition = mJoinPolicy -> join((this ->getOffers()));
      Agent clone_agent = agent_to_join_by_coalition;
      clone_agent.setAgentId(s.getAgents().size());
      clone_agent.setPartyId(this->getId());
      clone_agent.getCoalition() ->addParty(mId);
      clone_agent.getCoalition() ->addMandates(mMandates);
      s.setAgents(&clone_agent);
      Coalition* col = clone_agent.getCoalition(); 
      int x=col->getId();
      int y=col->getMandates();
      Coalition* col_saver = new Coalition(x,y);
      col_saver ->setParties(col->getParties());
      

    this->addCoalition(col_saver);
      agent_to_join_by_coalition.setNull();
    }
    // TODO: implement this method
}

int Party::getId() const {
    return mId;
}

const vector<Agent*> Party::getOffers() {
    return offers;
}