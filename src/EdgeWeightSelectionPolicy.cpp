#include "../include/SelectionPolicy.h"
#include "../include/Graph.h"
Party* EdgeWeightSelectionPolicy::select(const Graph *graph, int partyId) {
    return graph->getHeaviestEdgeNeighbor(partyId);
}