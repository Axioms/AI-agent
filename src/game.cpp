//game.cpp

#include "game.h"
#include <iostream>
#include <string>

BlackJack::BlackJack(int players, int shuffle) {
    BlackJack::numberOfPlayer = players;
    gameDeck.populateDeck();
    gameDeck.shuffle(shuffle);
    roundNumber = 0;
}

BlackJack::~BlackJack() {
    players.clear();
    players.shrink_to_fit();
}

// runs a game of black jack
void BlackJack::start() {
    players.push_back(Agent(true));
    for (int i=1; i < numberOfPlayer; i++) {
        players.push_back(Agent());
    }
    
    std::cout << "====" << " Round " << ++roundNumber  << " ====" << std::endl;
    while(turn() != numberOfPlayer) {
        std::cout << std::endl << "click ENTER to proceed to the next round" << std::endl;
        std::cin.get();
        roundNumber++;
        std::cout << std::endl << "====" << " Round " << roundNumber  << " ====" << std::endl;
    }
    
    std::cout << std::endl << hasWon() << std::endl << std::endl;
    printScores();

    players.clear();
    players.shrink_to_fit();
}

// polls agents to see if they want to take a card or not
int BlackJack::turn() {
    int numberFolds = 0;
    for(int i=0; i < numberOfPlayer; i++) {
        if (players[i].turn()) {
            Card drawnCard = gameDeck.draw();
            players[i].addCard(drawnCard);
            cardDrawn(drawnCard);
            std::cout << " Player " << i << " drew a " << drawnCard.getCard() << std::endl;
        }
        else {
            numberFolds++;
            std::cout << " Player " << i << " folded" << std::endl;
        }
    }
    return numberFolds;
}

// tells every agent what card has been taken
void BlackJack::cardDrawn(Card card) {
    for(int i=0; i < numberOfPlayer; i++) {
        players[i].takeCardOutOfRotation(card);
    }
}

// Determines winner
std::string BlackJack::hasWon() {

    std::string wonString = "";
        int numberOfWinners = 0;
        Agent winner;
        int winningHand = 0;

    if(players[0].getDealerTotal() <= 21) {
        wonString = "0 ";
        numberOfWinners = 1;
        winner = players[0];
        winningHand = winner.getDealerTotal();
    }

    for(int i= 1; i < numberOfPlayer; i++) {
        if (players[i].getHandTotal() > winningHand && players[i].getHandTotal() <= 21) {
            winner = players[i];
            winningHand = winner.getHandTotal();

            wonString = "" + std::to_string(i) + " ";
            numberOfWinners = 1;
        }

        else if (players[i].getHandTotal() == winningHand) {
            wonString += std::to_string(i) + " ";
            numberOfWinners++;
        }
    }
    if (numberOfWinners == 1) {
        return "Player " + wonString + "won with a hand of " + std::to_string(winningHand);
    }
    else if (numberOfWinners > 1) {
        return "Players " + wonString + "tied with a hand of " + std::to_string(winningHand);
    }
    else {
        return "no one won? HOW DID THIS HAPPEN!!!!";
    }
}

// prints scores after a game ends
void BlackJack::printScores() {
    std::cout << "==== Player Hands ====" << std::endl;
    std::cout << "Player " << 0 << " had a hand of " << players[0].getDealerTotal() << std::endl;
    for (int i = 1; i < numberOfPlayer; i++) {
        std::cout << "Player " << i << " had a hand of " << players[i].getHandTotal() << std::endl;
    }
}