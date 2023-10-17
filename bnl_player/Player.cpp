#include <fstream>
#include <string>
#include <iostream>
#include <limits>
#include "Player.h"

using namespace std;

//make default player object ask user. 向用户询问玩家名称，创建空白玩家
Player::Player(){
    for (int i = 0; i < 100; i++){
        system("clear");
        cout << "Enter your name: ";
        getline(cin, name);
        if (name.length() > 10){
            cout << "Name too long (max 10 chars).\n";
            cout << "Press enter to continue...";
            cin.get();
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if (name.length() > 0) {
            break;
        }
    }

    for (int i = 0; i < 6; i++) {
        property[i] = 0;
        manager[i] = false;
    }
    property[0] = 1;
    money = 0;
    days = 1;
}
//load from save file make player. 从文件加载玩家信息，恢复保存的玩家
Player::Player(string filepath){
    ifstream file(filepath.c_str());
    if (file.is_open()) {
        string line;
        getline(file, line);
        name = line;
        getline(file, line);
        money = stoi(line);
        getline(file, line);
        days = stoi(line);
        for (int i = 0; i < 6; i++) {
            getline(file, line);
            property[i] = stoi(line);
        }
        for (int i = 0; i < 6; i++) {
            getline(file, line);
            manager[i] = stoi(line);
        }
        file.close();
    }
}
// save to file player information 保存玩家信息到文件
int Player::save(string filepath){
    ofstream file(filepath.c_str());
    if (file.is_open()) {
        file << name << endl;
        file << money << endl;
        file << days << endl;
        for (int i = 0; i < 6; i++) {
            file << property[i] << endl;
        }
        for (int i = 0; i < 6; i++) {
            file << manager[i] << endl;
        }
        file.close();
        return 0;
    }
    return 1;
}
// give business information 提供玩家拥有的产业信息
int Player::getProperty(int index){
    return property[index];
}
// change player business count 改变玩家拥有的某个产业的数量
void Player::setProperty(int index, int value){
    property[index] = value;
}
// old manager setup, not used
bool Player::getManager(int index){
    return manager[index];
}
// old manager setup, not used
void Player::setManager(int index, bool value){
    manager[index] = value;
}
// return player money
int Player::getMoney(){
    return money;
}
// change player money
void Player::setMoney(int value){
    money = value;
}
// return player name
string Player::getName(){
    return name;
}
// change player name
void Player::setName(string value){
    name = value;
}
// return game days
int Player::getDays(){
    return days;
}
// game days+1
void Player::incrementDays(){
    days++;
}

