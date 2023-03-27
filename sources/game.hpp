#pragma once
#include <iostream>
#include "player.hpp"
using namespace std;

namespace ariel{
class Game{
    Player player1;
    Player player2;
    public:
        Game(Player player1,Player player2);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        Player GetPlayer1();
        Player GetPlayer2();

};
};

