#include "Graph.h"

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

const vector<Party*> Graph::getNeighbors(int partyId) {
    vector<Party*> neighbors;
    for(unsigned i = 0; i < mVertices.size(); i++){
        if(getEdgeWeight(partyId, mVertices[i].getId()) > 0)
            neighbors.push_back(&mVertices[i]);
    }
    return neighbors;
}

const vector<Party*> Graph::getValidNeighbors(int partyId) {
    vector<Party*> neighbors;
    for(unsigned i = 0; i < mVertices.size(); i++){
        if(getEdgeWeight(partyId, mVertices[i].getId()) > 0) {
            Party* partyToJoin = &mVertices[i];
            if(partyToJoin->getState() != Joined)
            neighbors.push_back(&mVertices[i]);
        }
    }
    return neighbors;
}

Party* Graph::getHeaviestNeighbor(int partyId) {
    vector<Party*> neighbors = getNeighbors(partyId);
    Party *maxNeighbor;
    if(neighbors.size() != 0) {
        maxNeighbor = neighbors[0];
        for (unsigned i = 0; i < neighbors.size(); i++) {
            if(neighbors[i]->getMandates() > maxNeighbor->getMandates())
                maxNeighbor = neighbors[i];
        }
    }
    return maxNeighbor;
}

Party* Graph::getHeaviestEdgeNeighbor(int partyId) {
    vector<Party*> neighbors = getNeighbors(partyId);
    Party *maxEdgeNeighbor;
    if(neighbors.size() != 0) {
        maxEdgeNeighbor = neighbors[0];
        for (unsigned i = 0; i < neighbors.size(); i++) {
            if(getEdgeWeight(partyId, neighbors[i]->getId()) > getEdgeWeight(partyId, maxEdgeNeighbor->getId()))
                maxEdgeNeighbor = neighbors[i];
        }
    }
    return maxEdgeNeighbor;
}
