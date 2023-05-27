#include "game.h"

#include <chrono> // std::chrono::milliseconds()
#include <iostream> // std::cout
#include <string> // std::string
#include <thread> // std::this_thread::sleep_for()

#define SLEEP_DURATION 500

namespace blackjack {
namespace gameplay {

Game::Game(std::string player_name) : player_(player_name), dealer_(), deck_() {}

bool Game::play() {
    int bet = query_bet();
    init_hands();

    int player_final_hand_value = player_action();   
    if (player_final_hand_value > 21) {
        std::cout << "\nYou lose this round.";
        player_.transact_money(bet * -1);
        return query_new_game();
    }

    int dealer_final_hand_value = dealer_action();

    if (player_final_hand_value > dealer_final_hand_value || dealer_final_hand_value > 21) {
        std::cout << "\nYou win this round!";
        player_.transact_money(bet);
        return query_new_game();
    } else {
        std::cout << "\nYou lose this round.";
        player_.transact_money(bet * -1);
        return query_new_game();
    }
}

int Game::query_bet() {
    int bet;

    std::cout << "\nBank: $" << player_.money();
    std::cout << "\nPlace your bet to begin a round: ";
    std::cin >> bet;

    while (bet > player_.money()) {
        std::cout << "\nYour bet is greater than your bank. Would you like to go all-in (y) or place a different bet? (any key): ";
        char response;
        std::cin >> response;

        if (response == 'y' || response == 'Y') {
            bet = player_.money();
        } else {
            std::cout << "\nBank: " << player_.money();
            std::cout << "\nPlace your bet to begin a round:\n";
            std::cin >> bet;
        }
    }

    return bet;
}

void Game::init_hands() {
    std::cout << "\nDealing cards...\n";
    
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DURATION));
    player_.init_hand(deck_.draw(), deck_.draw());

    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_DURATION));
    dealer_.init_hand(deck_.draw(), deck_.draw());
}

int Game::player_action() {
    std::cout << '\n' << player_.name() << "'s hand value is " << player_.hand_value();
    std::cout << "\n\nWould you like to hit (h) or stand (s)? ";
    char response;
    std::cin >> response;

    while (player_.hand_value() <= 21 && (response == 'h' || response == 'H')) {
        player_.hit(deck_.draw());
        std::cout << '\n' << player_.name() << "'s hand value is " << player_.hand_value();
        std::cout << "\nWould you like to hit (h) or stand (s)? ";
        response;
        std::cin >> response;
    }

    return player_.hand_value();
}

int Game::dealer_action() {
    dealer_.reveal_hand();
    std::cout << "\n\nDealer's hand value is " << dealer_.hand_value();

    while (dealer_.hand_value() < 17) {
        dealer_.hit(deck_.draw());
    }

    return dealer_.hand_value();
}

bool Game::query_new_game() {
    if (player_.money() <= 0)
        return false;
    
    char response;
    std::cout << "\n\nEnter 'q' to quit, or any other key to begin a new round: ";
    std::cin >> response;

    return response != 'q' && response != 'Q';
}

void Game::end_game() const {
    std::cout << "\nENDING GAME...";
    std::cout << '\n' << player_.name() << "'s final bank: $" << player_.money();
}

} // namespace gameplay
} // namespace blackjack