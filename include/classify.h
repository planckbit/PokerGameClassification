//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

#ifndef CLASSIFY_H
#define CLASSIFY_H

#include "cards.h" // Add this line

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
     void print_hidden() const;
     void debug_print_hand() const; // Debug print function
     
     //modifiers
     void insert_card(cardRank, cardSuit, int);
     void sort_hand();
     std::string determine_hand() const;
};
#endif
