#include "Lemon.h"
#include "Business.h"
#include <iostream>
#include <thread>

using namespace std;

Lemon::Lemon() : Business(){}

Lemon::Lemon(int p, int mw, bool hm, int i) : Business(p,mw,hm,i){}

// easy to get money 直接给钱，这个是游戏里最基础的商业
int Lemon::run(){
    cout<<"You get money!\nPress any key to continue"<<endl;
    return get_income() * 2;
}

Lemon::~Lemon(){}