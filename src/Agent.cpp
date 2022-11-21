#include "Agent.h"
#include <vector>
#include "Simulation.h"
#include "SelectionPolicy.h"
Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy)
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

void Agent::step(Simulation &sim)
{
    // TODO: implement this method
sim.getParty(mPartyId);

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