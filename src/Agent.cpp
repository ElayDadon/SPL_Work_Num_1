#include "Agent.h"
#include <vector>
#include "Simulation.h"
#include "SelectionPolicy.h"
#include "Coalition.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy), coalition(nullptr)
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

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
Party* allowedParty = mSelectionPolicy -> select(sim.getNonConstGraph(),mPartyId);
if (allowedParty != nullptr)
{
    /* there is no agent from the same party that already asked,
     then ask the party to join to the coalition */

    allowedParty ->setState(CollectingOffers);
    if(allowedParty->get_timer() == 0)
    {
        allowedParty->start_timer();
    }
    allowedParty -> addOffer(this);
}
}
Agent::~Agent(){
    if(mSelectionPolicy)
        delete mSelectionPolicy;
    if(coalition)
        delete coalition;
}
Agent::Agent(Agent &other) {
    delete this;
    mSelectionPolicy = other.mSelectionPolicy;
    coalition = other.coalition;
}
void Agent::updateMandates(int mandates){
    coalition = new Coalition(mPartyId, mandates);
}

Agent& Agent::operator=(const Agent& other){
    if(this != &other){
        delete this;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy->clone();
        coalition = other.coalition;
    }
    return *this;
}

Agent::Agent(const Agent& other){
    *this = other;
}

Agent::Agent(Agent&& other) noexcept :mAgentId(other.mAgentId), mPartyId(other.mPartyId), mSelectionPolicy(other.mSelectionPolicy), coalition(other.coalition){
    other.mSelectionPolicy = nullptr;
    other.coalition = nullptr;
}

Agent& Agent::operator=(Agent&& other) noexcept{
    if(this != &other) {
        delete this;
        mAgentId = other.mAgentId;
        mPartyId = other.mPartyId;
        mSelectionPolicy = other.mSelectionPolicy;
        coalition = other.coalition;

        //move other
        other.coalition = nullptr;
        other.mSelectionPolicy = nullptr;
    }
    return *this;
}




