//agent.cpp

#include "agent.h"

Agent::Agent() {
    //srand(time(0));
    hand = Deck();
    cardsInGameDeck = Deck();
    cardsInGameDeck.populateDeck();
    dealer = false;
    hasFolded = false;
    handValue= 0;
    DealerCard = Card();
    // the agents minnimum success chance to take
    minimunChanceOfSuccess = 0.3 + (float)(rand()%70)/150;
}

Agent::Agent(bool dealer) {
    hand = Deck();
    cardsInGameDeck = Deck();
    cardsInGameDeck.populateDeck();
    Agent::dealer = dealer;
    hasFolded = false;
    handValue = 0;
    DealerCard = Card();
    srand (time(NULL));
    // the agents minnimum success chance to take
    minimunChanceOfSuccess = 0.3 + (float)(rand()%70)/150;
}

Agent::~Agent() {
    
}
// returns the value of the dealer's hand
int Agent::getDealerTotal() {
    if (dealer) {
        getHandTotal();
        return handValue;
    }

    return -1;
}

// gets total rank of cards
int Agent::getHandTotal() {
    int total = 0;
    int DealerCardValue = 0;
    if (dealer && !DealerCard.isInvalid) {
        DealerCardValue = DealerCard.getRank() + 1; 
        if (DealerCardValue == 1 && total < 21) {
            total += 11;
        }
        else {
             if (DealerCardValue > TEN) {
                total += 10;
            }
            else {
                total += DealerCardValue;
            }
        }
    }
    Deck temp = hand;
    while (!temp.isDeckEmpty()) {
        int value = temp.draw().getRank() + 1;
        if (value == 1 && total < 21) {
            total += 11;
        }
        else {
             if (value > TEN) {
                total += 10;
            }
            else {
                total += value;
            }
        }       
    }
    handValue = total;
    if (dealer) {
        total -= DealerCardValue;
    }
    return total;
}

// decided where or not the agent is going to take a card
bool Agent::turn() {
    // false if agent has more then 21 cards
    if (hasFolded || handValue > 21) {
        return false;
    }
    else if(dealer && getDealerTotal() > 21) {
        return false;
    }
    
    //srand (time(NULL));
    getHandTotal();
    
    int totalCards = cardsInGameDeck.size();
    int pointsNeeded = 21 - handValue;
    int cardsBelowNeeded = cardsInGameDeck.numberOfCardsBellow(pointsNeeded);
    // probability of staying under 21 if taking a card
    float chanceOfSuccess = (float)(cardsBelowNeeded)/totalCards;
    // agent has a chance to "go all in"
    if ((rand()%3) == 0) {
        float tempMinxSuccess = minimunChanceOfSuccess - (0.1 + (float)(rand()%70)/250);

        if (chanceOfSuccess > tempMinxSuccess) {
            return true;
        }
        hasFolded = true;
        return false;
    }

    if(chanceOfSuccess > minimunChanceOfSuccess) {
        return true;
    }
    hasFolded = true;
    return false;
}

// returns if the agent is the "dealer"
bool Agent::isDealer() {
    return dealer;
}

// adds card to deck
void Agent::addCard(Card card) {
    hand.appendCard(card);
    takeCardOutOfRotation(card);
    getHandTotal();
}

//removes card from a deck
void Agent::takeCardOutOfRotation(Card card) {
    cardsInGameDeck.deleteCardByIndex(cardsInGameDeck.cardIndex(card));
}

// sees if two agesnt are the same
bool operator == (const Agent& agentOne, const Agent& agentTwo) {
    return agentOne.hand == agentTwo.hand;
}