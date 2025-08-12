//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

#ifndef CARDS_H
#define CARDS_H

#include <string>

enum cardSuit {CLUBS, DIAMONDS, HEARTS, SPADES};

typedef int cardRank; //2=deuce, 3=trey, 4=four,... 10=ten,
		      //11=Jack, 12=Queen, 13=King, 14=Ace

class playingCard {
    private:
	cardSuit suit;
	cardRank rank;

    public:
	//default constructor
	playingCard(cardSuit = CLUBS, cardRank = 2);

	//inspectors
	cardRank theRank() const;
	cardSuit theSuit() const;

	//display
	void print() const; //for example: 2S, 9D, TH, QC, AD
	std::string toString() const {
            std::string rankStr;
            if (rank >= 2 && rank <= 10) {
                rankStr = std::to_string(rank);
            } else {
                switch (rank) {
                    case 11: rankStr = "J"; break;
                    case 12: rankStr = "Q"; break;
                    case 13: rankStr = "K"; break;
                    case 14: rankStr = "A"; break;
                }
            }

            std::string suitStr;
            switch (suit) {
                case CLUBS: suitStr = "\u2663"; break; // ♣
                case DIAMONDS: suitStr = "\u2666"; break; // ♦
                case HEARTS: suitStr = "\u2665"; break; // ♥
                case SPADES: suitStr = "\u2660"; break; // ♠
            }

            return rankStr + suitStr;
        }
};

class deckOfCards {
    private:
	int deck[52];
	int cardsInDeck;

    public:
	//default constructor
	deckOfCards();

	//inspector
	bool deckEmpty() const; //answer whether the deck is empty

	//modifiers
	void shuffle();    //Replace all 52 cards into the deck
	playingCard deal();//Return 1 card at random. The card
			   //	is removed from the deck.
};
#endif
