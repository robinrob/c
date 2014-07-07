#include "poker.h"

//Runs the poker game.
void play_poker(card deck[52], int n_deals)
{
	int i, hand_cnts[9] = {0};
	card hand[5];
	pkr_hand score;

	srand(time(NULL));

	for (i = 0; i < n_deals; ++i) {
		shuffle(deck);
		deal_the_cards(deck, hand);
		score = score_hand(hand);
		hand_cnts[score]++;
	}

	for (i = 8; i >= 0; --i) {
		print_data(i, n_deals, hand_cnts[i]);
	}
}



