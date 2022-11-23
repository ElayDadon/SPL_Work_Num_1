#include "../include/JoinPolicy.h"
#include "../include/Agent.h"
#include "../include/Coalition.h"

Agent MandatesJoinPolicy::join(vector<Agent> offers){
    Agent maxAgent = offers[0];
    unsigned size_offers = offers.size();
    for (unsigned i = 1; i < size_offers; ++i) {
        if(maxAgent.getCoalition()->getMandates() < offers[i].getCoalition()->getMandates())
            maxAgent = offers[i];
    }
    return maxAgent;
}

JoinPolicy* MandatesJoinPolicy::clone() {
    return new MandatesJoinPolicy;
}