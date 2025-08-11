//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

#include <cstdio> // For printf
#include <stdlib.h>
#include <time.h>
#include <string> // For std::string
#include "cards.h"
#include "classify.h"

//Used for classify the hand
void classify_hand(classify, int [], unsigned int [], unsigned int);
void playPokerClassification();
void playTexasHoldem();
void printTable();

void classify_hand(classify poker_hand, int found[], unsigned int occur[], unsigned int counter) {
    auto print_hand = [&](const char* classification) {
        printf("%-10s%-21s", (std::to_string(counter) + ":").c_str(), classification);
        poker_hand.print(); // This will need to be updated later
        printf("\n");
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

void playPokerClassification() {
    deckOfCards deck;
    classify poker_hand;
    srand((unsigned) time(NULL)); // Seed random number generator once

    char choice;
    do {
        deck.shuffle(); // Shuffle for each new hand
        printf("\n\n\n");
        printf("                  ****************************************\n");
        printf("                  * THE POKER GAME RANDOM GENERATOR WILL *\n");
        printf("                  * GENERATE 50000 POKER HANDS, AND ONLY *\n");
        printf("                  * DISPLAY THE FIRST CLASSIFICATION OF  *\n");
        printf("                  * * OF EACH HAND AT THE TIME IT OCCURS.  *\n");
        printf("                  * IT WILL THEN DISPLAY HOW MANY TIMES  *\n");
        printf("                  *      EACH CLASSIFICATION OCCUR.      *\n");
        printf("                  ****************************************\n\n\n");

        // Removed the prompt to begin the game.

        printf("\n\n");
        const int number = 9;
        unsigned int counter = 0;
        int found[number] = {0};
        unsigned int occur[number] = {0};

        printf("Hand#     Classification       Poker Hand\n");
        printf("-----     --------------       -----------\n");

        for (unsigned int d = 0; d < 50000; d++) {
            bool test_deck = deck.deckEmpty();
            if (test_deck) {
                deck.shuffle();
            }
            for (int i = 0; i < 5; i++) {
                playingCard card = deck.deal();
                poker_hand.insert_card(card.theRank(), card.theSuit(), i);
            }
            poker_hand.sort_hand();
            ++counter;
            classify_hand(poker_hand, found, occur, counter);
        }

        printf("\n\n");
        for (int k = 0; k < 9; k++) {
            printf("\n     %5d     ", occur[k]);
            switch (k) {
                case 0:
                    printf("PLAIN");
                    break;
                case 1:
                    printf("ONE_PAIR");
                    break;
                case 2:
                    printf("TWO_PAIR");
                    break;
                case 3:
                    printf("THREE_OF_A_KIND");
                    break;
                case 4:
                    printf("STRAIGHT");
                    break;
                case 5:
                    printf("FLUSH");
                    break;
                case 6:
                    printf("FULL_HOUSE");
                    break;
                case 7:
                    printf("FOUR_OF_A_KIND");
                    break;
                case 8:
                    printf("STRAIGHT_FLUSH");
                    break;
            }
        }
        printf("\n\n\n");

        printf("Generate another hand? (y/n): ");
        // Clear input buffer before getting new char
        while (getchar() != '\n');
        choice = getchar();

    } while (choice == 'y' || choice == 'Y');
}

void printTable() {
    printf("\n"); 	
    printf("                             DEALER [D]\n");
    printf("                             [??] [??]\n");
    printf("\n");
    printf("            .----------------------------------------------.\n");
    printf("          .'                                                .'\n");
    printf("         /                    TEXAS HOLD'EM                   \\\n");
    printf("        /                                                      \\\n");
    printf("       |                                                        |\n");
    printf("       |          [    ] [    ] [    ] [    ] [    ]            |\n");
    printf("       |                                                        |\n");
    printf("        \\                                                      /\n");
    printf("         \\                                                    /\n");
    printf("          '.                   POT: $______                 .'\n");
    printf("            '----------------------------------------------'\n");
    printf("\n");
    printf("                              PLAYER\n");
    printf("                             [??] [??]\n");
}


void playTexasHoldem() {
    deckOfCards deck;
    deck.shuffle();
    srand((unsigned) time(NULL));

    classify player_hand;
    classify dealer_hand;

    // Deal two cards to the player
    for (int i = 0; i < 2; ++i) {
        playingCard card = deck.deal();
        player_hand.insert_card(card.theRank(), card.theSuit(), i);
    }

    // Deal two cards to the dealer
    for (int i = 0; i < 2; ++i) {
        playingCard card = deck.deal();
        dealer_hand.insert_card(card.theRank(), card.theSuit(), i);
    }

    printf("\nPress any key to start the game...");
    getchar(); // Wait for user input

    printf("\n\n");
    printTable();

    printf("\nDealer's cards: [??] [??]");
    printf("\nYour cards: ");
    player_hand.print();
    printf("\n");
}

int main() {
    int choice;
    printf("\n");
    printf("Please select a game to play:\n");
    printf("1.) Play Poker Hand Classification\n");
    printf("2.) Play Texas Hold'em\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            playPokerClassification();
            break;
        case 2:
            playTexasHoldem();
            break;
        default:
            printf("Invalid choice. Exiting.\n");
            break;
    }

    return 0;
}
