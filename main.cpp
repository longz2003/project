#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <fstream>
#include "bnl_player/Player.h"
#include "bnl_game_engine/Game_engine.h"

using namespace std;

// this is from old menu file, we changed menu to main
// loop to show menu, ask input and check input, then start game
// can use player to load saved game
// 原本为菜单类，后来觉得菜单类没有独立的意义，就做进了main里面，这里是游戏的起点，用来显示最初的主菜单，创建新玩家或者从文件载入存档
void start() {
    while (true) {
        
        // clear the screen of all previous output
        system("clear");
        cout<<"Buy in Large game"<<endl<<endl;
        cout<<"Main Menu"<<endl<<endl;
        cout<<"1. New Game"<<endl;
        cout<<"2. Load Game"<<endl;
        cout<<"3. Exit"<<endl<<endl;
        cout<<"Enter your choice: ";

        int choice = 0;
        cin>>choice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Player* player = nullptr;
        Game_engine* game = nullptr;
        bool still_going = true;
        // check if save.txt exists

        bool have_save = false;
        ifstream file("save.txt");
        if (file.good()) {
            have_save = true;
        }

        switch (choice) {
            case 1:
                cout << "\nStarting new game...\n";
                player = new Player();
                game = new Game_engine(player);
                while (still_going) {
                    game->run_game();
                }
                break;
            case 2:
                if (!have_save) {
                    cout << "\nNo save file found. Press enter to continue...";
                    cin.get();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                cout << "\nLoading game...\n";
                player = new Player("save.txt");
                game = new Game_engine(player);
                while (still_going) {
                    game->run_game();
                }
                break;
            case 3:
                cout << "\nExiting...\n";
                delete[] player;
                return;
            default:
                cout << "\nInvalid choice. Press enter to continue...";
                
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
        }
    }
}

// just to start loop
int main() {
    start();
    return 0;
}
