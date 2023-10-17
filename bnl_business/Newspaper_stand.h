#pragma once
#include <string>
#include "Business.h"

using namespace std;

//newspaper stnad, cheap and low income
class Newspaper_stand : public Business{
    public:
    Newspaper_stand();
    Newspaper_stand(int p, int mw, bool hm, int i);
    int run();
    ~Newspaper_stand();
};