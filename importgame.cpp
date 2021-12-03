#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "importgame.h"

using namespace std;

//Function to import saved game information to current game.
bool ImportGame(vector<string> &p1, vector<string> &p2){
  
    ifstream fin1;
    ifstream fin2;
    fin1.open("p1.txt"); //open player's deck
    fin2.open("p2.txt"); //open computer's deck
    
    string x, y;
    //initialize each bool as false which will indicates whether the deck contains any cards or not
    bool flag_1 = false; 
    bool flag_2 = false;

  //if player's deck is not empty, change flag_1 as true and append it to p1 vector
  if (fin1 >> x){
    flag_1 = true;
    p1.push_back(x);
    while (fin1 >> x){
      p1.push_back(x);
    } 
  }
    //if computer's deck is not empty, change flag_2 as true and append it to p2 vector
    if (fin2 >> y){
      flag_2 = true;
      p2.push_back(y);
      while (fin2 >> y){
        p2.push_back(y);
      }
      //close the txt file of both player's and computer's deck and return true
      fin1.close();
      fin2.close();
      return true;
    }

    //if both flag_1 and flag_2 remain as false which means both deck are empty, return false
    if (flag_1 == false || flag_2 ==false) {
      // cout << "No saved game file" << "\n";
      fin1.close();
      fin2.close();
      return false;
    }
    
    //if one or more files are failed to open, print error message and stop the program
    else if (fin1.fail() || fin2.fail()){
      cout << "Error in file opening! " << "\n";
      exit(1);
    }
}