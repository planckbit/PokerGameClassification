#ifndef CARDS_H
#define CARDS_H

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
};

class deckOfCards {

    private:
	int deck[52];
	int cardsInDeck;

    public:
	//default constructor
	deckOfCards();

	//inspector
	int deckEmpty() const; //answer whether the deck is empty

	//modifiers
	void shuffle();    //Replace all 52 cards into the deck
	playingCard deal();//Return 1 card at random. The card
			   //	is removed from the deck.
};

#endif
