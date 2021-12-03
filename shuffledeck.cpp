#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>       // std::chrono::system_clock
#include <ctime>
#include <cstdlib>
using namespace std;

#include "shuffledeck.h"

//Step 1: before the game 
//Function to shuffle deck and distribute cards to each player's deck 
void shuffle_deck(vector<string>& deck, vector<string>& p1, vector<string>& p2) {
    // Shuffle deck randomly
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    shuffle (deck.begin(), deck.end(), std::default_random_engine(seed));
    
    //Append card from 1st to 27th card in the shuffled deck to player's deck
    for (int i=0; i<27; i++) {
        p1.push_back(deck[i]);
    }
    //Append card from 28th card in the shuffled deck to computer's deck
    for (int i=27; i<deck.size(); i++) {
        p2.push_back(deck[i]);
    }
}