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
Party* allowedParty = mSelectionPolicy -> select(&sim.getGraph(),mPartyId);
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
    delete mSelectionPolicy;
    if(coalition)
        delete coalition;
}