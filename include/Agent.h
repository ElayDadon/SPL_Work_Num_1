#pragma once

#include <vector>
class Coalition;
class SelectionPolicy;
class Simulation;
class Agent
{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    ~Agent();
    Agent(const Agent&);
    Agent(Agent&&) noexcept;
    Agent& operator=(const Agent& other);
    Agent& operator=(Agent&& other) noexcept;
    int getPartyId() const;
    int getId() const;
    void step(Simulation &);
    Coalition *getCoalition();
    void updateMandates(int);

private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    Coalition *coalition;
};
