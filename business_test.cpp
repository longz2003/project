#include "bnl_business/Business.h"
#include "bnl_business/Lemon.h"
#include "bnl_business/Newspaper_stand.h"
#include "bnl_business/Convenience_store.h"
#include <iostream>
#include <string>

using namespace std;

int main () {
    // Business mybusiness;
    // mybusiness.set_price(100);
    // cout<<mybusiness.get_price()<<endl;

    // cout<<mybusiness.run()<<endl;

    // Lemon mylemon;
    // mylemon.set_income(200);
    // cout<<mylemon.get_income()<<endl;
    // cout<<mylemon.run()<<endl;

    // Newspaper_stand mynews;
    // mynews.set_income(200);
    // cout<<mynews.get_income()<<endl;
    // cout<<mynews.run()<<endl;

    Convenience_store mystore;
    mystore.set_income(50);
    cout<<mystore.get_income()<<endl;
    cout<<mystore.run()<<endl;

    return 0;
}