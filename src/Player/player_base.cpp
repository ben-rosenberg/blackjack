#include "player_base.h"

#include <iostream>

namespace blackjack {
namespace player {

PlayerBase::PlayerBase(std::string name) : name_(name) {}

std::string PlayerBase::name() const {
    return name_;
}

void PlayerBase::init_hand(cards::Card& c1, cards::Card& c2) {
    std::cout << '\n' << name_ << " is dealt:\n";
    c1.print_card();
    c2.print_card();
    hand_.init_hand(c1, c2);
}

void PlayerBase::hit(cards::Card& card) {
    std::cout << '\n' << name_ << " draws ";
    card.print_card();
    hand_.hit(card);
    std::cout << "Hand value: " << hand_.value();
}

void PlayerBase::read_hand() const {
    hand_.print_hand();
}

int PlayerBase::hand_value() const {
    return hand_.value();
}

} // namespace player
} // namespace blackjack