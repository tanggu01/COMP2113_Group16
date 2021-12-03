**C++ Project - Old Maid card game**

Kim Taehyun 3035751330
Jung Hyeonwoo 3035829948

**Identify a game: Old maid card game**a

**Description of the Game**

In this game, one player will match with one computer player. To win this game, the player should discard cards from their deck more quickly than the computer by pairing the cards. The player will receive one more additional card than the computer since the total number of cards are odd. As there is only one Joker card, it cannot be discarded. A player should wait for the computer to take a Joker card or be careful not to take a Joker card from the computer's deck. The player wins when the player's deck becomes 0. Otherwise, when computer's deck becomes 0, the computer wins and player will lose the game. 

**Game Rules**
1. Use 52 normal cards and one Joker card for the game. Total 53 cards 
2. Player will receive 27 cards and the Computer player will receive 26 cards.   
3. After receiving cards, each player should discard a pair of cards with the same number and color until there are more cards left to discard in each player’s deck.  
4. At each turn, the player should take one card from another player.  
5. If the player has a pair of cards with the same number and colour, they will be discarded from the player’s deck. If not, the turn will be passed. 
6. Repeat the turn until all pair of cards are discarded and only Joker left (one of the players' deck have 0 cards).  
7. The player who doesn’t have Joker on hand (which means have 0 cards left) wins the game.  


**Features:**
A list of features that you plan to implement, and explain how each coding element 1 to 5 listed under the coding requirements aforementioned supports your features.

* Have an vector that stores 53 cards.(vector<string> deck) 
* Function (in shuffledeck.cpp) that randomly distribute 53 cards to the player (vector<string> player) and the computer(vector<string> computer) including 1 joker card from the vector by using shuffle_deck function (Requirement 1).  
* Use vector to store each player’s cards. (requirement 2 & 3). 
* Function (in initializedeck.cpp) automatilcally discards all the cards which can be paired inside computer's and player's deck respectively. 
* Function (pick_card_user) that makes each turn a player takes one card from computer. Player can select which position he want to takes card from computer's deck. It removes the card from the computer’s vector and adds it to the player’s vector. If any player has a pair of cards with the same card number and same color, the function(step 4) will automatically discard those two cards from each player’s deck (requirement 2,3). 
* Function (pick_card_computer) that the computer randomly pick a card from the player and append the card to computer's deck. The function will automatically check for pairs and discard pairs from computer's deck. 
* Function (in savegame.cpp) saves current player's and computer's deck status to each .txt file when player want to save the game. (player's deck to p1.txt, computer's deck to p2.txt). Each turn the player will be asked to save or not (requirement 4).   
* Function (in importgame.cpp) loads the player's and computer's deck status to current game. load p1.txt file to player's vector and p2.txt file to computer's vector. The game will be automatically resumed when there are any saved file. (requirement 4)   
*After the winner has been declared, when the player want to play the game again, the last game status stored p1.txt and p2.txt will be cleared (in main.cpp) .  
* Store functions in different files (requirement 5).    


**To run the Game**
type: 
  make main  
  ./main
