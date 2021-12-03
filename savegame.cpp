#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "savegame.h"

using namespace std;

//Function that save current decks information to txt files.
void SaveGame(vector<string> &p1, vector<string> &p2){
    
    //save the current player's deck to p1.txt
    ofstream output_file("./p1.txt");
    ostream_iterator<string> output_iterator(output_file, " ");
    copy(p1.begin(), p1.end(), output_iterator);
    
    //save the current computer's deck to p2.txt
    ofstream output_file1("./p2.txt");
    ostream_iterator<string> output_iterator1(output_file1, " ");
    copy(p2.begin(), p2.end(), output_iterator1);
}