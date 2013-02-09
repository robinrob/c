/* This program deals out poker hands a set amount of times
 * and computes the empirical probabilities of certain hands.
 */

#include "poker.h"

double hand_probs[] = {0.5011466125, 0.4225690276, 0.0475390156, 0.0211284514,
		0.0039400376, 0.0019807923, 0.0014405762, 0.0002400960, 0.0000153908};

int main(void)
{
	card deck[52];
	card hand1[5], hand2[5];
	int i, n, cmp;

	printf("Enter n: ");
	scanf("%d", &n);
	srand(time(NULL));

	create_deck(deck);

	for (i = 0; i < n; ++i) {
		shuffle(deck);
		deal_the_cards(deck, hand1);
		shuffle(deck);
		deal_the_cards(deck, hand2);

		cmp = cmp_hands(hand1, hand2);

		if ((score_hand(hand1) == 7) || (score_hand(hand2) == 7)) {
			printf("\nhand 1:\n");
			print_cards(hand1, 5);
			printf("hand 2:\n");
			print_cards(hand2, 5);
			printf("%s wins!\n",
					cmp >= 0 ? (cmp > 0 ? "HAND 1" : "NEITHER") : "HAND 2");
		}
	}

	return 0;
}






