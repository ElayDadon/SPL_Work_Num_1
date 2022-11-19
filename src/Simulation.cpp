#include "Simulation.h"
#include "Party.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
    int numofparties = mGraph.getNumVertices();
    for(int i=0;i<numofparties;i++){  
    Party party_saver = mGraph.getParty(i);
    party_saver.step(*this);
    }
    for(Agent agent_saver:mAgents){
        agent_saver.step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    int numofparties = mGraph.getNumVertices();
    int join_parties_counter =0;
    for(int i=0;i<numofparties;i++){  
    Party party_saver = mGraph.getParty(i);
    if(*(party_saver.getCoalition()->getMandates()) >= 61)
    return true; 
    if(party_saver.getState()==Joined){
        join_parties_counter++;
    }
}
    if(join_parties_counter==numofparties)
    return true;


    return false;
    
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}
Graph* Simulation::getNonConstGraph(){
    return &mGraph;
}

const vector<Agent> &Simulation::getAgents() const
{
    return mAgents;
}

const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}
void Simulation::setAgents(Agent* agent_to_add){
    mAgents.push_back(*agent_to_add);
}

/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    //[[],[],[]]
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return vector<vector<int>>();
}
