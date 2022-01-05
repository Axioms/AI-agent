//agent.h

#pragma once
#include "deck.h"
#include "card.h"

class Agent {
    public:
        Agent();
        Agent(bool dealer);
        ~Agent();
        int getHandTotal();
        int getDealerTotal();
        bool turn();
        bool isDealer();
        void addCard(Card card);
        void takeCardOutOfRotation(Card card); 
        friend bool operator == (const Agent& agentOne, const Agent& agentTwo);
        private:
            int handValue;
            bool dealer;
            bool hasFolded;
            float minimunChanceOfSuccess;
            Deck hand;
            Deck cardsInGameDeck;
            Card DealerCard;
};