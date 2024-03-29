#include <iostream>
#include <string>

#include "Gameplay/game.h"

int main() {
    std::cout << "\nWelcome to Ben Rosenberg's C++ Blackjack Game!\n";
    std::cout << "\nEnter your name and press enter to begin a game: ";
    
    std::string player_name = "";
    std::cin >> player_name;

    blackjack::gameplay::Game game(player_name);
    
    while (game.play()) {}

    game.end_game();
}

// g++ -o blackjack main.cpp Gameplay/game.cpp Player/player_base.cpp Player/dealer.cpp Player/player.cpp Cards/hand.cpp Cards/deck.cpp Cards/card.cpp 
// g++ -o blackjack main.cpp Cards/deck.cpp Cards/card.cpp