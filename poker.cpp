//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <time.h>
#include "cards.h"
#include "classify.h"

//Used for classify the hand
void classify_hand(classify, int [], unsigned int [], unsigned int);

int main() {
     deckOfCards deck;              //create my object deck and invoke constructor
     classify poker_hand;           //object created for class classify
     deck.shuffle();                //call member function and shuffle cards
     srand((unsigned) time(NULL));  //this will produce a different sequence of 
                                    //  of random cards everytime the program 
                                    //  is executed
     
     char enter;
     bool test_deck;                 //this will store the return value of deck.deckEmpty()
     
     std::cout << std::endl << std::endl << std::endl;
          
     std::cout << "                  " << "****************************************" << std::endl
               << "                  " << "* THE POKER GAME RANDOM GENERATOR WILL *" << std::endl
               << "                  " << "* GENERATE 50000 POKER HANDS, AND ONLY *" << std::endl
               << "                  " << "* DISPLAY THE FIRST CLASSIFICATION OF  *" << std::endl
               << "                  " << "* OF EACH HAND AT THE TIME IT OCCURS.  *" << std::endl    
               << "                  " << "* IT WILL THEN DISPLAY HOW MANY TIMES  *" << std::endl
               << "                  " << "*      EACH CLASSIFICATION OCCUR.      *" << std::endl
               << "                  " << "****************************************" << std::endl << std::endl << std::endl;

	 std::cout << "            " << "TO BEGIN THE RANDOM POKER GAME GENERATOR HIT ANY KEY " << std::endl
	           << "            " << "           AND THEN ENTER OR HIT CTRL Z: ";  
	      
   while(std::cin >> enter) { 
       std::cout << std::endl << std::endl;
       const int number=9;            //use for the number of classifications 
       unsigned int counter=0;        //use for finding out the first time a classification hand occurs
       int found[number]={0};         //use to determine first time  a classification 
                                      //  happens, and when it happens the element is set to
                                      //  1, which means it can not be printed out again. 
      unsigned int occur[number]={0}; //this will be use to keep count of all the different 
                                      //   types of classifications for each hand.
	      
      std::cout << "Hand#     Classification       Poker Hand" << std::endl;
      std::cout << "-----     --------------       -----------" << std::endl;

      //Geenerate the number of random hands
      for(unsigned int d=0; d<50000; d++){
          //Will generate one card at a time, for a total of 5 cards per hand
	      for(int i=0; i<5; i++) {
	          test_deck = deck.deckEmpty(); //testing to make sure deck not empty 
	          //if this is true then my deck is empty. so we replace all 52 cards 
	          if(test_deck) {
	          deck.shuffle();
	          }   
	          playingCard card=deck.deal(); //initialize constructor, by dealing a card 
	          //add a card to the hand as it is dealt
	          poker_hand.insert_card(card.theRank(), card.theSuit(), i);
	      } 
   	      poker_hand.sort_hand(); //sort my poker hand by calling memeber funtion
	      ++counter;              //increment my counter, to indicate first hand 
	      //Classify each hand
	      classify_hand(poker_hand, found, occur, counter); 
      } 
     
     std::cout << std::endl << std::endl;
     //Print out how many occurrance of classifications
     //  occur for each hand
     for(int k=0; k<9; k++) {
          std::cout << std::endl
               << "     ";
          std::cout << std::setw(5)
               << std::setiosflags(std::ios::right);
          switch(k) {
          case 0:
               std::cout << occur[k] << "     " << "PLAIN"; break;
          case 1:
               std::cout << occur[k] << "     " << "ONE_PAIR"; break;     
          case 2:
               std::cout << occur[k] << "     " << "TWO_PAIR"; break;
          case 3:
               std::cout << occur[k] << "     " << "THREE_OF_A_KIND"; break; 
          case 4:
               std::cout << occur[k] << "     " << "STRAIGHT"; break;
          case 5:
               std::cout << occur[k] << "     " << "FLUSH"; break;
          case 6:
               std::cout << occur[k] << "     " << "FULL_HOUSE"; break;
          case 7:
               std::cout << occur[k] << "     " << "FOUR_OF_A_KIND"; break;
          case 8:
               std::cout << occur[k] << "     " << "STRAIGHT_FLUSH"; break;                                    
    	 }
     }
     std::cout << std::endl << std::endl << std::endl; 
     std::cout << "            " << "TO PLAY THE RANDOM POKER GAME GENERATOR AGAIN HIT ANY KEY " << std::endl
	      << "            " << "           AND THEN ENTER OR HIT CTRL Z: ";
   }
   return 0;  	 
}

//Will use the inspectors in class classify and will
//  determine the classification of each hand.
void classify_hand(classify poker_hand, int found[], unsigned int occur[], unsigned int counter) {
    auto print_hand = [&](const std::string& classification) {
        std::cout << std::left << std::setw(10) << (std::to_string(counter) + ":")
                  << std::left << std::setw(21) << classification;
        poker_hand.print();
        std::cout << std::endl;
    };

    if (poker_hand.straight_flush() == 1) {
        occur[8]++;
        if (found[8] == 0) {
            print_hand("STRAIGHT_FLUSH");
            found[8] = 1;
        }
    } else if (poker_hand.four_kind() == 1) {
        occur[7]++;
        if (found[7] == 0) {
            print_hand("FOUR_OF_A_KIND");
            found[7] = 1;
        }
    } else if (poker_hand.full_house() == 1) {
        occur[6]++;
        if (found[6] == 0) {
            print_hand("FULL_HOUSE");
            found[6] = 1;
        }
    } else if (poker_hand.flush() == 1) {
        occur[5]++;
        if (found[5] == 0) {
            print_hand("FLUSH");
            found[5] = 1;
        }
    } else if (poker_hand.straight() == 1) {
        occur[4]++;
        if (found[4] == 0) {
            print_hand("STRAIGHT");
            found[4] = 1;
        }
    } else if (poker_hand.three_kind() == 1) {
        occur[3]++;
        if (found[3] == 0) {
            print_hand("THREE_OF_A_KIND");
            found[3] = 1;
        }
    } else if (poker_hand.two_pair() == 1) {
        occur[2]++;
        if (found[2] == 0) {
            print_hand("TWO_PAIR");
            found[2] = 1;
        }
    } else if (poker_hand.one_pair() == 1) {
        occur[1]++;
        if (found[1] == 0) {
            print_hand("ONE_PAIR");
            found[1] = 1;
        }
    } else {
        occur[0]++;
        if (found[0] == 0) {
            print_hand("PLAIN");
            found[0] = 1;
        }
    }
}
