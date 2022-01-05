//card.cpp

#include "card.h"

const char *suitNames[] = {"Spades", "Hearts", "Clubs", "Diamonds"};
const char *rankNames[] = {"Ace", "Two", "Three", "Four", "Five", "Six", 
                           "Seven", "Eight", "Nine", "Ten", "Jack", 
                           "Queen", "King"};

Card::Card() {
    isInvalid = true;
}

Card::Card(Suit suit, Rank rank) {
    isInvalid = false;
    Card::rank = rank;
    Card::suit = suit;
}

// returns card as a string
std::string Card::getCard() {
    if (isInvalid) {
        return "Invalid Card";
    }
    return getRankString() + " of " + getSuitString();
}

// gets the cards suit
Suit Card::getSuit() {
    return suit;
}

//gets the cards value
Rank Card::getRank() {
    return rank;
}

// returns the suit string
std::string Card::getSuitString() {
    return suitNames[suit];
}

// returns the value as a string
std::string Card::getRankString() {
    return rankNames[rank];
}

// convert int to suit
Suit Card::intToSuit(int suit) {
    return static_cast<Suit>(suit);
}

// cunvert int to rank
Rank Card::intTORank(int rank) {
    return static_cast<Rank>(rank);
}

// determine if two cards are equal
bool Card::equals(Card card) {
    return !card.isInvalid && suit == card.getSuit() && rank == card.getRank();
}

// determine if two cards are equal
bool operator == (const Card& cardOne, const Card& cardTwo) {
    return !cardOne.isInvalid && !cardTwo.isInvalid && cardOne.rank == cardTwo.rank && cardOne.suit == cardTwo.suit;
}