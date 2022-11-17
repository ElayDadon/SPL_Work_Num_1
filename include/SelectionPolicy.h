#pragma once
class Graph;
class Party;
class SelectionPolicy {
public:
    virtual Party* select(Graph* graph, int partyId) = 0;
};

class MandatesSelectionPolicy: public SelectionPolicy{
public:
    virtual Party* select(Graph* graph, int partyId);
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
    virtual Party* select(Graph* graph, int partyId);
};