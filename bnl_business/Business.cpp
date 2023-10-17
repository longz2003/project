#include "Business.h"
#include<string>
using namespace std;

Business::Business(){
    price = 0;
    manager_wage = 0;
    has_manager = false;
    income = 0;
}
// make new businesss and set price income 用输入的价格，收入，经理（已弃用）
Business::Business(int p,int mw,bool hm,int i){
    price = p;
    manager_wage = mw;
    has_manager = hm;
    income = i;
}

// all the get and set methods, but manager is not used. we changed 所有的set和get方法，用来改变或获取business的属性（比如价格，收入等）
void Business::set_price(int p){
    price = p;
}
int Business::get_price(){
    return price;
}
void Business::set_manager_wage(int mw){
    manager_wage = mw;
}
int Business::get_manager_wage(){
    return manager_wage;
}
void Business::hire_manager(){
    has_manager = true;
}
bool Business::check_manager(){
    return has_manager;
}
void Business::set_income(int i){
    income = i;
}
int Business::get_income(){
    return income;
}
Business::~Business(){}