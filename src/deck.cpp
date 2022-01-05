//deck.cpp

#include "deck.h"
#include <iostream>

Deck::Deck() {
    
}

Deck::~Deck() {
    deckOfCards.clear();
    deckOfCards.shrink_to_fit();
}

// fills deck with all the cards in a real deck
void Deck::populateDeck() {
    deckOfCards.clear();

    for (int i = 0; i < DIAMONDS + 1; i++) {
        for(int j=0; j < KING + 1; j ++) {
            deckOfCards.push_back(Card(Card::intToSuit(i), Card::intTORank(j)));
        }
    }
}

// add card to deck
void Deck::appendCard(Card card) {
    deckOfCards.push_back(card);
}

// shuffles the deck given the number of times it needs to be shuffled
void Deck::shuffle(int n) {
    std::srand ( unsigned ( std::time(0) ) );
    for (int i=0; i < n; i++) {
        std::random_shuffle(deckOfCards.begin(), deckOfCards.end());
    }
}

// takes a card out of the deck
Card Deck::draw()
{
    if (getCardsRemaining() > 0) {
        Card drawnCard = deckOfCards.back();
        deckOfCards.pop_back();
        return drawnCard;
    }
    else {
        return Card();
    }
}

// gets the number of cards in the deck
int Deck::getCardsRemaining()
{
    return deckOfCards.size();
}

// gets the index of a card given the cards value
int Deck::cardIndex(Card card) {
    bool foundCard = false;
    int index = -1;
    for (std::vector<Card>::iterator it = deckOfCards.begin(); it != deckOfCards.end() && !foundCard; ++it) {
        index++;
        if (it->equals(card)) {
            foundCard = true;
        }
    }
    if (foundCard) {
        return index;
    }
    else {
        return -1;
    }
    
}

// removes a card from the deck by its index
void Deck::deleteCardByIndex(int index) {
    if (index < deckOfCards.size()) {
        deckOfCards.erase(deckOfCards.begin() + index);
        deckOfCards.shrink_to_fit();
    }
}

// get the number of cards that have a rank below a number
int Deck::numberOfCardsBellow(int number) {
    int cardsBellow = 0;
    for (std::vector<Card>::iterator it = deckOfCards.begin(); it != deckOfCards.end(); ++it) {
        if (it->getRank() + 1 < number) {
            cardsBellow++;
        }
    }
    return cardsBellow;
}

// gets the number of cards in a deck
int Deck::size() {
    return deckOfCards.size();
}

// gets if the deck is empty
bool Deck::isDeckEmpty() {
    return getCardsRemaining() < 1;
}

// checks that two decks are the same
bool operator == (const Deck& deckOne, const Deck& deckTwo) {
    return std::equal(deckOne.deckOfCards.begin(), deckOne.deckOfCards.begin() + deckOne.deckOfCards.size(), deckTwo.deckOfCards.begin());
}