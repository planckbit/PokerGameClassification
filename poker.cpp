//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

//THE POKER GAME PROBLEM:
//  THIS PROGRAM WILL CREATE A CLASS FOR CARDS AND A CLASS FOR CLASSIFICATION
//  OF A POKER GAME.  THE PROGRAM WILL GENERATE 50000 POKER HANDS AND WILL
//  CLASSIFY EACH HAND AND ONLY DISPLAY THE FIRST OCCURRANCE OF IT CLASSIFICATION
//  IT WILL THEN DISPLAY HOW MANY TIMES EACH HAND CLASSIFICATION OCCURS.

#include <iostream>
#include <stdlib.h> 
#include <iomanip>
#include <time.h>
#include "cards.h"
#include "classify.h"

//function will be use to classify my hand
void classify_hand(classify, int [], unsigned int [], int, unsigned int);

//will display the classification of a hand when it first occurs
void display(classify poker_hand, unsigned int);

int main() {
     deckOfCards deck;              //create my object deck and invoke constructor
     classify poker_hand;          //object created for class classify
     deck.shuffle();               //call member function and shuffle cards
     srand((unsigned) time(NULL)); //this will produce a different sequence of 
                                   //  of random cards everytime the program 
                                   //  is executed
     
     char enter;
     int test_deck;                //this will store the return value of deck.deckEmpty()
     
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
      unsigned int occur[number]={0};  //this will be use to keep count of all the different 
                                       //   types of classifications for each hand.
	      
      //Geenerate the number of random hands
      for(unsigned int d=0; d<50000; d++){
          //Will generate one card at a time, for a total of 5 cards per hand
	      for(int i=0; i<5; i++) {
	          test_deck = deck.deckEmpty(); //testing to make sure deck not empty 
	          //if this is true then my deck is empty. so we replace all 52 cards 
	          if(test_deck==1) {
	          deck.shuffle();
	          }   
	          playingCard card=deck.deal(); //initialize constructor, by dealing a card 
	          //add a card to the hand as it is dealt
	          poker_hand.insert_card(card.theRank(), card.theSuit(), i);
	      } 
   	      poker_hand.sort_hand(); //sort my poker hand by calling memeber funtion
	      ++counter;              //increment my counter, to indicate first hand 
	      //Classify each hand
	      classify_hand(poker_hand, found, occur, number, counter); 
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
void classify_hand(classify poker_hand, int found[], unsigned int occur[], int call, unsigned int counter) {
     int i=0;
     i=call-1;
     switch(call) {
     	case 9:
	      if(poker_hand.straight_flush()==1) {
		       occur[i]++;
		       if(found[i]==0) {
		            display(poker_hand, counter);
		            std::cout << "     " << "STRAIGHT_FLUSH" << std::endl;
		            found[i]=1;
	           }
	      }
	      else {
		       classify_hand(poker_hand, found, occur, --call, counter);
	      }
              break;
	case 8:
	      if(poker_hand.four_kind()==1) {
		       occur[i]++;
		       if(found[i]==0) {
		            display(poker_hand, counter);
		            std::cout << "     " << "FOUR_OF_A_KIND" << std::endl;
		            found[i]=1;
		       }
	      }
	      else {
		       classify_hand(poker_hand, found, occur, --call, counter);
	      }
	      break;
	case 7:
	      if(poker_hand.full_house()==1) {
	           occur[i]++;
		       if(found[i]==0) {
	                display(poker_hand, counter);
		            std::cout << "     " << "FULL_HOUSE" << std::endl;
	             	found[i]=1;
	          }
	      }
	      else {
	           classify_hand(poker_hand, found, occur, --call, counter);
	      }
	      break;	  
        case 6:
	      if(poker_hand.flush()==1) {
		       occur[i]++;
		       if(found[i]==0) {
		            display(poker_hand, counter);
	             	std::cout << "     " << "FLUSH" << std::endl;
	             	found[i]=1;
		       }
	      }
	      else {
		       classify_hand(poker_hand, found, occur, --call, counter);
	      }
	      break;
        case 5:
	      if(poker_hand.straight()==1) {
	           occur[i]++;
	           if(found[i]==0) {
	                display(poker_hand, counter);
	            	std::cout << "     " << "STRAIGHT" << std::endl;
		            found[i]=1;
	           }
	      }
	      else {
		       classify_hand(poker_hand, found, occur, --call, counter);
	      }
	      break;
        case 4:
	      if(poker_hand.three_kind()==1) {
		       occur[i]++;
	           if(found[i]==0) {
		            display(poker_hand, counter);
		            std::cout << "     " << "THREE_OF_A_KIND" << std::endl;
		            found[i]=1;
		       }
	      }
	      else {
		       classify_hand(poker_hand, found, occur, --call, counter);
	      }
              break;    
         case 3:
	      if(poker_hand.two_pair()==1) {
		       occur[i]++;
		       if(found[i]==0) {
		            display(poker_hand, counter);
		            std::cout << "     " << "TWO_PAIR"  << std::endl;
		            found[i]=1;
	               }
	      }
	      else {
		       classify_hand(poker_hand, found, occur, --call, counter);
	      }
	      break;
         case 2:
	      if(poker_hand.one_pair()==1) {
		       occur[i]++;
		       if(found[i]==0) {
		            display(poker_hand, counter );
		            std::cout << "     " << "ONE_PAIR" << std::endl;
		            found[i]=1;
		       }
	      }
	      else {
		       classify_hand(poker_hand, found, occur, --call, counter);
              }
	      break;   
         case 1:
	      if(poker_hand.plain()==1) {
		       occur[i]++;
		       if(found[i]==0) {
		            display(poker_hand, counter);
		            std::cout << "     " << "PLAIN" << std::endl;
		            found[i]=1;
		       }
	      }
	      else {
	          break;
	      } 
    } //End switch 
 } 
 
//this is my display function which will display my hand the first time
//  it occurs
void display(classify poker_hand, unsigned int counter) {
     std::cout << "     ";
     std::cout << std::setw(5)  
          << std::setiosflags(std::ios::right)
          << counter <<":     ";
     poker_hand.print(); //calls member function of class classify and prints the hand
}
