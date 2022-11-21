#pragma once

#include <vector>
#include "Graph.h"
#include "Coalition.h"
class SelectionPolicy;

class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    ~Agent();
    Agent(Agent&);
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Coalition* getCoalition();

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition* coalition;
};
