#include "hand.h"

namespace blackjack {
namespace cards {

Hand::Hand() : cards_(), card_count_(0), value_{0} {}

Hand::Hand(Card& c1, Card& c2)
    : cards_{c1, c2},
    card_count_(2),
    value_(c1.get_value() + c2.get_value()) {}

void Hand::hit(Card& card) {
    cards_.push_back(card);
    value_ += card.get_value();
    is_bust_ = value_ > 21;
}

void Hand::init_hand(Card& c1, Card& c2) {
    cards_.clear();
    cards_ = {c1, c2};
    value_ = c1.get_value() + c2.get_value();
}

int Hand::value() const {
    return value_;
}

bool Hand::is_bust() const {
    return is_bust_;
} 

void Hand::print_hand() const {
    for (const auto& card : cards_)
        card.print_card();
}

const Card& Hand::dealer_visible_card() const {
    return cards_[0];
}

} // namespace cards
} // namespace blackjack 