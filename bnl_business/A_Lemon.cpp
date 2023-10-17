#include "Lemon.h"
#include "A_Lemon.h"
#include "Business.h"
#include <iostream>
#include <thread>

using namespace std;

A_Lemon::A_Lemon() : Lemon(){}

A_Lemon::A_Lemon(int p, int mw, bool hm, int i) : Lemon(p, mw, hm, i){}

// good lemon need to wait 3 seconds to get more money 高级柠檬，等三秒就给钱
int A_Lemon::run(){
    cout<<"Please wait for 3 seconds..."<<endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    cout<<"Press any key to continue"<<endl;

    return get_income() * 3;
}

A_Lemon::~A_Lemon(){}