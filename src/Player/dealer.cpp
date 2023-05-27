#include "dealer.h"

#include <iostream>

namespace blackjack {
namespace player {

Dealer::Dealer() : PlayerBase("Dealer") {}

void Dealer::init_hand(cards::Card& c1, cards::Card& c2) {
    std::cout << '\n' << name_ << " is dealt:";
    std::cout << "\n{hidden}\n";
    c2.print_card();
    hand_.init_hand(c1, c2);
}

void Dealer::read_hand() const {
    hand_.dealer_visible_card().print_card();
    std::cout << "{hidden}";
}

void Dealer::reveal_hand() const {
    std::cout << "Dealer's hand is:\n";
    hand_.print_hand();
}

} // namespace player
} // namespace blackjack