// THIS CODE IS LICENSED UNDER THE MIT LICENSE. SEE THE LICENSE FILE IN IN THE PROJECT ROOT OR AT
// https://github.com/planckbit/PokerGameClassification

#include <iostream>
#include "cards.h"
#include "classify.h"

//constructor
classify::classify(){
     for(int i=hand; i<hand; i++) {
       store_suit[i]=0;
       store_rank[i]=0;
     }
}
int classify::straight_flush() const {

     int test=1; //test while loop condition
     int k=0;    //variable use for scanning elements of arrays
     
     while(test!=0) {
     
	  if(store_rank[k]==((store_rank[k+1])-1) && k<hand-1) {
          
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
     
	      if(store_rank[k]==((store_rank[k+1])-1) && k < hand-1) {
          
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

     for(int k=0; k<hand; k++) {
	     if(store_rank[k]==store_rank[k+1] || flush()==1) {
	          return 0;  //no plain found
	     }
     }
     return 1; //a plain hand was found
}

//member print function will print a hand in sorted order by rank
// the hand will never exceed 5 cards
void classify::print() const {

     for(int j=0; j<hand; j++) {

	  int rank_card=store_rank[j];
	  int suit_card=store_suit[j];

	  switch(rank_card) {


	   case 0:
	      std::cout << "2"; break;
	   case 1:
	      std::cout << "3"; break;
	   case 2:
	      std::cout << "4"; break;
	   case 3:
	      std::cout << "5"; break;
	   case 4:
	      std::cout << "6"; break;
	   case 5:
	      std::cout << "7"; break;
	   case 6:
	      std::cout << "8"; break;
	   case 7:
	      std::cout << "9"; break;
	   case 8:
	      std::cout << "T"; break;
	   case 9:
	      std::cout << "J"; break;
	   case 10:
	      std::cout << "Q"; break;
	   case 11:
	      std::cout << "K"; break;
	   case 12:
	      std::cout << "A"; break;
	   }
             
           
           switch(suit_card) {
           
            case 0:
               std::cout << "C" <<"     "; break;
            case 1:
               std::cout << "D" <<"     "; break;
            case 2:
               std::cout << "H" <<"     "; break;
            case 3:
               std::cout << "S" <<"     "; break;   
            }
          
       }   
          
 }         
          
  
//member function will insert one card at a time, one for rank, one for suit
void classify::insert_card(cardRank r, cardSuit s, int i) {
     
     //the card being stored must not exceed the hand which is 5 cards per hand
     if (i<hand) {
     
        store_rank[i]=r;
        store_suit[i]=s;
     }
}     
      
//member function will sort out the hand, by rank, the suit will also be sorted
//  so that the elements correspond to each other.    
void classify::sort_hand() {

     //this will only sort a five card hand
     
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
