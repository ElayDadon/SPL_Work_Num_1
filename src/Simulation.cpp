#include "../include/Simulation.h"
#include "../include/Party.h"
#include "../include/Agent.h"
#include "../include/Graph.h"
#include "../include/Coalition.h"

#include <iostream>
#include <algorithm>
using std::find;

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), numOfCoalitions(agents.size()) 
{
    // You can change the implementation of the constructor, but not the signature!
}

void Simulation::step()
{
    // TODO: implement this method
    //     for(Agent agent_saver:mAgents){
    //     agent_saver.step(*this);
    // }
   
    //Party Step
    int numofparties = mGraph.getNumVertices();
    for(int i=0;i<numofparties;i++){  
    Party* party_saver = getNonConstParty(i);
    party_saver->step(*this);
    }
    //Agent step
     for (unsigned i = 0; i < mAgents.size(); i++)
    {
        Agent* agent_saver = &mAgents[i];
        agent_saver->step(*this);
    }
}

bool Simulation::shouldTerminate() const
{
    // TODO implement this method
    int numofparties = mGraph.getNumVertices();
    int join_parties_counter =0;
    for(int i=0;i<numofparties;i++){  
        Party party_saver = mGraph.getParty(i);

        Coalition* col_saver = party_saver.getCoalition();
        if(col_saver){
            if(col_saver->getMandates() >= 61)
            return true;
        } 
    
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
void Simulation::updateCoalition(){
    for(int i=0;i<mAgents.size();i++){
        Coalition* col_to_party = mAgents[i].getCoalition();
        Party* to_upadte = this ->getNonConstParty(mAgents[i].getPartyId());
        to_upadte->setCoalition(col_to_party);
    }
}

Party* Simulation::getNonConstParty(int partyId){
    return &mGraph.getNonConstParty(partyId);
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
    vector<vector<int>> coalitions;
    for(unsigned i = 0; i < numOfCoalitions; i++){
        vector<int> coalition{mAgents[i].getPartyId()};
        coalitions.push_back(coalition);
    }
    for(unsigned i = numOfCoalitions; i < mAgents.size(); i++){
        bool found = false;
        Agent toAdd = mAgents[i];
        for(unsigned j = 0; j < numOfCoalitions & !found; j++){
            vector<int> c = coalitions[j];
            if(std::find(c.begin(), c.end(), toAdd.getCoalition()->getId()) != c.end()){
                coalitions[j].push_back(toAdd.getPartyId());
                found = true;
            }
        }
    }
    //[[],[],[]]
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    return coalitions;
}

void Simulation::updateMandates(){
    for(unsigned i=0;i<mAgents.size();i++){
        mAgents[i].updateMandates(getParty(mAgents[i].getPartyId()).getMandates());
    }
}