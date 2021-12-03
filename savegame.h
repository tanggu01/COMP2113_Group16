#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <chrono>       
#include <ctime>
#include <cstdlib>

using namespace std;

//Function that save current decks information to txt files.
void SaveGame(vector<string> &p1, vector<string> &p2);

#endif
