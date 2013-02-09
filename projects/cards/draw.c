/* This function draws a specified number of cards from a deck of 52 cards. */

#include "cards.h"

void draw_cards(int n)
{
	int i, j;
	pips p[n]; //Stores the values of the cards.
	suit s[n]; //Stores the suits of the cards.

	for (i = 0; i < n; ++i) {
		//Randomly choose a card value modulo 13:
		p[i] = (pips) ((rand() % 13) + 1);
		//Randomly choose a suit value modulo 4:
		s[i] = (suit) ((rand() % 4) + 1);
		//Check this card has not already been chosen:
		for (j = i - 1; j >= 0; --j) {
			if ((p[i] == p[j]) && (s[i] == s[j])) {
				--i; //if card HAS been chosen, try again.
				break;
			}
		}
	}
	//Display the hand:
	print_hand(n, p, s);
	//All the hand checks:
	check_three_of_a_kind(n, p);
	check_four_of_a_kind(n, p);
	check_full_house(n, p);
	check_straight(n, p);
	check_flush(n, p, s);
}
