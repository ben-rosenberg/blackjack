#ifndef BLACKJACK_PLAYER_PLAYER_BASE_H
#define BLACKJACK_PLAYER_PLAYER_BASE_H

#include <string>
#include <vector>

#include "../Cards/deck.h"
#include "../Cards/hand.h"

namespace blackjack {
namespace player {

class PlayerBase {
public:
    PlayerBase(std::string name);

    std::string name() const;

    virtual void init_hand(cards::Card& c1, cards::Card& c2);
    void hit(cards::Card& card);
    virtual void read_hand() const;
    int hand_value() const;

protected:
    std::string name_;
    cards::Hand hand_;
};

} // namescape player
} // namespace blackjack

#endif // BLACKJACK_PLAYER_PLAYER_BASE_H