#include "bnl_business/Business.h"
#include "bnl_business/Lemon.h"
#include "bnl_business/A_Lemon.h"
#include "bnl_business/A_Newspaper.h"

#include <iostream>
#include <string>

using namespace std;

int main (){
    // A_Lemon myalemon;
    // myalemon.set_income(100);
    // cout<<myalemon.get_income()<<endl;
    // cout<<myalemon.run()<<endl;
    // return 0;

    A_Newspaper mypaper;
    mypaper.set_income(100);
    cout<<mypaper.get_income()<<endl;
    cout<<mypaper.run()<<endl;
    return 0;
}