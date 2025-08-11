//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

#include <cstdio> // For printf
#include "cards.h"
#include "classify.h"

classify::classify(){
     for(int i=0; i<hand; i++) {
       store_suit[i]=0;
       store_rank[i]=0;
     }
}

//Will insert one card at a time, one for rank, one for suit
void classify::insert_card(cardRank r, cardSuit s, int i) {
     //The card being stored must not exceed the hand which is 5 cards per hand
     if (i<hand) {
        store_rank[i]=r;
        store_suit[i]=s;
     }
}

//Will sort out the hand, by rank, the suit will also be sorted
//  so that the elements correspond to each other.    
void classify::sort_hand() {

     //This will only sort a five card hand
     for(int scan=1; scan<hand; scan++) {
         for(int i=0; i< hand-scan; i++) {
            if(store_rank[i] > store_rank[i+1]) {
                 //sorting the rank
                 int hold_rank=store_rank[i];
                 store_rank[i]=store_rank[i+1];
                 store_rank[i+1]=hold_rank;
     
                 //sorting the suit
                 int hold_suit=store_suit[i];
                 store_suit[i]=store_suit[i+1];
                 store_suit[i+1]=hold_suit;
             }   
          }      
     }
}

//Will print a hand in sorted order by rank
// the hand will never exceed 5 cards
void classify::print() const {
     for(int j=0; j<hand; j++) {
	  int rank_card=store_rank[j];
	  int suit_card=store_suit[j];

      printf("[");
	  switch(rank_card) {
	   case 0:
	      printf("2"); break;
	   case 1:
	      printf("3"); break;
	   case 2:
	      printf("4"); break;
	   case 3:
	      printf("5"); break;
	   case 4:
	      printf("6"); break;
	   case 5:
	      printf("7"); break;
	   case 6:
	      printf("8"); break;
	   case 7:
	      printf("9"); break;
	   case 8:
	      printf("10"); break;
	   case 9:
	      printf("J"); break;
	   case 10:
	      printf("Q"); break;
	   case 11:
	      printf("K"); break;
	   case 12:
	      printf("A"); break;
	   }

           switch(suit_card) {
            case 0:
               printf("♣"); break;
            case 1:
               printf("\033[31m♦\033[0m"); break;
            case 2:
               printf("\033[31m♥\033[0m"); break;
            case 3:
               printf("♠"); break;
            }
        printf("] ");
       }
 }

void classify::print_hidden() const {
    // Print the first card
    int rank_card = store_rank[0];
    int suit_card = store_suit[0];

    printf("[");
    switch(rank_card) {
        case 0: printf("2"); break;
        case 1: printf("3"); break;
        case 2: printf("4"); break;
        case 3: printf("5"); break;
        case 4: printf("6"); break;
        case 5: printf("7"); break;
        case 6: printf("8"); break;
        case 7: printf("9"); break;
        case 8: printf("10"); break;
        case 9: printf("J"); break;
        case 10: printf("Q"); break;
        case 11: printf("K"); break;
        case 12: printf("A"); break;
    }

    switch(suit_card) {
        case 0: printf("♣"); break;
        case 1: printf("\033[31m♦\033[0m"); break;
        case 2: printf("\033[31m♥\033[0m"); break;
        case 3: printf("♠"); break;
    }
    printf("] ");

    // Print the second card as hidden
    printf("[??]");
}

int classify::straight_flush() const {
     int test=1; //test while loop condition
     int k=0;    //variable use for scanning elements of arrays
     while(test!=0) {
	  if(k<hand-1 && store_rank[k]==((store_rank[k+1])-1)) {
               if(store_suit[k]==store_suit[k+1]) {
                    ++k;
               }
               else {
		    return 0; //no straight flush
               }  
          }     
	  else if(k==hand-1) {
               return 1;     //straight flush found
          }
          else {
	       test=0;       //terminate the loop, no straight flush found
          }
     }     
     return 0;               //no straight flush found by termination of loop
}

int classify::flush() const {
     int test=1;
     int k=0;
     while(test!=0) {
	  if(store_suit[k]==store_suit[k+1] && k<hand-1) {
	      ++k;      //condition is true so continue loop
	  }
	  else if(k==hand-1) {
               return 1;  //flush found in hand
          }
          else {
	       test=0;    //terminate the loop
          }  
      }
      return 0;      //loop terminated on no flush found, so return 0
}

int classify::straight() const {
     int test=1;
     int k=0;
     while(test!=0) {
         if(k < hand-1 && store_rank[k]==((store_rank[k+1])-1)) {
             ++k;       //continue loop
         }
	 else if(k==hand-1) {
               return 1;  //a straight hand was found, return true
         }
         else {
	       test=0;   //end loop, no straight hand found
         }
     }
     return 0;           //no straight hand found on termination of loop                            
}

int classify::four_kind() const {
     int k=0;
     if(store_rank[k]==store_rank[k+3] || store_rank[k+1]==store_rank[k+4]) {
          return 1;   //four of a kind was found in the hand
     }
     else {
          return 0;   //four of a kind was not found
     }     
}

int classify::full_house() const {
     int k=0;
     if((store_rank[k]==store_rank[k+1] && store_rank[k+2]==store_rank[k+4]) || 
        (store_rank[k]==store_rank[k+2] && store_rank[k+3]==store_rank[k+4])) {
          return 1;  //full house found in hand
     }     
     else { 
          return 0;  //full house was not found
     }
}

int classify::three_kind() const {
     int k=0;
     if(store_rank[k]==store_rank[k+2] || store_rank[k+1]==store_rank[k+3]) {
	  return 1; //three of a kind was found
     }
     else if(store_rank[k+2]==store_rank[k+4]) {
	  return 1; //three of a kind was found
     }
     else {
	  return 0; //three of a kind was not found
     }
}

int classify::two_pair() const {
     int k=0;
     if(store_rank[k]==store_rank[k+1] && store_rank[k+2]==store_rank[k+3]) {
	  return 1;  //two pair found
     }
     else if(store_rank[k]==store_rank[k+1] && store_rank[k+3]==store_rank[k+4]) {
	  return 1;  //two pair found
     }
     else {
	  return 0;
     }
}

int classify::one_pair() const {
     int k=0;
     if(store_rank[k]==store_rank[k+1] || store_rank[k+1]==store_rank[k+2]) {
	  return 1; //one pair found
     }
     else if(store_rank[k+2]==store_rank[k+3] || store_rank[k+3]==store_rank[k+4]) {
	  return 1; //one pair found
     }
     else {
	 return 0;
     }
}

int classify::plain() const {
     // Check for pairs, three of a kind, four of a kind, full house
     for(int k=0; k<hand-1; k++) {
	     if(store_rank[k]==store_rank[k+1]) {
	          return 0;  // A pair was found, so it's not a plain hand
	     }
     }
     // Check for flush and straight
     if (flush() || straight()) {
          return 0;
     }
     return 1; //a plain hand was found
}