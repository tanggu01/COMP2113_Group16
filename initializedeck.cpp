#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

#include "initializedeck.h"

//Function that checks whether a is bigger than b or not.
bool desc(int a, int b){ 
    return a > b; 
} 

//Function to initialize player's deck and computer's deck
//Find all pair of the cards and delete from deck
void InitializeDeck(vector <string> &plr){
    
    //Declear arrays for each shape of cards
    int D_arr[13]={}; //D stands for Diamond
    int H_arr[13]={}; //H stands for Heart
    int C_arr[13]={}; //C stands for Clover
    int S_arr[13]={}; //S stands for Spade
    int final_arr[26]={}; //store the paired card to this array
    //append player's or computer's cards to each appropriate array
    //e.g.) append D4 card to D_arr[3]
    for (int i=0; i<plr.size(); ++i){
        string card_info=plr.at(i);
        
        if (card_info[0]=='D'){
            D_arr[(card_info[1]-48)*10+(card_info[2]-48)-1]=i+1;
        }
        
        else if (card_info[0]=='H'){
            H_arr[(card_info[1]-48)*10+(card_info[2]-48)-1]=i+1;
        }
        
        else if (card_info[0]=='C'){
            C_arr[(card_info[1]-48)*10+(card_info[2]-48)-1]=i+1;
        }
        
        else if (card_info[0]=='S'){
            S_arr[(card_info[1]-48)*10+(card_info[2]-48)-1]=i+1;
        }
    }

    //search whether there are any cards to be paired and append them to final_arr
    int location=0;
    for (int j=0; j<13; ++j){
        //if there are any diamond and heart shape cards with same number, append to final_arr. 
        if (D_arr[j]!=0 && H_arr[j]!=0){
            final_arr[location]=D_arr[j];
            location+=1;
            final_arr[location]=H_arr[j];
            location+=1;
        }
        //if there are any clover and spade cards with same number, append to final_arr. 
        if (C_arr[j]!=0 && S_arr[j]!=0){
            final_arr[location]=C_arr[j];
            location+=1;
            final_arr[location]=S_arr[j];
            location+=1;
        }
    }
    
    //sort the final_arr as descending order
    sort(final_arr, final_arr+26, desc); 
    
    //delete the cards in the final_arr from the player's or computer's deck
    for(int t=0; t<26; t++){
        if (final_arr[t]!=0){
            plr.erase(plr.begin()+final_arr[t]-1);
        }
    } 
}