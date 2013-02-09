//Functions used in checking cards for scoring Poker hands.

#include "poker.h"

/* Checks whether or not the given hand contains a straight flush and returns it
 * in order.
 */
int is_straight_flush(card h[5])
{
    int i;

    qsort(h, 5, sizeof(card), cmp_card);
    for (i = 3; i >= 0; --i) {
    	if (i == 0 && h[0].rank == 14 && h[1].rank == 5\
    			&& h[0].suit == h[1].suit) {;
    		return h[0].rank;
    	}
    	if (h[i].suit != h[4].suit || h[i].rank != (h[4].rank + (4 - i))) {
    		return 0;
    	}
    }
    return 1;
}

/* Checks whether or not the given hand contains a four-of-a-kind and returns it
 * in order.
 */
int is_four_kind(card h[5])
{
	int i, cnt = 0;
	qsort(h, 5, sizeof(card), cmp_card);
	for (i = 0; i < 4; ++i) {
		if (h[i].rank == h[i + 1].rank) {
			++cnt;
		}
		else {
			cnt = 0;
		}
		if (cnt == 3) {
			return 1;
		}
	}
	return 0;
}

/* Checks whether or not the given hand contains a full house and returns it in
 * order.
 */
int is_full_house(card h[5])
{
	qsort(h, 5, sizeof(card), cmp_card);
	if (is_three_kind_n(h, 3) && is_pair_n(h + 3, 2)) {
		return h[0].rank;
	}
	if (is_three_kind_n(h + 2, 3) && is_pair_n(h, 2)) {
		return h[2].rank;
	}
	return 0;
}

//Checks whether or not the given hand contains a flush and returns it in order.
int is_flush(card h[5])
{
    int i;

    qsort(h, 5, sizeof(card), cmp_card);
    for (i = 1; i < 5; ++i) {
    	if (h[i].suit != h[0].suit) {
    		return 0;
    	}
    }
    return 1;
}

/* Checks whether or not the given hand contains a straight and returns it in
 * order.
 */
int is_straight(card h[5])
{
	int i;
	qsort(h, 5, sizeof(card), cmp_card);
	for (i = 3; i >= 0; --i) {
		if ((i == 0) && (h[0].rank == 14) && h[1].rank == 5) {
			return 1;
		}
		if (h[i].rank != (h[4].rank + (4 - i))) {
			return 0;
		}
	}
	return 1;
}

/* Checks whether or not the given set of cards contains a three-of-a-kind and
 * returns it in order.
 */
int is_three_kind_n(card h[], int n)
{
	int i, cnt = 0;
	for (i = 0; i < n - 1; ++i) {
		if (h[i].rank == h[i + 1].rank) {
			++cnt;
		}
		else {
			cnt = 0;
		}
		if (cnt == 2) {
			return 1;
		}
	}
	return 0;
}

/* Checks whether or not the given hand contains a three-of-a-kind and returns
 * it in order.
 */
int is_three_kind(card h[5])
{
	int i, cnt = 0;
	qsort(h, 5, sizeof(card), cmp_card);
	for (i = 0; i < 4; ++i) {
		if (h[i].rank == h[i + 1].rank) {
			++cnt;
		}
		else {
			cnt = 0;
		}
		if (cnt == 2) {
			swap(h + i - 1, h);
			swap(h + i, h + 1);
			swap(h + i + 1, h + 2);
			return 1;
		}
	}
	return 0;
}

//Checks whether or not the given hand contains two pairs.
int is_two_pair(card h[5])
{
	int i, cnt = 0;
	qsort(h, 5, sizeof(card), cmp_card);
	for (i = 0; i < 4; ++i) {
		if (is_pair_n(h + i, 2)) {
			swap(h + i, h + 2 * cnt);
			swap(h + i + 1, h + 1 + 2 * cnt);
			++cnt;
			++i;
		}
		if (cnt == 2) {
			qsort(h, 4, sizeof(card), cmp_card);
			return 1;
		}
	}
	return 0;
}

/* Checks whether or not the given set of cards contains a pair and returns it
 * in order.
 */
int is_pair_n(card h[], int n)
{
	int i;
	for (i = 0; i < n - 1; ++i) {
		if (h[i].rank == h[i + 1].rank) {
			return 1;
		}
	}
	return 0;
}

//Checks whether or not the given five-card hand contains a pair.
int is_pair(card h[5])
{
	int i;
	qsort(h, 5, sizeof(card), cmp_card);
	for (i = 0; i < 4; ++i) {
		if (h[i].rank == h[i + 1].rank) {
			swap(h + i, h);
			swap(h + i + 1, h + 1);
			qsort(h + 2, 3, sizeof(card), cmp_card);
			return 1;
		}
	}
	return 0;
}

