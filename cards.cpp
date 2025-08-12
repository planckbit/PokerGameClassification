//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

#include <iostream>
#include <stdlib.h> 
#include "cards.h"

//Card suit and rank
playingCard::playingCard(cardSuit s, cardRank r) {
     suit=s;
     rank=r;
}     

cardRank playingCard::theRank() const {
     return rank;
}
    
cardSuit playingCard::theSuit() const {
     return suit;
} 

//Will print out one card at a time    
void playingCard::print() const {
    std::cout << "[";
    switch(rank) {
        case 0:  std::cout << "2"; break;
        case 1:  std::cout << "3"; break;
        case 2:  std::cout << "4"; break;
        case 3:  std::cout << "5"; break;
        case 4:  std::cout << "6"; break;
        case 5:  std::cout << "7"; break;
        case 6:  std::cout << "8"; break;
        case 7:  std::cout << "9"; break;
        case 8:  std::cout << "10"; break;
        case 9:  std::cout << "J"; break;
        case 10: std::cout << "Q"; break;
        case 11: std::cout << "K"; break;
        case 12: std::cout << "A"; break;
    }

    switch(suit) {
        case 0: std::cout << "♣"; break;
        case 1: std::cout << "\033[31m♦\033[0m"; break;
        case 2: std::cout << "\033[31m♥\033[0m"; break;
        case 3: std::cout << "♠"; break;
    }
    std::cout << "] ";
}        
 
deckOfCards::deckOfCards() {
     cardsInDeck=52;
}      
             
//This will let the user inspect whether the deck is empty or not                     
bool deckOfCards::deckEmpty() const {
     return cardsInDeck < 5;
}

//The user will call this function to get a card 
playingCard deckOfCards::deal() { 
    int c;   //used for switch statement
    cardSuit s; //this is used to determine suit
    cardRank r; //this is used to determine rank of that suit
    const int divisor=13;
    int card_dealt;

    while (true) {
        card_dealt = (rand() % (52));
        if (deck[card_dealt] == 1) {
            //card found, determine the suit and rank
            c = (card_dealt / divisor);
            r = (card_dealt % divisor) + 2; // Adjust rank to start from 2
            //remove card from deck, by setting this element to zero
            deck[card_dealt] = 0;
            //decrement the number of cards in the deck
            --cardsInDeck;
            switch (c) {
                case 0: s = CLUBS;    break;
                case 1: s = DIAMONDS; break;
                case 2: s = HEARTS;   break;
                case 3: s = SPADES;   break;
            }
            playingCard cards(s, r);
            return cards;
        }
    }
}        


//All elements are set to 1, meaning all cards in deck are now playable
//  user will call this function when deckEmpty returns true;
void deckOfCards::shuffle() {
     for(int i=0; i<=51; i++) {
        deck[i]=1;
     }   
     cardsInDeck=52;
}

