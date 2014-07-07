#include "poker.h"

//Runs the Poker Stats program.
void play_poker(card deck[52], int n_deals)
{
	int i, hand_cnts[9] = {0};
	card hand[5];;

	srand(time(NULL));

	for (i = 0; i < n_deals; ++i) {
		shuffle(deck);
		deal_the_cards(deck, hand);
		hand_cnts[hand_value(hand)]++;
	}

	for (i = 8; i >= 0; --i) {
		print_data(i, n_deals, hand_cnts[i]);
	}
}



