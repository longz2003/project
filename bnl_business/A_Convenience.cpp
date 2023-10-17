#include "Convenience_store.h"
#include "A_Convenience.h"
#include "Business.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>

using namespace std;

A_Convenience::A_Convenience() : Convenience_store(){}

A_Convenience::A_Convenience(int p, int mw, bool hm, int i) : Convenience_store(p,mw,hm,i){}

// good store need do big math to earn a lot of money 十以内加减法，对了给钱，错了没钱
int A_Convenience::run(){
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int random_number1 = std::rand() % 100;
    int random_number2 = std::rand() % 100;
    int the_sum = random_number1 + random_number2;
    int user_input;
    cout<<"What is the sum of "<<random_number1<<" and "<<random_number2<<"?"<<endl;
    cin >> user_input;

    if (user_input == the_sum){
        cout<<"Success!\nPress any key to continue"<<endl;

        return get_income() * 3;
    } else {
        cout<<"Wrong! No money for you!\nPress any key to continue"<<endl;

        return 0;
    }
}

A_Convenience::~A_Convenience(){}