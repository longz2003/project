#pragma once

#include <string>

using namespace std;

class Player {
private:
    int property[6];
    bool manager[6];
    int money;
    std::string name;
    int days;

public:
    Player();
    Player(std::string filepath);
    int save(std::string filepath);
    ~Player() {};

    int getProperty(int index);
    void setProperty(int index, int value);
    bool getManager(int index);
    void setManager(int index, bool value);
    int getMoney();
    void setMoney(int value);
    string getName();
    void setName(std::string value);
    int getDays();
    void incrementDays();
};
