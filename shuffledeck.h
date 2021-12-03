#ifndef SHUFFLEDECK_H
#define SHUFFLEDECK_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>      
#include <ctime>
#include <cstdlib>
using namespace std;

//Function to shuffle deck and distribute cards to each player's deck 
void shuffle_deck(vector<string>& deck, vector<string>& p1, vector<string>& p2);

#endif