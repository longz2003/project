#pragma once
#include<string>
#include "Business.h"
using namespace std;

// lemon drink shop, cheap and low income
class Lemon : public Business{
    public:
    Lemon();
    Lemon(int p, int mw, bool hm, int i);
    int run();
    ~Lemon();
};