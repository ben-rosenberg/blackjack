#include "player.h"

#include <iostream>

namespace blackjack {
namespace player {

Player::Player(std::string name) : PlayerBase(name), money_(INIT_MONEY) {}

/* int Player::turn(cards::Deck& game_deck) {
    std::cout << "\nThe value of your hand is " << hand_.value() << "\n";
    std::cout << "Would you like to hit (h) or stand (s)?\n";
    char response;
    std::cin >> response;

    if (response == 's' || response == 'S')
        return hand_.value();
    else if (response == 'h' || response == 'H') {
        std::cout << name_ << " draws ";
        hand_.hit(game_deck.draw());
        if (hand_.is_bust())
            return hand_.value();
        else
            return turn(game_deck);
    } else {
        std::cout << "Please enter a valid action ('h' or 's')\n";
        return turn(game_deck);
    }    
} */

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