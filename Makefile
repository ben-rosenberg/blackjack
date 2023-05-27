all:
	g++ -o blackjack src/main.cpp src/Gameplay/game.cpp src/Player/player_base.cpp src/Player/dealer.cpp src/Player/player.cpp src/Cards/hand.cpp src/Cards/deck.cpp src/Cards/card.cpp

clean:
	rm blackjack.exe