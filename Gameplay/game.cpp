#include "game.h"

#include <iostream>
#include <string>

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

int Game::player_action() {
    std::cout << '\n' << player_.name() << "'s hand value is " << player_.hand_value();
    std::cout << "\nWould you like to hit (h) or stand (s)? ";
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
    std::cout << "\nDealer's hand value is " << dealer_.hand_value();

    while (dealer_.hand_value() < 17) {
        dealer_.hit(deck_.draw());
    }

    return dealer_.hand_value();
}

int Game::query_bet() {
    int bet;

    std::cout << "\nBank: " << player_.money();
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
    player_.init_hand(deck_.draw(), deck_.draw());
    dealer_.init_hand(deck_.draw(), deck_.draw());
}

bool Game::query_new_game() {
    if (player_.money() <= 0)
        return false;
    
    char response;
    std::cout << "\n\nEnter 'q' to quit, or any other key to begin a new round: ";
    std::cin >> response;

    return response != 'q' && response != 'Q';
}

/* Game::Game(std::string player_name) : player_(player_name), dealer_(), deck_() {}

void Game::start_play() {
    std::cout << "\nLet's begin.\n\n";
    init_round();
}

void Game::init_round() {
    std::cout << "Bank: " << player_.money() << '\n';
    std::cout << "Place your bet:\n";
    int bet;
    std::cin >> bet;

    std::cout << '\n';

    while (bet > player_.money()) {
        std::cout << "Your bet is greater than your bank.\nWould you like to go all-in (y) or place a different bet? (any key)\n";
        char response;
        std::cin >> response;
        if (response == 'y' || response == 'Y')
            bet = player_.money();
        else {
            std::cout << "Bank: " << player_.money() << '\n';
            std::cout << "\nPlace your bet:\n";
            std::cin >> bet;
        }
    }

    round_bet_ = bet;
    deal_cards();
    play();
}

void Game::deal_cards() {
    player_.init_hand(deck_.draw(), deck_.draw());
    dealer_.init_hand(deck_.draw(), deck_.draw());
}

void Game::play() {
    int final_player_hand_value = player_.turn(deck_);
    if (final_player_hand_value > 21) {
        std::cout << player_.name() << " loses :(\n";
        // end_round();
        return;
    }

    int final_dealer_hand_value = dealer_.turn(deck_);

    if (final_dealer_hand_value > 21 || final_dealer_hand_value < final_player_hand_value) {
        std::cout << player_.name() << " wins!\n";
        player_.transact_money(2 * round_bet_);
    } else if (final_dealer_hand_value > final_player_hand_value) {
        std::cout << player_.name() << " loses :(\n";
        player_.transact_money(-1 * round_bet_);
    } else {
        std::cout << "Tie\n";
    }

    // end_round();
}

void Game::end_round() {
    std::cout << "Round finished.\n\n";
    if (player_.money() <= 0) {
        std::cout << "You lose.\n";
        return;
    } else {
        std::cout << "Would you like to begin another game? (y/n)\n";
        char response;
        std::cin >> response;
        if (response == 'y' || response == 'Y') {
            init_round();
        }
    }
} */

} // namespace gameplay
} // namespace blackjack