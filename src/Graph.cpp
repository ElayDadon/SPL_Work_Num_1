#include "../include/Graph.h"
#include "../include/Agent.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

Party& Graph::getNonConstParty(int partyId) {
    return mVertices[partyId];
}


const vector<Party*> Graph::getValidNeighbors(int partyId) {
    vector<Party*> neighbors;
    for(unsigned i = 0; i < mVertices.size(); i++){
        if(getEdgeWeight(partyId, mVertices[i].getId()) > 0) {
            Party* partyToJoin = &mVertices[i];
            if(((partyToJoin->getState()) != Joined) && isValidParty(partyToJoin ,partyId))
                neighbors.push_back(partyToJoin);
        }
    }
    return neighbors;
}

bool Graph::isValidParty(Party *party, int partyId) {
    vector<Agent> offers = party->getOffers();
    int size_offers = offers.size();
    for (unsigned i = 0; i < size_offers; ++i) {
        Agent agent = offers[i];
        Coalition* c = agent.getCoalition();
        if(c->contains(partyId))
            return false;
    }
    return true;
}

Party* Graph::getHeaviestNeighbor(int partyId) {
    vector<Party*> neighbors = getValidNeighbors(partyId);
    Party *maxNeighbor;
    if(neighbors.size() != 0) { 
        maxNeighbor = neighbors[0];
        unsigned size_neighbors = neighbors.size();
        for (unsigned i = 0; i < size_neighbors; i++) {
            if(neighbors[i]->getMandates() > maxNeighbor->getMandates())
                maxNeighbor = neighbors[i];
        }
    }
    return maxNeighbor;
}

Party* Graph::getHeaviestEdgeNeighbor(int partyId) {
    vector<Party*> neighbors = getValidNeighbors(partyId);
    Party *maxEdgeNeighbor = nullptr;
    if(neighbors.size() != 0) {
        maxEdgeNeighbor = neighbors[0];
        unsigned neighbors_size = neighbors.size();
        for (unsigned i = 1; i < neighbors_size; i++) {
            if(getEdgeWeight(partyId, neighbors[i]->getId()) > getEdgeWeight(partyId, maxEdgeNeighbor->getId()))
                maxEdgeNeighbor = neighbors[i];
        }
    }
    return maxEdgeNeighbor;
}
