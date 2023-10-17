#pragma once
#include "Business.h"
#include "Lemon.h"
using namespace std;

// good lemon drink, good income
class A_Lemon : public Lemon{
    public:
    A_Lemon();
    A_Lemon(int p, int mw, bool hm, int i);
    int run();
    ~A_Lemon();
};