#include "card.h"

#include <iostream>

namespace blackjack {
namespace cards {

Card::Card(int rank_id, int suit_id) 
    : rank_id_(rank_id), suit_id_(suit_id),
    rank_name_(card_characteristics.rank_names[rank_id]),
    suit_name_(card_characteristics.suit_names[suit_id]),
    value_(card_characteristics.rank_values[rank_id]) {}

int Card::get_value() const {
    return value_;
}

void Card::print_card() const {
    std::cout << rank_name_ << " of " << suit_name_ << '\n';
}

} // namespace cards
} // namespace blackjack