#include "player.h"

#include <iostream>

namespace blackjack {
namespace player {

Player::Player(std::string name) : PlayerBase(name), money_(INIT_MONEY) {}

void Player::transact_money(int amount) {
    if (amount < 0)
        std::cout << '\n' << name_ << " loses " << amount << '\n';
    else
        std::cout << '\n' << name_ << " wins " << amount << '\n';
    money_ += amount;
}

int Player::money() const {
    return money_;
}

} // namespace player
} // namespace blackjack