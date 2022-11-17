#pragma once
#include "Agent.h"
#include <vector>
using std::vector;
class JoinPolicy {
public:
    virtual Agent* join(vector<Agent*>) = 0;
};

class MandatesJoinPolicy : public JoinPolicy {
public:
    virtual Agent* join(vector<Agent*>);
};

class LastOfferJoinPolicy : public JoinPolicy {
public:
    virtual Agent* join(vector<Agent*>);
};