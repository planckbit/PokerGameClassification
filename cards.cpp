//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

#include <iostream>
#include <stdlib.h> 
#include "cards.h"

using namespace std;

//Card suit and rank
playingCard::playingCard(cardSuit s, cardRank r)
{
    suit=s;
    rank=r;
}

cardRank playingCard::theRank() const
{
    return rank;
}

cardSuit playingCard::theSuit() const
{
    return suit;
}

//Will print out one card at a time
void playingCard::print() const
{
    switch(rank)
    {
        case 0:
            cout << "2"; break;
        case 1:
            cout << "3"; break;
        case 2:
            cout << "4"; break;
        case 3:
            cout << "5"; break;
        case 4:
            cout << "6"; break;
        case 5:
            cout << "7"; break;
        case 6:
            cout << "8"; break;
        case 7:
            cout << "9"; break;
        case 8:
            cout << "T"; break;
        case 9: 
            cout << "J"; break;
        case 10:
            cout << "Q"; break;
        case 11:
            cout << "K"; break;
        case 12:
            cout << "A"; break;
    }

    switch(suit)
    {
        case 0:
            cout << "C" <<"     "; break;
        case 1:
            cout << "D" <<"     "; break;
        case 2:
            cout << "H" <<"     "; break;
        case 3:
            cout << "S" <<"     "; break;
    }
}
 
deckOfCards::deckOfCards()
{
    cardsInDeck=52;
}

//This will let the user inspect whether the deck is empty or not
int deckOfCards::deckEmpty() const 
{
    if (cardsInDeck <= 2)
        //the deck is empty, this tells the user by returning true
        return 1;
    else
        //the deck is not empty, returns false
        return 0;
}

//All elements are set to 1, meaning all cards in deck are now playable
//  user will call this function when deckEmpty returns true;
void deckOfCards::shuffle()
{
    for(int i=0; i<=51; i++)
    {
        deck[i]=1;
    }
    cardsInDeck=52;
}

//The user will call this function to get a card
playingCard deckOfCards::deal()
{
    int c;  //used for switch statement
    cardSuit s; //this is used to determine suit
    cardRank r; //this is used to determine rank of that suit
    const int divisor=13;
    int card_dealt=(rand() % (52));
    if (deck[card_dealt]==1)
    {
        //card found, determine the suit and rank
        c=(card_dealt/divisor);
        r=(card_dealt%divisor);
        //remove card from deck, by setting this element to zero
        deck[card_dealt]=0;
        //decrement the number of cards in the deck
        --cardsInDeck;
        switch(c)
        {
            case 0:
                s=CLUBS;    break;
            case 1:
                s=DIAMONDS; break;
            case 2:
                s=HEARTS;   break;
            case 3:
                s=SPADES;   break;
        }
    }
    else
    {
        //The card was not in the deck so get another card recurrsively
        return deckOfCards::deal();
    }
    playingCard cards(s,r);
    return cards;   
}

