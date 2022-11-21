#pragma once
class Graph;
class Party;
class SelectionPolicy {
public:
    virtual Party* select(Graph* graph, int partyId) = 0;
    virtual SelectionPolicy* clone() = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy{
public:
    virtual Party* select(Graph* graph, int partyId);
    virtual SelectionPolicy* clone();
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
    virtual Party* select(Graph* graph, int partyId);
    virtual SelectionPolicy* clone();
};