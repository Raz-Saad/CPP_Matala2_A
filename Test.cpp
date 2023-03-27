#include "doctest.h"
#include <iostream>
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace std;
using namespace ariel;


TEST_CASE("Test 1 - Check stacksize and cardstaken before the game started") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);

    CHECK(((p1.cardesTaken() == 0) && (p2.cardesTaken() == 0)));
    CHECK(((p1.stacksize() == 26)&&(p2.stacksize() == 26)));
    
}
TEST_CASE("Test 2 - Check stacksize and cardstaken after a one round") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    game.playTurn();

    CHECK(((p1.stacksize() >= 0) && (p1.stacksize() <= 25)));
    CHECK(((p2.stacksize() >= 0) && (p2.stacksize() <= 25)));
    CHECK(((p1.cardesTaken() >= 0) && (p1.cardesTaken() <= 52)));
    CHECK(((p2.cardesTaken() >= 0) && (p2.cardesTaken() <= 52)));
}


TEST_CASE("Test 3 - Check stacksize and cardstaken after 26 rounds") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    for(int i=0;i<26;i++)
    {
        game.playTurn();
    }

    CHECK(((p1.stacksize() == 0) && (p2.stacksize() == 0)));
    CHECK(((p1.cardesTaken() >= 0) && (p1.cardesTaken() <= 52)));
    CHECK(((p2.cardesTaken() >= 0) && (p2.cardesTaken() <= 52)));
}

TEST_CASE("Test 4 - Check stacksize and cardstaken after the the game ended") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    game.playAll();

    CHECK(((p1.stacksize() == 0) && (p2.stacksize() == 0)));
    CHECK(((p1.cardesTaken() >= 0) && (p1.cardesTaken() <= 52)));
    CHECK(((p2.cardesTaken() >= 0) && (p2.cardesTaken() <= 52)));
    
}

TEST_CASE("Test 5 - game with same player") {
    Player p1("Raz");
    
    CHECK_THROWS(Game(p1,p1));
    
}
TEST_CASE("Test 6 - playturn after the game is finished") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    game.playAll();
    CHECK_THROWS(game.playTurn());
    
}
TEST_CASE("Test 7 - print a winner before the game is even started") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    CHECK_THROWS(game.printWiner());
    
}

TEST_CASE("Test 8 - print a winner before the game is ended") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    for(int i=0;i<3;i++)
    {
        game.playTurn();
    }
    CHECK_THROWS(game.printWiner());
}

TEST_CASE("Test 9 - Check stacksize and cardstaken midgame") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    for(int i=0;i<3;i++)
    {
        game.playTurn();
    }

    CHECK(((p1.stacksize() >= 0) && (p1.stacksize() <= 23)));
    CHECK(((p2.stacksize() >= 0) && (p2.stacksize() <= 23)));
    CHECK(((p1.cardesTaken() >= 0) && (p1.cardesTaken() <= 52)));
    CHECK(((p2.cardesTaken() >= 0) && (p2.cardesTaken() <= 52)));
}

TEST_CASE("Test 10 - print the last turn stats before the game is even started") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn());
    
}
TEST_CASE("Test 11 - prints all turns played before the game is even started") {
    Player p1("Raz");
    Player p2("Maor");

    Game game(p1,p2);
    CHECK_THROWS(game.printLog());
    
}


