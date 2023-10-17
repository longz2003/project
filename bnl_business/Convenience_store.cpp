#include "Convenience_store.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

using namespace std;

Convenience_store::Convenience_store() : Business(){}

Convenience_store::Convenience_store(int p, int mw, bool hm, int i) : Business(p, mw, hm, i){}

// make user do math, if do right give good money 做简单数学，对了就给钱
int Convenience_store::run(){
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int random_number1 = std::rand() % 10;
    int random_number2 = std::rand() % 10;
    int the_sum = random_number1 + random_number2;
    int user_input;
    cout<<"What is the sum of "<<random_number1<<" and "<<random_number2<<"?"<<endl;
    cin >> user_input;

    if (user_input == the_sum){
        cout<<"Success!\nPress any key to continue"<<endl;

        return get_income() * 2;
    } else {
        cout<<"Wrong! No money for you!\nPress any key to continue"<<endl;

        return 0;
    }
}

Convenience_store::~Convenience_store(){}