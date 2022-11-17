#include "../include/SelectionPolicy.h"
#include "../include/Graph.h"

Party *MandatesSelectionPolicy::select(const Graph *graph, int partyId)
{
    return graph->getHeaviestNeighbor(partyId);
}
