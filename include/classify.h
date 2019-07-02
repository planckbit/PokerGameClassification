// THIS CODE IS LICENSED UNDER THE MIT LICENSE. SEE THE LICENSE FILE IN IN THE PROJECT ROOT OR AT
// https://github.com/planckbit/PokerGameClassification

#ifndef CLASSIFY_H
#define CLASSIFY_H

const int hand=5;   //a five card hand is defined for a hand of poker

class classify {

     private: 
     
     int store_rank[hand];
     int store_suit[hand];
     
     public:
     //default constructor
     classify();
     
     //inspectors for classification of the arrays
     int straight_flush() const;
     int flush() const;
     int straight() const;
     int four_kind() const;
     int full_house() const;
     int three_kind() const;
     int two_pair() const;
     int one_pair() const;
     int plain() const;
     
     //print a hand
     void print() const;
     
     //modifiers
     void insert_card(cardRank, cardSuit, int);
     void sort_hand();
};

#endif     
