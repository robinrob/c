//Comparison functions.

#include "poker.h"

/* Comparison function for two cards. 1 is returned if the card pointed to by
 * vp is greater than vq, 0 if equal and -1 if *vq is greater.
 */
int cmp_card(const void *vp, const void *vq)
{
	const int *p = &(((card *) vp) -> rank);
	const int *q = &(((card *) vq) -> rank);
	int diff = *q - *p;
	return (diff >= 0) ? ((diff > 0) ? +1 : 0) : -1;
}

//Compares two hands.
int cmp_hands(card h1[], card h2[])
{
	pkr_hand score1, score2;
	int diff;
	qsort(h1, 5, sizeof(card), cmp_card);
	qsort(h2, 5, sizeof(card), cmp_card);
	score1 = score_hand(h1);
	score2 = score_hand(h2);
	diff = score2 - score1;
	if (diff > 0) {
		return -1;
	}
	else if (diff < 0) {
		return 1;
	}
	return cmp_same_hands(h1, h2);
}

//Compares two hands of the same type.
int cmp_same_hands(card h1[], card h2[])
{
	int i;
	for (i = 0; i < 5; ++i) {
		if (h1[i].rank > h2[i].rank) {
			return 1;
		}
		else if (h1[i].rank < h2[i].rank) {
			return -1;
		}
	}
	return 0;
}
