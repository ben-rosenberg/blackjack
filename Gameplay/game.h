#ifndef BLACKJACK_GAMEPLAY_GAME_H
#define BLACKJACK_GAMEPLAY_GAME_H

#include <string>

#include "../Cards/deck.h"
#include "../Player/dealer.h"
#include "../Player/player.h"

namespace blackjack {
namespace gameplay {

class Game {
public:
    Game(std::string player_name);

    bool play();
    int query_bet();
    void init_hands();
    int player_action();
    int dealer_action();
    bool query_new_game();
private:
    player::Player player_;
    player::Dealer dealer_;
    cards::Deck deck_;
};

/* class Game {
public:
    Game(std::string player_name);
    void start_play();
    void init_round();
    void deal_cards();

    void play();

    void end_round();

private:
    player::Player player_;
    player::Dealer dealer_;
    cards::Deck deck_;
    int round_bet_;
}; */

} // namespace gameplay
} // namespace blackjack

#endif // BLACKJACK_GAMEPLAY_GAME_H