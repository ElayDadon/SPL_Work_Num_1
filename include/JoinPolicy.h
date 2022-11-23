#pragma once
#include "Agent.h"
#include <vector>
using std::vector;
class JoinPolicy {
public:
    virtual Agent &join(vector<Agent*>) = 0;
    virtual JoinPolicy* clone() = 0;
    //virtual ~JoinPolicy()=default;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
    virtual Agent& join(vector<Agent*>);
    virtual JoinPolicy* clone();
    //virtual ~MandatesJoinPolicy()=default;
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
    virtual Agent &join(vector<Agent*>);
    virtual JoinPolicy* clone();
    //virtual ~LastOfferJoinPolicy()=default;
};