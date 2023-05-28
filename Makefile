# Compiler
CC := g++

# Target executable
TARGET := blackjack

# Directories (source, build, and target)
SRC_DIR := src
BUILD_DIR := obj
TARGET_DIR := bin

# Flags
CPP_FLAGS := -Wall

# Build
OBJS := main.o game.o player_base.o dealer.o player.o hand.o deck.o card.o

# Source
SRCS := main.cpp Gameplay/game.cpp Player/player_base.cpp Player/dealer.cpp \
		Player/player.cpp Cards/hand.cpp Cards/deck.cpp Cards/card.cpp

blackjack: ${addprefix ${BUILD_DIR}/,${OBJS}}
	${CC} -o ${TARGET_DIR}/${TARGET} ${addprefix ${SRC_DIR}/,${SRCS}}

${BUILD_DIR}/main.o:
${BUILD_DIR}/game.o:
${BUILD_DIR}/player_base.o:
${BUILD_DIR}/dealer.o: 
${BUILD_DIR}/player.o: 
${BUILD_DIR}/hand.o: 
${BUILD_DIR}/deck.o: 
${BUILD_DIR}/card.o: 


#test:
#	@echo ${addprefix ${SRC_DIR}/,${OBJS}}

#all:
#	g++ -o blackjack src/main.cpp src/Gameplay/game.cpp src/Player/player_base.cpp src/Player/dealer.cpp src/Player/player.cpp src/Cards/hand.cpp src/Cards/deck.cpp src/Cards/card.cpp

#clean:
#	rm blackjack.exe