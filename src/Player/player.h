#ifndef BLACKJACK_PLAYER_PLAYER_H
#define BLACKJACK_PLAYER_PLAYER_H

#include "player_base.h"

#include <string>

namespace blackjack {
namespace player {

class Player : public PlayerBase {
public:
    #define INIT_MONEY 1000

    Player(std::string name);
    void transact_money(int amount);
    int money() const;
private:
    int money_;
};

} // namespace player
} // namespace blackjack

#endif // BLACKJACK_PLAYER_PLAYER_H