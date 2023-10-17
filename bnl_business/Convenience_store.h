#pragma once
#include <string>
#include "Business.h"

using namespace std;

// convenience store, cheap and low income
class Convenience_store : public Business{
    public:
    Convenience_store();
    Convenience_store(int p, int mw, bool hm, int i);
    int run();
    ~Convenience_store();
};
