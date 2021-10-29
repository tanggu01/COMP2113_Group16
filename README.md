**C++ Project - Old Maid card game**

Kim Taehyun 3035751330
Jung Hyeonwoo 3035829948

**Identify a game: Old maid card game**

**Description of the Game**

In this game, one player will match with one computer player. To win this game, the player should discard cards from their deck more quickly than the computer by pairing the cards. The player will receive one more additional card than the computer since the total number of cards are odd. As there is only one Joker card, it cannot be discarded. A player should wait for the computer to take a Joker card or be careful not to take a Joker card from the computer's deck. 

**Game Rules**
1. Use 52 normal cards and one Joker card for the game. Total 53 cards 
2. Player will receive 27 cards and the Computer player will receive 26 cards.  
3. After receiving cards, each player should discard a pair of cards with the same number and color until there are more cards left to discard in each player’s deck. 
4. At each turn, the player should take one card from another player.  
5. If the player has a pair of cards with the same number and colour, they will be discarded from the player’s deck. If not, the turn will be passed. 
6. Repeat the turn until all pair of cards are discarded and only Joker left 
7. The player who doesn’t have Joker on hand wins the game.  


**Features:**
A list of features that you plan to implement, and explain how each coding element 1 to 5 listed under the coding requirements aforementioned supports your features.

* Have an array that stores 53 cards. 
* Randomly distribute 53 cards to the player and the computer(player 2) including 1 joker card from the array. (Requirement 1). 
* Use arraylist to store each player’s cards. (requirement 2). 
* Function that resizes arraylist (requirement 3). 
* Function that makes each turn a player takes one card from another player. It removes the card from the player’s arraylist and adds it to another player’s arraylist. This includes the resizing function too. (requirement 2,3).  
* Function that if any player has a pair of cards with the same card number and same color, it will automatically discard those two cards from each player’s deck, and then resize arraylist accordingly using the function (requirement 2).  
* File input and outputs for loading and saving game status (requirement 4). 
* Store functions in different files (requirement 5).  


