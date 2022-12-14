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
    void setAgents(Agent*);
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    Graph* getNonConstGraph();
    void updateMandates();
private:
    Graph mGraph;
    vector<Agent> mAgents;
};
