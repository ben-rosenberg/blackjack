#ifndef BLACKJACK_CARDS_HAND_H
#define BLACKJACK_CARDS_HAND_H

#include <vector>

#include "card.h"
#include "deck.h"

namespace blackjack {
namespace cards {

class Hand {
public:
    Hand();
    Hand(Card& c1, Card& c2);
    // Hand(Deck& deck);

    void init_hand(Card& c1, Card& c2);
    void hit(Card& card);
    int value() const;
    bool is_bust() const;

    void print_hand() const;
    void print_top_card() const;
    const Card& dealer_visible_card() const;
private:
    std::vector<Card> cards_;
    int card_count_;
    int value_; // this needs to be changed to accomodate ace = 1 OR 11
    bool is_bust_ = false;
};

} // namespace blackjack
} // namespace cards

#endif // BLACKJACK_CARDS_HAND_H