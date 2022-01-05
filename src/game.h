//game.h

#pragma once
#include <vector>
#include "deck.h"
#include "card.h"
#include "agent.h"
#include <string>

class BlackJack {
    public:
        BlackJack(int players, int shuffle);
        void start();
        ~BlackJack();
    private:
        Deck gameDeck;
        std::vector<Agent> players;
        int numberOfPlayer;
        int roundNumber;
        void cardDrawn(Card card);
        int turn();
        std::string hasWon();
        void printScores();
};