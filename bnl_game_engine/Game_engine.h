#pragma once

#include <string> // Add this line to include the string header
#include <vector>
#include "../bnl_business/Business.h"
#include "../bnl_player/Player.h"

using namespace std;

class Game_engine {
private:
    Player* player;
    vector<Business*> business;

public:
    Game_engine(Player* newplayer);
    void run_game();
    void purchase();
    ~Game_engine();
};
