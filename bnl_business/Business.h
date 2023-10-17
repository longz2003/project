#pragma once
#include<string>
using namespace std;

// abstract class to have all common things for business
class Business{
    private:
    int price;
    int manager_wage;
    bool has_manager;
    int income;
    
    public:
    Business();
    Business(int p,int mw,bool hm,int i);
    void set_price(int p);
    int get_price();
    void set_manager_wage(int mw);
    int get_manager_wage();
    void hire_manager();
    bool check_manager();
    void set_income(int i);
    int get_income();
    virtual int run()=0;
    ~Business();
};
