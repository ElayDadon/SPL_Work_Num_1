#include "../include/SelectionPolicy.h"
#include "../include/Graph.h"
Party* EdgeWeightSelectionPolicy::select(Graph *graph, int partyId) {
    return graph->getHeaviestEdgeNeighbor(partyId);
}

SelectionPolicy* EdgeWeightSelectionPolicy::clone() {
    return new EdgeWeightSelectionPolicy;
}