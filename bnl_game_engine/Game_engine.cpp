#include "Game_engine.h"
#include "../bnl_business/Business.h"
#include "../bnl_player/Player.h"
#include <string>
#include <cstdlib>
#include <limits>
#include <iostream>
#include <vector>
#include "../bnl_business/Lemon.h"
#include "../bnl_business/Newspaper_stand.h"
#include "../bnl_business/Convenience_store.h"
#include "../bnl_business/A_lemon.h"
#include "../bnl_business/A_newspaper.h"
#include "../bnl_business/A_convenience.h"



using namespace std;
//Create a game_engine object based on player information（创建游戏引擎对象和商业对象，根据玩家名称初始化）
Game_engine::Game_engine(Player* newplayer){
    player = newplayer;
    Business* lemon = new Lemon(5, 10, false, 1);
    Business* newspaper = new Newspaper_stand(50, 100, false, 10);
    Business* store = new Convenience_store(750, 1000, false, 100);
    Business* alemon = new A_Lemon(100, 200, false, 20);
    Business* anewspaper = new A_Newspaper(500, 1000, false, 200);
    Business* astore = new A_Convenience(7500, 10000, false, 1000);
    business.push_back(lemon);
    business.push_back(newspaper);
    business.push_back(store);
    business.push_back(alemon);
    business.push_back(anewspaper);
    business.push_back(astore);
}

//Using objects to run the game, simulating each day with an infinite loop, players can run a business, or expand （用无限循环模拟每一天，玩家可以选择运营商业或者扩张）
void Game_engine::run_game(){
    while (true){
        system("clear");    
        cout<<"Welcome to Buy in Large!"<<endl;
        cout<<"Hello, "<<player->getName()<<"!"<<endl;
        cout<<"It is day "<<player->getDays()<<"."<<endl;
        cout<<"You have "<<player->getMoney()<<" dollars."<<endl;
        cout<<"Choose a business you would like to run: "<<endl;
        cout<<"1. Lemonade Stand, you have: "<<player->getProperty(0)<<endl;
        cout<<"2. Newspaper Stand, you have: "<<player->getProperty(1)<<endl;
        cout<<"3. Convenience Store, you have: "<<player->getProperty(2)<<endl;
        cout<<"4. Advanced Lemonade Stand, you have: "<<player->getProperty(3)<<endl;
        cout<<"5. Advanced Newspaper Stand, you have: "<<player->getProperty(4)<<endl;
        cout<<"6. Advanced Convenience Store, you have: "<<player->getProperty(5)<<endl;
        cout<<"7. I don't want to run. I want to expand my business!"<<endl;
        cout<<"8. I want to save my game and quit."<<endl;


        int choice = 0;
        cin>>choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int income = 0;

        switch (choice) {
            case 1:
                income = business[choice-1]->run();
                cout<<"You earned "<<player->getProperty(0) * income<<" dollars."<<endl;
                player->setMoney(player->getMoney() + player->getProperty(0) * income);
                player->incrementDays();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 2:
                if (player->getProperty(1) == 0){
                    cout<<"You do not have any newspaper stands. Press enter to continue..."<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                income = business[choice-1]->run();
                cout<<"You earned "<<player->getProperty(1) * income<<" dollars."<<endl;
                player->setMoney(player->getMoney() + player->getProperty(1) * income);
                player->incrementDays();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 3:
                if (player->getProperty(2) == 0){
                    cout<<"You do not have any convenience stores. Press enter to continue..."<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                income = business[choice-1]->run();
                cout<<"You earned "<<player->getProperty(2) * income<<" dollars."<<endl;
                player->setMoney(player->getMoney() + player->getProperty(2) * income);
                player->incrementDays();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 4:
                if (player->getProperty(3) == 0){
                    cout<<"You do not have any advanced lemonade stands. Press enter to continue..."<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                income = business[choice-1]->run();
                cout<<"You earned "<<player->getProperty(3) * income<<" dollars."<<endl;
                player->setMoney(player->getMoney() + player->getProperty(3) * income);
                player->incrementDays();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 5:
                if (player->getProperty(4) == 0){
                    cout<<"You do not have any advanced newspaper stands. Press enter to continue..."<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                income = business[choice-1]->run();
                cout<<"You earned "<<player->getProperty(4) * income<<" dollars."<<endl;
                player->setMoney(player->getMoney() + player->getProperty(4) * income);
                player->incrementDays();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 6:
                if (player->getProperty(5) == 0){
                    cout<<"You do not have any advanced convenience stores. Press enter to continue..."<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }
                income = business[choice-1]->run();
                cout<<"You earned "<<player->getProperty(5) * income<<" dollars."<<endl;
                player->setMoney(player->getMoney() + player->getProperty(5) * income);
                player->incrementDays();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 7:
                this->purchase();
                player->incrementDays();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            case 8:
                player->save("save.txt");
                cout<<"Game saved. Goodbye!"<<endl;
                exit(0);
                break;
            default:
                cout << "\nInvalid choice. Press enter to continue...";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
                break;
        }
    }

}

//Update player objects by making purchases based on selection（根据购物选择更新玩家对象）
void Game_engine::purchase(){
    while (true){
        system("clear");
        cout<<"You have "<<player->getMoney()<<" dollars."<<endl;
        cout<<"What would you like to buy?"<<endl;
        cout<<"1. Lemonade Stand for "<<business[0]->get_price()<<endl;
        cout<<"2. Newspaper Stand for "<<business[1]->get_price()<<endl;
        cout<<"3. Convenience Store for "<<business[2]->get_price()<<endl;
        cout<<"4. Advanced Lemonade Stand for "<<business[3]->get_price()<<endl;
        cout<<"5. Advanced Newspaper Stand for "<<business[4]->get_price()<<endl;
        cout<<"6. Advanced Convenience Store for "<<business[5]->get_price()<<endl;
        cout<<"7. I don't want to buy anything."<<endl;

        int choice = 0;
        cin>>choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                if (player->getMoney() >= business[0]->get_price()){
                    player->setMoney(player->getMoney() - business[0]->get_price());
                    player->setProperty(0, player->getProperty(0) + 1);
                    cout<<"You have purchased a lemonade stand!"<<endl;
                    cout<<"You now have "<<player->getProperty(0)<<" lemonade stands."<<endl;
                    cout<<"You have "<<player->getMoney()<<" dollars left."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return;
                } else {
                    cout<<"You do not have enough money to purchase a lemonade stand."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.get();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            case 2:
                if (player->getMoney() >= business[1]->get_price()){
                    player->setMoney(player->getMoney() - business[1]->get_price());
                    player->setProperty(1, player->getProperty(1) + 1);
                    cout<<"You have purchased a newspaper stand!"<<endl;
                    cout<<"You now have "<<player->getProperty(1)<<" newspaper stands."<<endl;
                    cout<<"You have "<<player->getMoney()<<" dollars left."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return;
                } else {
                    cout<<"You do not have enough money to purchase a newspaper stand."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.get();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            case 3:
                if (player->getMoney() >= business[2]->get_price()){
                    player->setMoney(player->getMoney() - business[2]->get_price());
                    player->setProperty(2, player->getProperty(2) + 1);
                    cout<<"You have purchased a convenience store!"<<endl;
                    cout<<"You now have "<<player->getProperty(2)<<" convenience stores."<<endl;
                    cout<<"You have "<<player->getMoney()<<" dollars left."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return;
                } else {
                    cout<<"You do not have enough money to purchase a convenience store."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.get();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            case 4:
                if (player->getMoney() >= business[3]->get_price()){
                    player->setMoney(player->getMoney() - business[3]->get_price());
                    player->setProperty(3, player->getProperty(3) + 1);
                    cout<<"You have purchased an advanced lemonade stand!"<<endl;
                    cout<<"You now have "<<player->getProperty(3)<<" advanced lemonade stands."<<endl;
                    cout<<"You have "<<player->getMoney()<<" dollars left."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return;
                } else {
                    cout<<"You do not have enough money to purchase an advanced lemonade stand."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.get();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            case 5:
                if (player->getMoney() >= business[4]->get_price()){
                    player->setMoney(player->getMoney() - business[4]->get_price());
                    player->setProperty(4, player->getProperty(4) + 1);
                    cout<<"You have purchased an advanced newspaper stand!"<<endl;
                    cout<<"You now have "<<player->getProperty(4)<<" advanced newspaper stands."<<endl;
                    cout<<"You have "<<player->getMoney()<<" dollars left."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return;
                } else {
                    cout<<"You do not have enough money to purchase an advanced newspaper stand."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.get();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            case 6:
                if (player->getMoney() >= business[5]->get_price()){
                    player->setMoney(player->getMoney() - business[5]->get_price());
                    player->setProperty(5, player->getProperty(5) + 1);
                    cout<<"You have purchased an advanced convenience store!"<<endl;
                    cout<<"You now have "<<player->getProperty(5)<<" advanced convenience stores."<<endl;
                    cout<<"You have "<<player->getMoney()<<" dollars left."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    return;
                } else {
                    cout<<"You do not have enough money to purchase an advanced convenience store."<<endl;
                    cout<<"Press enter to continue..."<<endl;
                    cin.clear();
                    cin.get();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                break;
            case 7:
                return;
            default:
                cout << "\nInvalid choice. Press enter to continue...";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
                break;
        }
        return;
    }

}

//Free memory when an object is deleted（在删除对象时释放内存）
Game_engine::~Game_engine(){
    delete player;
    for (int i = 0; i < 6; i++){
        delete business[i];
    }
}