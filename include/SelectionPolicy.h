#pragma once
class Graph;
class Party;
class SelectionPolicy {
public:
    virtual Party* select(Graph* graph, int partyId) = 0;
    virtual SelectionPolicy* clone() = 0;
    //virtual ~SelectionPolicy() = default;
};

class MandatesSelectionPolicy: public SelectionPolicy{
public:
    virtual Party* select(Graph* graph, int partyId);
    virtual SelectionPolicy* clone();
    //virtual ~MandatesSelectionPolicy() = default;
};

class EdgeWeightSelectionPolicy: public SelectionPolicy{
public:
    virtual Party* select(Graph* graph, int partyId);
    virtual SelectionPolicy* clone();
    //virtual ~EdgeWeightSelectionPolicy() = default;
};