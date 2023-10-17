#pragma once
#include "Business.h"
#include "Convenience_store.h"
using namespace std;

// good store, best business
class A_Convenience : public Convenience_store{
    public:
    A_Convenience();
    A_Convenience(int p, int mw, bool hm, int i);
    int run();
    ~A_Convenience();
};
