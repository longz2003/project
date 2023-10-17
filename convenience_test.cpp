#include "bnl_business/Business.h"
#include "bnl_business/Convenience_store.h"
#include "bnl_business/A_Convenience.h"
#include <iostream>
#include <string>

using namespace std;

int main (){
    A_Convenience mystore;
    mystore.set_income(500);
    cout<<mystore.get_income()<<endl;
    cout<<mystore.run()<<endl;

    return 0;
}