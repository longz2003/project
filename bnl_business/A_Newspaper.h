#pragma once
#include "Business.h"
#include "Newspaper_stand.h"
using namespace std;

// good newspaper, more income
class A_Newspaper : public Newspaper_stand{
    public:
    A_Newspaper();
    A_Newspaper(int p, int mw, bool hm, int i);
    int run();
    ~A_Newspaper();
};