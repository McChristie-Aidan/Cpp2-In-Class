#include "Player.h"

Player::Player(std::string _name, std::vector<Card*>*)
{
    this->name = _name;
    this->hand = _hand;
    handTotal = 0;
}

Player::~Player()
{
    delete this->hand;
}