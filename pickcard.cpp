#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
using namespace std;

#include "pickcard.h"

//Function to pick card & remove pairs for player
//p1: player's deck p2: computer's deck
void pick_card_user(vector<string> &p1, vector <string> &p2) { //For player
    //Step 1: Ask user which position he want to take card
    cout << "Select nth card position you want to pick from: 1 ~ " << p2.size() << " "; 
    int n; 
    cin >> n;
    while (n > (p2.size()) || (n <= 0)) { //while the user input is not valid
        cout << "Enter a valid position " << endl;
        cout << "Select nth card position you want to pick from: 1 ~ " << p2.size() << " ";
        cin >> n;
    }
    cout << "You have chosen " << p2[n-1] << endl;
    
    //Step 2: Ask user which position he want to place the selected card into the player's deck 
    cout << "Enter nth position you want to put the card from 1 ~ " << p1.size()+1 << " ";
    int n_dest;
    cin >> n_dest;
    while (n_dest > (p1.size()+1) || (n <= 0)) { //while the user input is not valid
        cout << "Enter a valid position" << endl;
        cout << "Select nth card position you want to pick from: 1 ~ " << p2.size()+1 << " ";
        cin >> n_dest;
    }
    //Step 3 : Append the selected card into player's deck
    p1.insert(p1.begin() + (n_dest-1), p2[n-1]);
    //Remove the selected card from computer's deck
    p2.erase(p2.begin() + (n-1));
 
    //Let the user know cards he have
    cout << "You have " << p1.size() << " cards in your hand " << endl;
    cout << "Your current deck after taking a card is: " << endl;
    for (int i=0; i< p1.size(); i++) {
        cout << p1[i] << " ";
    }
    cout << endl;

    //Step 4: Remove pairs
    cout << "Finding pairs..." << endl;
    int pair_num; //the selected card number
    char pair_shape; //the selected card shape
    string new_card, current_card;
    
    new_card=p1.at(n_dest-1); //get the shape and number of the new card
    
    //if the shape of the new card is 'C' the shape of pair should be 'S'
    if (new_card[0]=='C'){
        pair_shape='S';
        pair_num=p1[n_dest-1][1]*10+p1[n_dest-1][2]; 
    }
    
    //if the shape of the new card is 'S' the shape of pair should be 'C'
    else if (new_card[0]=='S'){
        pair_shape='C';
        pair_num=p1[n_dest-1][1]*10+p1[n_dest-1][2]; 
    }
    
    //if the shape of the new card is 'H' the shape of pair should be 'D'
    else if (new_card[0]=='H'){
        pair_shape='D';
        pair_num=p1[n_dest-1][1]*10+p1[n_dest-1][2]; 
    }
    
    //if the shape of the new card is 'D' the shape of pair should be 'H'
    else if (new_card[0]=='D'){
        pair_shape='H';
        pair_num=p1[n_dest-1][1]*10+p1[n_dest-1][2]; 
    }
    //if the card is 'J' no pair can be made
    else {
      pair_shape = 'J';
      pair_num = 0;
    }

    //scan the current deck whether there is corresponding card which is paired with new card
    for (int i=0; i<p1.size(); ++i){
        current_card=p1.at(i);
        //if there is corresponding card, discard from the current deck
        if (current_card[0]==pair_shape && current_card[1]*10+current_card[2]==pair_num){
            if (i>(n_dest-1)){
                p1.erase(p1.begin()+(i));
                p1.erase(p1.begin()+(n_dest-1));
            }
            else if (i<(n_dest-1)){
                p1.erase(p1.begin()+(n_dest-1));
                p1.erase(p1.begin()+(i));
            }
        }
    }

    cout << "After finding pairs : you have " << p1.size() << " cards in your hand " << endl;
    cout << "Your current deck after removing pairs is: " << endl;
    for (int i=0; i< p1.size(); i++) {
        cout << p1[i] << " ";
    }
    cout << endl;
}

//Function to pick card & remove pairs for player
void pick_card_computer(vector<string> &p1, vector <string> &p2) { //For computer
    //Step 1: Randomly choose which position computer want to select card from user's deck 
    int n = rand() % p1.size() + 1; //range: 1 ~ p1.size(); (Size of player's deck)

    //To let user which card the computer choose from the player's deck
    cout << "Computer have chosen " << p1[n-1] << " card from your deck "<< endl;
    
    //Step 2: Randomly choose the position to place selected card into the computer's deck 
    int n_dest = rand() % (p2.size()+1) + 1; //position(index)
    
    //Step 3 : Append the selected card into computer's deck
    p2.insert(p2.begin() + (n_dest-1), p1[n-1]);
    //Remove the selected card from player's deck
    p1.erase(p1.begin() + (n-1));
 
    //Step 4: Remove pairs
    cout << "Computer is removing pairs..." << endl;

    int pair_num; //the selected card number
    char pair_shape; //the selected card shape
    string new_card, current_card;
    
    new_card=p2.at(n_dest-1); //get the shape and number of the new card
    
    //if the shape of the new card is 'C' the shape of pair should be 'S'
    if (new_card[0]=='C'){
        pair_shape='S';
        pair_num=p2[n_dest-1][1]*10+p2[n_dest-1][2]; 
    }
    
    //if the shape of the new card is 'S' the shape of pair should be 'C'
    else if (new_card[0]=='S'){
        pair_shape='C';
        pair_num=p2[n_dest-1][1]*10+p2[n_dest-1][2]; 
    }
    
    //if the shape of the new card is 'H' the shape of pair should be 'D'
    else if (new_card[0]=='H'){
        pair_shape='D';
        pair_num=p2[n_dest-1][1]*10+p2[n_dest-1][2]; 
    }
    
    //if the shape of the new card is 'D' the shape of pair should be 'H'
    else if (new_card[0]=='D'){
        pair_shape='H';
        pair_num=p2[n_dest-1][1]*10+p2[n_dest-1][2]; 
    }
    //if the card is 'J' no pair can be made
    else {
      pair_shape = 'J';
      pair_num = 0;
    }

    //scan the current deck whether there is corresponding card which is paired with new card
    for (int i=0; i<p2.size(); ++i){
        current_card=p2.at(i);
        //if there is corresponding card, discard from the current deck
        if (current_card[0]==pair_shape && current_card[1]*10+current_card[2]==pair_num){
            if (i>(n_dest-1)){
                p2.erase(p2.begin()+(i));
                p2.erase(p2.begin()+(n_dest-1));
            }
            else if (i<(n_dest-1)){
                p2.erase(p2.begin()+(n_dest-1));
                p2.erase(p2.begin()+(i));
            }
        }
    }

    cout << "Now computer has " << p2.size() << " cards in hand " << endl;
    cout << "Your deck after computer taking " << new_card << " card out: " << endl;
    for (int i=0; i< p1.size(); i++) {
        cout << p1[i] << " ";
    }
    cout << endl;
}
