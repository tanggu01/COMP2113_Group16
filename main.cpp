#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "initializedeck.h"
#include "pickcard.h"
#include "shuffledeck.h"
#include "importgame.h"
#include "savegame.h"
using namespace std;

int main() {
  vector<string> player; // player's deck
  vector<string> computer; //computer's deck
  vector<string> deck  = {"D01","D02","D03","D04","D05","D06","D07","D08","D09","D10","D11","D12","D13",
                          "S01","S02","S03","S04","S05","S06","S07","S08","S09","S10","S11","S12","S13",
                          "C01","C02","C03","C04","C05","C06","C07","C08","C09","C10","C11","C12","C13",
                          "H01","H02","H03","H04","H05","H06","H07","H08","H09","H10","H11","H12","H13", "J00"};
                          
  //Step 1: Shuffle deck, Distribute them into player/computer's deck
  cout << "##########Welcome to Old Maid game!##########" << endl;

  bool status;
  status = ImportGame(player, computer);
  if (status==false) { //If ImportGame function returns false (which means there is no saved file), start new game
    cout << "Starting a new game. \n" << endl; 
    cout << "Card shuffling...\n" << endl;
    shuffle_deck(deck,player,computer); //Function to randomly shuffle card and distribute cards to each player's deck
  
    //For checking distributed cards
    cout << "Your deck: " << endl;
    for (int i=0; i< player.size(); i++) {
        cout << player[i] << " ";
    }
    cout << endl;
    cout << "you have " <<  player.size() << " cards in your hand." << endl;
  
    //To Show user how many cards computer have
    cout << "Computer have " << computer.size() << " cards\n" << endl;

    //Step 1-2: Discard pairs: Initialize player's deck and computer's deck
    cout << "Initially removing pairs for you..." << endl;
    InitializeDeck(player); //Remove pair
    
    cout <<"After removing your pairs - you have " << player.size()  << " cards left\n " << endl;
    cout << "Your final deck before game starts: "  << endl;
    for (int i=0; i<player.size(); ++i){
        cout<<player.at(i)<<' ';
    }
    cout << "\n\n";
    
    cout << "Computer is removing the pairs... " << endl;
    InitializeDeck(computer);
    cout <<"After removing computer's pairs - computer have " << computer.size() << " cards " <<  endl;
    cout << "\n\n";
  }
  else if (status==true) { //If ImportGame function returns true (which means there is saved file), resume the game.
    cout << "Saved file exist. Loading last game status... " << endl;

    cout << "Load complete! \nYour current deck is: " << endl;
    for (int i=0; i<player.size(); ++i) {
      cout<<player.at(i)<<' ';
    }
      cout << endl;
      cout << "you have " <<  player.size() << " cards in your hand.\n" << endl;
      cout << "Computer have " << computer.size() << " cards.\n" << endl;
      cout << "Resume game." << endl;
  }

  cout << "***********Game start! ************" << endl;
  //Step 3: Playing 
  while (true) { //repeat each player's turn until one of player's deck become empty
    cout << "Save and quit: type 'y'/\tTo continue: type 'n' (y/n): ";
    char choice;
    cin >> choice;
    while (choice != 'y' && choice != 'n') { //Prevent user inputting wrong command
        cout << "Enter a valid choice. " << endl;
        cout << "To save and quit: type 'y'/\tTo continue: type 'n' (y/n): ";
        cin >> choice;
    }
    if (choice == 'y') { //It user want to save game:
      SaveGame(player, computer);  //Function to save the current deck status  
      cout << "Save complete." << endl;
      cout << "Bye-bye!" << endl;
      exit(1);
    }
    else if (choice == 'n') { //If user don't want to save, continue game
      cout << "**********Player's turn!**********" << endl;
      pick_card_user(player, computer); //Pick card & remove pair for user
      cout << "**********End of Player's turn!**********\n" << endl;
      if (player.size() == 0)
        break;
      cout << "\n**********Computer's turn!**********" << endl;
      pick_card_computer(player, computer); //Pick card & remove pair for computer
      if(computer.size() == 0)
        break;
      cout << "**********End of computer's turn!**********\n" << endl;
    }
  }
      
  if (player.size() == 0) { //if player's deck have 0 cards
      cout << "You win!" << endl;
      cout << "Bye-bye!" << endl;
  }
  else if (computer.size() == 0) { //if computer's deck have 0 cards
      cout << "Computer win!\nYou Lost." << endl;
      cout << "Bye-bye!" << endl;
  }
  
  //To close and clear p1.txt and p2.txt file
  ofstream clf1;
  ofstream clf2;
  clf1.open("p1.txt", clf1.out | clf1.trunc);
  clf2.open("p2.txt", clf2.out | clf2.trunc);
  clf1.close();
  clf2.close();

  return 0;
}
