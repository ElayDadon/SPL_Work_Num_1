#include "../include/JoinPolicy.h"
#include "../include/Agent.h"
#include "../include/Coalition.h"

Agent* MandatesJoinPolicy::join(vector<Agent*> offers){
    Agent* maxAgent = offers[0];
    for (int i = 1; i < offers.size(); ++i) {
        if(maxAgent->getCoalition()->getMandates() < offers[i]->getCoalition()->getMandates())
            maxAgent = offers[i];
    }
    return maxAgent;
}

JoinPolicy* MandatesJoinPolicy::clone() {
    return new MandatesJoinPolicy;
}