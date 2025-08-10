<b>MIT License</b><br>
<b><i>Copyright (c) 2019 PlanckBit</b>

# Poker Game Hand Rank Card Classification
  
  The program generates 50000 poker hands, classifies the
  hand according to rank and only displays the first occurrance of its classification. 
  It will then display how many times each hand rank classification occurs.
  
## Features
   * Generates random poker hands and classifies them by rank.
   * Displays the total occurances for each specific poker hand rank.
  
## Tested with
   * g++ (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
   * Linux Distro: 
     Ubuntu 18.04.2 LTS
     4.15.0-54-generic #58-Ubuntu SMP Mon Jun 24 10:55:24 UTC 2019
     x86_64 x86_64 x86_64 GNU/Linux
  
## Usage:
   * Compile:
     ```
     g++ -o poker.bin -I~/PokerGameClassification/include poker.cpp cards.cpp classify.cpp
     ```
   * Execute: poker.bin

## Example Output
```
                  ****************************************
                  * THE POKER GAME RANDOM GENERATOR WILL *
                  * GENERATE 50000 POKER HANDS, AND ONLY *
                  * DISPLAY THE FIRST CLASSIFICATION OF  *
                  * OF EACH HAND AT THE TIME IT OCCURS.  *
                  * IT WILL THEN DISPLAY HOW MANY TIMES  *
                  *      EACH CLASSIFICATION OCCUR.      *
                  ****************************************

            TO BEGIN THE RANDOM POKER GAME GENERATOR HIT ANY KEY 
                       AND THEN ENTER OR HIT CTRL Z: 

Hand#     Classification       Poker Hand
-----     --------------       -----------
1:        PLAIN                [4♥] [J♦] [Q♠] [K♥] [A♥] 
2:        ONE_PAIR             [7♥] [7♠] [8♥] [Q♥] [A♦] 
19:       TWO_PAIR             [2♠] [2♥] [3♥] [3♦] [9♣] 
41:       THREE_OF_A_KIND      [8♦] [8♣] [8♠] [9♣] [A♥] 
87:       FULL_HOUSE           [3♦] [3♠] [7♦] [7♥] [7♠] 
346:      STRAIGHT             [7♣] [8♠] [9♣] [10♥] [J♣] 
648:      FLUSH                [8♥] [9♥] [10♥] [J♥] [K♥] 
9975:     FOUR_OF_A_KIND       [4♣] [J♦] [J♣] [J♦] [J♠] 

     25083     PLAIN
     21887     ONE_PAIR
      1546     TWO_PAIR
      1111     THREE_OF_A_KIND
       175     STRAIGHT
        99     FLUSH
        78     FULL_HOUSE
        21     FOUR_OF_A_KIND
         0     STRAIGHT_FLUSH
```

  If this program is useful, please give it a star! Thank you!.
