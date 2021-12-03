#ifndef INITIALIZEDECK_H
#define INITIALIZEDECK_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>      
#include <ctime>
#include <cstdlib>

using namespace std;

bool desc(int a, int b);

//Function to initialize player's deck and computer's deck so that no pairs can be made from the both player's and computer's deck
void InitializeDeck(vector<string> &plr);

#endif