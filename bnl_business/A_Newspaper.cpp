#include "Newspaper_stand.h"
#include "A_Newspaper.h"
#include "Business.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <thread>

using namespace std;

A_Newspaper::A_Newspaper() : Newspaper_stand(){}

A_Newspaper::A_Newspaper(int p, int mw, bool hm, int i) : Newspaper_stand(p, mw, hm, i){}

// hard newspaper need to type 5 letters more than one. but give good money 打五个英文字母，全对就给钱
int A_Newspaper::run(){
    srand(static_cast<unsigned int>(std::time(nullptr)));
    string target_string;
    for (int i = 0; i < 5; i ++){
        target_string += static_cast<char>('a' + rand() % 26);
    }
    string user_input;
    cout<<"Please type in these letters: "<<target_string<<endl;
    cin >> user_input;

    if (user_input == target_string){
        cout<<"Success!\nPress any key to continue"<<endl;

        return get_income() * 3;
    } else {
        cout<<"Wrong! No money for you!\nPress any key to continue"<<endl;

        return 0;
    }
}

A_Newspaper::~A_Newspaper(){}