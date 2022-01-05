//dech.h

#pragma once
#include <vector>
#include <algorithm>    // std::random_shuffle
#include <ctime>        // std::time
#include <cstdlib>      // std::rand, std::srand
#include "card.h"

class Deck {
    public:
        Deck();
        ~Deck();
        void populateDeck();
        void appendCard(Card card);
        void shuffle(int n);
        Card draw();
        int getCardsRemaining();
        int cardIndex(Card card);
        void deleteCardByIndex(int index);
        int numberOfCardsBellow(int number);
        int size();
        bool isDeckEmpty();

        friend bool operator == (const Deck& deckOne, const Deck& deckTwo);
    private:
        std::vector<Card> deckOfCards;
};