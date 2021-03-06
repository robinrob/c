/* The checking functions to check for Poker hands
 * and display messages if they are found.
 */

#include "cards.h"

/* Records the frequencies of pips values within a given array of pips values
 * and returns the frequencies as an array of integers.
 */
int *cnt_pips(int n, pips p[])
{
	int i, *cnt;
	cnt = calloc(sizeof(int), 13);
	//Initialise all elements of cnt[] to zero:
	for (i = 0; i < 13; ++i) {
		cnt[i] = 0;
	}
	//Record the frequencies of pips values:
	for (i = 0; i < n; ++i) {
		cnt[p[i] - 1]++; //pips values are offset by 1 (values are 1-13)
	}
	return cnt;
}

/* Checks for a three-of-a-kind within an array of pips values and displays a
 * message if one is found.
 */
void check_three_of_a_kind(int n, pips p[])
{
	int i, mod, *cnt;
	
	//Get a count of frequencies of pips values:
	cnt = cnt_pips(n, p);

	/* In descending order of card value (ace to 2), check for any count of
	 * three (or more) of a given pips value in cnt[]:
	 */
	for (i = 13; i > 0; --i) {
		mod = i % 13; //mod necessary because aces are stored in element zero.
		/* If a triplet is found in cnt[] for the current pips value, display
		 * a message and exit the loop:
		 */
		if (cnt[mod] >= 3) {
			printf("\n*** THREE OF A KIND!!! ***\n");
			printf("You have three %ss.\n", pips_name(mod + 1));
			break;
		}
	}
}

/* Checks for a four-of-a-kind within an array of pips values and displays a
 * message if one is found.
 */
void check_four_of_a_kind(int n, pips p[])
{
	int i, mod, *cnt;
	
	//Get a count of frequencies of pips values:
	cnt = cnt_pips(n, p);

	/* In descending order of card value (ace to 2), check for any count of
	 * four of a given pips value in cnt[]:
	 */
	for (i = 13; i > 0; --i) {
		mod = i % 13; //mod necessary because aces are stored in element zero.
		/* If a triplet is found in cnt[] for the current pips value, display
		 * a message and exit the loop:
		 */
		if (cnt[mod] == 4) {
			printf("\n*** FOUR OF A KIND!!! ***\n");
			printf("You have four %ss.\n", pips_name(mod + 1));
			break;
		}
	}
}

/* Checks for a full house within an array of pips values and displays a message
 * if one is found.
 */
void check_full_house(int n, pips p[])
{
	int i, mod, k, three_kind = 0, pair = 0, *cnt;
	
	//Get a count of frequencies of pips values:
	cnt = cnt_pips(n, p);

	//In descending pips order, look for a triplet and then a pair:
	for (i = 13; i > 0; --i) {
		mod = i % 13; //mod necessary because aces are stored in element zero.
		if (cnt[mod] >= 3 && !three_kind) {
			//Set three_kind to the pips value of the triplet:
			three_kind = mod + 1;
			continue;
		}
		if (cnt[mod] >= 2 && !pair) {
			//Set pair to the pips value of the pair:
			pair = mod + 1;
			break;
		}
	}
	//If both a triplet and a pair were found, display a message:
	if (three_kind && pair) {
		printf("\n*** FULL HOUSE!!! ***\n");
		printf("You have three %ss and two %ss.\n",
			   pips_name(three_kind), pips_name(pair));
	}
}

/* Checks for a straight within a given array of pips values and displays a
 * message if one is found.
 */
void check_straight(int n, pips p[])
{
	pips* straight;
	straight = has_straight(n, p);
	if (straight != NULL) {
		print_straight(straight);
	}
}

/* Checks if the given array of pips values contains a straight. If it does, an
 * array containing the values of the pips contained in the straight is
 * returned.
 */
pips* has_straight(int n, pips p[])
{
	int i, j, *cnt;
	pips* straight;
	straight = calloc(5, sizeof(int));
	
	//Get a count of frequencies of pips values:
	cnt = cnt_pips(n, p);
	//Loop over the suits:
	for (i = 13, j = 5; i > 0 && j > 0; --i) {
		if (cnt[i % 13] && j > 0) {
			//Add the pips value to the potential flush if not already complete:
			straight[--j] = (pips) ((i % 13) + 1);
		}
		//If the current potential straight has terminated, reset j:
		else {
			j = 5;
		}
	}
	//If straight is complete, return its pips values:
	if (j == 0) {
		return straight;
	}
	else {
		return NULL;
	}
}

/* Checks for a flush given arrays for the pips and suit values from a load of
 * cards. The check is terminated when the first flush is found.
 */
void check_flush(int n, pips p[], suit s[])
{
	int i, j, k, cnt[4][13];
	pips flush[5]; //Used to store pips values of cards in a potential flush.
	
	//Initialise all elements of cnt[][] to zero:
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 13; ++j) {
			cnt[i][j] = 0;
		}
	}
	//Record the cards in cnt[][] using s[] and p[].
	for (i = 0; i < n; ++i) {
		cnt[s[i] - 1][p[i] - 1]++;
	}
	
	//Loop over the set of suits:
	for (i = 0, k = 4; i < 4 && k > 0; ++i) {
		//Reset flush elements to zero.
		for (; k >= 0; --k) {
			flush[k] = 0;
		}
		/* For the current suit, add the first five pips values present
		 * in cnt[] to flush[] in descending order.
		 */
		for (j = 13, k = 5; j > 0 && k > 0; --j) {
			if (cnt[i][j % 13] && k > 0) {
				/* Add the pips value to the potential flush if not already
				 * complete:
				 */
				flush[--k] = (pips) ((j % 13) + 1);
			}
		}
		//If the flush is complete, terminate the loop and display the flush:
		if (k == 0) {
			print_flush(flush, i + 1);
			break;
		}
	}
}
