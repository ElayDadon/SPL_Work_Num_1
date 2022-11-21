#pragma once
#include "Agent.h"
#include <vector>
using std::vector;
class JoinPolicy {
public:
    virtual Agent* join(vector<Agent*>) = 0;
    virtual JoinPolicy* clone() = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
    virtual Agent* join(vector<Agent*>);
    virtual JoinPolicy* clone();
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
    virtual Agent* join(vector<Agent*>);
    virtual JoinPolicy* clone();
};