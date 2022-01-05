//main.cpp

#include <iostream>
#include <string>
#include "game.h"
#include "agent.h"
#include "deck.h"
#include "card.h"


using namespace std;

int main(int argc, char *argv[]) {
    // init random
    srand(time(NULL));

    // set number of games either through console args or the variable
    int numberOfGames = 1;
    if (argc > 1) {
        numberOfGames = atoi(argv[1]);
    }

    // play number of games spesified
    while (numberOfGames > 0) {
        BlackJack game(4, 100);

        game.start();
        numberOfGames--;
        cout << endl << "press ENTER to continue ( There are " << numberOfGames << " more games )" << "..." << endl;
        cin.get();
    }
    
}