#pragma once
#include <iostream>
#include "card.hpp"
using namespace std;
namespace ariel{

class Player{
    string name;//name of the player
    public:
        //Card beginning_deck[26];//deck of cards
        //Card win_deck[52];//deck of cards that the player won
        Player(){}
        Player(string name);
        int stacksize();
        int cardesTaken();
        string getName();
        
};
};

