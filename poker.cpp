//Author: PlanckBit
//MIT License
//Copyright (c) 2019 PlanckBit

#include <cstdio> // For printf
#include <stdlib.h>
#include <time.h>
#include <string> // For std::string
#include <vector> // For std::vector
#include "cards.h"
#include "classify.h"

// Function to classify the best possible hand
std::string classifyBestHand(const classify& handClassifier);
std::string classifyBestHand(const std::vector<playingCard>& cards);

//Used for classify the hand
void classify_hand(classify, int [], unsigned int [], unsigned int);
void playPokerClassification();
void playTexasHoldem();
void printTable();
void clearScreen();

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

void printTable(const std::string& dealerCards, const std::string& playerCards, const std::string& flopCards = "") {
    // Calculate padding to center the flop cards
    int totalWidth = 41; // Width of the table between the vertical bars
    int flopWidth = flopCards.length();
    int padding = (totalWidth > flopWidth) ? (totalWidth - flopWidth) / 2 : 0;
    std::string leftPadding(padding, ' ');
    std::string rightPadding((totalWidth > flopWidth) ? totalWidth - flopWidth - padding : 0, ' ');

    printf(R"(
                       DEALER
                     %s
              +---------------------------+
             /                             \
            /                               \
           /                                 \
          /                                   \
         /                                     \
        /                                       \
       +                                         +
       |           TEXAS HOLD'EM TABLE           |
              %s%s%s
       +                                         +
        \                                       /
         \                                     /
          \                                   /
           \                                 /
            \                               /
             \                             /
              +---------------------------+
                       PLAYER
                      %s

)", dealerCards.c_str(), leftPadding.c_str(), flopCards.c_str(), rightPadding.c_str(), playerCards.c_str());
}

void clearScreen() {
    // Clear the console screen
    system("clear");
}

void playTexasHoldem() {
    std::vector<playingCard> communityCards; // To store community cards
    std::vector<playingCard> dealerPrivateCards; // To store dealer's private cards
    std::vector<playingCard> playerPrivateCards; // To store player's private cards

    deckOfCards deck;
    deck.shuffle();
    srand((unsigned) time(NULL));

    classify player_hand;
    classify dealer_hand;

    clearScreen(); // Clear the screen before showing the table

    std::string dealerCards = "[??] [??]";
    std::string playerCards = "[??] [??]";

    // Present the table immediately
    printTable(dealerCards, playerCards);

    char choice;
    printf("\nDeal Cards (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        // Deal two cards to the player
        playerCards = "";
        for (int i = 0; i < 2; ++i) {
            playingCard card = deck.deal();
            playerPrivateCards.push_back(card);
            playerCards += "[" + card.toString() + "] ";
        }

        // Deal two cards to the dealer
        dealerCards = "";
        for (int i = 0; i < 2; ++i) {
            playingCard card = deck.deal();
            dealerPrivateCards.push_back(card);
            dealerCards += "[" + card.toString() + "] ";
        }

        clearScreen(); // Clear the screen before showing the table
        printTable(dealerCards, playerCards);
        printf("\nDealer Hand: %s", dealerCards.c_str());
        printf("\nPlayer Hand: %s\n", playerCards.c_str());

        // Prompt to deal the flop
        printf("\nDeal the Flop (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            std::string flopCards = "";
            for (int i = 0; i < 3; ++i) {
                playingCard card = deck.deal();
                communityCards.push_back(card);
                flopCards += "[" + card.toString() + "] ";
            }

            clearScreen(); // Clear the screen before showing the flop
            printTable(dealerCards, playerCards, flopCards);
            printf("\nDealer Hand: %s%s", dealerCards.c_str(), flopCards.c_str());
            printf("\nPlayer Hand: %s%s\n", playerCards.c_str(), flopCards.c_str());

            // Prompt to deal the turn
            printf("\nDeal the Turn (y/n): ");
            scanf(" %c", &choice);

            if (choice == 'y' || choice == 'Y') {
                std::string turnCard = "";
                playingCard card = deck.deal();
                communityCards.push_back(card);
                turnCard = "[" + card.toString() + "] ";

                clearScreen(); // Clear the screen before showing the turn
                printTable(dealerCards, playerCards, flopCards + turnCard);
                printf("\nDealer Hand: %s%s%s", dealerCards.c_str(), flopCards.c_str(), turnCard.c_str());
                printf("\nPlayer Hand: %s%s%s\n", playerCards.c_str(), flopCards.c_str(), turnCard.c_str());

                // Prompt to deal the river
                printf("\nDeal the River (y/n): ");
                scanf(" %c", &choice);

                if (choice == 'y' || choice == 'Y') {
                    std::string riverCard = "";
                    playingCard card = deck.deal();
                    communityCards.push_back(card);
                    riverCard = "[" + card.toString() + "] ";

                    clearScreen(); // Clear the screen before showing the river
                    printTable(dealerCards, playerCards, flopCards + turnCard + riverCard);
                    printf("\nDealer Hand: %s%s%s%s", dealerCards.c_str(), flopCards.c_str(), turnCard.c_str(), riverCard.c_str());
                    printf("\nPlayer Hand: %s%s%s%s\n", playerCards.c_str(), flopCards.c_str(), turnCard.c_str(), riverCard.c_str());

                    // Combine private and community cards for classification
                    std::vector<playingCard> dealerAllCards = dealerPrivateCards;
                    dealerAllCards.insert(dealerAllCards.end(), communityCards.begin(), communityCards.end());

                    std::vector<playingCard> playerAllCards = playerPrivateCards;
                    playerAllCards.insert(playerAllCards.end(), communityCards.begin(), communityCards.end());

                    // Classify the best hands
                    std::string dealerBestHand = classifyBestHand(dealerAllCards);
                    std::string playerBestHand = classifyBestHand(playerAllCards);

                    // Display the best hands
                    printf("\nDealer Best Hand: %s", dealerBestHand.c_str());
                    printf("\nPlayer Best Hand: %s\n", playerBestHand.c_str());
                }
            }
        }
    }
}

std::string classifyBestHand(const classify& handClassifier) {
    if (handClassifier.straight_flush()) return "Straight Flush";
    if (handClassifier.four_kind()) return "Four-of-a-Kind";
    if (handClassifier.full_house()) return "Full House";
    if (handClassifier.flush()) return "Flush";
    if (handClassifier.straight()) return "Straight";
    if (handClassifier.three_kind()) return "Three-of-a-Kind";
    if (handClassifier.two_pair()) return "Two Pair";
    if (handClassifier.one_pair()) return "One Pair";
    return "High Card";
}

std::string classifyBestHand(const std::vector<playingCard>& cards) {
    classify handClassifier;
    for (size_t i = 0; i < cards.size(); ++i) {
        handClassifier.insert_card(cards[i].theRank(), cards[i].theSuit(), i);
    }
    handClassifier.sort_hand();

    if (handClassifier.straight_flush()) return "Straight Flush";
    if (handClassifier.four_kind()) return "Four-of-a-Kind";
    if (handClassifier.full_house()) return "Full House";
    if (handClassifier.flush()) return "Flush";
    if (handClassifier.straight()) return "Straight";
    if (handClassifier.three_kind()) return "Three-of-a-Kind";
    if (handClassifier.two_pair()) return "Two Pair";
    if (handClassifier.one_pair()) return "One Pair";
    return "High Card";
}

int main() {
    char choice;
    do {
        clearScreen(); // Clear the screen before presenting the menu

        int gameChoice;
        printf("\n");
        printf("Please select a game to play:\n");
        printf("1.) Play Poker Hand Classification\n");
        printf("2.) Play Texas Hold'em\n");
        printf("Enter your choice: ");
        scanf("%d", &gameChoice);

        switch (gameChoice) {
            case 1:
                playPokerClassification();
                break;
            case 2:
                playTexasHoldem();
                break;
            default:
                printf("Invalid choice. Exiting.\n");
                return 0;
        }

        printf("\nPlay Again (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for playing!\n");
    return 0;
}
