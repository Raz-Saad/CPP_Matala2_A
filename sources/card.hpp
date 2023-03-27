#pragma once
#include <iostream>
using namespace std;
namespace ariel{
class Card{
    string value;
    string type;
    public:
        string GetValue();
        string GetType();
};
};