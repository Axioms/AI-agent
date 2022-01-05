//card.h

#pragma once
#include <string>

enum Suit {
    SPADES, HEARTS, CLUBS, DIAMONDS
};

enum Rank {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
    JACK, QUEEN, KING
};

class Card {
    public:
        Card();
        Card(Suit suit, Rank rank);
        std::string getCard();
        Suit getSuit();
        Rank getRank();
        std::string getSuitString();
        std::string getRankString();

        bool isInvalid;

        Suit static intToSuit(int suit);
        Rank static intTORank(int rank);
        bool equals(Card card);

        friend bool operator == (const Card& cardOne, const Card& cardTwo);
    private:
        Rank rank;
        Suit suit;
};