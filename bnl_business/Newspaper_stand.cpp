#include "Newspaper_stand.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>

using namespace std;

Newspaper_stand::Newspaper_stand() : Business(){}

Newspaper_stand::Newspaper_stand(int p, int mw, bool hm, int i) : Business(p,mw,hm,i){}

// ask user to type a letter, if user is right, give money 让用户输入指定字母，对了就给钱
int Newspaper_stand::run(){
    srand(static_cast<unsigned int>(std::time(nullptr)));
    int random_number = std::rand() % 26;
    char target_letter = static_cast<char>('a' + random_number);
    char user_input;
    cout<<"Please type in the letter: "<<target_letter<<endl;
    cin >> user_input;

    if (user_input == target_letter){
        cout<<"Success!\nPress any key to continue"<<endl;

        return get_income() * 2;
    } else {
        cout<<"Wrong! No money for you!\nPress any key to continue"<<endl;

        return 0;
    }
}

Newspaper_stand::~Newspaper_stand(){}