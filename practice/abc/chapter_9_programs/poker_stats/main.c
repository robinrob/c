/* The Poker Stats program deals out poker hands a user-specified amount of
 * times and computes the empirical probabilities of the different hand
 * types. For each hand type it displays the number of hands found, its
 * empirical probability and its theoretical probability.
 */

#include "poker.h"

//Probabilities for Poker hands (High Card to Straight Flush).
double hand_probs[] = {0.5011466125, 0.4225690276, 0.0475390156, 0.0211284514,
		0.0039400376, 0.0019807923, 0.0014405762, 0.0002400960, 0.0000153908};

int main(void)
{
    int n_deals;
    card deck[52];
    
    printf("Enter number of deals: ");
    scanf("%d", &n_deals);
    create_deck(deck);
    play_poker(deck, n_deals);

    return 0;
}






