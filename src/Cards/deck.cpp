#include "deck.h"

#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <iostream>

namespace blackjack {
namespace cards {

Deck::Deck() {
    reset();
    shuffle();
}

Deck::Deck(bool no_shuffle) {
    reset();
}

Card& Deck::draw() {
    Card& drawn_card = cards_.back();
    cards_.pop_back();

    if (cards_.size() == 0) {
        reset();
        shuffle();
    }

    return drawn_card;
}

// TODO it would be more efficient to default initialize cards_ and then insert
// card instances by index. But this would require a default Card ctor.
void Deck::reset() {
    cards_.clear();
    
    for (int suit_id = 0; suit_id < Card::NUM_SUITS; ++suit_id) {
        for (int rank_id = 0; rank_id < Card::NUM_RANKS; ++rank_id) {
            cards_.emplace_back(rank_id, suit_id);
        }
    }
}

void Deck::shuffle() {
    srand(time(NULL));

    for (int i = 51; i > 0; --i) {
        int rand_idx = rand() % i;
        auto tmp = cards_[rand_idx];
        cards_[rand_idx] = cards_[i];
        cards_[i] = tmp;
    }
}

void Deck::print_deck() const {
    std::cout << "================\nCARDS IN DECK:\n\n";

    for (const auto& card : cards_) {
        card.print_card();
    }
    
    std::cout << "\n================\n";
}

} // cards
} // blackjack