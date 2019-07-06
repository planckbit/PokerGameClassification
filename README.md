<b>MIT License</b><br>
<b><i>Copyright (c) 2019 PlanckBit</b>

# Poker Game Hand Rank Card Classification
  
  The program generates 50000 poker hands, classifies the
  hand and only displays the first occurrance of its classification. It will then
  display how many times each hand rank classification occurs.
  
## Features
   * Generates random poker hands and classifies them.
   * Displays the total occurances for each specific poker hand.
  
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

                  ****************************************
                  * THE POKER GAME RANDOM GENERATOR WILL *
                  * GENERATE 50000 POKER HANDS, AND ONLY *
                  * DISPLAY THE FIRST CLASSIFICATION OF  *
                  * OF EACH HAND AT THE TIME IT OCCURS.  *
                  * IT WILL THEN DISPLAY HOW MANY TIMES  *
                  *      EACH CLASSIFICATION OCCUR.      *
                  ****************************************

            TO BEGIN THE RANDOM POKER GAME GENERATOR HIT ANY KEY 
                       AND THEN ENTER OR HIT CTRL Z: a

         1:     4C     6S     7H     TH     JS          PLAIN
         2:     2H     3D     7S     JC     JD          ONE_PAIR
         3:     4H     5H     5D     5C     QC          THREE_OF_A_KIND
        25:     5C     5H     7C     9S     9C          TWO_PAIR
       138:     7S     7H     7D     QD     QH          FULL_HOUSE
       519:     2H     3H     4H     8H     JH          FLUSH
       560:     4D     5D     6D     7C     8S          STRAIGHT
      1953:     2C     4H     4D     4S     4C          FOUR_OF_A_KIND
     24714:     5C     6C     7C     8C     9C          STRAIGHT_FLUSH

     24921     PLAIN
     22079     ONE_PAIR
      1548     TWO_PAIR
      1070     THREE_OF_A_KIND
       184     STRAIGHT
        99     FLUSH
        86     FULL_HOUSE
        12     FOUR_OF_A_KIND
         1     STRAIGHT_FLUSH
