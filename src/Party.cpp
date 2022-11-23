#include "../include/Party.h"
#include "../include/JoinPolicy.h"
#include "../include/Simulation.h"
#include "../include/Agent.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : is_timer_on(false), mId(id),timer(0), mName(name), mMandates(mandates), mJoinPolicy(jp),mState(Waiting){
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
void Party::addOffer(Agent offering_agent){
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
Party::~Party() {
    if(mJoinPolicy)
        delete mJoinPolicy;
}

Party::Party(const Party& other): is_timer_on(other.is_timer_on),mId(other.mId), timer(other.timer), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), offers(other.offers){
    
}

Party::Party(Party&& other) noexcept : is_timer_on(other.is_timer_on), mId(other.mId), timer(other.timer), mName(other.mName), mMandates(other.mMandates), mJoinPolicy(other.mJoinPolicy->clone()), mState(other.mState), offers(other.offers){
    other.mJoinPolicy = nullptr;
    }

Party& Party::operator=(const Party& other){
    if(this != &other) {
        if(mJoinPolicy)
            delete mJoinPolicy;
    
        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->clone();
        offers = other.offers;
        timer = other.timer;
        is_timer_on = other.is_timer_on;
    }
    return *this;
}

Party& Party::operator=(Party&& other) noexcept{
    if(this != & other) {
         if(mJoinPolicy)
            delete mJoinPolicy;

        mId = other.mId;
        mName = other.mName;
        mMandates = other.mMandates;
        mJoinPolicy = other.mJoinPolicy->clone();
        offers = other.offers;
        timer = other.timer;
        is_timer_on = other.is_timer_on;
        //move other
        other.mJoinPolicy = nullptr;
    }
    return *this;
}

void Party::step(Simulation &s)
{
    if(this->is_timer_on&&this ->get_timer()<3){
        this->increase_timer();
    }
    if((this->get_timer() == 3) & (this->getState() != Joined)){
      this -> setState(Joined);
      Agent agent_to_join_by_coalition = mJoinPolicy -> join(getOffers());
      Agent clone_agent = agent_to_join_by_coalition;
      clone_agent.setAgentId(s.getAgents().size());
      clone_agent.setPartyId(mId);
      clone_agent.getCoalition() ->addParty(mId);
      clone_agent.getCoalition() ->addMandates(mMandates);
      s.setAgents(clone_agent);
    }
    // TODO: implement this method
}

int Party::getId() const {
    return mId;
}

const vector<Agent> Party::getOffers() {
    return offers;
}