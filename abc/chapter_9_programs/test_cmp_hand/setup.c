//Functions used in setting up a Poker game.

#include "poker.h"

//Returns a card with the given suit and rank.
card assign_values(int rank, suit suit)
{
    card c;

    if (rank == 1) {
    	c.rank = 14;
    }
    else {
    	c.rank = rank;
    }
    c.suit = suit;
    return c;
}

//Swaps the values of the two given cards.
void swap(card *p, card *q)
{
    card tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;
}

//Fills the given card array with a deck of standard playing cards.
void create_deck(card deck[52])
{
	int i, rank;
	suit suit;

    for (i = 0; i < 52; ++i) {
    	rank = i % 13 + 1;
    	if (i < 13)
    		suit = clubs;
    	else if (i < 26)
    		suit = diamonds;
    	else if (i < 39)
    		suit = hearts;
    	else
    		suit = spades;
    	*(deck + i) = assign_values(rank, suit);
    }
}

//Shuffles an array of 52 cards.
void shuffle(card deck[52])
{
    int i, j;

    for (i = 0; i < 52; ++i) {
    	j = rand() % 52;
    	swap(&deck[i], &deck[j]);
    }
}

//Deals the cards from a deck into an array of hands.
void deal_the_cards(card deck[52], card hand[5])
{
    int card_cnt = 0, i;

    for (i = 0; i < 5; ++i)
	    hand[i] = deck[card_cnt++];
}

//Returns the enum value of the poker hand contained within the given hand.
pkr_hand score_hand(card h[5])
{
	pkr_hand hand;
	if (is_straight_flush(h)) {
		hand = straight_flush;
	}
	else if (is_four_kind(h)) {
		hand = four_kind;
	}
	else if (is_full_house(h)) {
		hand = full_house;
	}
	else if (is_flush(h)) {
		hand = flush;
	}
	else if (is_straight(h)) {
		hand = straight;
	}
	else if (is_three_kind(h)) {
		hand = three_kind;
	}
	else if (is_two_pair(h)) {
		hand = two_pair;
	}
	else if (is_pair(h)) {
		hand = pair;
	}
	else {
		hand = high_card;
	}
	return hand;
}
