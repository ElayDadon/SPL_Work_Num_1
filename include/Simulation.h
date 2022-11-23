#pragma once

#include <vector>

#include "Graph.h"
#include "Agent.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;
    Graph &getGraph();
    const Graph &getGraph() const;
    const vector<Agent> &getAgents() const;
    void setAgents(Agent &agent);
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Graph* getNonConstGraph();
    Party* getNonConstParty(int partyId);
    void updateMandates();
    void updateCoalition();  
    void addPartyToCoalition(int id,int mandates);
private:
    Graph mGraph;
    vector<Agent> mAgents;
    int numOfCoalitions;
    vector<Coalition> Coalitions;
};
