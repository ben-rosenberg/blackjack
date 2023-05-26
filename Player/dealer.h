#ifndef BLACKJACK_PLAYER_DEALER_H
#define BLACKJACK_PLAYER_DEALER_H

#include "player_base.h"

namespace blackjack {
namespace player {

class Dealer : public PlayerBase {
public:
    Dealer();
    void init_hand(cards::Card& c1, cards::Card& c2) override;
    // int turn(cards::Deck& game_deck) override;
    void read_hand() const override;
    void reveal_hand() const;
};

} // namespace player
} // namespace blackjack

#endif // BLACKJACK_PLAYER_DEALER_H