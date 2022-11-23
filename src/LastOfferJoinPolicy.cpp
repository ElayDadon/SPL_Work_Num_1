#include "../include/JoinPolicy.h"

Agent &LastOfferJoinPolicy::join(vector<Agent*> offers){
    return *offers[offers.size() - 1];
}

JoinPolicy* LastOfferJoinPolicy::clone() {
    return new LastOfferJoinPolicy;
}