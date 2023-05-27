#ifndef BLACKJACK_CARDS_DECK_H
#define BLACKJACK_CARDS_DECK_H

#include "card.h"

#include <vector>

namespace blackjack {
namespace cards {

class Deck {
public:
    Deck();
    Deck(bool no_shuffle);

    Card& draw();

    void reset();
    void shuffle();

    void print_deck() const;

private:
    std::vector<Card> cards_;
};

} // namespace cards
} // namespace blackjack

#endif // BLACKJACK_CARDS_DECK_H