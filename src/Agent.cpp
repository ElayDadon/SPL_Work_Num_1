#include "../include/Agent.h"
#include <vector>
#include "../include/Simulation.h"
#include "../include/SelectionPolicy.h"
#include "../include/Coalition.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalition(nullptr), numOfPointersToCoalition(new int(1))
{
    // You can change the implementation of the constructor, but not the signature!
}

int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}
Coalition* Agent::getCoalition(){
    return this->coalition;
}
void Agent::setPartyId(int partyId){
    mPartyId = partyId;
}
void Agent::setNull(){
    this->mSelectionPolicy =nullptr;
    this->coalition = nullptr;
}
void Agent::step(Simulation &sim)
{
    Party* allowedParty = mSelectionPolicy -> select(sim.getNonConstGraph(),mPartyId);
    if (allowedParty != nullptr)
    {
        allowedParty ->setState(CollectingOffers);
        if(allowedParty->get_timer() == 0)
        {
            allowedParty->start_timer();
        }
        allowedParty -> addOffer(*this);
    }
}

Agent::~Agent(){
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    if(numOfPointersToCoalition) {
        if (*numOfPointersToCoalition == 1) {
            delete numOfPointersToCoalition;
            delete coalition;
        } else
            *numOfPointersToCoalition = *numOfPointersToCoalition - 1;
    }
}

void Agent::updateMandates(int mandates){
    coalition = new Coalition(mPartyId, mandates);
    coalition->addParty(mPartyId);
}
int Agent::coalitionMandates() const {
    return coalition->getMandates();
}
void Agent::setAgentId(int id){
    this->mAgentId = id;
}

Agent& Agent::operator=(const Agent& other){
    if(this != &other){
        if(mSelectionPolicy)
            delete mSelectionPolicy;
        if(numOfPointersToCoalition) {
            if (*numOfPointersToCoalition == 1) {
                delete numOfPointersToCoalition;
                delete coalition;
            } else
                *numOfPointersToCoalition = *numOfPointersToCoalition - 1;
        }

        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        coalition = other.coalition;
        *other.numOfPointersToCoalition = *other.numOfPointersToCoalition + 1;
        numOfPointersToCoalition = other.numOfPointersToCoalition;
    }
    return *this;
}

Agent::Agent(const Agent& other){
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy->clone();
    coalition = other.coalition;
    *other.numOfPointersToCoalition = *other.numOfPointersToCoalition + 1;
    numOfPointersToCoalition = other.numOfPointersToCoalition;
}

Agent::Agent(Agent&& other) noexcept{
    mAgentId = other.mAgentId;
    mPartyId = other.mPartyId;
    mSelectionPolicy = other.mSelectionPolicy->clone();
    coalition = other.coalition;
    numOfPointersToCoalition = other.numOfPointersToCoalition;
    other.mSelectionPolicy = nullptr;
    other.coalition = nullptr;
    other.numOfPointersToCoalition = nullptr;

}

Agent& Agent::operator=(Agent&& other) noexcept{
    if(this != &other) {
        if(mSelectionPolicy)
            delete mSelectionPolicy;
        if(numOfPointersToCoalition) {
            if (*numOfPointersToCoalition == 1) {
                delete numOfPointersToCoalition;
                delete coalition;
            } else
                *numOfPointersToCoalition = *numOfPointersToCoalition - 1;
        }

        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        coalition = other.coalition;
        numOfPointersToCoalition = other.numOfPointersToCoalition;

        //move other
        other.coalition = nullptr;
        other.mSelectionPolicy = nullptr;
        other.numOfPointersToCoalition = nullptr;
    }
    return *this;
}




