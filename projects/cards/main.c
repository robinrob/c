/* A Program which draws a user-defined number of cards
 * and checks for Poker hands within those cards. A message
 * is displayed for each hand above a pair.
 */

#include "cards.h"

int main(void)
{
	int n;
	char c;
	srand(time(NULL));
	printf("Enter number of cards to draw: ");
	while ((scanf("%d", &n) == 1)) {
		draw_cards(n);
		printf("\nEnter number of cards to draw: ");
	}
	return 0;
}
