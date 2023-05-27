#ifndef BLACKJACK_CARDS_CARD_H
#define BLACKJACK_CARDS_CARD_H

#include <array>
#include <string>
#include <unordered_map>

namespace blackjack {
namespace cards {

class Card {
public:
    static constexpr int NUM_RANKS = 13;
    static constexpr int NUM_SUITS = 4;
    
    Card(int rank_id, int suit_id);
    int get_value() const;
    void print_card() const;

private:
    int rank_id_;
    int suit_id_;
    std::string rank_name_;
    std::string suit_name_;
    int value_;
};

static const struct CardCharacteristics {
    std::array<std::string, Card::NUM_RANKS> rank_names = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
    };

    std::array<std::string, Card::NUM_SUITS> suit_names = {
        "Clubs", "Diamonds", "Hearts", "Spades"
    };

    std::array<int, Card::NUM_RANKS> rank_values = {
        2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11
    };
} card_characteristics;

} // namespace cards
} // namespace blackjack

#endif // BLACKJACK_CARDS_CARD_H